<?php
/**
 * @file
 * Distributed Blocks module drush integration.
 */

/**
 * Implementation of hook_drush_command().
 *
 * @see drush_parse_command()
 *
 * @return
 *   An associative array describing your command(s).
 */
function distributed_blocks_drush_command() {

  $items['distrib-blocks-fetch-blocks'] = array(
    'description' => "Update distributed blocks from the master site.",
    'drupal dependencies' => array('distributed_blocks'),
    'aliases' => array('db-fetch-blocks'),
  );

  return $items;
}

/**
 * Drush implementation of the fetch all blocks method.
 */
function drush_distributed_blocks_distrib_blocks_fetch_blocks() {
  $res = distributed_blocks_fetch_blocks();

  if (!$res['status']) {
    drush_set_error('DISTRIB_BLOCKS_FETCH', $res['message']);
  }
  else {
    drush_log($res['message'], 'success');
  }
}
