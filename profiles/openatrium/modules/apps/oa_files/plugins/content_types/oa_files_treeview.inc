<?php
/**
 * @file oa_files_menu.inc
 */

$plugin = array(
  'title' => t('Files & Folders'),
  'description' => t('Displays documents in a folder hierarchy that can be expanded and collapsed.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_files_treeview_settings_form',
  'render callback' => 'oa_files_treeview_render',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
  'defaults' => array(
    'oa_files_treeview_mode' => 0,
    'oa_files_menu_mode' => 0,
    'oa_files_fields' => array('size' => 'size'),
    'oa_files_showcount' => FALSE,
    'oa_files_showfilter' => FALSE,
    'oa_files_actions' => array(),
    'oa_files_sort' => 'title',
    'oa_files_dir' => 'ASC',
    'oa_files_all' => TRUE,
    'oa_files_space' => OA_SPACE_CURRENT,
    'oa_files_section' => -1,
    'oa_files_only_attached' => FALSE,
    'oa_files_hide_empty' => FALSE,
    'oa_files_subspaces' => FALSE,
    'oa_files_auto' => FALSE,
    'oa_files_link_vocab' => FALSE,
    'oa_files_only_folders' => FALSE,
  ),
);

/**
 * Helper function to return the text theme name for a given oa_files view mode
 * @param $mode
 */
function _oa_files_themename($mode) {
  $default = 'sidebar';
  if (isset($mode)) {
    switch ($mode) {
      case 0:
        return "sidebar";
      case 1:
        return "wide";
      case 2:
        return "split";
      default:
        return $default;
    }
  }
  return $default;
}

/**
 * Return a list of default actions
 */
function oa_files_actions(&$conf = array()) {
  $actions = array(
    "download" => array(
      "title" => t('Download'),
      "exposed" => TRUE,
      "enabled" => TRUE,
      "icon" => 'icon-download',
      "weight" => 1,
    ),
    "view" => array(
      "title" => t('View metadata'),
      "exposed" => FALSE,
      "enabled" => TRUE,
      "icon" => 'icon-eye-open',
      "weight" => 2,
    ),
    "edit" => array(
      "title" => t('Edit metadata'),
      "exposed" => FALSE,
      "enabled" => TRUE,
      "icon" => 'icon-pencil',
      "weight" => 3,
    ),
    "folder" => array(
      "title" => t('New folder'),
      "exposed" => FALSE,
      "enabled" => TRUE,
      "icon" => 'icon-folder-close',
      "weight" => 4,
    ),
    "addfile" => array(
      "title" => t('Add file'),
      "exposed" => FALSE,
      "enabled" => TRUE,
      "icon" => 'icon-plus',
      "weight" => 5,
    ),
    "adddocument" => array(
      "title" => t('Add document'),
      "exposed" => FALSE,
      "enabled" => TRUE,
      "icon" => 'icon-plus',
      "weight" => 6,
    ),
  );

  foreach ($actions as $key => $action) {
    $id = 'oa_files_action_' . $key;
    if (!isset($conf[$id])) {
      $conf[$id] = ($action['exposed']) ? 2 : (($action['enabled']) ? 1 : 0);
    }
    else {
      $actions[$key]['exposed'] = ($conf[$id] == 2);
      $actions[$key]['enabled'] = ($conf[$id] != 0);
    }

    $id = 'oa_files_action_title_' . $key;
    if (!isset($conf[$id])) {
      $conf[$id] = $action['title'];
    }
    else {
      $actions[$key]['title'] = $conf[$id];
    }
  }
  return $actions;
}

/**
 * Run-time rendering of the body of the pane.
 *
 * @see ctools_plugin_examples for more advanced info
 */
function oa_files_treeview_render($subtype, $conf, $args, $context) {
  global $user;
  static $js_instance = 0;

  drupal_add_js('misc/ajax.js', array('group' => JS_LIBRARY, 'weight' => 2));

  $base = drupal_get_path('module', 'oa_files');
  $space_id = oa_core_get_space_context();
  $current_id = isset($context->data) ? $context->data->nid : $space_id;

  $files = array();
  $plid = NULL;
  $vid = 0;
  $conf['topid'] = 0;
  $node_type = (isset($conf['oa_files_type']) ? $conf['oa_files_type'] : 'oa_wiki_page');
  $allowfiles = og_user_access('node', $space_id, "create " . $node_type . " content");
  $mode = !empty($conf['oa_files_menu_mode']) ? $conf['oa_files_menu_mode'] : 0;
  $override_vocab = variable_get_value('oa_wiki_vocab');
  if (!empty($override_vocab)  && !empty($conf['oa_files_auto'])) {
    if ($mode == 0) {
      $conf['oa_files_space'] = -1;
      $conf['oa_files_section'] = -1;
    }
    $mode = 1;  // force taxonomy base
    $conf['oa_files_vocabulary'] = $override_vocab;
    $conf['oa_files_all'] = FALSE;
  }
  if ($mode == 0) {
    $parent_field = "menu_parent";
    $rearrange = url('/group/node/' . $space_id . '/admin/menu');
    $allownew = $allowfiles;
    // use Space Menu for tree
    $plid = og_menu_single_get_active_plid();
    if (isset($conf['og_menu_single_parent']) && ($conf['og_menu_single_parent'] == 'auto')) {
      $result = module_invoke_all('og_menu_single_menu_parent', $conf);
      if (!empty($result)) {
        $plid = reset($result);
      }
    }
    else if (!empty($conf['og_menu_single_parent'])) {
      $plid = $conf['og_menu_single_parent'];
    }

    drupal_add_js(array('oa_files' => array('node_token' => array('undefined' => drupal_get_token('add-node-undefined')))), 'setting');
    if ($plid) {
      // determine nid of menu parent
      $top_menu = menu_link_load($plid);
      if (!empty($top_menu['link_path']) && preg_match('#node/(\d+)#', $top_menu['link_path'], $matches) !== FALSE) {
        $conf['topid'] = $matches[1];
      }
      $menu_tree = og_menu_single_children_items($plid, !empty($conf['og_menu_single_depth']) ? $conf['og_menu_single_depth'] : MENU_MAX_DEPTH);
      if ($menu_tree) {
        $files = oa_files_prepare_files_from_menu($menu_tree, $conf);
      }
      if (!isset($conf['oa_files_all']) || $conf['oa_files_all']) {
        oa_files_add_uncategorized($files, $conf);
      }
      foreach ($files as $file) {
        // keys of arrays need to be strings or else javascript will rekey the numbers
        drupal_add_js(array('oa_files' => array('node_token' => array('node:' . $file['nid'] => drupal_get_token('add-node-' . $file['nid'])))), 'setting');
      }
    }
  }
  elseif ($mode == 1) {
    // use Vocabulary for tree
    $parent_field = 'term_parent';
    if ($user->uid == 0) {
      // always hide empty terms from anonymous users
      $conf['oa_files_hide_empty'] = TRUE;
    }
    $vid = $conf['oa_files_vocabulary'];
    $vocab = taxonomy_vocabulary_load($vid);
    $rearrange = $vocab ? url('admin/structure/taxonomy/' . $vocab->machine_name) : '';
    $terms = taxonomy_get_tree($vid);
    $allownew = FALSE;
    if (module_exists('og_vocab')) {
      $vids = og_vocab_get_accessible_vocabs('node', $node_type, OG_VOCAB_FIELD);
      if (!empty($vids) && in_array($vid, $vids)) {
        // check OG access for editing vocab terms
        $allownew = og_user_access('node', $space_id, "edit terms");
      }
    }
    if (!$allownew) {
      // otherwise check global permission for vocab
      $allownew = user_access('edit terms in ' . $vid);
    }
    $files = oa_files_prepare_files_from_vocab($terms, $conf, $allownew);
    // don't use numeric tokens for sparse javascript arrays or else they get rekeyed
    drupal_add_js(array('oa_files' => array('vocab_token' => array('vid:' . $vid => drupal_get_token('add-term-' . $vid)))), 'setting');
  }

  $actions = oa_files_actions($conf);
  $space = oa_files_space_filter($conf);
  $section = oa_files_section_filter($conf);
  if (is_array($section)) {
    // If multiple sections are selected, convert to a string list.
    // Just used for the Cookie for saving expand/collapse state.
    $section = implode('_', $section);
  }

  if ($node_type != 'oa_wiki_page') {
    // allow taxonomy-based tree for any content type, but only oa_wiki_page for files.
    if ($actions['adddocument']['enabled']) {
      $actions['adddocument']['title'] = t('Add') . ' ' . node_type_get_name($node_type);
    }
    $actions['addfile']['enabled'] = FALSE;
  }

  if (!empty($files) || ($allownew && ($actions['addfile']['enabled'] || $actions['adddocument']['enabled']))) {
    oa_files_add_file_links($files, $conf);

    drupal_add_js(array(
      'oa_files_instance_' . $js_instance => array(
        'files' => $files,
        'space' => $space,
        'section' => $section,
        'mode' => _oa_files_themename($conf['oa_files_treeview_mode']),
        'fields' => isset($conf['oa_files_fields']) ? $conf['oa_files_fields'] : (!empty($conf['oa_files_treeview_mode']) ? array('size' => 'size') : 0),
        'allownew' => $allownew,
        'allowfiles' => $allowfiles,
        'showcount' => isset($conf['oa_files_showcount']) ? $conf['oa_files_showcount'] : FALSE,
        'showfilter' => isset($conf['oa_files_showfilter']) ? $conf['oa_files_showfilter'] : FALSE,
        'hideempty' => isset($conf['oa_files_hide_empty']) ? $conf['oa_files_hide_empty'] : FALSE,
        'actions' => $actions,
        'parentfield' => $parent_field,
        'currentpath' => current_path(),
        'currentid' => $current_id,
        'rearrange' => $rearrange,
        'linkvocab' => isset($conf['oa_files_link_vocab']) ? $conf['oa_files_link_vocab'] : FALSE,
        'nodetype' => str_replace('_', '-', $node_type),
        'vid' => $vid,
        'topid' => $conf['topid'],
      ),
    ), 'setting');

    oa_angular_add(array('sanitize', 'cookies', 'ng-modules', 'ng-treecontrol'));

    drupal_add_js($base . '/js/oa_files_treeview.js');
    drupal_add_css($base . '/css/oa_files_treeview.css');

    $theme = 'oa_files';
    $block = new stdClass();
    $block->title = '';
    $block->content = theme($theme, array('instance' => $js_instance));
    // Don't want to do menu_link_load if overriding title.
    if (empty($conf['override_title']) && $plid) {
      $item = og_menu_single_menu_link_load($plid);
      $block->title = l($item['link_title'], $item['link_path'], $item['options']);
    }

    $js_instance++;
    return $block;
  }

  return FALSE;
}

/**
 * Helper function to determine if a given field is being displayed in the conf options
 */
function oa_files_showfield($conf, $fieldname) {
  $fields = !empty($conf['oa_files_fields']) ? $conf['oa_files_fields'] : array();
  return !empty($fields[$fieldname]);
}

/**
 * Helper function to return summary or trimmed body
 * @param $node
 */
function oa_files_summary($node) {
  $body = field_get_items('node', $node, 'body');

  if (!empty($body[0]['summary'])) {
    return $body[0]['summary'];
  }
  else {
    $alter = array(
      'max_length' => variable_get('teaser_length', 300),
      'ellipsis' => TRUE,
      'word_boundary' => TRUE,
      'html' => TRUE,
    );
    $body = strip_tags($body[0]['value'], '<strong> <em> <p> <br>');
    return views_trim_text($alter, $body);
  }
}

/**
 * Return files flat array of nodes with parent pointers from a menu tree
 * @param $tree - the expanded menu tree
 * @param $conf - configuration options
 * @param $parent - nid of parent
 */
function oa_files_prepare_files_from_menu($tree, &$conf, $parent = 0) {
  $icon_directory = variable_get('file_icon_directory', drupal_get_path('module', 'file') . '/icons');
  $node_type = (isset($conf['oa_files_type']) ? $conf['oa_files_type'] : 'oa_wiki_page');

  $result = array();
  $all_nids = array();
  foreach ($tree as $key => $item) {
    $tree[$key]['nid'] = 0;
    if (preg_match('#node/(\d+)#', $item['link']['href'], $matches) !== FALSE) {
      $tree[$key]['nid'] = $matches[1];
    }
    $all_nids[] = $tree[$key]['nid'];
  }
  $titles = $all_nids ? oa_core_get_titles($all_nids, '', 'title', array('title', 'created', 'changed', 'type'), TRUE, 0) : array();
  // Determine if we should check node access.  Only if less than 20 nodes.
  // For other cases, we add the Edit link for all files and let normal node access handle Access denied.
  $check_edit_access = !empty($conf['oa_files_action_edit']) && count($all_nids) < 20;
  // Find if node is a folder.
  $nids_are_folder = array();
  if ($all_nids) {
    $query = db_select('node', 'n');
    $query->fields('n', array('nid'));
    $query->condition('n.nid', $all_nids);
    $query->addJoin('LEFT', 'field_data_field_oa_media', 'f', "n.nid = f.entity_id AND f.entity_type = 'node'");
    $query->addJoin('LEFT', 'field_data_field_oa_wiki_page_no_redirect', 'fw', "n.nid = fw.entity_id AND fw.entity_type = 'node'");
    $query->addJoin('LEFT', 'field_data_body', 'fb', "n.nid = fb.entity_id AND fb.entity_type = 'node'");
    $query->isNull('f.field_oa_media_fid');
    $query->condition(
      db_or()
        ->condition('fw.field_oa_wiki_page_no_redirect_value', 0)
        ->isNull('fw.field_oa_wiki_page_no_redirect_value')
    );
    $query->condition(
      db_or()
        ->condition('fb.body_value', '')
        ->isNull('fb.body_value')
    );
    $nids_are_folder = $query->execute()->fetchCol();
  }

  foreach ($tree as $key => $item) {
    $nid = $item['nid'];
    // need to load the node to determine edit access.
    // but only load node if $check_edit_access is set or if we need the body field.
    $body = '';
    if (oa_files_showfield($conf, 'body') && $nid && ($render_array = field_view_field('node', node_load($nid), 'body', 'teaser'))) {
      $body = render($render_array);
    }

    $treenode = array(
      "id" => $nid,
      "nid" => $nid,
      "parent" => array($parent),
      "name" => $item['link']['link_title'],
      "url" => $item['link']['href'],
      "weight" => $item['link']['weight'],
      "date" => $nid && !empty($titles['createds'][$nid]) ? format_date($titles['createds'][$nid], 'short') : '',
      "modified" => $nid && !empty($titles['changeds'][$nid]) ? format_date($titles['changeds'][$nid], 'short') : '',
      "editor" => $check_edit_access && $nid ? node_access("update", node_load($nid)) : TRUE,
      "body" => $body,
      "isfolder" => FALSE,
    );
    $result[$nid] = $treenode;
    $children = oa_files_prepare_files_from_menu($item['below'], $conf, $nid);

    $isfolder = (count($children) > 0) || in_array($nid, $nids_are_folder);
    if (($titles['types'][$nid] != $node_type) && (count($children) == 0)) {
      // Don't show single items that are not document pages and don't have children
      // e.g., don't show manually added menu links to spaces/sections
      unset($result[$nid]);
    }
    else {
      $result = $result + $children;
      $result[$nid]['isfolder'] = $isfolder;
      if (!$isfolder) {
        $result[$nid]['icon'] = url($icon_directory . '/application-octet-stream.png');
      }
    }
  }
  return $result;
}

/**
 * Helper function to modify a query to add the Space and Section filters
 * @param $query
 * @param $conf
 */
function oa_files_apply_filters(&$query, &$conf) {
  $space_id = oa_files_space_filter($conf);
  $section_id = oa_files_section_filter($conf);

  $extra_groups = array();
  $extra_sections = array();
  if ($space_id > 0) {
    if (module_exists('oa_subspaces') && !empty($conf['oa_files_subspaces'])) {
      // add list of subspaces to query
      $extra_groups = array_merge($extra_groups, oa_core_get_groups_by_parent($space_id, OA_SPACE_TYPE, NODE_PUBLISHED, FALSE, NULL, TRUE));
    }
    $extra_groups[] = $space_id;
    $query->join('og_membership', 'og', "n.nid = og.etid AND og.entity_type = 'node' AND og.field_name = '" . OA_SPACE_FIELD . "'");
    $query->condition('og.gid', $extra_groups, 'IN');
  }
  $sections = is_array($section_id) ? $section_id : array($section_id);
  foreach ($sections as $section_id) {
    if ($section_id > 0) {
      if (module_exists('oa_subspaces') && isset($conf['oa_files_section']) && ($conf['oa_files_section'] != 0) && (count($extra_groups) > 1)) {
        // we are searching multiple spaces and have a specific section selected, so use that same section name within subspaces
        $extra_sections = oa_subspaces_matching_sections($section_id, $extra_groups, array($space_id));
      }
      $extra_sections[] = $section_id;
    }
  }
  if (!empty($extra_sections)) {
    $query->join('field_data_oa_section_ref', 's', "s.entity_id = n.nid AND s.entity_type = 'node'");
    $query->condition('s.oa_section_ref_target_id', $extra_sections, 'IN');
  }
  $conf['extra_groups'] = $extra_groups;
  $conf['extra_sections'] = $extra_sections;
}

/**
 * Return array of files that are not categorized into the OG menu for this section
 * @param $conf - configuration options
 */
function oa_files_add_uncategorized(&$menu_tree, &$conf) {
  $icon_directory = variable_get('file_icon_directory', drupal_get_path('module', 'file') . '/icons');
  $sort_field = !empty($conf['oa_files_sort']) ? $conf['oa_files_sort'] : 'title';
  $sort_dir = !empty($conf['oa_files_dir']) ? $conf['oa_files_dir'] : 'ASC';
  $node_type = (isset($conf['oa_files_type']) ? $conf['oa_files_type'] : 'oa_wiki_page');

  $query = db_select('node', 'n');
  $query->leftJoin('menu_links', 'm', "CONCAT('node/', n.nid) = m.link_path AND m.menu_name = 'og-menu-single'");
  oa_files_apply_filters($query, $conf);
  $query->fields('n', array('nid'))
    ->isNull('m.plid')
    ->condition('n.type', $node_type)
    ->addTag('node_access')
    ->orderBy($sort_field, $sort_dir);

  $result = $query->execute()->fetchAll();
  oa_files_add_other_nodes($result, $conf);

  $weight = count($menu_tree)+1;
  foreach ($result as $node) {
    $nid = $node->nid;
    $full_node = node_load($nid);
    $body = '';
    if (oa_files_showfield($conf, 'body')) {
      $body = oa_files_summary($full_node);
    }

    $treenode = array(
      "id" => $nid,
      "nid" => $nid,
      "parent" => array(0),
      "name" => $full_node->title,
      "url" => 'node/' . $nid,
      "weight" => $weight,
      "date" => format_date($full_node->created, 'short'),
      "modified" => format_date($full_node->changed, 'short'),
      "editor" => node_access("update", $full_node),
      "body" => $body,
      "icon" => url($icon_directory . '/application-octet-stream.png'),
    );
    $menu_tree[$nid] = $treenode;
    $weight++;
  }
}

/**
 * Helper function to fetch all nodes that use the "also visible on X space"
 * @param $result assoc array with nids of query (and potentially tids of nodes)
 * @param $conf array of configuration settings
 * @param $tid array of optional taxonomy ids to filter nodes
 * @param $exclude array of optional nids to exclude from query
 */
function oa_files_add_other_nodes(&$result, $conf, $tids = NULL, $exclude = NULL) {
  if (!empty($conf['extra_groups'])) {
    $node_type = (isset($conf['oa_files_type']) ? $conf['oa_files_type'] : 'oa_wiki_page');
    $query = db_select('node', 'n');
    $query->join('field_data_oa_other_spaces_ref', 'o', "o.entity_id = n.nid AND o.entity_type = 'node'");
    if (!empty($tids)) {
      $query->join('taxonomy_index', 't', 't.nid = n.nid');
      $query
        ->condition('t.tid', $tids, 'IN')
        ->fields('t', array('tid'));
    }
    if (!empty($exclude)) {
      $query->condition('n.nid', $exclude, 'NOT IN');
    }
    $query
      ->fields('n', array('nid'))
      ->condition('o.oa_other_spaces_ref_target_id', $conf['extra_groups'], 'IN')
      ->condition('n.type', $node_type)
      ->addTag('node_access');
    $extra_nodes = $query->execute()->fetchAll();
    $result = array_merge($result, $extra_nodes);
  }
}

/**
 * Return files flat array of nodes with parent pointers from a vocab
 * @param $terms - the vocab terms
 * @param $conf - configuration options
 * @param $allowedit - boolean if user has permission to edit vocab
 */
function oa_files_prepare_files_from_vocab($terms, &$conf, $allowedit = FALSE) {
  $result = array();
  $tids = array();
  $conf['max_weight'] = 0;

  // create folders for each term
  $weight = 0;
  // terms are already in weight order from drupal, but we can't use the term weight
  // because angular treecontrol doesn't handle equal weights the same way
  foreach ($terms as $term) {
    $tid = $term->tid;
    $parents = array();
    // need to prefix tids so they don't conflict with node ids.
    foreach ($term->parents as $parent) {
      $parents[] = empty($parent) ? 0 : 'tid' . $parent;
    }
    $id = empty($tid) ? 0 : 'tid' . $tid;
    $treenode = array(
      "id" => $id,
      "tid" => $tid,
      "parent" => $parents,
      "name" => $term->name,
      "weight" => $weight,
      "isfolder" => TRUE,
      "editor" => $allowedit,
      "url" => 'taxonomy/term/' . $tid,
      "vid" => $term->vid,
    );
    $tids[] = $tid;
    $result[$id] = $treenode;
    $weight++;
  }

  // now grab the files associated with the terms
  $children = oa_files_prepare_files_from_terms($tids, $conf);
  $result = $result + $children;

  return $result;
}

/**
 * Return files flat array of nodes with parent pointers from a vocab
 * @param $tids - the vocab term ids
 * @param $conf - configuration options
 */
function oa_files_prepare_files_from_terms($tids, &$conf) {
  $icon_directory = variable_get('file_icon_directory', drupal_get_path('module', 'file') . '/icons');
  $sort_field = !empty($conf['oa_files_sort']) ? $conf['oa_files_sort'] : 'title';
  $sort_dir = !empty($conf['oa_files_dir']) ? $conf['oa_files_dir'] : 'ASC';
  $node_type = (isset($conf['oa_files_type']) ? $conf['oa_files_type'] : 'oa_wiki_page');

  $nids = array();
  $result = array();
  // query all nodes that match the vocab terms
  if (!empty($tids)) {
    $query = db_select('taxonomy_index', 't');
    $query->join('node', 'n', "t.nid = n.nid");
    oa_files_apply_filters($query, $conf);
    $query->fields('n', array('nid'))
      ->fields('t', array('tid'))
      ->condition('t.tid', $tids, 'IN')
      ->condition('n.type', $node_type)
      ->addTag('node_access')
      ->orderBy($sort_field, $sort_dir);
    $result = $query->execute()->fetchAll();
    oa_files_add_other_nodes($result, $conf, $tids);
    foreach ($result as $node) {
      $nids[$node->nid] = $node->nid;
    }
  }

  if (!isset($conf['oa_files_all']) || $conf['oa_files_all']) {
    // add all other section files that are not categorized
    $query = db_select('node', 'n');
    oa_files_apply_filters($query, $conf);
    if (!empty($nids)) {
      $query->condition('n.nid', $nids, 'NOT IN');
    }
    $query->fields('n', array('nid'))
      ->condition('n.type', $node_type)
      ->addTag('node_access')
      ->orderBy($sort_field, $sort_dir);
    $all_nids = $query->execute()->fetchAll();
    oa_files_add_other_nodes($all_nids, $conf, NULL, $nids);

    foreach ($all_nids as $row) {
      $node = new stdClass();
      $node->nid = $row->nid;
      $node->tid = 0;
      array_push($result, $node);
    }
  }

  $tree = array();
  // ensure files at top level appear after the tid folders
  $weight = count($tids) + 1;
  $all_nids = array();
  foreach ($result as $node) {
    $all_nids[] = $node->nid;
  }
  $titles = oa_core_get_titles($all_nids, '', 'title', array('title', 'created', 'changed'), TRUE, 0);
  $check_edit_access = !empty($conf['oa_files_action_edit']) && count($result) < 20;
  foreach ($result as $node) {
    $nid = $node->nid;
    if (isset($tree[$nid])) {
      // node already in list so just add to parent list
      $tree[$nid]['parent'][] = empty($node->tid) ? 0 : 'tid' . $node->tid;
    }
    else {
      $body = '';
      if (oa_files_showfield($conf, 'body')) {
        $body = oa_files_summary(node_load($nid));
      }
      $parent = (empty($node->tid)) ? 0 : 'tid' . $node->tid;

      $treenode = array(
        "id" => $nid,
        "nid" => $nid,
        "parent" => array($parent),
        "name" => $titles['titles'][$nid],
        "date" => format_date($titles['createds'][$nid], 'short'),
        "modified" => format_date($titles['changeds'][$nid], 'short'),
        // Just show the link if too many, won't grant access if can't.
        "editor" => $check_edit_access ? node_access("update", node_load($nid)) : TRUE,
        "url" => 'node/' . $nid,
        "icon" => url($icon_directory . '/application-octet-stream.png'),
        "body" => $body,
        "isfolder" => FALSE, // cannot contain other items
        "weight" => $weight,
      );
      $tree[$nid] = $treenode;
      $weight++;
    }
  }
  return $tree;
}


/**
 * Add info about each file in files
 * @param $files
 */
function oa_files_add_file_links(&$files, $conf) {

  if (!empty($conf['oa_files_only_folders'])) {
    foreach ($files as $id => $file) {
      if (empty($file['isfolder'])) {
        unset($files[$id]);
      }
    }
  }

  // generate list of nids to get files for and create map array
  $nids = array();
  $map = array();
  foreach ($files as $key => $file) {
    if (isset($file['nid']) && !in_array($file['nid'], $nids)) {
      $nids[] = $file['nid'];
      $map[$file['nid']] = $key;
    }
  }

  if (empty($nids)) {
    return;
  }

  // query all files that match the nodes
  $query = db_select('file_managed', 'f');
  $query->join('field_data_field_oa_media', 'm', "m.field_oa_media_fid = f.fid AND m.entity_type = 'node'");
  $query->fields('m', array('entity_id', 'delta'))
    ->fields('f', array('fid', 'uri', 'filesize', 'filemime', 'filename', 'timestamp'))
    ->condition('m.entity_id', $nids, 'IN');
  $result = $query->execute()->fetchAllAssoc('fid');

  foreach ($result as $fid => $file) {
    if ($file->delta == 0) {
      $id = $map[$file->entity_id];
      $files[$id]['filesize'] = format_size($file->filesize);
      $files[$id]['downloadurl'] = oa_files_download_uri($fid, $file->uri);
      $files[$id]['filename'] = $file->filename;
      $files[$id]['date'] = format_date($file->timestamp, 'short');

      $icon = file_icon_url($file);
      $files[$id]['icon'] = $icon;
      $files[$id]['mimetype'] = $file->filemime;
    }
  }

  if (!empty($conf['oa_files_only_attached'])) {
    foreach ($files as $id => $file) {
      if (empty($file['filename']) && empty($file['isfolder'])) {
        unset($files[$id]);
      }
    }
  }
}

/**
 * Helper function to return the filtered Space id
 * @param $conf
 */
function oa_files_space_filter($conf) {
  $filter = isset($conf['oa_files_space']) ? $conf['oa_files_space'] : -1;
  return ($filter == -1 || $filter == OA_SPACE_CURRENT) ? oa_core_get_space_context() : $filter;
}

/**
 * Helper function to return the filtered Section id
 * @param $conf
 */
function oa_files_section_filter($conf) {
  $filter = isset($conf['oa_files_section']) ? $conf['oa_files_section'] : -1;
  $filter = is_array($filter) ? $filter : array($filter);
  $current_section = NULL;
  foreach ($filter as $key => $value) {
    if ($value == -1) {
      if (!isset($current_section)) {
        $current_section = oa_core_get_section_context();
      }
      $filter[$key] = $current_section;
    }
  }
  if (empty($filter)) {
    $filter = 0;
  }
  elseif (is_array($filter) && count($filter) == 1) {
    $filter = $filter[0];
  }
  return $filter;
}

/**
 * Empty config form
 */
function oa_files_treeview_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['oa_files_mode_group'] = array(
    '#type' => 'fieldset',
  );
  $form['oa_files_mode_group']['oa_files_menu_mode'] = array(
    '#type' => 'select',
    '#options' => array (
      0 => 'Space Menu',
      1 => 'Vocabulary',
    ),
    '#title' => 'Select whether files should be categorized by a vocabulary or by the Space Menu',
    '#default_value' => $conf['oa_files_menu_mode'],
  );
  $form['oa_files_mode_group']['oa_files_auto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow space taxonomy to override widget'),
    '#default_value' => isset($conf['oa_files_auto']) ? $conf['oa_files_auto'] : FALSE,
  );

  /* Fields for using the Space Menu */
  if ($plid = og_menu_single_get_active_plid()) {
    $form['oa_files_mode_group']['og_menu_single_depth'] = array(
      '#title' => t('Depth'),
      '#type' => 'select',
      '#options' => array(0 => t('All'), 1 => 1, 2 => 2, 3 => 3, 4 => 4, 5 => 5, 6 => 6, 7 => 7),
      '#default_value' => isset($conf['og_menu_single_depth']) ? $conf['og_menu_single_depth'] : 0,
      '#description' => t('Select how deep/how many levels of the menu to display.'),
      '#states' => array(
        'visible' => array(
          ':input[name="oa_files_menu_mode"]' => array('value' => 0),
        ),
      ),
    );
    if ($tree = og_menu_single_children_items($plid)) {
      $options = array();
      $options[OG_MENU_SINGLE_MENU_NAME . ':' . 0] = '<' . t('Full Menu') . '>';
      if (module_implements('og_menu_single_menu_parent')) {
        $options[OG_MENU_SINGLE_MENU_NAME . ':auto'] = '<' . t('Automatically Detect') . '>';
      }
      _menu_parents_recurse($tree, OG_MENU_SINGLE_MENU_NAME, '--', $options, 0, 8);
      $form['oa_files_mode_group']['og_menu_single_parent'] = array(
        '#title' => t('Parent'),
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => OG_MENU_SINGLE_MENU_NAME . ':' . (isset($conf['og_menu_single_parent']) ?  $conf['og_menu_single_parent'] : 0),
        '#description' => t('Select which parent item to display items below.'),
        '#states' => array(
          'visible' => array(
            ':input[name="oa_files_menu_mode"]' => array('value' => 0),
          ),
        ),
      );
    }
  }

  $node_type = isset($form_state['values']['oa_files_type']) ? $form_state['values']['oa_files_type'] :
    (isset($conf['oa_files_type']) ? $conf['oa_files_type'] : 'oa_wiki_page');

  $types = array_map('check_plain', node_type_get_names());
  $form['oa_files_mode_group']['oa_files_type'] = array(
    '#type' => 'select',
    '#title' => t('Content Type'),
    '#default_value' => $node_type,
    '#options' => $types,
    '#states' => array(
      'visible' => array(
        ':input[name="oa_files_menu_mode"]' => array('value' => 1),
      ),
    ),
    '#ajax' => array(
      'callback' => 'oa_files_vocab_ajax',
      'wrapper' => 'oa-files-vocab',
      'method' => 'replace',
      'effect' => 'fade',
      // This is needed because Ctools doesn't allow normal Drupal #ajax.
      'path' => 'system/panopoly-magic',
    ),
  );

  /* Fields for using Vocabularies */
  $form['oa_files_mode_group']['oa_files_vocabulary'] = array(
    '#title' => t('Vocabulary'),
    '#type' => 'select',
    '#options' => oa_files_get_vocab_options($node_type),
    '#default_value' => $conf['oa_files_vocabulary'],
    '#description' => t('Select which vocabulary to group files by.'),
    '#prefix' => '<div id="oa-files-vocab">',
    '#suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name="oa_files_menu_mode"]' => array('value' => 1),
      ),
    ),
  );

  $form['oa_files_mode_group']['oa_files_link_vocab'] = array(
    '#type' => 'checkbox',
    '#title' => t('Link vocab folders to listing pages'),
    '#default_value' => isset($conf['oa_files_link_vocab']) ? $conf['oa_files_link_vocab'] : FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="oa_files_menu_mode"]' => array('value' => 1),
      ),
    ),
  );

  $form['oa_files_mode_group']['oa_files_space'] = array(
    '#type' => 'og_group_ref',
    '#title' => t('Space'),
    '#default_value' => isset($conf['oa_files_space']) ? $conf['oa_files_space'] : OA_SPACE_CURRENT,
    '#states' => array(
      'visible' => array(
        ':input[name="oa_files_menu_mode"]' => array('value' => 1),
      ),
    ),
    '#allow_current' => TRUE,
  );

  if (module_exists('oa_subspaces')) {
    $form['oa_files_mode_group']['oa_files_subspaces'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show subspace content'),
      '#default_value' => isset($conf['oa_files_subspaces']) ? $conf['oa_files_subspaces'] : FALSE,
    );
  }

  $form['oa_files_mode_group']['oa_files_section'] = array(
    '#type' => 'oa_section_ref',
    '#title' => 'Section',
    '#default_value' => isset($conf['oa_files_section']) ? $conf['oa_files_section'] : OA_SPACE_CURRENT,
    '#og_group_ref' => 'oa_files_space',
    '#multiple' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="oa_files_menu_mode"]' => array('value' => 1),
      ),
    ),
  );

  /* General options */
  $sort_options = array(
    'title' => 'Title',
    'created' => 'Date created',
    'changed' => 'Date modified',
  );
  $form['oa_files_sort'] = array(
    '#title' => t('Field to Sort'),
    '#type' => 'select',
    '#options' => $sort_options,
    '#default_value' => !empty($conf['oa_files_sort']) ? $conf['oa_files_sort'] : 'title',
    '#description' => t('Select which field to sort documents by.'),
  );
  $form['oa_files_dir'] = array(
    '#title' => t('Sort direction'),
    '#type' => 'select',
    '#options' => array('ASC' => 'Ascending', 'DESC' => 'Descending'),
    '#default_value' => !empty($conf['oa_files_dir']) ? $conf['oa_files_dir'] : 'ASC',
    '#description' => t('Select which direction to sort.'),
  );

  $form['oa_files_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show uncategorized files'),
    '#default_value' => isset($conf['oa_files_all']) ? $conf['oa_files_all'] : TRUE,
  );

  $form['oa_files_only_attached'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only show documents with attached files'),
    '#default_value' => isset($conf['oa_files_only_attached']) ? $conf['oa_files_only_attached'] : FALSE,
  );

  $form['oa_files_only_folders'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only show folders'),
    '#default_value' => isset($conf['oa_files_only_folders']) ? $conf['oa_files_only_folders'] : FALSE,
  );

  $form['oa_files_hide_empty'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide empty folders'),
    '#default_value' => isset($conf['oa_files_hide_empty']) ? $conf['oa_files_hide_empty'] : FALSE,
  );

  $form['oa_files_showcount'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show file count within folders'),
    '#default_value' => $conf['oa_files_showcount'],
  );

  $form['oa_files_showfilter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show filter'),
    '#default_value' => $conf['oa_files_showfilter'],
  );

  $form['oa_files_treeview_mode'] = array(
    '#type' => 'select',
    '#options' => array (
      0 => 'Sidebar',
      1 => 'Wide',
    ),
    '#title' => 'Style of tree view',
    '#default_value' => $conf['oa_files_treeview_mode'],
  );

  $field_options = array(
    'size' => 'File size',
    'date' => 'Date (created/uploaded)',
    'modified' => 'Date (last modified)',
    'filename' => 'File name',
    'body' => 'Description',
  );
  $form['oa_files_fields'] = array(
    '#type' => 'checkboxes',
    '#options' => $field_options,
    '#default_value' => $conf['oa_files_fields'],
    '#title' => t('Fields to show'),
    '#description' => t('If showing Description with many files, it will slow the page load signicantly.'),
  );

  $actions = oa_files_actions($conf);
  $form['oa_files_actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Actions'),
    '#description' => t('Enabled and Exposed actions are only shown to users who have permission to use them.')
  );
  foreach ($actions as $key => $action) {
    $form['oa_files_actions']['oa_files_action_fieldset_' . $key] = array(
      '#type' => 'fieldset',
      '#title' => $action['title'],
    );
    $form['oa_files_actions']['oa_files_action_fieldset_' . $key]['oa_files_action_title_' . $key] = array(
      '#type' => 'textfield',
      '#title' => t('Caption'),
      '#default_value' => $conf['oa_files_action_title_' . $key],
    );
    $form['oa_files_actions']['oa_files_action_fieldset_' . $key]['oa_files_action_' . $key] = array(
      '#type' => 'select',
      '#options' => array (
        0 => 'Disabled',
        1 => 'Enabled',
        2 => 'Exposed',
      ),
      '#title' => t('Mode'),
      '#default_value' => $conf['oa_files_action_' . $key],
    );
  }

  return $form;
}

/**
 * Ajax callback when selecting content type for vocab
 */
function oa_files_vocab_ajax($form, $form_state) {
  return $form['oa_files_mode_group']['oa_files_vocabulary'];
}

/**
 * Helper function to determine which vocabularies are allowed on this content type
 */
function oa_files_get_vocab_options($type = 'oa_wiki_page') {
  $vids = array();
  $vocab_names = array();

  // first grab any taxonomy reference fields on the content type
  $field_info = field_info_fields();
  $fields = field_info_instances('node', $type);
  foreach ($fields as $key => $field) {
    $info = $field_info[$key];
    if ($info['module'] == 'taxonomy') {
      foreach ($info['settings']['allowed_values'] as $index => $item) {
        $vocab_names[] = $item['vocabulary'];
      }
    }
  }

  // if using og_vocab, grab the valid vocab ids.
  if (module_exists('og_vocab')) {
    $vids = og_vocab_get_accessible_vocabs('node', $type, OG_VOCAB_FIELD);
  }

  $result = array();
  foreach (taxonomy_get_vocabularies() as $vid => $vocab) {
    if (in_array($vid, $vids) || (in_array($vocab->machine_name, $vocab_names))) {
      $result[$vid] = $vocab->name;
    }
  }
  return $result;
}

/**
 * Saves changes to the widget.
 */
function oa_files_treeview_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      if ($key == 'og_menu_single_parent') {
        $form_state['values'][$key] = substr($form_state['values'][$key], strpos($form_state['values'][$key], ':') + 1);
      }
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
