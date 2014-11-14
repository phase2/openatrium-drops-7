#!/bin/bash
# Script to add create a new release
#
if [ $# -eq 0 ]; then
  echo "Usage $0 version"
  echo "e.g. $0 2.14 (do not add the 7.x part)"
  exit 1
fi
VERSION=$1
DRUPAL_VERSION="7.x-"$VERSION
# first, patch the openatrium.info file with version
echo "Patching version info..."
sed -i "s/version = .*/version = \"$DRUPAL_VERSION\"/" openatrium.info
git commit -a -m "Updating version info"
git push origin 7.x-2.x
echo "Creating tag...$DRUPAL_VERSION"
git checkout 7.x-2.x
git tag $DRUPAL_VERSION
git push origin tag $DRUPAL_VERSION
echo "Release complete!"
