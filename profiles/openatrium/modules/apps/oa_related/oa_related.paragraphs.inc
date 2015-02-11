<?php
/**
 * @file
 * Render various paragraph types.
 */

/**
 * Implements HOOK_oa_paragraph_media_alter()
 */
function oa_related_oa_paragraph_media_alter(&$vars) {
  $layout = !empty($vars['field_image_alignment'][0]['value']) ? $vars['field_image_alignment'][0]['value'] : 'none';

  // For images, add a class pull-LAYOUT where LAYOUT is the layout config value.
  $vars['classes_array'][] = drupal_html_class('pull-' . $layout);
  // update caption titles and any display properties as needed
  for ($i = 0; $i < count($vars['content']['field_oa_media']['#items']); $i++) {
    $item = &$vars['content']['field_oa_media'][$i];
    switch ($layout) {
      case 'full':
      case 'grid2':
        // for large images we need to change the view mode to fetch original image sizes
        $item['#display_settings']['file_view_mode'] = 'default';
        break;
    }
    // set the title based on the image alt/title or filename
    $item['#title'] = !empty($vars['field_oa_media'][$i]['alt']) ? $vars['field_oa_media'][$i]['alt'] :
      (!empty($vars['field_oa_media'][$i]['title']) ? $vars['field_oa_media'][$i]['title'] : $vars['field_oa_media'][$i]['filename']);
  }
  switch ($layout) {
    case 'table':
    case 'preview':
      $header = array();
      $rows = array();
      if ($layout == 'table') {
        $header = array('', t('Title'), t('Filename'), t('Size'));
      }
      // render all the images in the paragraph item
      $view = field_view_field('paragraphs_item', $vars['paragraphs_item'], 'field_oa_media', 'default');
      // now loop through the media and build the table
      for ($i = 0; $i < count($vars['content']['field_oa_media']['#items']); $i++) {
        $item = &$vars['content']['field_oa_media'][$i];
        $file = (object)$vars['field_oa_media'][$i];

        if ($layout == 'preview') {
          $title = l($item['#title'], 'file/' . $file->fid);
          if ($item['#title'] != $file->filename) {
            $title .= '<br/>' . $file->filename;
          }
          if ($file->type != 'video') {
            $title .= ' (' . format_size($file->filesize) . ')';
          }
          $row = array(
            array('data' => $view[$i], 'width' => '258'),
            $title,
          );
        }
        elseif ($layout == 'table') {
          $icon = file_icon_url($file);
          $row = array(theme('image', array('path' => $icon)));
          if ($item['#title'] == $file->filename) {
            $row[] = array(
              'data' => l($item['#title'], 'file/' . $file->fid),
              'colspan' => 2,
            );
          }
          else {
            $row[] = l($item['#title'], 'file/' . $file->fid);
            $row[] = l($file->filename, 'file/' . $file->fid);
          }
          $row[] = ($file->type != 'video') ? format_size($file->filesize) : '';
        }
        $rows[] = $row;
      }
      $vars['content']['oa_media_table'] = array(
        '#theme' => 'table',
        '#header' => $header,
        '#rows' => $rows,
      );
      unset($vars['content']['field_oa_media']);
      break;
  }
  unset($vars['content']['field_image_alignment']);
}

/**
 * Implements HOOK_oa_paragraph_text_alter()
 */
function oa_related_oa_paragraph_text_alter(&$vars) {
  // Handle alignment for paragraph text.
  if (!empty($vars['field_paragraph_layout'][0]['value']) && !empty($vars['field_paragraph_text'][0]['value'])) {
    if (is_numeric($vars['field_paragraph_layout'][0]['value'])) {
      $vars['classes_array'][] = drupal_html_class('oa-columns-' . $vars['field_paragraph_layout'][0]['value']);
    }
    else {
      $vars['classes_array'][] = drupal_html_class('oa-callout-' . $vars['field_paragraph_layout'][0]['value']);
      $vars['classes_array'][] = drupal_html_class('oa-callout');
    }
  }
  unset($vars['content']['field_paragraph_layout']);
}

/**
 * Implements HOOK_oa_paragraph_snippet_alter()
 */
function oa_related_oa_paragraph_snippet_alter(&$vars) {
  // For snippets, pull the body field of the referenced entity
  if (!empty($vars['field_snippet_content'][0]['entity'])) {
    $wrapper = entity_metadata_wrapper('paragraphs_item', $vars['paragraphs_item']);
    $body = $wrapper->snippet_body->value();
    $vars['content']['field_snippet_content'] = array(
      '#markup' => $body,
    );
    if (!empty($vars['field_paragraph_layout'][0]['value']) && !empty($body)) {
      if (is_numeric($vars['field_paragraph_layout'][0]['value'])) {
        $vars['classes_array'][] = drupal_html_class('oa-columns-' . $vars['field_paragraph_layout'][0]['value']);
      } else {
        $vars['classes_array'][] = drupal_html_class('oa-callout-' . $vars['field_paragraph_layout'][0]['value']);
        $vars['classes_array'][] = drupal_html_class('oa-callout');
      }
    }
    if (!empty($vars['field_snippet_showtitle'][0]['value'])) {
      $title = $wrapper->snippet_title->value();
      $node = $wrapper->field_snippet_content->value();
      $vars['content']['title'] = array(
        '#markup' => '<h3 class="oa_snippet_title">' . l($title, 'node/' . $node->nid) . '</h3>',
        '#weight' => -9,
      );
    }
  }
  unset($vars['content']['field_paragraph_lock_revision']);
  unset($vars['content']['field_paragraph_layout']);
  unset($vars['content']['field_snippet_showtitle']);
  unset($vars['content']['field_snippet_title_override']);
  unset($vars['content']['field_snippet_viewmode']);
}

/**
 * Helper function to return an array of file action icons
 * @param $node
 * @param $file
 */
function oa_related_make_icons($node, $file) {
  $icons = array();
  if (($node->type == 'oa_wiki_page') && (!empty($node->field_oa_media[LANGUAGE_NONE]))) {
    $icons[] = l("<i class='icon-eye-open'></i>", 'node/' . $node->nid . '/view', array('html' => TRUE));
  }
  if (node_access('update', $node)) {
    $icons[] = l("<i class='icon-pencil'></i>", 'node/' . $node->nid . '/edit', array('html' => TRUE));
  }
  if (isset($file)) {
    $uri = file_entity_download_uri($file);
    $uri['options']['html'] = TRUE;
    $icons[] = l("<i class='icon-download'></i>", $uri['path'], $uri['options']);
  }
  return $icons;
}

/**
 * Implements HOOK_oa_paragraph_content_alter()
 */
function oa_related_oa_paragraph_content_alter(&$vars) {
  $layout = !empty($vars['field_oa_content_layout'][0]['value']) ? $vars['field_oa_content_layout'][0]['value'] : 'table';

  switch ($layout) {
    case 'table':
      if (!empty($vars['field_oa_related_content'])) {
        // For related files, convert to a table of links with file size info
        $icon_directory = variable_get('file_icon_directory', drupal_get_path('module', 'file') . '/icons');
        $rows = array();
        $header = array('', t('Document'), t('Download'), t('Size'), t('Modified'), '');
        foreach ($vars['field_oa_related_content'] as $key => $item) {
          $node = $item['entity'];
          $file = isset($node->field_oa_media[LANGUAGE_NONE][0]) ? (object)$node->field_oa_media[LANGUAGE_NONE][0] : NULL;
          $icons = oa_related_make_icons($node, $file);

          if (!empty($node->field_oa_media[LANGUAGE_NONE])) {
            foreach ($node->field_oa_media[LANGUAGE_NONE] as $index => $field) {
              $file = (object)$field;
              $icon = file_icon_url($file);
              $uri = file_entity_download_uri($file);
              if (node_access('view', $node)) {
                $rows[] = array(
                  theme('image', array('path' => $icon)),
                  l($node->title, 'node/' . $node->nid),
                  l($file->filename, $uri['path'], $uri['options']),
                  format_size($file->filesize),
                  array('data' => format_date($node->changed, 'short'), 'class' => 'oa-table-noborder'),
                  array('data' => implode('&nbsp', $icons), 'class' => 'oa-table-actions oa-table-noborder'),
                );
              }
            }
          } else {
            $rows[] = array(
              theme('image', array('path' => url($icon_directory . '/application-octet-stream.png'))),
              array(
                'data' => l($node->title, 'node/' . $node->nid),
                'colspan' => 3
              ),
              format_date($node->changed, 'short'),
              array('data' => implode('&nbsp', $icons), 'class' => 'oa-table-actions oa-table-noborder'),
            );
          }
        }
        $vars['content']['field_oa_related_content'] = array(
          '#theme' => 'table',
          '#header' => $header,
          '#rows' => $rows,
        );
      }
      break;
    case 'preview':
      if (!empty($vars['field_oa_related_content'])) {
        $rows = array();
        $icon_directory = variable_get('file_icon_directory', drupal_get_path('module', 'file') . '/icons');
        foreach ($vars['field_oa_related_content'] as $key => $item) {
          $row = array();
          $node = $item['entity'];
          if (node_access('view', $node)) {
            $body = oa_core_get_summary($node);
            $output = '<h4 class="oa-table-title">' . l($node->title, 'node/' . $node->nid) . '</h4>' . $body;

            $files = array();
            if (isset($node->field_oa_media)) {
              $files = field_view_field('node', $node, 'field_oa_media', 'featured');
            }
            $file = NULL;
            if (!empty($files['#items'])) {
              $file = (object)$files['#items'][0];
              $row[] = array('data' => $files, 'width' => '258');
              $row[] = array('data' => $output, 'class' => 'oa-table-body oa-table-noborder');
            } else {
              $row[] = array('data' => $output, 'class' => 'oa-table-body oa-table-noborder', 'colspan' => 2);
            }

            $icons = oa_related_make_icons($node, $file);
            $row[] = array(
              'data' => implode('&nbsp', $icons),
              'class' => 'oa-table-actions oa-table-noborder'
            );

            $rows[] = $row;
          }
        }

        $vars['content']['field_oa_related_content'] = array(
          '#theme' => 'table',
          '#rows' => $rows,
        );
      }
      break;
    case 'full':
      if (!empty($vars['field_oa_related_content'])) {
        $title = count($vars['field_oa_related_content']) == 1
          ? t('Related') . ' ' . node_type_get_name($vars['field_oa_related_content'][0]['entity'])
          : $vars['content']['field_oa_related_content']['#title'];
        foreach ($vars['field_oa_related_content'] as $key => $item) {
          $node = $item['entity'];
          if (node_access('view', $node)) {
            $file = isset($node->field_oa_media[LANGUAGE_NONE][0]) ? (object)$node->field_oa_media[LANGUAGE_NONE][0] : NULL;
            $icons = oa_related_make_icons($node, $file);
            if ($key > 0) {
              $vars['content']['paragraph_file_' . $key . 'rule']['#markup'] = '<hr>';
              $vars['content']['paragraph_file_' . $key . 'rule']['#weight'] = $key + 0.5;
            }
            if (!empty($icons)) {
              $vars['content']['paragraph_file_' . $key . 'icons'] = array(
                '#prefix' => '<div class="oa-table-actions pull-right">',
                '#markup' => implode('&nbsp', $icons),
                '#suffix' => '</div>',
                '#weight' => $key + 0.75,
              );
            }
            $vars['content']['paragraph_file_' . $key] = node_view($node, 'featured');
            $vars['content']['paragraph_file_' . $key]['#weight'] = $key + 1;
          }
          unset($vars['content']['field_oa_related_content'][$key]);
        }
        $vars['content']['field_oa_related_content']['#title'] = $title;
        $vars['content']['field_oa_related_content']['#weight'] = -1;
      }
      break;
  }
  unset($vars['content']['field_oa_content_layout']);
}

function oa_related_paragraph_snippet_property_get($entity, array $options, $name, $entity_type, &$context) {
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  if (isset($wrapper->field_snippet_content)) {
    // grab the node.  Do *not* use $wrapper->field_snippet_content->value() since
    // it does not return the proper revision
    $node = $entity->field_snippet_content[LANGUAGE_NONE][0]['entity'];
    $view_mode = $wrapper->field_snippet_viewmode->value();
    if ($view_mode == 'summary') {
      $body = oa_core_get_summary($node);
    }
    else {
      $body_field = field_get_items('node', $node, 'body');
      $body = $body_field[0]['safe_value'];
      if ($view_mode == 'full') {
        $paragraphs = field_view_field('node', $node, 'field_oa_related');
        $paragraphs['#label_display'] = 'hidden';
        $body .= drupal_render($paragraphs);
      }
    }
    return $body;
  }
  return '';
}

function oa_related_paragraph_snippet_title_property_get($entity, array $options, $name, $entity_type, &$context) {
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  if (isset($wrapper->field_snippet_content)) {
    $node = $wrapper->field_snippet_content->value();
    $override = $wrapper->field_snippet_title_override->value();
    return !empty($override) ? $override : $node->title;
  }
  return '';
}

function oa_related_entity_property_info_alter(&$info) {
  $properties = &$info['paragraphs_item']['bundles']['paragraph_snippet']['properties'];

  $properties['snippet_body'] = array(
    'label' => t("Snippet body"),
    'description' => t("The referenced body text to be displayed."),
    'type' => 'text',
    'computed' => TRUE,
    'getter callback' => 'oa_related_paragraph_snippet_property_get',
  );
  $properties['snippet_title'] = array(
    'label' => t("Snippet title"),
    'description' => t("The title text to be displayed."),
    'type' => 'text',
    'computed' => TRUE,
    'getter callback' => 'oa_related_paragraph_snippet_title_property_get',
  );

}

