<?php
/**
 * @file The page callbacks for the Apps module.
 */

/**
 * Title for the App Server
 */
function apps_server_title($server) {
  return t("@title Apps", array('@title' => $server['title']));
}

/**
 * Title for the app detail page
 */
function apps_app_title($app) {
  return t("@title Details", array('@title' => $app['name']));
}

/**
 * Callback for the market page
 *
 * If there is only one server, go directly to it. Otherwise, list 'em.
 */
function apps_market_page() {
  apps_include('manifest');
  $servers = apps_servers();

  // If there is only one, go directly to it
  if (isset($servers) && count($servers) === 1) {
    return drupal_goto('admin/apps/' . key($servers));
  }

  foreach ($servers as &$server) {
    $server['#theme'] = 'apps_server_item';
  }
  return theme('apps_market_page', array('servers' => $servers));
}

/**
 * Callback list off all apps
 */
function apps_install_page($server_name) {
  apps_include('manifest'); 
  $element = array(
    '#theme'=> 'apps_install_page',
  );
  //find all apps
  try {
    $apps = apps_apps($server_name, array(), TRUE);
    if (!empty($apps)) {
      $element['apps'] = $apps;
      $featured_apps = apps_apps($server_name , array('featured' => TRUE)) ;
      if(!empty($featured_apps)) {
        $element['featured_app'] = array_pop($featured_apps);
      }
    }
  }
  catch (Exception $e) {
    drupal_set_message(t("There was the following error: @msg", array('@msg' => $e->getMessage())), 'warning');
  }
  return $element; 
}

/**
 * Callback for listing of installed apps
 */
function apps_manage_page($server) {
  apps_include('manifest');
  $element = array(
    '#theme'=> 'apps_manage_page',
  );
  // find all installed apps
  try {
    $apps = apps_apps($server['name'], array("installed" =>TRUE), TRUE);
    $element['apps'] = $apps;
  }
  catch (Exception $e) {
    drupal_set_message("There was the following error - " . $e->getMessage(), 'warning');
  }
  return $element;
}

/**
 * Callback for listing of installed apps that have available updates
 */
function apps_update_page($server) {
  return array(
    '#theme'=> 'apps_update_page',
  );
}

/**
 * Callback for app config page
 */
function apps_app_config_page($app) {
  apps_include('manifest');
  $element = array();
  if(apps_app_callback($app, "demo content enable callback")) {
    $element['demo'] = drupal_get_form('apps_demo_content_form', $app);
  }

  // Check for a status table
  if($data_callback = apps_app_callback($app, "status callback")) {
    $data = $data_callback();
    $header = isset($data['header']) ? $data['header'] : NULL;
    $items = isset($data['items']) ? $data['items'] : array();
    $element['status'] = array(
      '#type' => 'fieldset',
      '#title' => t('Status'),
      'table' => apps_app_status_report($items, $header),
    );
  }
  if($form = apps_app_callback($app, "configure form")) {
    $element['config'] =  drupal_get_form($form);
  }
  return $element;
}

/**
 * Callback for the app detail page
 */
function apps_app_details_page($app) {
  $app['#theme'] = 'apps_app_page';
  return $app;
}

/**
 * Callback for app install
 * TODO: check to see the app is install able and then install
 * TODO: should goto config page but pass on the current destination
 * NOTE: it is expected that this page would be called with a drupal desination set
 */
function apps_app_install($app) {
  apps_include('installer');
  require_once DRUPAL_ROOT . '/includes/authorize.inc';
  $action = arg(5);
  switch ($action) {
    case 'install':
      $_SESSION['apps_install_next'] = apps_app_page_path($app, 'enable');
      return apps_install_downloads();
    default:
      // Adds an extra path element to avoid an endless loop. If we check for
      // install at arg(4) we are usually there. So here we add an install at
      // arg(5) and that will get caught in the case above ^-^
      $_SESSION['apps_install_next'] = apps_app_page_path($app, 'install/install');
      apps_download_apps($app);
      break;
  }
}

/**
 * Centralize the generation of App paths
 *
 * @param $app
 *    The app array
 * @param string $op
 *    The path type
 * @return string
 *    A path to the app operation
 */
function apps_app_page_path($app, $op = 'details') {
  if (isset($app['machine_name'])) {
    return "admin/apps/{$app['server']['name']}/{$app['machine_name']}/$op";
  }
}

/**
 * Callback for the enable action
 *
 * Enables the app and got to config page if it exists
 */
function apps_app_enable($app) {
  $next = apps_app_page_path($app, 'configure');
  $success = module_enable(array($app['machine_name']), TRUE);
  if ($success) {
    drupal_flush_all_caches();
    drupal_set_message(t("Enabled @name app", array('@name' => $app['name'])));
    if (!$app['disabled'] && ($cb = apps_app_callback($app, "post install callback"))) {
      $cb($app);
    }
    if(!apps_app_access('administer apps', $app, 'configure')) {
      $next = apps_app_page_path($app);
    }
  }
  else {
    drupal_set_message(t("@name App Not Enabled", array('@name' => $app['name'])));
    $next = apps_app_page_path($app);
  }
  drupal_goto($next);
}

/**
 * Callback for app disable
 */
function apps_app_disable($app) {
  // Force the user to disable demo content before disabling the app
  if (($is_cb = apps_app_callback($app, "demo content enabled callback")) &&
    $is_cb($app)) {
    $next = apps_app_page_path($app, 'configure');
    drupal_set_message(t("Please disable demo content before disabling the app"));
    drupal_goto($next);
  }

  module_disable(array($app['machine_name']));
  drupal_flush_all_caches();
  drupal_set_message(t("Disabled @name app", array('@name' => $app['name'])));
  $next = apps_app_page_path($app);
  drupal_goto($next);
}

/**
 * Callback for app uninstall
 */
function apps_app_uninstall($app) {
  require_once DRUPAL_ROOT . '/includes/install.inc';
  $uninstall[] = $app['machine_name'];
  if (isset($app['demo content module']) && $app['demo content module']) {
    array_unshift($uninstall, $app['demo content module']);
  }

  if (drupal_uninstall_modules($uninstall)) {
    drupal_flush_all_caches();
    drupal_set_message(t("Uninstalled @name app", array('@name' => $app['name'])));
  }
  else {
    drupal_set_message(t("Uninstalling @name app failed. Please ensure all modules that depend on this module are also uninstalled", array('@name' => $app['name'])));
   }
  $next = apps_app_page_path($app);
  drupal_goto($next);
}

/**
 * Admin settings form for Apps.
 */
function apps_settings_form() {
  $form = array();
  $form['apps_offline_mode'] = array(
    '#title' => t('Apps Offline Mode'),
    '#description' => t('Does not try to make external requests to app servers. Assumes all apps are already locally stored.'),
    '#type' => 'checkbox',
    '#default_value'=> variable_get('apps_offline_mode', FALSE),
  );
  $form['apps_enable_dev_console'] = array(
    '#title' => t('Enable Development Console'),
    '#description' => t('Allows local Apps to be displayed in a development app server.'),
    '#type' => 'checkbox',
    '#default_value'=> variable_get('apps_enable_dev_console', FALSE),
  );
  $form['apps_allow_voting'] = array(
    '#title' => t('Allow Voting'),
    '#description' => t('Allow users who can install apps to also rate them.  Requires that the appserver is running the appserver module.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('apps_allow_voting', TRUE),
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'apps_settings_form_submit';
  return $form;
}

/**
 * Once the settings are saved, flush all caches. This will trigger the
 * Apps dev server to appear in the Apps console.
 */
function apps_settings_form_submit() {
  drupal_flush_all_caches();
}


/**
 * apps_app_status_report()
 *
 * @PARAM items: an array of items to display the keys of which should be the 
 * keys of the $header param or use the default.
 * The default are severity, title, description and action.  Severity is expected to be
 * an int in (REQUIREMENT_INFO, REQUIREMENT_OK, REQUIREMENT_WARNING, REQUIREMENT_ERROR)
 * @PARAM header: an array of header titles, the keys of which should match the keys in $items
 * there is a default for this value
 *
 * @RETURN: a render array for the status report table
 */
function apps_app_status_report($items, $header = NULL) {
  if(!isset($header)) {
    $header = array(
      'severity' => 'Status',
      'title' => 'Title',
      'description' => 'Description',
      'action' => 'Action',
    );
  }
  $rows = array();
  $severities = array(
    REQUIREMENT_INFO => array(
      'title' => t('Info'),
      'class' => 'info',
      'image' => array('#theme'=>"image", "#path" => "misc/message-24-info.png", "#alt"=>"Info"),
    ),
    REQUIREMENT_OK => array(
      'title' => t('OK'),
      'class' => 'ok',
      'image' => array('#theme'=>"image", "#path" => "misc/message-24-ok.png", "#alt"=>"Ok"),
    ),
    REQUIREMENT_WARNING => array(
      'title' => t('Warning'),
      'class' => 'warning',
      'image' => array('#theme'=>"image", "#path" => "misc/message-24-warning.png", "#alt"=>"Warning"),
    ),
    REQUIREMENT_ERROR => array(
      'title' => t('Error'),
      'class' => 'error',
      'image' => array('#theme'=>"image", "#path" => "misc/message-24-error.png", "#alt"=>"Error"),
    ),
  );
  foreach($items as $item) {
    $row = array();
    foreach(array_keys($header) as $key) {
      if(isset($item[$key])) {
        if($key =='severity') {
          $row['data'][] = render($severities[$item[$key]]['image']);
          $row['class'][] = $severities[$item[$key]]['class'];
        }
        elseif($key == 'action') {
          $row['data'][] = theme('item_list', array("items" => $item[$key]));
        
        }
        else {
          $row['data'][] = $item[$key];
        }
      }
      else {
          $row['data'][] = '';
      }
    }
    $rows[] = $row;
  }
  return array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );
}
