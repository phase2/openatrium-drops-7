<?php

/**
 * @file
 * Code to override field to add in auto option.
 */

class oa_core_og_group_ref_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  private $fail_build = FALSE;
  function init(&$view, &$options) {
    parent::init($view, $options);
    $exposed = $this->view->get_exposed_input();
    if (!empty($this->options['expose']['identifier']) && empty($this->options['expose']['oa_core_no_auto'])) {
      $id = $this->options['expose']['identifier'];
      if (isset($exposed[$id]) && empty($exposed[$id])) {
        if ($group = oa_core_get_space_context()) {
          $exposed[$id] = $group;
        }
        else {
          unset($exposed[$id]);
        }
      }
    }
    // Pane doesn't allow unrelated exposed input, so bring it back.
    if (!empty($_GET[$id . '_mine'])) {
      $exposed[$id . '_mine'] = 1;
    }

    // Form API considers a Value of 0 to be CHECKED!!!!!
    // So if the value is zero, we set it to FALSE so it is properly UnChecked.
    if (isset($exposed[$id . '_mine']) && empty($exposed[$id . '_mine'])) {
      $exposed[$id . '_mine'] = FALSE;
    }

    global $user;
    if (!empty($exposed[$id . '_mine'])) {
      $groups = oa_core_get_groups_by_user($user, 'node');
      if ($groups && ($gids = array_intersect_key($groups, $this->get_value_options()))) {
        $exposed[$id] = $gids;
        $this->options['expose']['multiple'] = TRUE;
      }
      else {
        // If restricting to My Spaces but the user has no spaces, fail the build
        $this->fail_build = TRUE;
      }
    }
    // If was multiple from mine setting, clear it out.
    elseif (empty($this->options['expose']['multiple']) && isset($exposed[$id]) && is_array($exposed[$id])) {
      unset($exposed[$id]);
    }
    $this->view->set_exposed_input($exposed);
  }

  function query() {
    parent::query();
    if (!empty($this->fail_build)) {
      $this->view->build_info['fail'] = TRUE;
    }
  }

  function exposed_form(&$form, &$form_state) {
    parent::exposed_form($form, $form_state);
    global $user;
    $exposed = $this->view->get_exposed_input();
    $groups = oa_core_get_groups_by_user($user, 'node');
    if (($id = $this->options['expose']['identifier']) && $groups && !empty($form[$id]['#options']) && array_intersect_key($groups, $form[$id]['#options'])) {
      $form[$id . '_mine'] = array(
        '#title' => t('My Spaces'),
        '#default_value' => 0,
        '#type' => 'checkbox',
      );
      if (!empty($exposed[$id . '_mine'])) {
        $form[$id]['#access'] = FALSE;
        // Need to set it here else the value is ignored when access is FALSE.
        if (!empty($exposed[$id])) {
          $form[$id]['#value'] = $exposed[$id];
        }
      }
    }
  }

}
