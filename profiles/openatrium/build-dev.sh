#!/bin/sh
# Script to build OpenAtrium 2.x
# Make sure the correct number of args was passed from the command line
#
# NOTE: This script is used internally by Phase2 to build a working
# environment that points to both drupal.org and to the public github
# repositories.  It is not intended for general use for production
# OA2 sites.  Use the regular build.sh script to build just from the
# drupal.org source
#
if [ $# -eq 0 ]; then
  echo "Usage $0 [-d] target_build_dir"
  exit 1
fi
DRUSH_OPTS='--working-copy --no-gitinfofile --no-cache'
MAKEFILE='build-openatrium.make'
TARGET=$1
# Make sure we have a target directory
if [ -z "$TARGET" ]; then
  echo "Usage $0 target_build_diri"
  exit 2
fi
CALLPATH=`dirname "$0"`
ABS_CALLPATH=`cd "$CALLPATH"; pwd -P`
BASE_PATH=`cd ..; pwd`

echo '_______      ___'
echo '| ___ |     /  |'
echo '| | | |    /   |'
echo '| |_| |   / /| |'
echo '|____ |  / / | |'
echo '   OpenAtrium   '
echo '================'

# Temp move settings
echo 'Backing up settings.php...'
mv "$TARGET/sites/default/settings.php" settings.php
set -e
echo 'Verifying make...'
drush verify-makefile
# Remove current drupal dir
echo 'Wiping Drupal directory...'
rm -rf "$TARGET"
# Do the build
echo 'Running drush make...'
drush make $DRUSH_OPTS "$ABS_CALLPATH/$MAKEFILE" "$TARGET"
set +e
# Build Symlinks
echo 'Setting up symlinks...'
DRUPAL=`cd "$TARGET"; pwd -P`
ln -s /opt/files/openatrium "$DRUPAL/sites/default/files"
# Restore settings
echo 'Restoring settings...'
ln -s "$BASE_PATH/settings.php" "$DRUPAL/sites/default/settings.php"

# Move libraries from profile into site libraries
# Modules properly using Library API don't need this, but many modules
# don't support libraries in the profile (like WYSIWYG)
mv $DRUPAL/profiles/openatrium/libraries $DRUPAL/sites/all/libraries

# Set up the github remotes
./add-remotes.sh $DRUPAL/profiles/openatrium
# Clear caches and Run updates
cd "$DRUPAL"
echo 'Clearing caches...'
drush cc all; drush cc all;
echo 'Running updates...'
drush updb -y;
# @TODO Figure out why this cc all is needed
drush cc drush;
echo 'Reverting all features...'
drush fra -y;
drush cc all;
echo 'Build complete.'
