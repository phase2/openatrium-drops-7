<?php
/**
 * @file
 * MailhandlerParser class.
 */

/**
 * Parses an IMAP stream.
 */
class OaMailParser extends MailhandlerParser {

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $defaults = parent::configDefaults();
    $defaults['require_contextual_nid'] = TRUE;
    $defaults['filter_email'] = TRUE;
    return $defaults;
  }

  /**
   * Build configuration form.
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $form['require_contextual_nid'] = array(
      '#type' => 'checkbox',
      '#title' => t('Require contextual node ID'),
      '#description' => t("This will require that emails have a contextual node ID ([#nid]) in the subject, or they won't be parsed."),
      '#default_value' => $this->config['require_contextual_nid'],
    );
    $form['filter_email'] = array(
      '#type' => 'checkbox',
      '#title' => t('Filter email body'),
      '#description' => t("Attempts to filter excessive text from emails such as signatures, original email message etc. This is strongly recommended unless legitimate content is being filtered. Body (HTML) isn't filtered."),
      '#default_value' => $this->config['filter_email'],
    );
    return $form;
  }

  /**
   * Implementation of FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = parent::parse($source, $fetcher_result);

    foreach ($result->items as &$item) {
      // Parse the subject for a contextual nid
      $contextual_nid = $this->getContextualNidFromSubject($item['subject']);
      if ($contextual_nid) {
        $context = node_load($contextual_nid);
        $item['contextual_nid'] = $context->nid;
        $space = current(field_get_items('node', $context, 'og_group_ref'));
        if ($space) {
          $item['contextual_space_id'] = $space['target_id'];
        }
        $section = current(field_get_items('node', $context, 'oa_section_ref'));
        if ($section) {
          $item['contextual_section_id'] = $section['target_id'];
        }
      }
      elseif ($this->config['require_contextual_nid']) {
        $item = array();
      }

      // Filter the email
      if ($this->config['filter_email'] && isset($item['body_text'])) {
        $item['body_text'] = $this->filterEmailBody($item['body_text']);
      }
    }

    return $result;
  }

  private function getContextualNidFromSubject($subject) {
    preg_match('/\[#([0-9]*)\]/', $subject, $matches);
    return isset($matches[1]) ? $matches[1] : 0;
  }

  /**
   * This defines sources which user's can select to map values to.
   */
  public function getMappingSources() {
    $sources = parent::getMappingSources();
    $sources['contextual_nid'] = array(
      'name' => t('Contextual node ID'),
      'description' => t('Contextual node ID parsed from the subject, in the form of [#nid].'),
    );
    $sources['contextual_space_id'] = array(
      'name' => t('Contextual node space ID'),
      'description' => t('The space the contextual node belongs to, if available.'),
    );
    $sources['contextual_section_id'] = array(
      'name' => t('Contextual node section ID'),
      'description' => t('The section the contextual node belongs to, if available.'),
    );
    return $sources;
  }


  /**
   * Filter things like signatures, message threads out of email body. Taken
   * from Mail Comment module.
   */
  private function filterEmailBody($body) {
    $delimiters = array(
      "On \d{1,2}[\/\-]{1}\d{1,2}[\/\-]{1}\d{1,2},", // Gmail form 1
      "On \w{3}, \w{3} \d{1,2}, \d{4} at \d{1,2}:\d{1,2} [AP]M", // Gmail form 1
      "On \w{3}, \w{3} \d{1,2}, \d{4} at \d{1,2}:\d{1,2} [AP]M", // Gmail form 2
      "On \d{1,2}\/\d{1,2}\/\d{4} \d{1,2}:\d{1,2} [AP]M,", // Thunderbird
      "On [A-Z][a-z]{2} [0-9]{1,2}, [0-9]{4}, at [0-9]{1,2}:[0-9]{2} [AP]M, [a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4} wrote", // Mac mail form 1
      "On [A-Z][a-z]{2} [0-9]{1,2}, [0-9]{4}, at [0-9]{1,2}:[0-9]{2} [AP]M,", // Mac mail form 2
      "On \d{1,2} \w{3} \d{4}, at \d{1,2}:\d{2} [AP]M, [a-zA-Z0-9._%-]+@?[a-zA-Z0-9.-]*[\.]?[a-zA-Z]{0,4} wrote:", // Mac mail v4.2
      "-----\s?Original Message\s?-----", // Outlook Express
      "From:(\s*)[A-Za-z0-9._%+-]+@[A-Za-z0-9._%+-]+\.[A-Za-z]{2,3}(\s*)\[mailto:[A-Za-z0-9._%+-]+@[A-Za-z0-9._%+-]+\.[A-Za-z]{2,3}\]", // Outlook legacy
      "[_]*\nFrom:", // Yahoo + Outlook web
      "From:.*Sent:.*To:.*Subject:", // Fallback
    );

    $expression = '/('. implode('|', $delimiters) .')/';
    if (preg_match($expression, $body, $matches, PREG_OFFSET_CAPTURE)) {
      $body = trim(drupal_substr($body, 0, $matches[0][1]));
    }

    return $body;
  }
}
