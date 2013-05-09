#!/bin/bash

# Configuration variables
drupal_root="/opt/development/integration/drupal"
backup_dest="/opt/backups"
dbname="oa-integration.sql"

# Make sure the backup directory is available
if [ ! -d ${backup_dest} ]; then
	  echo backup_dest="/opt/development/integration"
  fi

  # Make sure the backup directory is available
  if [ ! -d ${backup_dest} ]; then
	    echo "Backup directory /opt/backups is missing or not writeable... exiting."; exit 1
    else
	      echo "Starting integration db dump"
      fi

      # Dump our SQL DATABASE
      drush -r ${drupal_root} sql-dump > ${backup_dest}/${dbname}

      echo "Backup for integratoin created: ${backup_dest}/${dbname}"
