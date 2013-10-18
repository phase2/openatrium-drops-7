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

    // Our $message is a cloned copy of the original $message with the mid field removed to
    // prevent overwriting (this happens in message_subscribe) so we need to fetch the mid manually.
    $mid = db_select('message', 'm')
      ->fields('m', array('mid'))
      ->condition('timestamp', $message->timestamp)
      ->execute()
      ->fetchField();
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
      $account = user_load($row->receiver);
      if (!empty($account->data['digest_grouping']) && $account->data['digest_grouping'] == 'global') {
        // Allow users to group all groups together in the same digest.
        $gid = 0;
      }
      $message_groups[$row->receiver][$row->gid][] = $row->mid;
    }
    return $message_groups;
  }

  /**
   * Given an array of mids, build the full message content for them
   * and combine them into one blob of email content.
   */
  public function format($digest) {
    $output_array = array();
    foreach ($digest as $mid) {
      $message = message_load($mid);
      $build = $message->view();
      $build += array(
        '#theme' => 'message',
        '#entity' => $message,
        '#view_mode' => 'message_notify_email_subject', // @TODO: Default to the "Email Subject" view mode but use the Message Digest view mode if it is customized.
      );
      $output_array[] = drupal_render($build);
    }
    return implode('<hr />', $output_array); // @TODO: Use a theme function + template for this.
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
