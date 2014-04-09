#!/bin/bash
# Script to add the remote Github repos for dev versions
# of Open Atrium submodules
#
TARGET=$1
# Use current dir as default
if [ -z "$TARGET" ]; then
  TARGET=`pwd -P`
fi
TARGET=`cd "$TARGET"; pwd -P`
echo 'Adding remotes...'
submodules=( "oa_core" "oa_discussion" "oa_wiki" "oa_events" "oa_events_import" "oa_contextual_tabs" "oa_notifications" "oa_media" "oa_subspaces" )
for subdir in "${submodules[@]}"
do
  if [ -e "$TARGET/modules/contrib/$subdir/.git" ]; then
    cd $TARGET/modules/contrib/$subdir
    echo "** Pulling -dev version of module $subdir in $CURDIR"
    # rename default Drupal git repo created by drush make
    git remote rename origin drupal
    # add Phase2 dev repo as origin
    git remote add --track 7.x-2.x origin git@github.com:phase2/$subdir.git
    # pull latest code from Phase2 dev
    git pull origin 7.x-2.x
  else
    echo "** No git repository found for module $subdir"
  fi
done
subthemes=( "oa_radix" )
for subdir in "${subthemes[@]}"
do
  if [ -e "$TARGET/themes/$subdir/.git" ]; then
    cd $TARGET/themes/$subdir
    echo "** Pulling -dev version of theme $subdir in $CURDIR"
    # rename default Drupal git repo created by drush make
    git remote rename origin drupal
    # add Phase2 dev repo as origin
    git remote add --track 7.x-2.x origin git@github.com:phase2/$subdir.git
    # pull latest code from Phase2 dev
    git pull origin 7.x-2.x
  else
    echo "** No git repository found for theme $subdir"
  fi
done

