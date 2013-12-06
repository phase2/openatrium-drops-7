<?php
/**
 * @file
 * Handles pulling and processing of app data from the server
 *
 */

/**
 * Return all local apps for the specified server.
 *
 * @param string $server
 *    A machine name for a server
 * @return array An array of apps
 */
function apps_server_local($server) {
  $apps = array();
  $modules = system_rebuild_module_data();
  foreach ($modules as $module => $info) {
    // If an app is not limited to a specific server, or the limiting server is this server.
    if (isset($info->info['apps']) && (!isset($info->info['apps']['server']) || $info->info['apps']['server'] == $server['name'])) {
      $manifest = $info->info['apps'];
      $app_path = drupal_get_path('module', $module);

      // Set some defaults, if needed
      $manifest['machine_name'] = $module;
      $manifest['local'] = TRUE;
      if (!isset($manifest['name'])) {
        $manifest['name'] = $info->info['name'];
      }
      if (!isset($manifest['description'])) {
        $manifest['description'] = $info->info['description'];
      }
      if (!isset($manifest['version'])) {
        $manifest['version'] = $info->info['version'];
      }
      if (isset($manifest['screenshots'])) {
        foreach ($manifest['screenshots'] as $id => $image) {
          $manifest['screenshots'][$id] = url($app_path . '/' . $image);
        }
      }
      if (isset($manifest['logo'])) {
        $manifest['logo'] = url($app_path . '/' . $manifest['logo']);
      }
      $apps[$module] = $manifest;
    }
  }
  return $apps;
}

/**
 * Returns all app servers configured to work for the current site.
 *
 * @param $server_name
 *      Optional. The name of a specific server to return
 * @return array An array of servers, or one server array if $server_name has a valid value
 */
function apps_servers($server_name = FALSE) {
  $servers_cache = cache_get('apps_servers');
  $servers = $servers_cache ? $servers_cache->data : FALSE;
  if (!$servers) {
    $profile = drupal_get_profile();
    // Get apps servers from profile
    $servers = ($s = module_invoke($profile, 'apps_servers_info')) ? $s : array();
    // Allow modules to add apps servers as well.
    $servers += module_invoke_all('apps_servers_info');

    drupal_alter('apps_servers', $servers);

    foreach($servers as $name =>$server) {
      $servers[$name]['name'] = $name;
    }
  }
  // if we have the dev console turned on add it as a server
  if (variable_get('apps_enable_dev_console', FALSE)) {
    $servers['development'] = array(
      'name' => 'development',
      'description' => 'Local Apps in Development',
      'title' => 'Development',
      'manifest' => FALSE,
      'featured app' => FALSE,
    );
  }
  cache_set('apps_servers', $servers);
  if($server_name) {
    if(isset($servers[$server_name])) {
      return $servers[$server_name];
    }
  }
  else {
    return $servers;
  }
  return FALSE;
}

/**
 * Retrieve apps from the server manifest.
 *
 * @param $server
 *    A server object return from apps_servers
 * @param $condition
 *    An array of key/values to filter the apps
 * @param $add_theme
 *    If TRUE apps_apps_add_theme will be called when done getting apps
 * @return
 *    An array of app info arrays
 */
function apps_apps($server, $condition = array(), $add_theme=FALSE) { 
  if (!is_array($server)) {
    $server = apps_servers($server);
  }
  $manifest = apps_manifest($server);
  if (isset($manifest['error'])) {
    $e = new Exception($manifest['error']);
    $e->request = $manifest['request'];
    throw $e;
  }
  $apps = $manifest['apps'];
  foreach($apps as $id => $app) {
    $intersect = array_intersect_assoc($app, $condition);
    if ($intersect !== $condition) {
      unset($apps[$id]);
    }
  }
  if (!empty($apps) && $add_theme) {
    apps_apps_add_theme($apps);
  }
  return $apps;
}

/**
 * takes an array of apps and ands #theme properties so that
 * it can be drupal rendered
 * PARAM $apps: an array of apps from apps_apps
 * RETURN : the apps array with add #theme settings for a list 
 * view of the apps
 */
function apps_apps_add_theme(&$apps) {
  foreach($apps as $id=> $app) {
    // add teaser theme
    $apps[$id]['#theme'] = 'apps_app_teaser';
    // add style name for image_style theming
    if($apps[$id]['logo']) {
      $apps[$id]['logo']['style_name']= 'apps_logo';
    }
  }
  $apps['#theme'] = 'apps_list';
}


function apps_client_id() {
  $id = variable_get('apps_client_id', FALSE);
  if (!$id) {
    $id = uniqid(rand(0, 10000), TRUE);
    variable_set('apps_client_id', $id);
  }
  return $id;
  
}

/**
 * Request manifest and media assets from the app server.
 *
 * @param $server
 *    A server array
 * @return
 *    An array representation of the json manifest, with images
 *    replaced by file objects.
 */
function apps_request_manifest($server) {
  if ($cache = cache_get("apps_manifest_{$server['name']}")) {
    return $cache->data;
  }

  // Gather all local apps
  $local_apps = apps_server_local($server);
  $manifest = $server;
  $manifest['apps'] = $local_apps;
  apps_request_manifest_image_process($manifest);

  // If there is no remote server, or we're in offline mode, stop here
  if (!$server['manifest'] || variable_get('apps_offline_mode', FALSE)) {
    return $manifest;
  }

  // Now process remote apps
  $info =  drupal_parse_info_file(dirname(__FILE__) . '/apps.info');
  $rest_data = array(
    'client_id' => apps_client_id(),
    'apps_version' => $info['version'],
    'format' => 'json',
  ) + $server;

  $url = url($server['manifest'], array('query' => $rest_data));
  $request = drupal_http_request($url);

  if (isset($request->error)) {
    $msg = t("Manifest error from @server: @error", array('@server' => $server['title'], '@error' => $request->error));
    watchdog("apps", $msg);
    drupal_set_message($msg, 'warning');
  }
  else if ($remote_manifest = json_decode($request->data, TRUE)) {
    // Translate index to machine name
    foreach ($remote_manifest['apps'] as $index => $app) {
      // If it is already a local app, note the remote version
      if (array_key_exists($app['machine_name'], $manifest['apps'])) {
        $manifest['apps'][$app['machine_name']]['remote manifest'] = $app;
      }
      // else translate index to machine name
      else {
        $remote_manifest['apps'][$app['machine_name']] = $app;
        $remote_manifest['apps'][$app['machine_name']]['remote'] = TRUE;
      }
      unset($remote_manifest['apps'][$index]);
    }
    apps_request_manifest_image_process($remote_manifest);
    $manifest['apps'] = array_merge($remote_manifest['apps'], $manifest['apps']);
    cache_set("apps_manifest_{$server['name']}", $manifest, 'cache', REQUEST_TIME + 60 +30);
  }
  else {
    $msg = t("Manifest JSON from @server not parsable", array('@server' => $server['title']));
    watchdog("apps", $msg);
    drupal_set_message($msg, 'warning');
  }

  return $manifest;
}

/**
 * Process images (logo and screenshots) so that they can be sized with image styles
 *
 * @param array $manifest
 *    An app manifest for a server
 */
function apps_request_manifest_image_process(&$manifest) {
  foreach ($manifest['apps'] as $id => &$app) {
    if (isset($app['logo'])) {
      $logo = apps_retrieve_app_image($id, $app['logo'], t("@name Logo", array('@name' => $app['name'])));
      $app['logo'] = !empty($logo) ? $logo : FALSE;
    }

    if (isset($app['screenshots'])) {
      foreach ($app['screenshots'] as $index => $url) {
        $name = isset($app['name']) ? $app['name'] : $manifest['name'];
        $screenshot = apps_retrieve_app_image($id, $url, t("@name Screenshot @index", array('@name' => $name, '@index' => $index)));

        if (!empty($screenshot)) {
          $app['screenshots'][$index] = $screenshot;
        }
        else {
          unset($app['screenshots'][$index]);
        }
      }
    }
  }

}

/**
 * Retrieve the image from the manifest
 *
 * @param string $app
 *    The app machine name
 * @param string $url
 *    The url of the image
 * @param string $title
 *    The title of the image
 * @param string $alt
 *    The alt text of the image
 * @return array A file object for the download file or FALSE if no image was downloaded
 */
function apps_retrieve_app_image($app, $url, $title = '', $alt = '') {
  // Allow for local files
  $check = parse_url($url);
  if(!$check || !isset($check['host']) || !$check['host']){
    $url = url($url, array('absolute' => TRUE));
  }

  $url_parts = explode("/", parse_url($url, PHP_URL_PATH));
  $file_name = array_pop($url_parts);

  $dir = "apps/$app";
  $uri = file_build_uri("$dir/$file_name");
  $current = FALSE;
  
  $fids = db_select('file_managed', 'f')
    ->condition('uri', $uri)
    ->fields('f', array('fid'))
    ->execute()
    ->fetchCol();
  
  if (!empty($fids) && isset($fids[0]) && is_numeric($fids[0])) {
    $current = file_load($fids[0]);
  }

  // Check to see if the remote file is newer than the one that
  // we have and that the one we have still exists
  if ($current && file_exists($current->uri)){
    // Get the remote headers
    $remote = drupal_http_request($url, array('method' => 'HEAD'));
    $remote = $remote->headers;
    $use_current = !empty($remote['last-modified']) && strtotime($remote['last-modified']) <= $current->timestamp;

    if ($use_current && !empty($remote['content-length']) && $remote['content-length'] == $current->filesize){
      $current->path = $current->uri;
      $current->title = !empty($title) ? $title : '';
      $current->alt = !empty($alt) ? $alt : $title;
      return (array)$current;
    }
  }
   
  $request = drupal_http_request($url, array(), 'GET');
  if (isset($request->data) && $request->code == 200) {
    if (!file_exists(drupal_realpath(file_build_uri($dir)))) {
      drupal_mkdir(file_build_uri($dir), NULL, TRUE);
    }

    $file = new stdClass;
    $file->mimetype = $request->headers['content-type'];
    $file->uri = file_unmanaged_save_data($request->data, $uri, FILE_EXISTS_RENAME);
    if ($current) {
      $file->fid = $current->fid;
    }
    $file->title = !empty($title) ? $title : '';
    $file->alt = !empty($alt) ? $alt : $file->title;
    file_save($file);
    $file->path = $file->uri;
    return (array)$file;
  }
}

/**
 * Produce the Process Manifest
 *
 * Starting with the json manifest and adding data around the current status of the app
 * in this install
 *
 * PARAM $server: a server object return from apps_servers
 * RETURN : an array of the process json manifest
 *
 *TODO: Cache status data and clear on changes to any module status
 */
function apps_manifest($server) {
  $manifests = &drupal_static(__FUNCTION__);
  require_once DRUPAL_ROOT . '/includes/install.inc';
  if (empty($manifests[$server['name']]) && !isset($manifests[$server['name']]['error'])) {

    // Get the manifest for apps for this server
    $manifest = apps_request_manifest($server);

    //if there is an error with the manifest jump out now
    if (isset($manifest['error'])) {
      return $manifest;
    }
    $modules = system_rebuild_module_data();
    $apps = array();
    foreach($manifest['apps'] as $machine_name => $app) {
      $current_app_module = isset($modules[$machine_name]) ? $modules[$machine_name] : FALSE;
      $app['enabled'] = $current_app_module && $current_app_module->status;
      $app['incompatible'] = FALSE;
      $app['installed'] = (bool) $current_app_module;
      $app['dep_installed'] = TRUE;
      $app['disabled'] = $current_app_module && empty($current_app_module->status) && $current_app_module->schema_version > SCHEMA_UNINSTALLED;
      $app['featured'] = isset($manifest['featured app']) && ($machine_name == $manifest['featured app']);
      $app['server'] = $server;
      $app['dependencies'] = isset($app['dependencies']) ? $app['dependencies'] : array();
      $app['libraries'] = isset($app['libraries']) ? $app['libraries'] : array();
      // Add info to dependencies
      foreach($app['dependencies'] as $name_version => $downloadable) {
        //Parse dep versions
        $version = drupal_parse_dependency($name_version);
        $name = $version['name'];

        //check status of modules
        $current = isset($modules[$name]) ? $modules[$name] : FALSE;
        $incompatible = $current ? (bool) drupal_check_incompatibility($version, $current->info['version']) : FALSE;
        $installed = (bool) $current;
        $enabled = $current && $current->status;
        $status = $incompatible ? APPS_INCOMPATIBLE : (!$installed ? APPS_INSTALLABLE : ($enabled ? APPS_ENABLED : APPS_DISABLED));

        if($status == APPS_INCOMPATIBLE) {
          //if any one module is incompatible then the app is incompatible
          $app['incompatible'] = TRUE;
        }
        if($status == APPS_INSTALLABLE) {
          //if any one module is installable then we are not installed yet
          $app['dep_installed'] = FALSE;
        }
        //rebuild dep with new data
        $info = array(
          'downloadable' => $downloadable,
          'version' => $version,
          'status' => $status,
          'incompatible' => $incompatible,
          'enabled' => $enabled,
          'installed' => $installed,
        );
        unset($app['dependencies'][$name_version]);
        $app['dependencies'][$version['name']] = $info;
      }
      if (isset($app['libraries'])) {
        $profile = variable_get('install_profile', 'standard');
        $profile_path = drupal_get_path('profile', $profile);
        foreach($app['libraries'] as $name_version => $downloadable) {
          $info = array(
            'downloadable' => $downloadable,
            'version' => array('name'=>$name_version),
            'status' => APPS_INSTALLABLE,
            'incompatible' => 0,
            'enabled' => 0,
            'installed' =>  is_dir(DRUPAL_ROOT . "/sites/all/libraries/$name_version") || is_dir($profile_path . "/libraries/$name_version"),
          );
          $app['libraries'][$name_version] = $info;
        }
      }
      $app['status'] = $app['incompatible'] ? APPS_INCOMPATIBLE : (!$app['installed'] || !$app['dep_installed'] ? APPS_INSTALLABLE : ($app['enabled'] ? APPS_ENABLED : APPS_DISABLED));
      $apps[$machine_name] = $app;
    }
    //override json apps with our enhanced apps
    apps_add_app_info($apps);
    $manifest['apps'] = $apps;
    $manifests[$server['name']] = $manifest;
  }
  return $manifests[$server['name']];
}

/**
 *
 *
 * @param $apps
 */
function apps_add_app_info(&$apps) {
  $info_cache = cache_get("apps_installed_app_info");
  $info = array();
  if ($info_cache) {
    $info = $info_cache->data;
  }
  $set_cache = FALSE;
  foreach($apps as $id => $app) {
    if(!isset($info[$app['machine_name']])) {
       $info[$app['machine_name']] = ($i = module_invoke($app['machine_name'], 'apps_app_info')) ? $i : array();
       $set_cache = TRUE;
    }
    $apps[$id] += $info[$app['machine_name']];
    //add defaults
    $info_defaults = array(
      'configure form' => $app['machine_name'] . "_apps_app_configure_form",
      'demo content description' => "Enabling the demo content will add content to the site that can help to understand how the app functions.  When it is disabled all of the demo content will be removed.",
    );
    $apps[$id] += $info_defaults;
    
    // set demo content callbacks if demo content module is set
    if (isset($apps[$id]['demo content module'])) {
      $apps[$id] += array(
        'demo content enabled callback' => 'apps_demo_content_enabled',
        'demo content enable callback' => 'apps_demo_content_enable',
        'demo content disable callback' => 'apps_demo_content_disable',
      );
    }
  }
  if ($set_cache) {
    cache_set("apps_install_app_info", $info);
  }
}

/**
 * Find an App callback and ensure the proper file is required.
 *
 * @param $app
 *    The app
 * @param $key
 *    The call back key
 * @return string
 *    The callback function on the given App for the provided key
 */
function apps_app_callback($app, $key) {
  module_load_include("inc", $app['machine_name'], $app['machine_name'] . ".app");
  if(isset($app['file'])) {
    require_once $app['file'];
  }
  if (isset($app[$key]) && module_exists($app['machine_name']) && function_exists($app[$key])){
    return $app[$key];
  }
}


/**
 * default demo content enabled callback
 * 
 * check to see if the apps demo content module is enabled
 */
function apps_demo_content_enabled($app) {
  return (module_exists($app['demo content module']));
}

/**
 * default demo content enable callback
 * 
 * enables the app's demo content module
 * PARAM $app: an app array
 * RETURN : bool if the module was enabled
 */
function apps_demo_content_enable($app) {
  $success = module_enable(array($app['demo content module']));
  drupal_flush_all_caches();
  return $success;
}

/**
 * default demo content disable callback
 * 
 * disables the app's demo content module
 * PARAM $app: an app array
 * RETURN : bool if the module was disabled
 */
function apps_demo_content_disable($app) {
  $success = module_disable(array($app['demo content module']));
  drupal_flush_all_caches();
  return !apps_demo_content_enabled($app);
}

/**
 * Form callback for demo content
 */
function apps_demo_content_form($form, &$form_state, $app) {
  $form = array();
  $cb = apps_app_callback($app, 'demo content enabled callback');
  $enabled = $cb($app);
  $form['demo_content_group'] = array(
    '#type' => 'fieldset',
    '#title' => "Demo Content for {$app['name']}",
  );
  $form['demo_content_group']['demo_content_current'] = array(
    '#markup' => $app['demo content description']. " <i>Demo content for {$app['name']} is currently " . ($enabled ? 'enabled' : 'disabled') . ".</i><br /><br />",
  );
  $form['demo_content_action'] = array(
    '#type' => 'value',
    '#value' => !$enabled,
  );
  $form['app'] = array(
    '#type' => 'value',
    '#value' => $app
  );

  $form['demo_content_group']['demo_content_button'] = array(
    '#type' => 'button',
    '#value' => !$enabled ? t('Enable Demo Content') : t('Disable Demo Content'),
    '#submit' => array('apps_demo_content_form_submit'),
    '#executes_submit_callback' => TRUE,
  );
  return $form;
}

/**
 * Submit handler for demo content form
 */
function apps_demo_content_form_submit($form, &$form_state) {
  $app = $form_state['values']['app'];
  $enable = $form_state['values']['demo_content_action'];
  if($enable) {
     $cb = apps_app_callback($app, 'demo content enable callback'); 
     $success = $cb($app);
     if($success) {
       drupal_set_message("Enabled demo content for {$app['name']}");
     }
  }
  else {
     $cb = apps_app_callback($app, 'demo content disable callback'); 
     $success = $cb($app);
     if($success) {
       drupal_set_message("Disabled demo content for {$app['name']}");
     }
  }
}


