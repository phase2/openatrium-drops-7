<?php

/**
 * Define the task plugin.
 */
$plugin = array(
  // This is a 'page' task and will fall under the page admin UI
  'task type' => 'page',

  'title' => t('Default site template'),
  'admin title' => t('Default site template'),
  'admin description' => t('When enabled, the site template allows templates to be selectively applied to all pages.'),
  'admin path' => FALSE,

  // This is task uses 'context' handlers and must implement these to give the
  // handler data it needs.
  'handler type' => 'context',
  'get arguments' => 'panels_everywhere_site_template_get_arguments',
  'get context placeholders' => 'panels_everywhere_site_template_get_contexts',
  'get base contexts' => 'panels_everywhere_site_template_get_base_contexts',

  // Allow this to be enabled or disabled:
  'disabled' => !variable_get('panels_everywhere_site_template_enabled', FALSE),
  'enable callback' => 'panels_everywhere_site_template_enable',
  'tab title' => t('Edit site template'),
);

/**
 * Callback to get arguments provided by this task handler.
 *
 * Since this is the node view and there is no UI on the arguments, we
 * create dummy arguments that contain the needed data.
 */
function panels_everywhere_site_template_get_arguments($task, $subtask_id) {
  $arguments = array();

  $arguments[] = array(
    'keyword' => 'content',
    'identifier' => t('Page content'),
    'id' => 1,
    'name' => 'page_content',
    'settings' => array(),
  );

  return $arguments;
}

/**
 * Figure out the base contexts in use for the page.
 *
 * This only works with CTools API v1.8 or greater; prior to that Page Manager
 * only supported arguments.
 */
function panels_everywhere_site_template_get_base_contexts($task, $subtask, $placeholders) {
  $contexts = array();

  // Only load taxonomy support if the Taxonomy module is loaded.
  $load_taxonomy = FALSE;
  if (module_exists('taxonomy')) {
    $load_taxonomy = TRUE;
  }

  if ($placeholders) {
    $managed_page = ctools_context_create_empty('managed_page');
    $url = ctools_context_create_empty('string');
    $alias = ctools_context_create_empty('string');
    $node = ctools_context_create_empty('node');
    $account = ctools_context_create_empty('user');

    // This context will only be created if the Taxonomy module is loaded.
    if ($load_taxonomy) {
      $term = ctools_context_create_empty('entity:taxonomy_term');
    }
  }
  else {
    $page = page_manager_get_current_page();
    $managed_page = ctools_context_create('managed_page', $page);
    $url = ctools_context_create('string', $_GET['q']);
    $alias = ctools_context_create('string', drupal_get_path_alias($_GET['q']));

    // If using a Page Manager Page, attempt to inherit our known contexts from
    // this.
    if ($page) {
      $node = _panels_everywhere_find_context($page['contexts'], 'node');
      $account = _panels_everywhere_find_context($page['contexts'], 'user');

      // We're already including the logged in user. We don't want that to
      // accidentally show up as the user being viewed if we're doing
      // something unrelated and the logged in user was added as a context.
      if (isset($account->data->logged_in_user)) {
        $account = ctools_context_create_empty('user');
      }

      // This context will only be loaded if the Taxonomy module is loaded.
      if ($load_taxonomy) {
        $term = _panels_everywhere_find_context($page['contexts'], 'entity:taxonomy_term');
      }
    }
    else {
      // Attempt to drive our basic contexts from the environemnt if we are
      // not using a panel page.

      // First, find a node. This is the same code used by Views.
      $raw_node = _panels_everywhere_find_node_context();
      $node = (!empty($raw_node)) ? ctools_context_create('node', $raw_node) : ctools_context_create_empty('node');

      // Now try to find a user.
      $raw_user = _panels_everywhere_find_user_context();
      $account = (!empty($raw_user)) ? ctools_context_create('user', $raw_user) : ctools_context_create_empty('user');

      // Now try to find a term.
      // This context will only be loaded if the Taxonomy module is loaded.
      if ($load_taxonomy) {
        $raw_term = _panels_everywhere_find_term_context();
        $term = (!empty($raw_term)) ? ctools_context_create('entity:taxonomy_term', $raw_term) : ctools_context_create_empty('entity:taxonomy_term');
      }
    }
  }

  $user = ctools_context_create('user', $GLOBALS['user']);

  // First, the managed page. The id is weird because this was formerly an
  // object so we want to retain that so pre-existing templates don't just
  // break.
  panels_everywhere_site_template_add_context($contexts, $url, t('Internal URL'), 'url', 'argument_string_1');
  panels_everywhere_site_template_add_context($contexts, $alias, t('Aliased URL'), 'alias', 'alias');
  panels_everywhere_site_template_add_context($contexts, $managed_page, t('Managed page'), 'page', 'argument_managed_page_1');
  panels_everywhere_site_template_add_context($contexts, $user, t('Logged in user'), 'user', 'logged-in-user');
  panels_everywhere_site_template_add_context($contexts, $node, t('Node being viewed'), 'node', 'node');
  panels_everywhere_site_template_add_context($contexts, $account, t('User being viewed'), 'account', 'account');

  // This context will only be added if the Taxonomy module is loaded.
  if ($load_taxonomy) {
    panels_everywhere_site_template_add_context($contexts, $term, t('Taxonomy term being viewed'), 'term', 'term');
  }

  // Allow other modules to also add contexts to the site template.
  drupal_alter('panels_everywhere_contexts', $contexts, $placeholders);

  return $contexts;
}

/**
 * Set up a context with the basic information needed.
 */
function panels_everywhere_site_template_add_context(&$contexts, &$context, $identifier, $keyword, $id) {
  $context->page_title  = '';
  $context->identifier  = $identifier;
  $context->keyword     = $keyword;
  $context->id          = $id;
  $contexts[$id]        = $context;
}

/**
 * Search for the first context that matches our requirements.
 *
 * If we can't find a context, produce an empty one instead.
 */
function _panels_everywhere_find_context($contexts, $type) {
  $list = ctools_context_filter($contexts, new ctools_context_required('', $type));
  if ($list) {
    return clone(array_shift($list));
  }

  return ctools_context_create_empty($type);
}

/**
 * Attempt to extract a node from the environment to turn into a context.
 */
function _panels_everywhere_find_node_context() {
  foreach (range(1, 3) as $i) {
    $node = menu_get_object('node', $i);
    if (!empty($node)) {
      return $node;
    }
  }

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    return node_load(arg(1));
  }
}

/**
 * Attempt to extract a user from the environment to turn into a context.
 */
function _panels_everywhere_find_user_context() {
  foreach (range(1, 3) as $i) {
    $user = menu_get_object('user', $i);
    if (!empty($user)) {
      return $user;
    }
  }

  foreach (range(1, 3) as $i) {
    $user = menu_get_object('user_uid_optional', $i);
    if (!empty($user)) {
      return $user;
    }
  }

  if (arg(0) == 'user' && is_numeric(arg(1))) {
    return user_load(arg(1));
  }
}

/**
 * Attempt to extract a term from the environment to turn into a context.
 */
function _panels_everywhere_find_term_context() {
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    return taxonomy_term_load(arg(2));
  }
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function panels_everywhere_site_template_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(panels_everywhere_site_template_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function panels_everywhere_site_template_enable($cache, $status) {
  variable_set('panels_everywhere_site_template_enabled', !$status);
}
