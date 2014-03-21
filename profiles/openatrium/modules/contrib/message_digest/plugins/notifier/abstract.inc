<?php

/**
 * Message Digest notifier.
 */
class MessageDigest extends MessageNotifierBase {

  // Do not actually deliver this message because it will be delivered
  // via cron in a digest, but return TRUE to prevent a logged error.
  // Instead, we "deliver" it to the message_digest DB table so that it
  // can be retrieved at a later time.
  public function deliver(array $output = array()) {
    $message = $this->message;
    $plugin = $this->plugin;

    $message_digest = array(
      'receiver' => $message->uid,
      'gid' => !empty($message->gid) ? $message->gid : 0,
      'notifier' => $plugin['name'],
      'sent' => FALSE,
      'timestamp' => $message->timestamp,
    );
    // This will only have a value if the message is not a message_subscribe message.
    $mid = isset($message->mid) ? $message->mid : NULL;

    // Our $message is a cloned copy of the original $message with the mid field removed to
    // prevent overwriting (this happens in message_subscribe) so we need to fetch the mid manually.
    if (empty($mid)) {
      $mid = db_select('message', 'm')
        ->fields('m', array('mid'))
        ->condition('timestamp', $message->timestamp)
        ->condition('type', $message->type)
        ->execute()
        ->fetchField();
    }

    if (!empty($mid)) {
      $message_digest['mid'] = $mid;
    }

    drupal_write_record('message_digest', $message_digest);

    return TRUE;
  }

  /**
   * This will be overridden in subclasses with custom intervals.
   */
  public function getInterval() {
    return '1 day';
  }

  /**
   * Aggregate all of the messages for this interval and notifier that haven't
   * already been sent, and group them by user and then by group.
   */
  public function aggregate() {
    $interval = $this->getInterval();
    $start = strtotime('-' . $interval); // Invert $interval since it's in the past.
    $message_groups = array();

    $query = db_select('message_digest', 'md');
    $query->fields('md');
    $query->condition('timestamp', $start, '>');
    $query->condition('sent', FALSE);
    $query->condition('notifier', $this->plugin['name']);
    $result = $query->execute();

    foreach ($result as $row) {
      $gid = $row->gid;
      if (empty($gid)) {
        $gid = 0;
      }
      $account = user_load($row->receiver);
      $context = array(
        'account' => $account,  // reference only
        'data' => $row,
        'gid' => $gid,  // set this to zero to aggregate group content
        'plugin' => $this->plugin, // reference only
      );
      drupal_alter('message_digest_aggregate', $context);
      if (!empty($context['data']->mid)) {
        $message_groups[$context['data']->receiver][$context['gid']][] = $context['data']->mid;
      }
    }
    return $message_groups;
  }

  /**
   * Given an array of mids, build the full message content for them
   * and combine them into one blob of email content.
   */
  public function format($digest, $view_modes) {
    $output_array = array();
    foreach ($digest as $mid) {
      $message = message_load($mid);
      if (empty($message) || !is_object($message)) {
        continue;
      }
      $rows = array();
      foreach ($view_modes as $view_mode_name => $view_mode) {
        $content = $message->buildContent($view_mode_name);
        $rows[$view_mode_name] = render($content);
      }
      $output_array[] = theme('message_digest_row', array(
        'rows' => $rows,
        'plugin' => $this->plugin,
        'message' => $message,
      ));
    }
    return theme('message_digest', array(
      'messages' => $output_array,
      'plugin' => $this->plugin,
    ));
  }

  /**
   * Send the actual digest email.
   */
  public function deliverDigest($uid, $gid, $formatted_message) {
    $account = user_load($uid);
    $lang = !empty($account->language) && $account->language != LANGUAGE_NONE ? $languages[$account->language] : language_default();
    $params = array(
      'body' => $formatted_message,
      'gid' => $gid
    );
    drupal_mail('message_digest', 'digest', $account->mail, $lang, $params);  // @TODO, USE message_notify_send_message() INSTEAD.
  }

  /**
   * Mark the sent digest messages as sent in the message_digest DB table.
   */
  public function markSent($uid, $plugin_name) {
    $num_rows = db_update('message_digest')
      ->fields(array('sent' => TRUE))
      ->condition('receiver', $uid)
      ->condition('notifier', $plugin_name)
      ->execute();
  }
}
