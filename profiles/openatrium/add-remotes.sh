#!/bin/bash
# Script to add the remote Github repos for dev versions
# of Open Atrium submodules
#
TARGET=$1
# Use current dir as default
if [ -z "$TARGET" ]; then
  TARGET=`pwd -P`
fi
echo 'Adding remotes...'
submodules=( "oa_core" "oa_discussion" "oa_wiki" "oa_events" "oa_events_import" "oa_contextual_tabs" "oa_notifications" "oa_media" "oa_subspaces" )
for subdir in "${submodules[@]}"
do
  cd $TARGET/modules/contrib/$subdir
  # rename default Drupal git repo created by drush make
  git remote rename origin drupal
  # add Phase2 dev repo as origin
  git remote add --track 7.x-2.x origin git@github.com:phase2/$subdir.git
  # pull latest code from Phase2 dev
  git pull origin 7.x-2.x
done
subthemes=( "oa_radix" )
for subdir in "${subthemes[@]}"
do
  cd $TARGET/themes/$subdir
  # rename default Drupal git repo created by drush make
  git remote rename origin drupal
  # add Phase2 dev repo as origin
  git remote add --track 7.x-2.x origin git@github.com:phase2/$subdir.git
  # pull latest code from Phase2 dev
  git pull origin 7.x-2.x
done

