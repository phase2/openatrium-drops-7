#!/bin/sh
# Script to build OpenAtrium 2.x
# Make sure the correct number of args was passed from the command line
if [ $# -eq 0 ]; then
  echo "Usage $0 [-d] target_build_dir"
  exit 1
fi
DEV_BUILD=0
while getopts ":d" opt; do
  case $opt in
    d) # dev arguments
      DRUSH_OPTS='--working-copy --no-gitinfofile --no-cache'
      MAKEFILE='build-openatrium-dev.make'
      DEV_BUILD=1
      ;;
    r) # release arg
      MAKEFILE='build-openatrium-release.make'
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done
shift $((OPTIND-1))
TARGET=$1
# Make sure we have a target directory
if [ -z "$TARGET" ]; then
  echo "Usage $0 target_build_dir"
  exit 2
fi
CURDIR=`pwd -P`
ORIG_TARGET=$TARGET
TARGET=$TARGET"__build"
CALLPATH=`dirname "$0"`
ABS_CALLPATH=`cd "$CALLPATH"; pwd -P`

echo '_______      ___'
echo '| ___ |     /  |'
echo '| | | |    /   |'
echo '| |_| |   / /| |'
echo '|____ |  / / | |'
echo '   OpenAtrium   '
echo '================'

set -e
if [ $DEV_BUILD -eq 1 ]; then
  echo "*** DEVELOPMENT BUILD ***"
fi
echo "Building to build dir: $TARGET"
echo 'Verifying make...'
drush verify-makefile
# Remove current drupal dir
if [ -e "$TARGET" ]; then
  echo 'Removing old build directory...'
  rm -rf "$TARGET"
fi
# Do the build
if [ $DEV_BUILD -eq 1 ]; then
# Dev version
  DRUSH_OPTS='--working-copy --no-gitinfofile --no-cache'
  # first build core
  MAKEFILE='drupal-org-core.make'
  echo "Building Drupal core..."
  drush make --prepare-install $DRUSH_OPTS "$ABS_CALLPATH/$MAKEFILE" "$TARGET"
  # now get the latest profile distro
  # now build the dev version
  cd "$TARGET"
  MAKEFILE='drupal-org-dev.make'
  echo "Building the profile -dev version..."
  drush make --yes --no-core $DRUSH_OPTS "$ABS_CALLPATH/$MAKEFILE" --contrib-destination=profiles/openatrium
  if [ -e "profiles/openatrium" ]; then
    cd "profiles/openatrium"
    echo "Downloading latest profile..."
    git init .
    git remote add --track 7.x-2.x origin http://git.drupal.org/project/openatrium.git
    git fetch
    git checkout 7.x-2.x
  fi
  cd $CURDIR
else
# Release version
  MAKEFILE='build-openatrium.make'
  DRUSH_OPTS='--no-cache --prepare-install'
  echo 'Running drush make...'
  drush make $DRUSH_OPTS "$ABS_CALLPATH/$MAKEFILE" "$TARGET"
fi
set +e
# check to see if drush make was successful by checking for oa_core module
if [ -e "$TARGET/profiles/openatrium/modules/contrib/oa_core" ]; then
  # Restore previous sites folder if build was successful
  if [ -e "$ORIG_TARGET/sites" ]; then
    echo "Restoring sites folder from: $ORIG_TARGET/sites"
    rm -rf "$TARGET/sites"
    mv "$ORIG_TARGET/sites" "$TARGET/sites"
  fi

  echo "Moving files to: $ORIG_TARGET"
  if [ -e "$ORIG_TARGET" ]; then
    rm -rf "$ORIG_TARGET"
  fi
  if [ -e "$ORIG_TARGET" ]; then
    echo "Error removing old files.  Please fix permissions."
    exit 1
  fi
  mv $TARGET $ORIG_TARGET
  DRUPAL=`cd "$ORIG_TARGET"; pwd -P`

  echo "Active site now in: $DRUPAL"

  # Copy libraries from profile into site libraries
  # Modules properly using Library API don't need this, but many modules
  # don't support libraries in the profile (like WYSIWYG)
  echo "Copying library files."
  rsync -r $DRUPAL/profiles/openatrium/libraries/ $DRUPAL/sites/all/libraries/

  if [ $DEV_BUILD -eq 1 ]; then
    echo 'Connecting to github -dev repositories.'
    ./add-remotes.sh $DRUPAL/profiles/openatrium
  fi

  if [ ! -e "$DRUPAL/sites/default/settings.php" ]; then
    echo "No settings.php file found"
    echo "Please run the install.php script to install Drupal and Open Atrium"
    exit 1
  fi

  # Clear caches and Run updates
  cd "$DRUPAL"
  echo 'Running updates...'
  drush updb -y;
  # @TODO Figure out why this cc all is needed
  drush cc drush;
  echo 'Reverting all features...'
  drush fra -y;
  echo 'Clearing caches...'
  drush cc all;
  echo 'Build completed successfully!'
else
  echo 'Error in build.'
  exit 2
fi
