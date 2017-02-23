<?php

/**
 * @file
 * Helper test case for cloning an existing Drupal configuration.
 */

/**
 * Clone existing Drupal instance.
 */
class SimpleTestCloneTestCase extends DrupalWebTestCase {

  /**
   * Tables listed in this array will not have data copied, only table
   * structure. This is so that sites with large amounts of data can still be
   * tested to a certain extent, without having the tests run on forever while
   * the tables are copied over.
   */
  protected $excludeTables = array(
    'cache',
    'cache_block',
    'cache_bootstrap',
    'cache_field',
    'cache_filter',
    'cache_form',
    'cache_image',
    'cache_menu',
    'cache_page',
    'cache_path',
    'cache_update',
    'watchdog',
  );

  /**
   * Don't create test db via install, instead copy existing db.
   */
  protected function setUp() {
    // Copy of parent::setUp();
    global $user, $language, $language_url, $conf;

    // Generate a temporary prefixed database to ensure that tests have a clean starting point.
    $this->databasePrefix = 'simpletest' . mt_rand(1000, 1000000);
    db_update('simpletest_test_id')
      ->fields(array('last_prefix' => $this->databasePrefix))
      ->condition('test_id', $this->testId)
      ->execute();

    // Store necessary current values before switching to prefixed database.
    $this->originalLanguage = $language;
    $this->originalLanguageUrl = $language_url;
    $this->originalLanguageDefault = variable_get('language_default');
    $this->originalFileDirectory = variable_get('file_public_path', conf_path() . '/files');
    $this->originalProfile = drupal_get_profile();
    $clean_url_original = variable_get('clean_url', 0);

    // Save and clean shutdown callbacks array because it static cached and
    // will be changed by the test run. If we don't, then it will contain
    // callbacks from both environments. So testing environment will try
    // to call handlers from original environment.
    $callbacks = &drupal_register_shutdown_function();
    $this->originalShutdownCallbacks = $callbacks;
    $callbacks = array();

    // Create test directory ahead of installation so fatal errors and debug
    // information can be logged during installation process.
    // Use temporary files directory with the same prefix as the database.
    $this->public_files_directory  = $this->originalFileDirectory . '/simpletest/' . substr($this->databasePrefix, 10);
    $this->private_files_directory = $this->public_files_directory . '/private';
    $this->temp_files_directory    = $this->private_files_directory . '/temp';

    // Create the directories
    file_prepare_directory($this->public_files_directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    file_prepare_directory($this->private_files_directory, FILE_CREATE_DIRECTORY);
    file_prepare_directory($this->temp_files_directory, FILE_CREATE_DIRECTORY);
    $this->generatedTestFiles = FALSE;

    // Log fatal errors.
    ini_set('log_errors', 1);
    ini_set('error_log', $this->public_files_directory . '/error.log');

    // Set the test information for use in other parts of Drupal.
    $test_info = &$GLOBALS['drupal_test_info'];
    $test_info['test_run_id'] = $this->databasePrefix;
    $test_info['in_child_site'] = FALSE;

    // Rebuild schema based on prefixed database and such.
    $schemas = drupal_get_schema(NULL, TRUE);
    // Create a list of prefixed source table names.
    $sources = array();
    foreach ($schemas as $name => $schema) {
      $sources[$name] = Database::getConnection()->prefixTables('{' . $name . '}');
    }

    // Clone the current connection and replace the current prefix.
    $connection_info = Database::getConnectionInfo('default');
    Database::renameConnection('default', 'simpletest_original_default');
    foreach ($connection_info as $target => $value) {
      $connection_info[$target]['prefix'] = array(
        'default' => $value['prefix']['default'] . $this->databasePrefix,
      );
    }
    Database::addConnectionInfo('default', 'default', $connection_info['default']);

    // Clone each table into the new database.
    foreach ($schemas as $name => $schema) {
      $this->cloneTable($name, $sources[$name], $schema);
    }

    // Log in with a clean $user.
    $this->originalUser = $user;
    drupal_save_session(FALSE);
    $user = user_load(1);

    // Set up English language.
    unset($GLOBALS['conf']['language_default']);
    $language_url = $language = language_default();

    // Use the test mail class instead of the default mail handler class.
    variable_set('mail_system', array('default-system' => 'TestingMailSystem'));

    drupal_set_time_limit($this->timeLimit);
    $this->resetAll();
    $this->refreshVariables();
    $this->setup = TRUE;
  }

  /**
   * Mirror over an existing tables structure, and copy the data.
   *
   * @param $name
   *   Table name.
   * @param $schema
   *   A Schema API definition array.
   * @return
   *   Array of table creation results.
   */
  protected function cloneTable($name, $source, $schema) {
    db_create_table($name, $schema);

    $target = Database::getConnection()->prefixTables('{' . $name . '}');
    if (!in_array($name, $this->excludeTables)) {
      // Explicitly name fields since the order of fields can vary
      // (particularly in CCK) from that specified in the schema array.
      $fields = implode(', ', array_keys($schema['fields']));
      db_query("INSERT INTO $target ($fields) SELECT $fields FROM $source");
    }
  }
}
