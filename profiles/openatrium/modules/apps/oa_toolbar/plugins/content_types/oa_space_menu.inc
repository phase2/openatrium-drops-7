<?php
/**
 * @file
 * Provides a panels pane that displays the OA Space Menu in the toolbar.
 */

$plugin = array(
  'title' => t('Open Atrium Space Menu'),
  'description' => t('The Open Atrium space-specific navigation menu.'),
  'category' => array(t('OA Admin'), -9),
);

/**
 * Render callback.
 */
function oa_toolbar_oa_space_menu_content_type_render($subtype, $conf, $panel_args) {

  $node = menu_get_object();
  $front_panel = drupal_is_front_page() && !(isset($node) && ($node->type == OA_SPACE_TYPE));
  if ($front_panel) {
    return;
  }

  $space_id = oa_core_get_space_context();
  $space_id = $space_id ? oa_core_get_group_from_node($space_id) : NULL;
  if ($space_id && ($space = node_load($space_id)) && node_access('view', $space)) {
    // We can view this space.
  }
  else {
    $space_id = NULL;
  }

  if (empty($space_id) || !variable_get('oa_space_menu_' . $space_id, TRUE)) {
    return;
  }

  $vars = array();
  if (module_exists('oa_appearance')) {
    $field = field_get_items('node', $space, OA_SPACE_BANNER_POSITION);
    $show_space_banner = (!empty($field[0]['value']) && ($field[0]['value'] == OA_SPACE_BANNER_SPACE_MENU));
    if ($show_space_banner) {
      $space_picture = field_get_items('node', $space, 'field_oa_banner');
      if (!empty($space_picture)) {
        $space_picture = array_shift($space_picture);
        $vars['height'] = $space_picture['height'];
        $vars['width'] = $space_picture['width'];
        $vars['banner'] = theme('image_style', array(
          'style_name' => 'oa_banner',
          'path' => $space_picture['uri'],
          'width' => $space_picture['width'],
          'height' => $space_picture['height'],
          'alt' => $space_picture['alt'],
          'attributes' => array(
            'class' => array('oa-banner-img')
          ),
        ));
        $vars['banner'] = l($vars['banner'], 'node/' . $space_id, array('html' => true));
      }
      else {
        $show_space_banner = FALSE;
      }
    }
  }

  // Grab the basic group menu from og_menu_single's content-type.
  $space_menu = ctools_content_render('og_menu_single_menu', '', array(
    'og_menu_single_depth' => 1,
    'og_menu_single_parent' => '0',
    'override_title_text' => '',
    'override_title' => TRUE,
  ), array());

  // If we have space menu items.
  if (!empty($space_menu->content)) {
    // Format and add menu to template.
    $space_menu->content['#theme_wrappers'] = array('menu_tree__oa_navigation');
    // Get icon settings from section types.
    $terms = oa_sections_get_icons();
    // If we are viewing content within a section.
    if (isset($node) && $node->type != OA_SECTION_TYPE) {
      // Get the section this content belongs to.
      $parent_section = entity_load_single('node', oa_core_get_section_context());
      if ($parent_section) {
        // Get the node id for the section.
        $parent_section_id = $parent_section->nid;
      }
    }
    elseif (isset($node) && $node->type == OA_SECTION_TYPE) {
      $parent_section_id = $node->nid;
    }
    // Iterate over the space menu items so we can prepend icons to their titles.
    foreach (element_children($space_menu->content) as $mlid) {
      // Render the links as Radix defaults.
      $space_menu->content[$mlid]['#theme'] = 'menu_link__oa_navigation';
      // Get the router item for this link.
      $item = menu_get_item($space_menu->content[$mlid]['#href']);
      // The node for this menu item.
      $item_node = $item['map'][1];
      // If there is no icon class or image, we set the icon to nothing.
      $icon = '';
      // The term id for this items node as it relates to the section.
      if (isset($item_node->field_oa_section[LANGUAGE_NONE][0]['tid'])) {
        $term_id = $item_node->field_oa_section[LANGUAGE_NONE][0]['tid'];
        if (isset($terms[$term_id])) {
          // See if we have an icon value in the form of a class. We check for
          // this first as we want this to override any uploaded image.
          if (!empty($terms[$term_id]->field_oa_icon_class_value)) {
            $icon = '<i class="' . check_plain($terms[$term_id]->field_oa_icon_class_value) . '"></i>';
          }
          // Otherwise we will use an uploaded icon image.
          else {
            if (!empty($terms[$term_id]->field_oa_icon_image_fid)) {
              // Load the file that represents the icon.
              $file = file_load($terms[$term_id]->field_oa_icon_image_fid);
              // Build a content array so we can render the file.
              $content = array(
                'file' => array(
                  '#theme' => 'image_style',
                  '#style_name' => 'oa_medium_thumbnail',
                  '#path' => $file->uri,
                ),
              );
              // Render the file as content.
              $icon = drupal_render($content);
            }
          }
        }
      }
      // Prepend the icon to the link title.
      $space_menu->content[$mlid]['#title'] = $icon . $space_menu->content[$mlid]['#title'];
      // Allow html in the title.
      $space_menu->content[$mlid]['#localized_options']['html'] = TRUE;
      // We are on a section content page we need to set the parent section menu
      // item as the active link.
      if (isset($parent_section_id)) {
        // If the node's nid matches the parent's section nid then we set
        // the parent menu item to 'active'.
        if (isset($item_node) && ($item_node->nid == $parent_section_id)) {
          $space_menu->content[$mlid]['#attributes']['class'][] = 'active';
        }
      }
    }
  }
  // If we have space menu items.
  if (!empty($space_menu->content)) {
    foreach ($space_menu->content as $key => $value) {
      if (!empty($value['#original_link']['menu_name'])) {
        // rename menu to prevent DHTML menu from hooking into this
        $space_menu->content[$key]['#original_link']['menu_name'] = 'oa-space-menu';
      }
    }
  }

  $vars['menu'] = (!empty($space_menu->content)) ? $space_menu->content : '';
  if (!$show_space_banner && variable_get('oa_space_menu_home_' . $space_id, TRUE) && (!empty($space_menu->content)) && $space_id) {
    $title = t('Space home');
    $field = field_get_items('node', $space, 'field_oa_space_type');
    if (!empty($field[0]['tid'])) {
      $space_type = $field[0]['tid'];
      $term = taxonomy_term_load($space_type);
      $title = ($term->name != 'Default') ? $term->name . ' ' . t('home') : $title;
    }
    $class = ($node == $space) ? 'active' : '';
    $home_link = array(
      '#theme' => 'menu_link__oa_navigation',
      '#title' => '<i class="fa fa-home"></i>' . $title,
      '#href' => 'node/' . $space_id,
      '#localized_options' => array('html' => true),
      '#below' => array(),
      '#attributes' => array('class' => array($class)),
    );
    array_unshift($vars['menu'], $home_link);
  }
  $block = new stdClass();
  $block->module = 'oa_toolbar';
  $block->content = theme('oa_space_menu', $vars);

  return $block;
}

/**
 * Edit form callback.
 */
function oa_toolbar_oa_space_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
