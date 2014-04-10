<?php
/**
  * @file
  *   drush integration for imagesloaded.
  */

 /**
  * The URI to the jReject library.
  */
define('ZIP_DOWNLOAD_URI', 'https://codeload.github.com/TurnWheel/jReject/zip/master');

/*
 * Implements hook_drush_command().
 *
 * @return
 *  An associative array describing your command(s).
 */
function jreject_drush_command() {
  $items = array();
  $items['jreject-download'] = array(
    'callback' => 'jreject_drush_download',
    'description' => dt('Downloads the required jReject library from https://github.com/TurnWheel/jReject.'),
    'aliases' => array('jrdl'),
    'arguments' => array(
    ),
  );
  return $items;
}

/*
 * Defining drush command implementation.
 */
function jreject_drush_download(){
  if (function_exists('libraries_get_path')) {
    $path = libraries_get_path('jreject');
    if ($path === FALSE) {
      $path = 'sites/all/libraries/jreject';
    }
  }
  else {
    drupal_set_message(t('Please download and install Libraries API 2.x'));
  }

  // Create the path if it does not exist yet.
  if (!is_dir($path)) {
    drush_mkdir($path);
  }

  // Download the file and report back
  if (is_file($path . 'js/jquery.reject.js')) {
    drush_log('jReject already present. No download required.', 'ok');
    return TRUE;
  }
  //omg this is ugly
  elseif (drush_op('chdir', $path . "/..") && (drush_shell_exec('curl -O '. ZIP_DOWNLOAD_URI) || drush_shell_exec('wget --no-check-certificate ' . ZIP_DOWNLOAD_URI))
    && drush_shell_exec('unzip master') && drush_shell_exec('mv jReject-master/* jreject') && drush_shell_exec('rmdir jReject-master') && drush_shell_exec('rm master')
    ) {
    drush_log(dt('The latest jReject library has been downloaded to @path', array('@path' => $path)), 'success');
    return TRUE;
  }
  else {
    drush_log(dt('Drush was unable to download the jReject library to @path', array('@path' => $path)), 'error');
    return FALSE;
  }
}

/*
 * Implements drush_module_post_command().
 */
function drush_jreject_post_pm_enable() {
  $extensions = func_get_args();
  // Deal with comma delimited extension list.
  if (strpos($extensions[0], ',') !== FALSE) {
    $extensions = explode(',', $extensions[0]);
  }

  if (in_array('jreject', $extensions) && !drush_get_option('skip')) {
    // First attempt to download the JS library.
    jreject_drush_download();
  }
}

/*
 * Implements hook_drush_help().
 *
 * @param
 *  A string with the help section (prepend with 'drush:')
 * @return
 *  A string with the help text for your command.
 */
function jreject_drush_help($section) {
  switch ($section) {
    case 'drush:jreject-download':
      return dt("Downloads the jReject library from https://github.com/TurnWheel/jReject. You'll need an unzip program accessible from the path for this to work.");
  }
}