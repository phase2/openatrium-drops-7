<?php


/**
 * List all bundles and administrative options for command buttons.
 */
function command_buttons_entities_page() {
  $entity_info = entity_get_info('command_button');

  $header = array(t('Name'), array('data' => t('Operations'), 'colspan' => 2));
  $rows = array();

  foreach ($entity_info['bundles'] as $bundle => $info) {
    $type_url_str = str_replace('_', '-', $bundle);

    $row = array();

    $label = check_plain($info['label']);
    $label .= ' <small>' . t('(Machine name: @type)', array('@type' => $bundle)) . '</small>';

    $row[] = $label;

    $operations = array();

    $operations['list'] = array(
      'title' => t('list'),
      'href' => 'admin/structure/command-buttons/manage/' . $type_url_str,
    );

    $operations['add'] = array(
      'title' => t('add'),
      'href' => 'admin/structure/command-buttons/manage/' . $type_url_str . '/add',
    );

    $operations['fields'] = array(
      'title' => t('manage fields'),
      'href' => 'admin/structure/command-buttons/manage/' . $type_url_str . '/fields',
    );

    $operations['display'] = array(
      'title' => t('manage display'),
      'href' => 'admin/structure/command-buttons/manage/' . $type_url_str . '/display',
    );

    $ops = theme('links', array('links' => $operations, 'attributes' => array('class' => array('links', 'inline'))));

    $row[] = $ops;
    $rows[] = $row;
  }

  $build['panes_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}

/**
 * Page callback to add a new pane entity.
 */
function command_buttons_entities_add_page($type) {
  $form_state = array(
    'entity' => command_buttons_create(array('bundle' => $type)),
    'add submit' => TRUE,
  );

  // Default these to reusable.
  $form_state['entity']->reusable = TRUE;
  return drupal_build_form('command_buttons_entity_edit_form', $form_state);
}

/**
 * Page callback to view a entity.
 */
function command_buttons_entity_edit_page($entity) {
  $form_state = array(
    'entity' => $entity,
    'add submit' => TRUE,
  );

  return drupal_build_form('command_buttons_entity_edit_form', $form_state);
}

/**
 * Menu callback -- ask for confirmation of node deletion
 */
function command_buttons_entity_delete_form($form, &$form_state, $entity) {
  $form_state['entity'] = $entity;
  return confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => $entity->title)),
    'admin/structure/command-buttons/view/' . $entity->bid,
    t('This action cannot be undone. Note that deleting this entity will not delete panes using it, they will exist but display nothing.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Execute node deletion
 */
function command_buttons_entity_delete_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $entity = $form_state['entity'];
    command_buttons_delete($entity->bid);
    watchdog('command_buttons', '@type: deleted %title.', array('@type' => $entity->bundle, '%title' => $entity->title));
    drupal_set_message(t('@type %title has been deleted.', array('@type' => command_buttons_entities_title($entity->bundle), '%title' => $entity->title)));
  }

  $form_state['redirect'] = 'admin/structure/command-buttons';
}
