<?php

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_pre_render().
 */
function og_subgroups_views_pre_render(&$view) {
  if ($view->name == 'og_members_admin') {
    // Add an overview of the users that are inherited from parent groups.
    $inherited_users = _og_subgroups_get_inherited_users($view->args[0], $view->args[1]);
    $header = array('Name', 'Inherited from');
    $rows = array();
    $membership_states = og_group_content_states();
    if (!empty($inherited_users)) {
      foreach ($inherited_users as $inherited_uid => $data) {
        $row = array();
        $row[] = l($data[0]['user']->name, 'user/' . $inherited_uid);
        $inherited_from = array();
        foreach ($data as $inheritance) {
          $inherited_from[] = t('!parent (@roles)', array(
            '!parent' => l(entity_label($inheritance['inherited_from']['type'], $inheritance['inherited_from']['entity']), 'group/' . $inheritance['inherited_from']['type'] . '/' . $inheritance['inherited_from']['id'] . '/admin/people'),
            '@roles' => implode(', ', $inheritance['roles']),
          ));
        }
        $row[] = implode(', ', $inherited_from);
        $rows[] = $row;
      }
    }
    $view->attachment_after = theme('table', array(
      'caption' => t('Inherited users'),
      'header' => $header,
      'rows' => $rows,
      'empty' => t('No inherited users.'),
    ));
  }
}
