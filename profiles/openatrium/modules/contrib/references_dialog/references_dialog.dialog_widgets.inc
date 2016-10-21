<?php

/**
 * @file
 * Implements dialogs for node reference and user reference fields.
 */

/**
 * Implements hook_references_dialog_widgets().
 */
function references_dialog_references_dialog_widgets() {
  return array(
    'node_reference_autocomplete' => array(
      'element_type' => 'textfield',
      'dialog_form' => 'node_reference_dialog_form',
      'entity_type' => 'node',
      'format' => '$label [nid: $entity_id]',
      'views_query' => 'references_dialog_node_reference_views_query',
      'operations' => array(
        'search' => array(
          'function' => 'references_dialog_get_field_search_links',
          'title' => t('Search Dialog'),
        ),
        'edit' => array(
          'function' => 'references_dialog_node_reference_edit_link',
          'title' => t('Edit dialog'),
        ),
        'add' => array(
          'function' => 'references_dialog_node_reference_add_link',
          'title' => t('Add dialog'),
        ),
      ),
    ),
    'user_reference_autocomplete' => array(
      'element_type' => 'textfield',
      'entity_type' => 'user',
      'format' => '$label [uid: $entity_id]',
      'operations' => array(
        'search' => array(
          'function' => 'references_dialog_get_field_search_links',
          'title' => t('Search Dialog'),
        ),
        'edit' => array(
          'function' => 'references_dialog_user_reference_edit_link',
          'title' => t('Edit dialog'),
        ),
        'add' => array(
          'function' => 'references_dialog_user_reference_add_link',
          'title' => t('Add dialog'),
        ),
      ),
    ),
    'entityreference_autocomplete' => array(
      'element_type' => 'textfield',
      'dialog_form' => 'entityreference_autocomplete_dialog_form',
      'views_query' => 'references_dialog_entityreference_views_query',
      'type_callback' => 'references_dialog_entityreference_get_type',
      'format' => '$label ($entity_id)',
      'operations' => array(
        'edit' => array(
          'function' => 'references_dialog_entityreference_edit_link',
          'title' => t('Edit dialog'),
        ),
        'add' => array(
          'function' => 'references_dialog_entityreference_add_link',
          'title' => t('Add dialog'),
        ),
        'search' => array(
          'function' => 'references_dialog_get_field_search_links',
          'title' => t('Search Dialog'),
        ),
      ),
    ),
    'references_dialog_term_reference' => array(
      'element_type' => 'textfield',
      'dialog_form' => 'term_reference_dialog_form',
      'entity_type' => 'taxonomy_term',
      'format' => '$label',
      'views_query' => 'references_dialog_term_reference_views_query',
      'operations' => array(
        'search' => array(
          'function' => 'references_dialog_get_field_search_links',
          'title' => t('Search Dialog'),
        ),
        'edit' => array(
          'function' => 'references_dialog_term_reference_edit_link',
          'title' => t('Edit dialog'),
        ),
        'add' => array(
          'function' => 'references_dialog_term_reference_add_link',
          'title' => t('Add dialog'),
        ),
      ),
    ),
  );
}

/**
 * Edit link callback for node references.
 */
function references_dialog_node_reference_edit_link($element, $widget_settings, $field, $instance) {
  if (isset($element['#default_value']) || isset($element['#value'])) {
    if (isset($element['#default_value'])) {
      $value = $element['#default_value'];
    } else {
      // Take "label [nid:id]', match the id from parenthesis.
      if (preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $element['#value'], $matches)) {
        list(, $title, $value) = $matches;
      } else {
        return array();
      }
    }

    $node = node_load($value);
    if (node_access('update', $node)) {
      return array(
        array(
          'title' => t('Edit'),
          'href' => 'node/' . $value . '/edit'
        ),
      );
    }
  }
  return array();
}

/**
 * Add link callback for node references.
 */
function references_dialog_node_reference_add_link($element, $widget_settings, $field, $instance) {
  $add_links = array();
  foreach ($field['settings']['referenceable_types'] as $type => $active) {
    if ($active !== 0) {
      $node_type = node_type_load($type);
      if (node_access('create', $node_type->type)) {
        $add_links[] = array(
          'title' => t('Create @type', array('@type' => $node_type->name)),
          'href' => 'node/add/' . strtr($type, array('_' => '-')),
        );
      }
    }
  }
  return $add_links;
}

/**
 * View query callback for node references.
 */
function references_dialog_node_reference_views_query($view, $instance, $field) {
  // We need to make sure that no entries that we can't add to our field shows
  // up, so we need to limit the data here.
  $types = array();
  foreach ($field['settings']['referenceable_types'] as $type => $active) {
    if ($active !== 0) {
      $types[] = $type;
    }
  }
  $view->query->add_where(0, "$view->base_table.type", $types);
}

/**
 * Edit callback for user references.
 */
function references_dialog_user_reference_edit_link($element, $widget_settings, $field, $instance) {
  if (!isset($element['#default_value']) && !isset($element['#value'])) {
    return array();
  }
  if (isset($element['#default_value'])) {
    $value = $element['#default_value'];
  } else {
    // Take "label [uid:id]', match the id from parenthesis.
    if (preg_match('/^(?:\s*|(.*) )?\[\s*uid\s*:\s*(\d+)\s*\]$/', $element['#value'], $matches)) {
      list(, $title, $value) = $matches;
    } else {
      return array();
    }
  }
  global $user;
  $user_links = array();
  if (is_numeric($value) && user_load($value) &&
    user_access('access user profiles') &&
    (user_access('administer users') || $user->uid == $value)) {
    $user_links[] = array(
      'title' => t('Edit'),
      'href' => 'user/' . $value . '/edit',
    );
  }
  return $user_links;
}

/**
 * Add link callback for user references.
 */
function references_dialog_user_reference_add_link($element, $widget_settings, $field, $instance) {
  $user_links = array();
  // Check permissions for adding users.
  if (user_access('administer users')) {
    $user_links[] = array(
      'title' => t('Create user'),
      'href' => 'admin/people/create'
    );
  }
  return $user_links;
}

/**
 * Edit link callback for entity references.
 */
function references_dialog_entityreference_edit_link($element, $widget_settings, $field, $instance) {
  if (isset($element['#default_value'])) {
    $raw_value = $element['#default_value'] ? $element['#default_value'] : $element['#value'];
    $entity_type = $field['settings']['target_type'];
    // Take "label (entity id)', match the id from parenthesis.
    if (preg_match("/.+\((\d+)\)/", $raw_value, $matches)) {
        $value = $matches[1];
      }
    if (isset($value)) {
      $entity = current(entity_load($entity_type, array($value)));
      if (entity_access('update', $entity_type, $entity)) {
        return array(
          array(
            'title' => t('Edit'),
            'href' => references_dialog_get_admin_path($entity_type, 'edit', NULL, $entity),
          ),
        );
      }
    }
 }
  return array();
}

/**
 * Add link callback for entity references.
 */
function references_dialog_entityreference_add_link($element, $widget_settings, $field, $instance) {
  $add_links = array();
  $entity_type = $field['settings']['target_type'];
  $entity_info = entity_get_info($entity_type);
  $entity_bundles = array_keys($entity_info['bundles']);
  if (!empty($field['settings']['handler_settings']['target_bundles'])) {
    $bundles = $field['settings']['handler_settings']['target_bundles'];
  }
  elseif (!empty($field['settings']['handler_settings']['view'])) {
    $name = $field['settings']['handler_settings']['view']['view_name'];
    $display = $field['settings']['handler_settings']['view']['display_name'];
    $views = views_get_view($name);
    $views_display = $views->display;
    $bundle_key = $entity_info['bundle keys']['bundle'];

    if (isset($views_display[$display]->display_options['filters'][$bundle_key])) {
      $views_filters = $views_display[$display]->display_options['filters'][$bundle_key]['value'];
    }
    else if (!empty($views_display['default']->display_options['filters'][$bundle_key]['value'])) {
      $views_filters = $views_display['default']->display_options['filters'][$bundle_key]['value'];
    }

    $bundles = array_keys($views_filters);
  }
  elseif (isset($entity_info['bundles'])) {
    // If the entity target bundles is empty, it means all target bundles are allowed. Fill it all up!
    $bundles = $entity_bundles;
  }
  // Create a link for each allowed bundles.
  if (isset($bundles)) {
    foreach ($bundles as $bundle) {
      if (in_array($bundle, $entity_bundles) && $link = references_dialog_entityreference_link_helper($entity_type, $bundle)) {
        $add_links[] = $link;
      }
    }
  }
  return $add_links;
}

function references_dialog_entityreference_link_helper($entity_type, $bundle = NULL) {
  $wrapper = entity_metadata_wrapper($entity_type, NULL, array('bundle' => $bundle));
  $info = $wrapper->entityInfo();
  if (isset($bundle)) {
    $label = $info['bundles'][$bundle]['label'];
  }
  else {
    $label = $info['label'];
  }

  // entity_access() doesn't provide a generic bundle create op access check.
  switch ($entity_type) {
    case 'node':
      $access = node_access('create', $bundle);
      break;

    case 'taxonomy_term':
      if (module_exists('taxonomy_access_fix')) {
        $vocabulary = taxonomy_vocabulary_machine_name_load($bundle);
        $access = taxonomy_access_fix_access('add terms', $vocabulary);
      } else {
        $access = entity_access('create', $entity_type);
      }
      break;

    default:
      $access = entity_access('create', $entity_type);
      break;
  }

  $path = references_dialog_get_admin_path($entity_type, 'add', $bundle);

  if ($access && $path) {
    $link = array(
      'title' => t('Create @type', array('@type' => $label)),
      'href' => $path,
    );
    return $link;
  }
  return FALSE;
}

/**
 * View query callback for entityreference references.
 */
function references_dialog_entityreference_views_query($view, $instance, $field) {
  // We need to make sure that no entries that we can't add to our field shows
  // up, so we need to limit the data here.
  $types = array();
  if (!empty($field['settings']['handler_settings']['target_bundles'])) {
    $entity_info = entity_get_info($field['settings']['target_type']);
    if (isset($entity_info['entity keys']['bundle'])) {
      // Taxonomy terms don't have their bundle in the table, so we handle them
      // specially, for now.
      if ($field['settings']['target_type'] == 'taxonomy_term') {
        $table = 'taxonomy_vocabulary';
        $column = 'machine_name';
      }
      else {
        $table = $view->base_table;
        $column = $entity_info['entity keys']['bundle'];
      }
      // Add the bundle property as a default.
      $view->query->add_where(0, "$table." . $column, array_values($field['settings']['handler_settings']['target_bundles']));
    }
  }
}

function references_dialog_entityreference_get_type($instance, $field) {
  return $field['settings']['target_type'];
}

/**
 * Edit link callback for term references.
 */
function references_dialog_term_reference_edit_link($element, $widget_settings, $field, $instance) {
  if (isset($element['#default_value'])) {
    // Get Term ID from entity.
    $term = taxonomy_term_load($element['#entity']->{$element['#field_name']}[$element['#language']][$element['#delta']]['tid']);
    if ($term && taxonomy_term_edit_access($term)) {
      $path = taxonomy_term_uri($term);
      return array(
        array(
          'title' => t('Edit'),
          'href' => $path['path'] . '/edit'
        ),
      );
    }
  }
  return array();
}

/**
 * Add link callback for term references.
 */
function references_dialog_term_reference_add_link($element, $widget_settings, $field, $instance) {
  $vocabulary = $field['settings']['allowed_values'][0]['vocabulary'];
  $add_links = array();
  if (user_access('administer taxonomy') || (module_exists('taxonomy_access_fix') && taxonomy_access_fix_access('add terms', $vocabulary))) {
    $add_links[] = array(
      'title' => t('Create @type', array('@type' => taxonomy_vocabulary_machine_name_load($vocabulary)->name)),
      'href' => 'admin/structure/taxonomy/' . $field['settings']['allowed_values'][0]['vocabulary'] . '/add',
    );
  }
  return $add_links;
}

/**
 * View query callback for term references.
 */
function references_dialog_term_reference_views_query($view, $instance, $field) {
  // We need to make sure that no entries that we can't add to our field shows
  // up, so we need to limit the data here.
  $vocabulary = taxonomy_vocabulary_machine_name_load($field['settings']['allowed_values'][0]['vocabulary']);
  $types = array($vocabulary->vid);
  $view->query->add_where(0, "$view->base_table.vid", $types);
}
