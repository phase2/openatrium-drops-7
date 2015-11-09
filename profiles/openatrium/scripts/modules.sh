#!/bin/bash
# Script to list modules that need to be updated
#
if [ $# -eq 0 ]; then
  echo "Usage $0 [-d] [-p] [-f] [module]"
  echo "  -d shows the current git description"
  echo "  -p pulls the latest code"
  echo "  -r tag a new release of the module"
  echo "  -f force module into local directory"
  echo "  [module] specifies specific module, or if omitted, all modules are processed"
  exit 1
fi
RED="\033[0;31m"
YELLOW="\033[0;33m"
NORMAL="\033[0;0m"

CURRENT=`pwd -P`
LOGFILE="$CURRENT/release.txt"
PULL=0
DESCRIBE=0
FORCE=0
RELEASE=0
while getopts ":pdfr" opt; do
  case $opt in
    p) # pull repo
      PULL=1
      ;;
    d) # describe
      DESCRIBE=1
      ;;
    f) # force
      FORCE=1
      ;;
    r) # release
      RELEASE=1
      ;;
    ?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done
shift $((OPTIND-1))
echo 'Checking modules...'
submodules=(
  "oa_core"
  "oa_discussion"
  "oa_events"
  "oa_wiki"
  "oa_worktracker"
  "oa_admin"
  "oa_analytics"
  "oa_appearance"
  "oa_archive"
  "oa_brand"
  "oa_clone"
  "oa_comment"
  "oa_contextual_tabs"
  "oa_devel"
  "oa_domains"
  "oa_export"
  "oa_events_import"
  "oa_favorites"
  "oa_files"
  "oa_home"
  "oa_htmlmail"
  "oa_mailhandler"
  "oa_markdown"
  "oa_media"
  "oa_messages_digest"
  "oa_notifications"
  "oa_related"
  "oa_sandbox"
  "oa_search"
  "oa_sitemap"
  "oa_styles"
  "oa_subspaces"
  "oa_toolbar"
  "oa_tour"
  "oa_tour_defaults"
  "oa_wizard"
  "oa_radix"
  "bootstrap_tour"
  "command_buttons"
  "contextual_tabs"
  "oa_angular"
  "openatrium"
)
TARGET=$1
# Make sure we have a target directory
if [ ! -z "$1" ]; then
  # if module is specified, then just use that instead of full list
  submodules=("$1")
fi

for module in "${submodules[@]}"
do
  TARGET=''
  # first look in local modules dir
  if [ -e modules ]; then
    TARGET=`find modules -type d -name "$module" -print -quit`
  fi
  # if not found and not forced, look for other subdirs
  if [ -z $TARGET ]; then
    if [ $FORCE = 0 ]; then
      TARGET=`find . -type d -name "$module" -print -quit`
    fi
  fi
  if [ ! -e "$TARGET/.git" ]; then
    # repo not found, so create it if pulling
    if [ $PULL = 1 ]; then
      if [ ! -e "modules" ]; then
        mkdir modules
      fi
      cd modules
      git clone git@git.drupal.org:project/"$module".git
      cd "$module"
      TARGET=`pwd -P`
      cd $CURRENT
    fi
  fi

  if [ -e "$TARGET/.git" ]; then
    cd $TARGET
    if [ $PULL = 1 -o $RELEASE = 1 ]; then
      echo "Pulling $module"
      git fetch --tags
      if [ $module = "openatrium" ]; then
        # if pulling main distro, do a rebase
        git pull --rebase
      else
        git pull origin
      fi
    fi

    if [ $DESCRIBE = 1 ]; then
      status=`git status --porcelain --untracked-files=no`
      tag=`git describe --tags`
      old_tag=`git describe --abbrev=0 --tags`
      if [ ! "$status" = "" ]; then
        printf "$RED$module: $tag (DIRTY)$NORMAL\n"
      elif [ "$tag" = "$old_tag" ]; then
        echo "$module: $tag"
      else
        printf "$YELLOW$module: $tag$NORMAL\n"
      fi
    fi

    if [ $RELEASE = 1 ]; then
      full_tag=`git describe --tags`
      old_tag=`git describe --abbrev=0 --tags`
      if [ "$full_tag" = "$old_tag" ]; then
        echo "$module $full_tag : no release is needed"
      else
        # increment and release new tag
        new_tag="${old_tag/-beta/-beta.}"
        new_tag="${new_tag/-alpha/-alpha.}"
        new_tag="${new_tag/-rc/-rc.}"
        # http://stackoverflow.com/questions/8653126/how-to-increment-version-number-in-a-shell-script
        new_tag=$(echo $new_tag | \
          awk -F"." '{$NF+=1}{print $0RT}' OFS="." ORS="") #increments $old_tag
        new_tag="${new_tag/-beta./-beta}"
        new_tag="${new_tag/-alpha./-alpha}"
        new_tag="${new_tag/-rc./-rc}"

        if [ ! "$old_tag" = "$new_tag" ]; then
          echo "$module: Tagging with $new_tag"
          git tag $new_tag
          git push origin tag $new_tag
          notes=$(drush rn $old_tag $new_tag)
          # use printf instead of echo to handle multiline
          printf "$notes\n"
          name=$(grep "name =" "$module".info | sed "s/name = //")
          echo "<h4>$name $new_tag</h4>" >> $LOGFILE
          # pull out just the list of changes
          # trick to convert \n to \r so sed sees the entire thing as one line
          changes=$(printf "$notes\n" | tr '\n' '\r' | sed 's/.*\(<ul>.*<\/ul>\).*/\1/'  | tr '\r' '\n')
          printf "$changes\n" >> $LOGFILE
          echo "" >> $LOGFILE
        fi
      fi
    fi
  fi
  cd $CURRENT
done
