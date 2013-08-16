<?php
/**
 * @file
 * opensanmateo_resp_images.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function opensanmateo_resp_images_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'custom.user.mobile';
  $breakpoints[] = 'custom.user.narrow';
  $breakpoints[] = 'custom.user.wide';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'opensanmateo_resp_images';
  $breakpoint_group->name = 'opensanmateo_resp_images';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['opensanmateo_resp_images'] = $breakpoint_group;

  return $export;
}
