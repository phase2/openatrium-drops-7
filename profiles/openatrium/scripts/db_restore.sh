#!/bin/bash

# Configuration variables
backup_file="/opt/backups/oa-integration.sql"

# Check if file exists
if [ ! -f ${backup_file} ]; then
	  backup_file="/opt/development/integration/oa-integration.sql"
  fi

  # Check if file exists
  if [ ! -f ${backup_file} ]; then
	    echo "No backupfile exists, please run db_dump first."; exit 1
    fi

    cd ../drupal

    echo "Restoring db from ${backup_file}"

    # remove current tables
    `drush sql-connect` -e "show tables" -s | xargs -I "@@" `drush sql-connect` -e "DROP TABLE @@"

    # perform import
    `drush sql-connect` < ${backup_file}

    echo "Database restored."
