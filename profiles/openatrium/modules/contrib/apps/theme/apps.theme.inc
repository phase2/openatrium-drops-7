<?PHP

/**
 * implement hook_preprocess_apps_list
 */
function theme_apps_list($vars) {
  $items = array();
  foreach($vars['apps'] as $id=> $app) {
    if (!preg_match("/^#/", $id)) {
      $items[] = drupal_render($app);
    }
  }
  return theme('item_list', array('items'=>$items));
}


/**
 * implement hook_preprocess_apps_app_teaser
 */
function apps_preprocess_apps_app_teaser(&$vars) {
  
  apps_include('pages');
  $link = apps_app_page_path($vars['app']);
  $vars['name'] = l($vars['app']['name'], $link);
  if(!empty($vars['app']['logo'])) {
    $vars['app']['logo']['style_name']= 'apps_logo';
    $vars['logo'] = l(theme('image_style', $vars['app']['logo']), $link, array('html'=>TRUE));
  }
  else {
    $vars['logo'] = FALSE;
  }
  $status = $vars['app']['status'];
  $vars['status'] = $status === APPS_ENABLED ?
    'enabled' :
    (($status === APPS_DISABLED) ?
      'disabled' :
      (($status === APPS_INCOMPATIBLE) ?
        'incompatible' :
        'available'
      )
    );
  
  //add rating information for theming
  $vars['app']['teaser'] = TRUE;

  if (variable_get('apps_allow_voting', FALSE)) {
    $vars['rating'] = theme('apps_voting_widget', $vars['app']);
  }
  
  //action link
  $vars['action'] = l('Details', $link);
}

/**
 * implement hook_preprocess_apps_app_page
 */
function apps_preprocess_apps_app_page(&$vars) {
  //first do everything we do in the teaser
  drupal_add_css(drupal_get_path('module', 'apps').'/theme/css/apps.css');
  apps_preprocess_apps_app_teaser($vars);
  
  //we need some special stuff for the logo here
  if(!empty($vars['app']['logo']) && $vars['app']['logo']) {
    $vars['app']['logo']['style_name']= 'apps_logo_small';
    $vars['logo'] = theme('image_style', $vars['app']['logo']);
  }
   
    
  if(isset($vars['app']['screenshots'][0])) {
    $vars['app']['screenshots'][0]['style_name'] = 'apps_screenshot';
    $vars['screenshot'] = theme('image_style', $vars['app']['screenshots'][0]);
  }
  else {
    $vars['screenshot'] = FALSE;
  }
  
  $vars['description'] = $vars['app']['description'];
  $vars['name'] = $vars['app']['name'];
  $vars['author'] = l($vars['app']['author'], $vars['app']['author_url']);
  $vars['version'] = $vars['app']['version'];
  if ($vars['app']['status'] === APPS_INCOMPATIBLE) {
    $incompatible_deps = array();
    $incompatible_message = '';
    foreach($vars['app']['dependencies'] as $dep) {
      if ($dep['status'] === APPS_INCOMPATIBLE) {
        $incompatible_deps[] = "{$dep['version']['name']} {$dep['version']['original_version']}";
      }
    }
    if (!empty($incompatible_deps)) {
      $incompatible_message = "Incompatible - requires " . implode(", ", $incompatible_deps);
    }
    else {
      //this should never run
      $incompatible_message = "Incompatible with current install";
    }
    $vars['status'] = $incompatible_message;
  }
  
  //Title texts for App Detail Page
  $vars['author_title'] = t('Author');
  $vars['version_title'] = t('Version');
  $vars['description_title'] = t('Description');

  $vars['app']['teaser'] = FALSE;

  if (variable_get('apps_allow_voting', FALSE)) {
    $vars['rating_title'] = t('Customer Rating');
    //Override the rating key with the full widget
    $vars['rating_caption'] = t('Average rating for this version:');
    $vars['rating'] = theme('apps_voting_widget', $vars['app']);
  }
}


/**
 * implement hook_preprocess_apps_app_featured
 */
function apps_preprocess_apps_app_featured(&$vars) {
  //first do everything we do in the teaser
  apps_preprocess_apps_app_teaser($vars);
  if($vars['app']['screenshots'][0]) {
    $vars['app']['screenshots'][0]['style_name'] = 'apps_featured_screenshot';
    $vars['screenshot'] = theme('image_style', $vars['app']['screenshots'][0]);
  }
  $vars['description'] = $vars['app']['description'];

  if (variable_get('apps_allow_voting', FALSE)) {
    $vars['rating'] = theme('apps_voting_widget', $vars['app']);
  }

  //action link
  $link = apps_app_page_path($vars['app']);
  $vars['action'] = l('free', $link);  //The text and link for the action button
}

/**
 * implement hook_preprocess_apps_install_page
 */
function apps_preprocess_apps_install_page(&$vars) {
  drupal_add_css(drupal_get_path('module', 'apps').'/theme/css/apps.css');
  if (isset($vars['content']['featured_app'])) {
    $vars['content']['featured_app']['#theme'] = 'apps_app_featured';
  }
}

/**
 * implement hook_preprocess_apps_manage_page
 */
function apps_preprocess_apps_manage_page(&$vars) {
  drupal_add_css(drupal_get_path('module', 'apps').'/theme/css/apps.css');
}

function apps_preprocess_apps_update_page(&$vars) {
  drupal_add_css(drupal_get_path('module', 'apps').'/theme/css/apps.css');
}
