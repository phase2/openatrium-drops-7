#!/bin/sh
CURDIR=`pwd -P`
shift $((OPTIND-1))
TARGET=$1
if [ -z "$TARGET" ]; then
  echo "Usage $0 target directory"
  exit 2
fi
PATTERN=${2:-*}

cd $TARGET
TARGET=`pwd -P`;

# Find make files, very
for DIRECTORY in $PATTERN/; do
  DIRECTORY_SANS_SLASH=${DIRECTORY%/};
  MAKE_FILE="$DIRECTORY$DIRECTORY_SANS_SLASH.make"
  if [ -f $MAKE_FILE ]; then
    echo "Verifying $MAKE_FILE";
    drush verify-makefile $MAKE_FILE
   fi
done
cd $CURDIR;