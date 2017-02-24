<?php
/**
 * @file
 * opensanmateo_overrides.features.inc
 */

/**
 * Implements hook_context_default_contexts_alter().
 */
function opensanmateo_overrides_context_default_contexts_alter(&$data) {
  if (isset($data['profile_page'])) {
    unset($data['profile_page']->reactions['block']);
  }
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function opensanmateo_overrides_field_default_field_bases_alter(&$data) {
  if (isset($data['field_document_attachment'])) {
    $data['field_document_attachment']['settings']['display_default'] = 1; /* WAS: 0 */
  }
  if (isset($data['field_files'])) {
    $data['field_files']['settings']['display_default'] = 1; /* WAS: 0 */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function opensanmateo_overrides_field_default_field_instances_alter(&$data) {
  if (isset($data['file-image-field_summmary'])) {
    unset($data['file-image-field_summmary']);
  }
  if (isset($data['node-blog_entry-body'])) {
    $data['node-blog_entry-body']['widget']['weight'] = 1; /* WAS: 5 */
  }
  if (isset($data['node-blog_entry-field_author'])) {
    unset($data['node-blog_entry-field_author']);
  }
  if (isset($data['node-blog_entry-field_contact'])) {
    unset($data['node-blog_entry-field_contact']);
  }
  if (isset($data['node-blog_entry-field_custom_layout'])) {
    $data['node-blog_entry-field_custom_layout']['widget']['weight'] = 10; /* WAS: 36 */
  }
  if (isset($data['node-blog_entry-field_do_not_index'])) {
    $data['node-blog_entry-field_do_not_index']['widget']['weight'] = 11; /* WAS: 31 */
  }
  if (isset($data['node-blog_entry-field_event'])) {
    unset($data['node-blog_entry-field_event']);
  }
  if (isset($data['node-blog_entry-field_files'])) {
    $data['node-blog_entry-field_files']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-blog_entry-field_files']['widget']['weight'] = 5; /* WAS: 9 */
  }
  if (isset($data['node-blog_entry-field_govdelivery_topic_ref'])) {
    $data['node-blog_entry-field_govdelivery_topic_ref']['widget']['weight'] = 9; /* WAS: 37 */
  }
  if (isset($data['node-blog_entry-field_location_address'])) {
    unset($data['node-blog_entry-field_location_address']);
  }
  if (isset($data['node-blog_entry-field_quick_search'])) {
    $data['node-blog_entry-field_quick_search']['widget']['weight'] = 6; /* WAS: 32 */
  }
  if (isset($data['node-blog_entry-field_release_date'])) {
    $data['node-blog_entry-field_release_date']['widget']['settings']['display_all_day'] = 0; /* WAS: '' */
    $data['node-blog_entry-field_release_date']['widget']['weight'] = 2; /* WAS: 1 */
  }
  if (isset($data['node-blog_entry-field_sub_type'])) {
    unset($data['node-blog_entry-field_sub_type']);
  }
  if (isset($data['node-blog_entry-field_subject'])) {
    $data['node-blog_entry-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-blog_entry-field_subject']['widget']['weight'] = 8; /* WAS: 34 */
  }
  if (isset($data['node-blog_entry-field_thumbnail_image'])) {
    $data['node-blog_entry-field_thumbnail_image']['label'] = 'Main Image'; /* WAS: 'Thumbnail Image' */
    $data['node-blog_entry-field_thumbnail_image']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(
        'attach' => 0,
        'clipboard' => 0,
        'imce' => 0,
        'opensanmateo_search' => 0,
        'osmremotefile' => 0,
        'plupload' => 0,
        'reference' => 0,
        'remote' => 0,
      ),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['widget']['weight'] = 4; /* WAS: 11 */
    $data['node-blog_entry-field_thumbnail_image']['workbench_access_field'] = 0; /* WAS: '' */
  }
  if (isset($data['node-blog_entry-field_topic'])) {
    $data['node-blog_entry-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-blog_entry-field_topic']['widget']['weight'] = 7; /* WAS: 34 */
  }
  if (isset($data['node-document-body'])) {
    $data['node-document-body']['widget']['weight'] = 1; /* WAS: 2 */
  }
  if (isset($data['node-document-field_author'])) {
    unset($data['node-document-field_author']);
  }
  if (isset($data['node-document-field_contact'])) {
    unset($data['node-document-field_contact']);
  }
  if (isset($data['node-document-field_custom_layout'])) {
    $data['node-document-field_custom_layout']['widget']['weight'] = 9; /* WAS: 36 */
  }
  if (isset($data['node-document-field_do_not_index'])) {
    $data['node-document-field_do_not_index']['widget']['weight'] = 10; /* WAS: 31 */
  }
  if (isset($data['node-document-field_document_attachment'])) {
    $data['node-document-field_document_attachment']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(
        'attach' => 0,
        'clipboard' => 0,
        'imce' => 0,
        'opensanmateo_search' => 0,
        'osmremotefile' => 0,
        'plupload' => 0,
        'reference' => 0,
        'remote' => 0,
        'upload' => 'upload',
      ),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-document-field_document_attachment']['widget']['weight'] = 5; /* WAS: 3 */
  }
  if (isset($data['node-document-field_event'])) {
    unset($data['node-document-field_event']);
  }
  if (isset($data['node-document-field_govdelivery_topic_ref'])) {
    unset($data['node-document-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-document-field_location_address'])) {
    unset($data['node-document-field_location_address']);
  }
  if (isset($data['node-document-field_quick_search'])) {
    $data['node-document-field_quick_search']['widget']['weight'] = 6; /* WAS: 32 */
  }
  if (isset($data['node-document-field_sub_type'])) {
    unset($data['node-document-field_sub_type']);
  }
  if (isset($data['node-document-field_subject'])) {
    $data['node-document-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-document-field_subject']['widget']['weight'] = 8; /* WAS: 34 */
  }
  if (isset($data['node-document-field_topic'])) {
    $data['node-document-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-document-field_topic']['widget']['weight'] = 7; /* WAS: 34 */
  }
  if (isset($data['node-event-body'])) {
    $data['node-event-body']['widget']['weight'] = 1; /* WAS: 2 */
  }
  if (isset($data['node-event-field_contact'])) {
    unset($data['node-event-field_contact']);
  }
  if (isset($data['node-event-field_custom_layout'])) {
    $data['node-event-field_custom_layout']['widget']['weight'] = 10; /* WAS: 36 */
  }
  if (isset($data['node-event-field_do_not_index'])) {
    $data['node-event-field_do_not_index']['widget']['weight'] = 11; /* WAS: 31 */
  }
  if (isset($data['node-event-field_event'])) {
    unset($data['node-event-field_event']);
  }
  if (isset($data['node-event-field_event_calendar'])) {
    unset($data['node-event-field_event_calendar']);
  }
  if (isset($data['node-event-field_event_contact'])) {
    $data['node-event-field_event_contact']['widget']['weight'] = 5; /* WAS: 6 */
  }
  if (isset($data['node-event-field_event_date'])) {
    $data['node-event-field_event_date']['widget']['weight'] = 2; /* WAS: 1 */
  }
  if (isset($data['node-event-field_files'])) {
    $data['node-event-field_files']['widget']['weight'] = 4; /* WAS: 7 */
  }
  if (isset($data['node-event-field_govdelivery_topic_ref'])) {
    unset($data['node-event-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-event-field_location_address'])) {
    $data['node-event-field_location_address']['widget']['weight'] = 6; /* WAS: 34 */
  }
  if (isset($data['node-event-field_quick_search'])) {
    $data['node-event-field_quick_search']['widget']['weight'] = 7; /* WAS: 32 */
  }
  if (isset($data['node-event-field_sub_type'])) {
    unset($data['node-event-field_sub_type']);
  }
  if (isset($data['node-event-field_subject'])) {
    $data['node-event-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-event-field_subject']['widget']['weight'] = 9; /* WAS: 34 */
  }
  if (isset($data['node-event-field_topic'])) {
    $data['node-event-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-event-field_topic']['widget']['weight'] = 8; /* WAS: 34 */
  }
  if (isset($data['node-location-field_address'])) {
    $data['node-location-field_address']['widget']['weight'] = 2; /* WAS: 4 */
  }
  if (isset($data['node-location-field_contact'])) {
    unset($data['node-location-field_contact']);
  }
  if (isset($data['node-location-field_custom_layout'])) {
    $data['node-location-field_custom_layout']['widget']['weight'] = 9; /* WAS: 36 */
  }
  if (isset($data['node-location-field_do_not_index'])) {
    $data['node-location-field_do_not_index']['widget']['weight'] = 10; /* WAS: 31 */
  }
  if (isset($data['node-location-field_event'])) {
    unset($data['node-location-field_event']);
  }
  if (isset($data['node-location-field_files'])) {
    $data['node-location-field_files']['widget']['weight'] = 5; /* WAS: 8 */
  }
  if (isset($data['node-location-field_govdelivery_topic_ref'])) {
    unset($data['node-location-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-location-field_quick_search'])) {
    $data['node-location-field_quick_search']['widget']['weight'] = 6; /* WAS: 32 */
  }
  if (isset($data['node-location-field_sub_type'])) {
    unset($data['node-location-field_sub_type']);
  }
  if (isset($data['node-location-field_subject'])) {
    $data['node-location-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-location-field_subject']['widget']['weight'] = 8; /* WAS: 34 */
  }
  if (isset($data['node-location-field_thumbnail_image'])) {
    $data['node-location-field_thumbnail_image']['widget']['weight'] = 4; /* WAS: 10 */
  }
  if (isset($data['node-location-field_topic'])) {
    $data['node-location-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-location-field_topic']['widget']['weight'] = 7; /* WAS: 34 */
  }
  if (isset($data['node-media-body'])) {
    $data['node-media-body']['widget']['weight'] = 1; /* WAS: 3 */
  }
  if (isset($data['node-media-field_contact'])) {
    unset($data['node-media-field_contact']);
  }
  if (isset($data['node-media-field_custom_layout'])) {
    $data['node-media-field_custom_layout']['widget']['weight'] = 9; /* WAS: 36 */
  }
  if (isset($data['node-media-field_do_not_index'])) {
    $data['node-media-field_do_not_index']['widget']['weight'] = 10; /* WAS: 31 */
  }
  if (isset($data['node-media-field_event'])) {
    unset($data['node-media-field_event']);
  }
  if (isset($data['node-media-field_files'])) {
    $data['node-media-field_files']['widget']['weight'] = 5; /* WAS: 6 */
  }
  if (isset($data['node-media-field_govdelivery_topic_ref'])) {
    unset($data['node-media-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-media-field_image_collection'])) {
    $data['node-media-field_image_collection']['widget']['weight'] = 2; /* WAS: 4 */
  }
  if (isset($data['node-media-field_location_address'])) {
    unset($data['node-media-field_location_address']);
  }
  if (isset($data['node-media-field_quick_search'])) {
    $data['node-media-field_quick_search']['widget']['weight'] = 6; /* WAS: 32 */
  }
  if (isset($data['node-media-field_sub_type'])) {
    unset($data['node-media-field_sub_type']);
  }
  if (isset($data['node-media-field_subject'])) {
    $data['node-media-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-media-field_subject']['widget']['weight'] = 8; /* WAS: 34 */
  }
  if (isset($data['node-media-field_thumbnail_image'])) {
    $data['node-media-field_thumbnail_image']['widget']['weight'] = 4; /* WAS: 1 */
  }
  if (isset($data['node-media-field_topic'])) {
    $data['node-media-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-media-field_topic']['widget']['weight'] = 7; /* WAS: 34 */
  }
  if (isset($data['node-media-field_video'])) {
    $data['node-media-field_video']['widget']['weight'] = 3; /* WAS: 5 */
  }
  if (isset($data['node-press_release-body'])) {
    $data['node-press_release-body']['widget']['weight'] = 1; /* WAS: 4 */
  }
  if (isset($data['node-press_release-field_contact'])) {
    $data['node-press_release-field_contact']['widget']['weight'] = 5; /* WAS: 37 */
  }
  if (isset($data['node-press_release-field_custom_layout'])) {
    $data['node-press_release-field_custom_layout']['widget']['weight'] = 9; /* WAS: 36 */
  }
  if (isset($data['node-press_release-field_do_not_index'])) {
    $data['node-press_release-field_do_not_index']['widget']['weight'] = 10; /* WAS: 31 */
  }
  if (isset($data['node-press_release-field_event'])) {
    unset($data['node-press_release-field_event']);
  }
  if (isset($data['node-press_release-field_files'])) {
    $data['node-press_release-field_files']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-press_release-field_files']['widget']['weight'] = 4; /* WAS: 6 */
  }
  if (isset($data['node-press_release-field_govdelivery_topic_ref'])) {
    unset($data['node-press_release-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-press_release-field_location_address'])) {
    unset($data['node-press_release-field_location_address']);
  }
  if (isset($data['node-press_release-field_quick_search'])) {
    $data['node-press_release-field_quick_search']['widget']['weight'] = 6; /* WAS: 32 */
  }
  if (isset($data['node-press_release-field_sub_type'])) {
    unset($data['node-press_release-field_sub_type']);
  }
  if (isset($data['node-press_release-field_subject'])) {
    $data['node-press_release-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-press_release-field_subject']['widget']['weight'] = 8; /* WAS: 34 */
  }
  if (isset($data['node-press_release-field_thumbnail_image'])) {
    $data['node-press_release-field_thumbnail_image']['label'] = 'Main Image'; /* WAS: 'Thumbnail Image' */
    $data['node-press_release-field_thumbnail_image']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-press_release-field_thumbnail_image']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(
        'attach' => 0,
        'clipboard' => 0,
        'imce' => 0,
        'opensanmateo_search' => 0,
        'osmremotefile' => 0,
        'plupload' => 0,
        'reference' => 0,
        'remote' => 0,
      ),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-press_release-field_thumbnail_image']['widget']['weight'] = 3; /* WAS: 32 */
    $data['node-press_release-field_thumbnail_image']['workbench_access_field'] = 0; /* WAS: '' */
  }
  if (isset($data['node-press_release-field_topic'])) {
    $data['node-press_release-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-press_release-field_topic']['widget']['weight'] = 7; /* WAS: 34 */
  }
  if (isset($data['node-profile-body'])) {
    $data['node-profile-body']['widget']['weight'] = 3; /* WAS: 5 */
  }
  if (isset($data['node-profile-field_contact'])) {
    unset($data['node-profile-field_contact']);
  }
  if (isset($data['node-profile-field_custom_layout'])) {
    $data['node-profile-field_custom_layout']['widget']['weight'] = 14; /* WAS: 36 */
  }
  if (isset($data['node-profile-field_do_not_index'])) {
    $data['node-profile-field_do_not_index']['widget']['weight'] = 15; /* WAS: 31 */
  }
  if (isset($data['node-profile-field_event'])) {
    unset($data['node-profile-field_event']);
  }
  if (isset($data['node-profile-field_govdelivery_topic_ref'])) {
    unset($data['node-profile-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-profile-field_location_address'])) {
    unset($data['node-profile-field_location_address']);
  }
  if (isset($data['node-profile-field_profile_address'])) {
    unset($data['node-profile-field_profile_address']);
  }
  if (isset($data['node-profile-field_profile_department'])) {
    $data['node-profile-field_profile_department']['widget']['weight'] = 5; /* WAS: 14 */
  }
  if (isset($data['node-profile-field_profile_division'])) {
    $data['node-profile-field_profile_division']['display']['default']['weight'] = 6; /* WAS: 14 */
    $data['node-profile-field_profile_division']['widget']['weight'] = 6; /* WAS: 4 */
  }
  if (isset($data['node-profile-field_profile_email'])) {
    $data['node-profile-field_profile_email']['display']['default']['label'] = 'above'; /* WAS: 'hidden' */
    $data['node-profile-field_profile_email']['display']['default']['module'] = 'text'; /* WAS: '' */
    $data['node-profile-field_profile_email']['display']['default']['type'] = 'text_default'; /* WAS: 'hidden' */
    $data['node-profile-field_profile_email']['display']['default']['weight'] = 7; /* WAS: 10 */
  }
  if (isset($data['node-profile-field_profile_job_title'])) {
    $data['node-profile-field_profile_job_title']['widget']['weight'] = 7; /* WAS: 13 */
  }
  if (isset($data['node-profile-field_profile_leadership'])) {
    unset($data['node-profile-field_profile_leadership']);
  }
  if (isset($data['node-profile-field_profile_organization'])) {
    unset($data['node-profile-field_profile_organization']);
  }
  if (isset($data['node-profile-field_profile_phone'])) {
    $data['node-profile-field_profile_phone']['display']['default']['label'] = 'above'; /* WAS: 'hidden' */
    $data['node-profile-field_profile_phone']['display']['default']['module'] = 'text'; /* WAS: '' */
    $data['node-profile-field_profile_phone']['display']['default']['type'] = 'text_default'; /* WAS: 'hidden' */
    $data['node-profile-field_profile_phone']['display']['default']['weight'] = 8; /* WAS: 4 */
  }
  if (isset($data['node-profile-field_profile_photo'])) {
    $data['node-profile-field_profile_photo']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-profile-field_profile_photo']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-profile-field_profile_photo']['widget']['weight'] = 4; /* WAS: 6 */
  }
  if (isset($data['node-profile-field_profile_social_media'])) {
    $data['node-profile-field_profile_social_media']['widget']['weight'] = 10; /* WAS: 15 */
  }
  if (isset($data['node-profile-field_profile_staff'])) {
    unset($data['node-profile-field_profile_staff']);
  }
  if (isset($data['node-profile-field_profile_user'])) {
    unset($data['node-profile-field_profile_user']);
  }
  if (isset($data['node-profile-field_quick_search'])) {
    $data['node-profile-field_quick_search']['widget']['weight'] = 11; /* WAS: 32 */
  }
  if (isset($data['node-profile-field_sub_type'])) {
    unset($data['node-profile-field_sub_type']);
  }
  if (isset($data['node-profile-field_subject'])) {
    $data['node-profile-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-profile-field_subject']['widget']['weight'] = 13; /* WAS: 34 */
  }
  if (isset($data['node-profile-field_topic'])) {
    $data['node-profile-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-profile-field_topic']['widget']['weight'] = 12; /* WAS: 34 */
  }
  if (isset($data['node-services-body'])) {
    $data['node-services-body']['widget']['weight'] = 1; /* WAS: -4 */
  }
  if (isset($data['node-services-field_contact'])) {
    unset($data['node-services-field_contact']);
  }
  if (isset($data['node-services-field_custom_layout'])) {
    $data['node-services-field_custom_layout']['widget']['weight'] = 7; /* WAS: 36 */
  }
  if (isset($data['node-services-field_do_not_index'])) {
    $data['node-services-field_do_not_index']['widget']['weight'] = 8; /* WAS: 31 */
  }
  if (isset($data['node-services-field_event'])) {
    unset($data['node-services-field_event']);
  }
  if (isset($data['node-services-field_files'])) {
    $data['node-services-field_files']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-services-field_files']['widget']['weight'] = 3; /* WAS: 32 */
  }
  if (isset($data['node-services-field_govdelivery_topic_ref'])) {
    unset($data['node-services-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-services-field_location_address'])) {
    unset($data['node-services-field_location_address']);
  }
  if (isset($data['node-services-field_quick_search'])) {
    $data['node-services-field_quick_search']['widget']['weight'] = 4; /* WAS: 32 */
  }
  if (isset($data['node-services-field_services_photo'])) {
    $data['node-services-field_services_photo']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-services-field_services_photo']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-services-field_services_photo']['widget']['weight'] = 2; /* WAS: -3 */
  }
  if (isset($data['node-services-field_sub_type'])) {
    unset($data['node-services-field_sub_type']);
  }
  if (isset($data['node-services-field_subject'])) {
    $data['node-services-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-services-field_subject']['widget']['weight'] = 6; /* WAS: 34 */
  }
  if (isset($data['node-services-field_topic'])) {
    $data['node-services-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-services-field_topic']['widget']['weight'] = 5; /* WAS: 34 */
  }
  if (isset($data['node-site_page-body'])) {
    $data['node-site_page-body']['widget']['weight'] = 1; /* WAS: -3 */
  }
  if (isset($data['node-site_page-field_contact'])) {
    unset($data['node-site_page-field_contact']);
  }
  if (isset($data['node-site_page-field_custom_layout'])) {
    $data['node-site_page-field_custom_layout']['widget']['weight'] = 9; /* WAS: 36 */
  }
  if (isset($data['node-site_page-field_do_not_index'])) {
    $data['node-site_page-field_do_not_index']['widget']['weight'] = 10; /* WAS: 31 */
  }
  if (isset($data['node-site_page-field_event'])) {
    unset($data['node-site_page-field_event']);
  }
  if (isset($data['node-site_page-field_files'])) {
    $data['node-site_page-field_files']['settings']['description_field'] = 1; /* WAS: 0 */
    $data['node-site_page-field_files']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-site_page-field_files']['widget']['weight'] = 4; /* WAS: 1 */
  }
  if (isset($data['node-site_page-field_govdelivery_topic_ref'])) {
    $data['node-site_page-field_govdelivery_topic_ref']['widget']['weight'] = 8; /* WAS: 37 */
  }
  if (isset($data['node-site_page-field_location_address'])) {
    unset($data['node-site_page-field_location_address']);
  }
  if (isset($data['node-site_page-field_quick_search'])) {
    $data['node-site_page-field_quick_search']['widget']['weight'] = 5; /* WAS: 32 */
  }
  if (isset($data['node-site_page-field_sub_type'])) {
    unset($data['node-site_page-field_sub_type']);
  }
  if (isset($data['node-site_page-field_subject'])) {
    $data['node-site_page-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-site_page-field_subject']['widget']['weight'] = 7; /* WAS: 34 */
  }
  if (isset($data['node-site_page-field_thumbnail_image'])) {
    $data['node-site_page-field_thumbnail_image']['label'] = 'Main Image'; /* WAS: 'Thumbnail Image' */
    $data['node-site_page-field_thumbnail_image']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-site_page-field_thumbnail_image']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(
        'attach' => 0,
        'clipboard' => 0,
        'imce' => 0,
        'opensanmateo_search' => 0,
        'osmremotefile' => 0,
        'plupload' => 0,
        'reference' => 0,
        'remote' => 0,
      ),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-site_page-field_thumbnail_image']['widget']['weight'] = 3; /* WAS: -1 */
    $data['node-site_page-field_thumbnail_image']['workbench_access_field'] = 0; /* WAS: '' */
  }
  if (isset($data['node-site_page-field_topic'])) {
    $data['node-site_page-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-site_page-field_topic']['widget']['weight'] = 6; /* WAS: 34 */
  }
  if (isset($data['node-webform-body'])) {
    $data['node-webform-body']['widget']['weight'] = 1; /* WAS: -3 */
  }
  if (isset($data['node-webform-field_contact'])) {
    unset($data['node-webform-field_contact']);
  }
  if (isset($data['node-webform-field_custom_layout'])) {
    $data['node-webform-field_custom_layout']['widget']['weight'] = 5; /* WAS: 36 */
  }
  if (isset($data['node-webform-field_do_not_index'])) {
    $data['node-webform-field_do_not_index']['widget']['weight'] = 6; /* WAS: 31 */
  }
  if (isset($data['node-webform-field_event'])) {
    unset($data['node-webform-field_event']);
  }
  if (isset($data['node-webform-field_govdelivery_topic_ref'])) {
    unset($data['node-webform-field_govdelivery_topic_ref']);
  }
  if (isset($data['node-webform-field_location_address'])) {
    unset($data['node-webform-field_location_address']);
  }
  if (isset($data['node-webform-field_quick_search'])) {
    $data['node-webform-field_quick_search']['widget']['weight'] = 2; /* WAS: 32 */
  }
  if (isset($data['node-webform-field_sub_type'])) {
    unset($data['node-webform-field_sub_type']);
  }
  if (isset($data['node-webform-field_subject'])) {
    $data['node-webform-field_subject']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-webform-field_subject']['widget']['weight'] = 4; /* WAS: 34 */
  }
  if (isset($data['node-webform-field_topic'])) {
    $data['node-webform-field_topic']['widget']['settings']['shs'] = array(
      'create_new_levels' => FALSE,
      'create_new_terms' => FALSE,
      'force_deepest' => FALSE,
      'node_count' => FALSE,
    ); /* WAS: '' */
    $data['node-webform-field_topic']['widget']['weight'] = 3; /* WAS: 34 */
  }
  if (isset($data['taxonomy_term-blog_terms-field_govdelivery_topic_ref'])) {
    unset($data['taxonomy_term-blog_terms-field_govdelivery_topic_ref']);
  }
  if (isset($data['taxonomy_term-calendars-field_govdelivery_topic_ref'])) {
    unset($data['taxonomy_term-calendars-field_govdelivery_topic_ref']);
  }
  if (isset($data['taxonomy_term-document_terms-field_govdelivery_topic_ref'])) {
    unset($data['taxonomy_term-document_terms-field_govdelivery_topic_ref']);
  }
  if (isset($data['taxonomy_term-event_type-field_govdelivery_topic_ref'])) {
    unset($data['taxonomy_term-event_type-field_govdelivery_topic_ref']);
  }
  if (isset($data['taxonomy_term-location_type-field_govdelivery_topic_ref'])) {
    unset($data['taxonomy_term-location_type-field_govdelivery_topic_ref']);
  }
  if (isset($data['taxonomy_term-sub_type-field_govdelivery_topic_ref'])) {
    unset($data['taxonomy_term-sub_type-field_govdelivery_topic_ref']);
  }
  if (isset($data['taxonomy_term-topic-field_govdelivery_topic_ref'])) {
    unset($data['taxonomy_term-topic-field_govdelivery_topic_ref']);
  }
}
