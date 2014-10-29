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
    return $form;
  }

  /**
   * Implementation of FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = parent::parse($source, $fetcher_result);

    foreach ($result->items as &$item) {
      // Parse the subject for a contextual nid
      $context = oa_mailhandler_get_node_from_subject($item['subject']);
      if ($context) {
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
    }

    return $result;
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
}
