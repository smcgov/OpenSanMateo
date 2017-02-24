<?php
/**
 * @file
 * opensanmateo_sharethis.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opensanmateo_sharethis_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_blog_entry_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_blog_entry_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_button_option';
  $strongarm->value = 'stbc_large';
  $export['sharethis_button_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_comments';
  $strongarm->value = 0;
  $export['sharethis_comments'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_document_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_document_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_event_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_event_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_fastshare';
  $strongarm->value = 1;
  $export['sharethis_fastshare'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_late_load';
  $strongarm->value = 1;
  $export['sharethis_late_load'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_location';
  $strongarm->value = 'content';
  $export['sharethis_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_location_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_location_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_media_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_media_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_node_option';
  $strongarm->value = 'blog_entry,0,0,0,0,0,0,0,0,0';
  $export['sharethis_node_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_node_types';
  $strongarm->value = array(
    'blog_entry' => 'blog_entry',
    'document' => 'document',
    'event' => 'event',
    'location' => 'location',
    'media' => 'media',
    'press_release' => 'press_release',
    'site_page' => 'site_page',
    'profile' => 0,
    'services' => 0,
    'sitecrawler_page' => 0,
    'webform' => 0,
  );
  $export['sharethis_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras';
  $strongarm->value = array(
    'Google Plus One:plusone' => 0,
    'Facebook Like:fblike' => 0,
    'Facebook Recommend:fbrec' => 0,
    'Facebook Send:fbsend' => 0,
  );
  $export['sharethis_option_extras'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_fbsub';
  $strongarm->value = array(
    'Facebook Subscribe:fbsub' => 0,
  );
  $export['sharethis_option_extras_fbsub'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_fbsub_field';
  $strongarm->value = '';
  $export['sharethis_option_extras_fbsub_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_foursquarefollow';
  $strongarm->value = array(
    'Foursquare Follow:foursquarefollow' => 0,
  );
  $export['sharethis_option_extras_foursquarefollow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_foursquarefollow_field';
  $strongarm->value = '';
  $export['sharethis_option_extras_foursquarefollow_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_foursquarefollow_field2';
  $strongarm->value = '';
  $export['sharethis_option_extras_foursquarefollow_field2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_foursquaresave';
  $strongarm->value = array(
    'Foursquare Save:foursquaresave' => 0,
  );
  $export['sharethis_option_extras_foursquaresave'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_pinterestfollow';
  $strongarm->value = array(
    'Pinterest Follow:pinterestfollow' => 0,
  );
  $export['sharethis_option_extras_pinterestfollow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_pinterestfollow_field';
  $strongarm->value = '';
  $export['sharethis_option_extras_pinterestfollow_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_twitterfollow';
  $strongarm->value = array(
    'Twitter Follow:twitterfollow' => 0,
  );
  $export['sharethis_option_extras_twitterfollow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_twitterfollow_field';
  $strongarm->value = '';
  $export['sharethis_option_extras_twitterfollow_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_youtube';
  $strongarm->value = array(
    'YouTube Follow:youtube' => 0,
  );
  $export['sharethis_option_extras_youtube'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_extras_youtube_field';
  $strongarm->value = '';
  $export['sharethis_option_extras_youtube_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_neworzero';
  $strongarm->value = 0;
  $export['sharethis_option_neworzero'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_onhover';
  $strongarm->value = 1;
  $export['sharethis_option_onhover'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_servicepopup';
  $strongarm->value = 0;
  $export['sharethis_option_servicepopup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_option_shorten';
  $strongarm->value = 1;
  $export['sharethis_option_shorten'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_press_release_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_press_release_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_profile_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_profile_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_publisherID';
  $strongarm->value = '14d67d33-cb3a-4433-a608-837e83e1b295';
  $export['sharethis_publisherID'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_services_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_services_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_service_option';
  $strongarm->value = '"Email:email","Facebook:facebook","Google +:googleplus","LinkedIn:linkedin","Pinterest:pinterest","Tweet:twitter","Yammer:yammer"';
  $export['sharethis_service_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_sitecrawler_page_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_sitecrawler_page_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_site_page_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_site_page_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_teaser_option';
  $strongarm->value = 1;
  $export['sharethis_teaser_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_twitter_handle';
  $strongarm->value = 'sanmateoco';
  $export['sharethis_twitter_handle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_twitter_prefix';
  $strongarm->value = '';
  $export['sharethis_twitter_prefix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_twitter_recommends';
  $strongarm->value = '';
  $export['sharethis_twitter_recommends'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_twitter_suffix';
  $strongarm->value = '#sanmateocounty';
  $export['sharethis_twitter_suffix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_webform_options';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'diff_standard' => 0,
    'token' => 0,
  );
  $export['sharethis_webform_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_weight';
  $strongarm->value = '10';
  $export['sharethis_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sharethis_widget_option';
  $strongarm->value = 'st_direct';
  $export['sharethis_widget_option'] = $strongarm;

  return $export;
}
