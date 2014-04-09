<?php

/**
 * @file
 * Provides WYSIWYG integration for CKEditor.
 */

/**
 * Implements hook_ckeditor_plugin_alter().
 */
function media_wysiwyg_ckeditor_plugin_alter(&$plugins) {
  // Replace the CKEditor media plugin with the Media WYSIWYG media plugin.
  if (isset($plugins['media'])) {
    $plugins['media']['path'] = drupal_get_path('module', 'media_wysiwyg') . '/wysiwyg_plugins/media_ckeditor/';
  }
}
