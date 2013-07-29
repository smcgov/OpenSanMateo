#!/bin/sh

# Script to build a San Mateo platform development site
#
# This script offers two functions. Building a document root and symlinking this
# repo in as a profile and using this repo to build into the docroot area of the
# Acquia repo for deployment purposes.
#
# There is an assumption that the directory being built to exists outside of the
# directory containing the working copy of the repo. So, ./build.sh ../html rather
# than ./build.sh html (building inside the repo leads to recursion)
#

set -e # bail on a failed command

usage () {
  echo "Usage $0 target_build_dir [link]"
  echo "  Or $0 --acquia target_build_dir branch_to_build_to"
  echo "See comments at top of script for more information about script functionality"
}


# Make sure the correct number of args was passed from the command line
if [ $# -eq 0 ]; then
  usage
  exit 1
fi

CALLPATH=`dirname $0`
ABS_CALLPATH=`cd $CALLPATH; pwd`

# Added to get around curl SSL issues on Acquia
GIT_SSL_NO_VERIFY=true
export GIT_SSL_NO_VERIFY

MAKEFILE='sanmateo.make'
# Initialize variables based on target environment
if [ "$1" = "--acquia" ]; then
  DRUSH_OPTS=''
  TYPE='acquia'
  TARGET="$ABS_CALLPATH/../"
  BRANCH=$3
  NOMAKE=0
  GIT_REPO='git@bitbucket.org:phase2tech/sanmateo.git'
else
  #DRUSH_OPTS='--working-copy'
  TARGET=$1
fi

# Make sure we have a target directory
if [ -z "$TARGET" ]; then
  echo "Target directory invalid: $TARGET"
  usage
  exit 2
fi

if [ "$TYPE" = 'acquia' ]; then
  GITPULL=0
  if [ -d "$TARGET" ]; then
    echo Skipping clone, target build directory exists assuming this is the result of a previous clone and will pull to update
    GITPULL=1
  else
    # clone and checkout branch from acquia repo
    echo $GIT_REPO
    echo $TARGET
    git clone $GIT_REPO $TARGET
  fi

  cd $TARGET
  git checkout $BRANCH
  if [ $GITPULL ]; then
    git pull
  fi

  # copy in our profile (this is our source repo)
  PROFILE_DIR=docroot/profiles

  if [ $NOMAKE -eq 1 ]; then
    rm -rf $PROFILE_DIR/sanmateo
  else
    # remove old docroot (we are going to rebuild this)
    if [ -d docroot ]; then
      rm -rf docroot
    fi

    # build site using our makefile
    drush make $DRUSH_OPTS $ABS_CALLPATH/$MAKEFILE docroot
  fi

  ln -s ../../profile/ $PROFILE_DIR/profile
  cp $ABS_CALLPATH/build/flag.ico docroot/misc/favicon.ico

  if [ $NOMAKE -eq 0 ]; then
    # remove git ignore placed by make
    rm -rf docroot/.gitignore

    # restore acquia sites folders except sites/all
    mv docroot/sites/all keep-the-new-sites-all
    git checkout HEAD docroot/sites
    rm -rf docroot/sites/all/modules/contrib
    rm -rf docroot/sites/all/libraries
    rm -rf docroot/sites/all/themes
    cp -r keep-the-new-sites-all/* docroot/sites/all
    rm -rf keep-the-new-sites-all

    cd docroot
    
    # Add directory-based sites as symlinks so we can use the same codebase
    #ln -s . site-dir
    
    cd ..
    sed -i.bak "/^ *RewriteEngine on/r $ABS_CALLPATH/build/htaccess_deny_drupal_text_files.txt" docroot/.htaccess
    rm docroot/.htaccess.bak
    sed -i.bak "/^ *RewriteEngine on/r $ABS_CALLPATH/build/htaccess_custom_redirects.txt" docroot/.htaccess
    rm docroot/.htaccess.bak
    sed -i.bak "s/^ *<IfModule mod_headers.c>/&\\n    Header append Vary Authorization env=AH_NON_PRODUCTION/" docroot/.htaccess
    rm docroot/.htaccess.bak
    cat $ABS_CALLPATH/build/htaccess_register_ie_mime_types.txt >> docroot/.htaccess
    #cp $ABS_CALLPATH/build/google58ce90b3ca3c2b88.html docroot/
    #add in password protection to
    echo AuthType Basic >> docroot/.htaccess
    echo AuthName \"Access Restricted\" >> docroot/.htaccess
    echo "# since staging and dev are on the same machine, this path will be available" >> docroot/.htaccess
    echo "# for both the staging and dev tiers and since that is the only place we are" >> docroot/.htaccess
    echo "# password protecting that is acceptable" >> docroot/.htaccess
    echo AuthUserFile /mnt/files/sanmateo/.htpasswd >> docroot/.htaccess
    echo Require valid-user >> docroot/.htaccess
    echo SetEnvIf AH_SITE_ENVIRONMENT prod SANMATEO_ALLOW_ACCESS=1 >> docroot/.htaccess
    echo Deny from All >> docroot/.htaccess
    echo Allow from env=SANMATEO_ALLOW_ACCESS >> docroot/.htaccess
    echo Satisfy Any >> docroot/.htaccess
  fi

  # add for commit
  #git add -A .
  echo "Automatic committing and pushing of Acquia repo not yet enabled"
  echo "Please go to $TARGET, confirm build results are as desired, then add, commit and push"
  #git commit -a -m "$MESSAGE"
  #git push

  #clean up temp space
  #cd ../
  #rm -rf $TARGET
else
  # Do the build
  drush make $DRUSH_OPTS $CALLPATH/$MAKEFILE $TARGET
  echo "drush make $DRUSH_OPTS $CALLPATH/$MAKEFILE $TARGET"
  echo $TARGET
  DRUPAL=`cd $TARGET; pwd`
  ln -s $ABS_CALLPATH $DRUPAL/profiles/sanmateo
  cp $ABS_CALLPATH/build/flag.ico $DRUPAL/misc/favicon.ico
  if [ "$2" = "link" ]; then
    cd $DRUPAL/sites/default && ln -s ../../../settings.php && ln -s ../../../files
  fi
  cat $ABS_CALLPATH/build/htaccess_register_ie_mime_types.txt >> $DRUPAL/.htaccess
fi

