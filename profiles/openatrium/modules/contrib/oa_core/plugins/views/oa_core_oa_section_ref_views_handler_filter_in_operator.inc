<?php

/**
 * @file
 * Code to override field to add in auto option.
 */

class oa_core_oa_section_ref_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $id = NULL;
    if (!empty($this->options['expose']['identifier']) && empty($this->options['expose']['oa_core_no_auto'])) {
      $id = $this->options['expose']['identifier'];
      $exposed = $this->view->get_exposed_input();
      if (isset($exposed[$id]) && empty($exposed[$id])) {
        $section = oa_core_get_section_context();
        if (($node = menu_get_object()) && $node->type == 'oa_space') {
          $section = NULL;
        }
        if ($section) {
          $exposed[$id] = $section;
        }
        else {
          unset($exposed[$id]);
        }
        $this->view->set_exposed_input($exposed);
      }
    }
    $exposed = $this->view->get_exposed_input();
    // Remove section value if section not in group.
    if (!empty($id) && !empty($exposed[$id]) && is_numeric($exposed[$id]) &&
      !empty($exposed['og_group_ref_target_id']) &&
      ($section = node_load($exposed[$id])) && isset($section->{OA_SPACE_FIELD}[LANGUAGE_NONE][0]['target_id']) &&
      $section->{OA_SPACE_FIELD}[LANGUAGE_NONE][0]['target_id'] != $exposed['og_group_ref_target_id']) {
      unset($exposed[$id]);
      $this->view->set_exposed_input($exposed);
    }
  }
}
