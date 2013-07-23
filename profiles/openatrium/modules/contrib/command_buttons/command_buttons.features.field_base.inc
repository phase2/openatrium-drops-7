<?php
/**
 * @file
 * command_buttons.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function command_buttons_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_block_buttons'
  $field_bases['field_block_buttons'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_buttons',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_button_size'
  $field_bases['field_button_size'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_button_size',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'default' => 'Default',
        'btn-large' => 'Large',
        'btn-small' => 'Small',
        'btn-mini' => 'Mini',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_button_style'
  $field_bases['field_button_style'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_button_style',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'btn' => 'Default',
        'btn btn-primary' => 'Primary',
        'btn btn-info' => 'Info',
        'btn btn-success' => 'Success',
        'btn btn-warning' => 'Warning',
        'btn btn-danger' => 'Danger',
        'btn btn-inverse' => 'Inverse',
        'btn btn-link' => 'Link',
        'other' => 'Other',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_command_link'
  $field_bases['field_command_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_command_link',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_commands'
  $field_bases['field_commands'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commands',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'command_button',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_css_class'
  $field_bases['field_css_class'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_css_class',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_dropdown_label'
  $field_bases['field_dropdown_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dropdown_label',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_link_icon'
  $field_bases['field_link_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_link_icon',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'icon-glass' => 'icon-glass',
        'icon-music' => 'icon-music',
        'icon-search' => 'icon-search',
        'icon-envelope' => 'icon-envelope',
        'icon-heart' => 'icon-heart',
        'icon-star' => 'icon-star',
        'icon-star-empty' => 'icon-star-empty',
        'icon-user' => 'icon-user',
        'icon-film' => 'icon-film',
        'icon-th-large' => 'icon-th-large',
        'icon-th' => 'icon-th',
        'icon-th-list' => 'icon-th-list',
        'icon-ok' => 'icon-ok',
        'icon-remove' => 'icon-remove',
        'icon-zoom-in' => 'icon-zoom-in',
        'icon-zoom-out' => 'icon-zoom-out',
        'icon-off' => 'icon-off',
        'icon-signal' => 'icon-signal',
        'icon-cog' => 'icon-cog',
        'icon-trash' => 'icon-trash',
        'icon-home' => 'icon-home',
        'icon-file' => 'icon-file',
        'icon-time' => 'icon-time',
        'icon-road' => 'icon-road',
        'icon-download-alt' => 'icon-download-alt',
        'icon-download' => 'icon-download',
        'icon-upload' => 'icon-upload',
        'icon-inbox' => 'icon-inbox',
        'icon-play-circle' => 'icon-play-circle',
        'icon-repeat' => 'icon-repeat',
        'icon-refresh' => 'icon-refresh',
        'icon-list-alt' => 'icon-list-alt',
        'icon-lock' => 'icon-lock',
        'icon-flag' => 'icon-flag',
        'icon-headphones' => 'icon-headphones',
        'icon-volume-off' => 'icon-volume-off',
        'icon-volume-down' => 'icon-volume-down',
        'icon-volume-up' => 'icon-volume-up',
        'icon-qrcode' => 'icon-qrcode',
        'icon-barcode' => 'icon-barcode',
        'icon-tag' => 'icon-tag',
        'icon-tags' => 'icon-tags',
        'icon-book' => 'icon-book',
        'icon-bookmark' => 'icon-bookmark',
        'icon-print' => 'icon-print',
        'icon-camera' => 'icon-camera',
        'icon-font' => 'icon-font',
        'icon-bold' => 'icon-bold',
        'icon-italic' => 'icon-italic',
        'icon-text-height' => 'icon-text-height',
        'icon-text-width' => 'icon-text-width',
        'icon-align-left' => 'icon-align-left',
        'icon-align-center' => 'icon-align-center',
        'icon-align-right' => 'icon-align-right',
        'icon-align-justify' => 'icon-align-justify',
        'icon-list' => 'icon-list',
        'icon-indent-left' => 'icon-indent-left',
        'icon-indent-right' => 'icon-indent-right',
        'icon-facetime-video' => 'icon-facetime-video',
        'icon-picture' => 'icon-picture',
        'icon-pencil' => 'icon-pencil',
        'icon-map-marker' => 'icon-map-marker',
        'icon-adjust' => 'icon-adjust',
        'icon-tint' => 'icon-tint',
        'icon-edit' => 'icon-edit',
        'icon-share' => 'icon-share',
        'icon-check' => 'icon-check',
        'icon-move' => 'icon-move',
        'icon-step-backward' => 'icon-step-backward',
        'icon-fast-backward' => 'icon-fast-backward',
        'icon-backward' => 'icon-backward',
        'icon-play' => 'icon-play',
        'icon-pause' => 'icon-pause',
        'icon-stop' => 'icon-stop',
        'icon-forward' => 'icon-forward',
        'icon-fast-forward' => 'icon-fast-forward',
        'icon-step-forward' => 'icon-step-forward',
        'icon-eject' => 'icon-eject',
        'icon-chevron-left' => 'icon-chevron-left',
        'icon-chevron-right' => 'icon-chevron-right',
        'icon-plus-sign' => 'icon-plus-sign',
        'icon-minus-sign' => 'icon-minus-sign',
        'icon-remove-sign' => 'icon-remove-sign',
        'icon-ok-sign' => 'icon-ok-sign',
        'icon-question-sign' => 'icon-question-sign',
        'icon-info-sign' => 'icon-info-sign',
        'icon-screenshot' => 'icon-screenshot',
        'icon-remove-circle' => 'icon-remove-circle',
        'icon-ok-circle' => 'icon-ok-circle',
        'icon-ban-circle' => 'icon-ban-circle',
        'icon-arrow-left' => 'icon-arrow-left',
        'icon-arrow-right' => 'icon-arrow-right',
        'icon-arrow-up' => 'icon-arrow-up',
        'icon-arrow-down' => 'icon-arrow-down',
        'icon-share-alt' => 'icon-share-alt',
        'icon-resize-full' => 'icon-resize-full',
        'icon-resize-small' => 'icon-resize-small',
        'icon-plus' => 'icon-plus',
        'icon-minus' => 'icon-minus',
        'icon-asterisk' => 'icon-asterisk',
        'icon-exclamation-sign' => 'icon-exclamation-sign',
        'icon-gift' => 'icon-gift',
        'icon-leaf' => 'icon-leaf',
        'icon-fire' => 'icon-fire',
        'icon-eye-open' => 'icon-eye-open',
        'icon-eye-close' => 'icon-eye-close',
        'icon-warning-sign' => 'icon-warning-sign',
        'icon-plane' => 'icon-plane',
        'icon-calendar' => 'icon-calendar',
        'icon-random' => 'icon-random',
        'icon-comment' => 'icon-comment',
        'icon-magnet' => 'icon-magnet',
        'icon-chevron-up' => 'icon-chevron-up',
        'icon-chevron-down' => 'icon-chevron-down',
        'icon-retweet' => 'icon-retweet',
        'icon-shopping-cart' => 'icon-shopping-cart',
        'icon-folder-close' => 'icon-folder-close',
        'icon-folder-open' => 'icon-folder-open',
        'icon-resize-vertical' => 'icon-resize-vertical',
        'icon-resize-horizontal' => 'icon-resize-horizontal',
        'icon-hdd' => 'icon-hdd',
        'icon-bullhorn' => 'icon-bullhorn',
        'icon-bell' => 'icon-bell',
        'icon-certificate' => 'icon-certificate',
        'icon-thumbs-up' => 'icon-thumbs-up',
        'icon-thumbs-down' => 'icon-thumbs-down',
        'icon-hand-right' => 'icon-hand-right',
        'icon-hand-left' => 'icon-hand-left',
        'icon-hand-up' => 'icon-hand-up',
        'icon-hand-down' => 'icon-hand-down',
        'icon-circle-arrow-right' => 'icon-circle-arrow-right',
        'icon-circle-arrow-left' => 'icon-circle-arrow-left',
        'icon-circle-arrow-up' => 'icon-circle-arrow-up',
        'icon-circle-arrow-down' => 'icon-circle-arrow-down',
        'icon-globe' => 'icon-globe',
        'icon-wrench' => 'icon-wrench',
        'icon-tasks' => 'icon-tasks',
        'icon-filter' => 'icon-filter',
        'icon-briefcase' => 'icon-briefcase',
        'icon-fullscreen' => 'icon-fullscreen',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_use_dropdowns'
  $field_bases['field_use_dropdowns'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_use_dropdowns',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
