<?php
/**
 * @file
 * oa_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: add media from remote sources.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: administer panels styles.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: change layouts in place editing.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: create fieldable basic_file.
  $permissions['create fieldable basic_file'] = array(
    'name' => 'create fieldable basic_file',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create fieldable image.
  $permissions['create fieldable image'] = array(
    'name' => 'create fieldable image',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create fieldable map.
  $permissions['create fieldable map'] = array(
    'name' => 'create fieldable map',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create fieldable quick_links.
  $permissions['create fieldable quick_links'] = array(
    'name' => 'create fieldable quick_links',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create fieldable spotlight.
  $permissions['create fieldable spotlight'] = array(
    'name' => 'create fieldable spotlight',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create fieldable table.
  $permissions['create fieldable table'] = array(
    'name' => 'create fieldable table',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create fieldable text.
  $permissions['create fieldable text'] = array(
    'name' => 'create fieldable text',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create fieldable video.
  $permissions['create fieldable video'] = array(
    'name' => 'create fieldable video',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: create files.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete any files.
  $permissions['delete any files'] = array(
    'name' => 'delete any files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete fieldable basic_file.
  $permissions['delete fieldable basic_file'] = array(
    'name' => 'delete fieldable basic_file',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable image.
  $permissions['delete fieldable image'] = array(
    'name' => 'delete fieldable image',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable map.
  $permissions['delete fieldable map'] = array(
    'name' => 'delete fieldable map',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable quick_links.
  $permissions['delete fieldable quick_links'] = array(
    'name' => 'delete fieldable quick_links',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable spotlight.
  $permissions['delete fieldable spotlight'] = array(
    'name' => 'delete fieldable spotlight',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable table.
  $permissions['delete fieldable table'] = array(
    'name' => 'delete fieldable table',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable text.
  $permissions['delete fieldable text'] = array(
    'name' => 'delete fieldable text',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete fieldable video.
  $permissions['delete fieldable video'] = array(
    'name' => 'delete fieldable video',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: delete own files.
  $permissions['delete own files'] = array(
    'name' => 'delete own files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download any files.
  $permissions['download any files'] = array(
    'name' => 'download any files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download own files.
  $permissions['download own files'] = array(
    'name' => 'download own files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit any files.
  $permissions['edit any files'] = array(
    'name' => 'edit any files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit fieldable basic_file.
  $permissions['edit fieldable basic_file'] = array(
    'name' => 'edit fieldable basic_file',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable image.
  $permissions['edit fieldable image'] = array(
    'name' => 'edit fieldable image',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable map.
  $permissions['edit fieldable map'] = array(
    'name' => 'edit fieldable map',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable quick_links.
  $permissions['edit fieldable quick_links'] = array(
    'name' => 'edit fieldable quick_links',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable spotlight.
  $permissions['edit fieldable spotlight'] = array(
    'name' => 'edit fieldable spotlight',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable table.
  $permissions['edit fieldable table'] = array(
    'name' => 'edit fieldable table',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable text.
  $permissions['edit fieldable text'] = array(
    'name' => 'edit fieldable text',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit fieldable video.
  $permissions['edit fieldable video'] = array(
    'name' => 'edit fieldable video',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: edit own files.
  $permissions['edit own files'] = array(
    'name' => 'edit own files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit own oa_group content.
  $permissions['edit own oa_group content'] = array(
    'name' => 'edit own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own oa_space content.
  $permissions['edit own oa_space content'] = array(
    'name' => 'edit own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: save draft.
  $permissions['save draft'] = array(
    'name' => 'save draft',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'save_draft',
  );

  // Exported permission: use panels in place editing.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: use text format panopoly_html_text.
  $permissions['use text format panopoly_html_text'] = array(
    'name' => 'use text format panopoly_html_text',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format panopoly_wysiwyg_text.
  $permissions['use text format panopoly_wysiwyg_text'] = array(
    'name' => 'use text format panopoly_wysiwyg_text',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: view files.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own files.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own private files.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: view private files.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  return $permissions;
}
