#!/bin/bash

COMMAND=$1
BUILD_TOP=`dirname $TRAVIS_BUILD_DIR`
EXIT_VALUE=0

export PATH="$HOME/.composer/vendor/bin:$PATH"
export DISPLAY=:99.0
export CHROME_SANDBOX=/opt/google/chrome/chrome-sandbox

##
# SCRIPT COMMANDS
##

# system-install
#
# This is meant to setup the server on Travis-CI so that it can run the tests.
#
system_install() {
  # Add the Google Chrome packages.
  header Setting up APT
  wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add -
  sudo sh -c 'echo "deb http://dl.google.com/linux/chrome/deb/ stable main" >> /etc/apt/sources.list.d/google.list'
  sudo apt-get update > /dev/null

  # Create a database for our Drupal site.
  mysql -e 'create database drupal;'

  # Install the latest Drush 6.
  header Installing Drush
  composer global require --prefer-source --no-interaction drush/drush:6.*
  drush dl -y drupalorg_drush-7.x-1.x-dev --destination=$HOME/.drush
  drush cc drush

  # Build Codebase
  mkdir profiles
  mv openatrium profiles/
  mkdir drupal
  mv profiles drupal/

  # Build the current branch.
  header Building Open Atrium from current branch
  cd drupal
  pwd
  drush make --yes profiles/openatrium/drupal-org-core.make --prepare-install
  drush make --yes profiles/openatrium/scripts/oa-drush6-dev.make --no-core --contrib-destination=profiles/openatrium
  drush dl panopoly_demo-7.x-1.x-dev
  mkdir sites/default/files
  mkdir sites/default/files/private
  mkdir sites/default/files/temp

  # Build Behat dependencies
  header Installing Behat
  cd profiles/openatrium/modules/panopoly/panopoly_test/tests
  composer install --prefer-source --no-interaction
  cd ../../../../../../../

  # Verify that all the .make files will work on Drupal.org.
  header Verifying .make file
  #verify the release makefile instead
  #drush verify-makefile drupal/profiles/openatrium/drupal-org-dev.make
  drush verify-makefile drupal/profiles/openatrium/drupal-org.make
  find drupal/profiles/openatrium/modules -name \*.make -print0 | xargs -0 -n1 drush verify-makefile

  # Download an old version to test upgrading from.
  if [[ "$UPGRADE" != none ]]; then
    header Downloading Open Atrium $UPGRADE
    drush dl openatrium-$UPGRADE
  fi

  # Setup files
  sudo chmod -R 777 drupal/sites/all

  # Setup display for Selenium
  header Starting X
  sh -e /etc/init.d/xvfb start
  sleep 5

  # Get Chrome and ChromeDriver
  header Installing Google Chrome
  sudo apt-get install google-chrome-stable
  wget http://chromedriver.storage.googleapis.com/2.9/chromedriver_linux64.zip
  unzip -a chromedriver_linux64.zip

  # Insane hack from jsdevel:
  #   https://github.com/jsdevel/travis-debugging/blob/master/shim.bash
  # This allows chrome-sandbox to work in side of OpenVZ, because I can't
  # figure out how to start chrome with --no-sandbox.
  sudo rm -f $CHROME_SANDBOX
  sudo wget https://googledrive.com/host/0B5VlNZ_Rvdw6NTJoZDBSVy1ZdkE -O $CHROME_SANDBOX
  sudo chown root:root $CHROME_SANDBOX
  sudo chmod 4755 $CHROME_SANDBOX
  sudo md5sum $CHROME_SANDBOX

  # Get Selenium
  header Downloading Selenium
  wget http://selenium-release.storage.googleapis.com/2.41/selenium-server-standalone-2.41.0.jar
 
  # Disable sendmail
  echo sendmail_path=`which true` >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
}

# before_tests
#
# Setup Drupal to run the tests.
#
before_tests() {
  UPGRADE_DEMO_VERSION=`echo $UPGRADE | sed -e s/^7.x-//`

  # Do the site install (either the current revision or old for the upgrade).
  header Installing Drupal
  if [[ "$UPGRADE" == none ]]; then
    cd drupal
  else
    cd openatrium-$UPGRADE
    drush dl panopoly_demo-$UPGRADE_DEMO_VERSION
  fi
  drush si openatrium --db-url=mysql://root:@127.0.0.1/drupal --account-name=admin --account-pass=admin --site-mail=admin@example.com --site-name="Open Atrium" --yes
  drush dis -y dblog
  drush vset -y file_private_path "sites/default/files/private"
  drush vset -y file_temporary_path "sites/default/files/temp"

  # Switch to the Panopoly platform built from Git (if we aren't there already).
  cd ../drupal

  # If we're an upgrade test, run the upgrade process.
  if [[ "$UPGRADE" != none ]]; then
    header Upgrading to latest version
    cp -a ../openatrium-$UPGRADE/sites/default/* sites/default/ && drush updb --yes
  fi
  drush cc all

  # Our tests depend on panopoly_demo.
  drush en -y panopoly_demo

  # Our tests depend on panopoly_test.
  drush en -y panopoly_test

  # Run the webserver
  header Starting webserver
  drush runserver --server=builtin 8888 > /dev/null 2>&1 &
  echo $! > /tmp/web-server-pid
  wait_for_port 8888
  sleep 3

  cd ..

  # Run the selenium server
  header Starting selenium
  java -jar selenium-server-standalone-2.41.0.jar -Dwebdriver.chrome.driver=`pwd`/chromedriver > /dev/null 2>&1 &
  echo $! > /tmp/selenium-server-pid
  wait_for_port 4444

  # Prime the site to prevent timeouts when the tests run
  wget -q -O - http://localhost:8888
  sleep 3
}

# before_tests
#
# Run the tests.
#
run_tests() {
  header Running tests

  # Make the Travis tests repos agnostic by injecting drupal_root with BEHAT_PARAMS
  export BEHAT_PARAMS="extensions[Drupal\\DrupalExtension\\Extension][drupal][drupal_root]=$BUILD_TOP/drupal"

  # cd drupal/profiles/openatrium/modules/contrib/oa_test/tests
  cd drupal/profiles/openatrium/modules/panopoly/panopoly_test/tests

  # If this isn't an upgrade, we test if any features are overridden.
  #if [[ "$UPGRADE" == none ]]; then
  #  run_test ../../../../scripts/check-overridden.sh
  #fi

  # First, run all the tests in Firefox.
  run_test ./bin/behat --config behat.travis.yml

  # Then run some Chrome-only tests.
  run_test ./bin/behat --config behat.travis.yml -p chrome
}

# after_tests
#
# Clean up after the tests.
#
after_tests() {
  header Cleaning up after tests

  WEB_SERVER_PID=`cat /tmp/webserver-server-pid`
  SELENIUM_SERVER_PID=`cat /tmp/selenium-server-pid`

  # Stop the servers we started
  kill $WEB_SERVER_PID
  kill $SELENIUM_SERVER_PID
}

##
# UTILITY FUNCTIONS:
##

# Prints a message about the section of the script.
header() {
  set +xv
  echo
  echo "** $@"
  echo
  set -xv
}

# Sets the exit level to error.
set_error() {
  EXIT_VALUE=1
}

# Runs a command and sets an error if it fails.
run_test() {
  if ! $@; then
    set_error
  fi
}

# Runs a command showing all the lines executed
run_command() {
  set -xv
  $@
  set +xv
}

# Wait for a specific port to respond to connections.
wait_for_port() {
  local port=$1
  while echo | telnet localhost $port 2>&1 | grep -qe 'Connection refused'; do
    echo "Connection refused on port $port. Waiting 5 seconds..."
    sleep 5
  done
}

##
# SCRIPT MAIN:
##

# Capture all errors and set our overall exit value.
trap 'set_error' ERR

# We want to always start from the same directory:
cd $BUILD_TOP

case $COMMAND in
  system-install)
    run_command system_install
    ;;

  drupal-install)
    run_command drupal_install
    ;;

  before-tests)
    run_command before_tests
    ;;

  run-tests)
    run_command run_tests
    ;;

  after-tests)
    run_command after_tests
    ;;
esac

exit $EXIT_VALUE
