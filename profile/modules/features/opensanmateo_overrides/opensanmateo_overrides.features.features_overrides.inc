<?php
/**
 * @file
 * opensanmateo_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function opensanmateo_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: context
  $overrides["context.profile_page.reactions|block"]["DELETED"] = TRUE;

  // Exported overrides for: field_base
  $overrides["field_base.field_document_attachment.settings|display_default"] = 1;
  $overrides["field_base.field_files.settings|display_default"] = 1;

  // Exported overrides for: field_instance
  $overrides["field_instance.file-image-field_summmary.file-image-field_summmary"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-body.widget|weight"] = 1;
  $overrides["field_instance.node-blog_entry-field_author.node-blog_entry-field_author"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_contact.node-blog_entry-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_custom_layout.widget|weight"] = 10;
  $overrides["field_instance.node-blog_entry-field_do_not_index.widget|weight"] = 11;
  $overrides["field_instance.node-blog_entry-field_event.node-blog_entry-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_files.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_files.widget|weight"] = 5;
  $overrides["field_instance.node-blog_entry-field_govdelivery_topic_ref.widget|weight"] = 9;
  $overrides["field_instance.node-blog_entry-field_location_address.node-blog_entry-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_quick_search.widget|weight"] = 6;
  $overrides["field_instance.node-blog_entry-field_release_date.widget|settings|display_all_day"] = 0;
  $overrides["field_instance.node-blog_entry-field_release_date.widget|weight"] = 2;
  $overrides["field_instance.node-blog_entry-field_sub_type.node-blog_entry-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-blog_entry-field_subject.widget|weight"] = 8;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.label"] = 'Main Image';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.widget|weight"] = 4;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.workbench_access_field"] = 0;
  $overrides["field_instance.node-blog_entry-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-blog_entry-field_topic.widget|weight"] = 7;
  $overrides["field_instance.node-document-body.widget|weight"] = 1;
  $overrides["field_instance.node-document-field_author.node-document-field_author"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_contact.node-document-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_custom_layout.widget|weight"] = 9;
  $overrides["field_instance.node-document-field_do_not_index.widget|weight"] = 10;
  $overrides["field_instance.node-document-field_document_attachment.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-document-field_document_attachment.widget|weight"] = 5;
  $overrides["field_instance.node-document-field_event.node-document-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_govdelivery_topic_ref.node-document-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_location_address.node-document-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_quick_search.widget|weight"] = 6;
  $overrides["field_instance.node-document-field_sub_type.node-document-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-document-field_subject.widget|weight"] = 8;
  $overrides["field_instance.node-document-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-document-field_topic.widget|weight"] = 7;
  $overrides["field_instance.node-event-body.widget|weight"] = 1;
  $overrides["field_instance.node-event-field_contact.node-event-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_custom_layout.widget|weight"] = 10;
  $overrides["field_instance.node-event-field_do_not_index.widget|weight"] = 11;
  $overrides["field_instance.node-event-field_event.node-event-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_calendar.node-event-field_event_calendar"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_contact.widget|weight"] = 5;
  $overrides["field_instance.node-event-field_event_date.widget|weight"] = 2;
  $overrides["field_instance.node-event-field_files.widget|weight"] = 4;
  $overrides["field_instance.node-event-field_govdelivery_topic_ref.node-event-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_location_address.widget|weight"] = 6;
  $overrides["field_instance.node-event-field_quick_search.widget|weight"] = 7;
  $overrides["field_instance.node-event-field_sub_type.node-event-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-event-field_subject.widget|weight"] = 9;
  $overrides["field_instance.node-event-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-event-field_topic.widget|weight"] = 8;
  $overrides["field_instance.node-location-field_address.widget|weight"] = 2;
  $overrides["field_instance.node-location-field_contact.node-location-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-location-field_custom_layout.widget|weight"] = 9;
  $overrides["field_instance.node-location-field_do_not_index.widget|weight"] = 10;
  $overrides["field_instance.node-location-field_event.node-location-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-location-field_files.widget|weight"] = 5;
  $overrides["field_instance.node-location-field_govdelivery_topic_ref.node-location-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-location-field_quick_search.widget|weight"] = 6;
  $overrides["field_instance.node-location-field_sub_type.node-location-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-location-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-location-field_subject.widget|weight"] = 8;
  $overrides["field_instance.node-location-field_thumbnail_image.widget|weight"] = 4;
  $overrides["field_instance.node-location-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-location-field_topic.widget|weight"] = 7;
  $overrides["field_instance.node-media-body.widget|weight"] = 1;
  $overrides["field_instance.node-media-field_contact.node-media-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-media-field_custom_layout.widget|weight"] = 9;
  $overrides["field_instance.node-media-field_do_not_index.widget|weight"] = 10;
  $overrides["field_instance.node-media-field_event.node-media-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-media-field_files.widget|weight"] = 5;
  $overrides["field_instance.node-media-field_govdelivery_topic_ref.node-media-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-media-field_image_collection.widget|weight"] = 2;
  $overrides["field_instance.node-media-field_location_address.node-media-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-media-field_quick_search.widget|weight"] = 6;
  $overrides["field_instance.node-media-field_sub_type.node-media-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-media-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-media-field_subject.widget|weight"] = 8;
  $overrides["field_instance.node-media-field_thumbnail_image.widget|weight"] = 4;
  $overrides["field_instance.node-media-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-media-field_topic.widget|weight"] = 7;
  $overrides["field_instance.node-media-field_video.widget|weight"] = 3;
  $overrides["field_instance.node-press_release-body.widget|weight"] = 1;
  $overrides["field_instance.node-press_release-field_contact.widget|weight"] = 5;
  $overrides["field_instance.node-press_release-field_custom_layout.widget|weight"] = 9;
  $overrides["field_instance.node-press_release-field_do_not_index.widget|weight"] = 10;
  $overrides["field_instance.node-press_release-field_event.node-press_release-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-press_release-field_files.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-press_release-field_files.widget|weight"] = 4;
  $overrides["field_instance.node-press_release-field_govdelivery_topic_ref.node-press_release-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-press_release-field_location_address.node-press_release-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-press_release-field_quick_search.widget|weight"] = 6;
  $overrides["field_instance.node-press_release-field_sub_type.node-press_release-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-press_release-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-press_release-field_subject.widget|weight"] = 8;
  $overrides["field_instance.node-press_release-field_thumbnail_image.label"] = 'Main Image';
  $overrides["field_instance.node-press_release-field_thumbnail_image.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-press_release-field_thumbnail_image.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-press_release-field_thumbnail_image.widget|weight"] = 3;
  $overrides["field_instance.node-press_release-field_thumbnail_image.workbench_access_field"] = 0;
  $overrides["field_instance.node-press_release-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-press_release-field_topic.widget|weight"] = 7;
  $overrides["field_instance.node-profile-body.widget|weight"] = 3;
  $overrides["field_instance.node-profile-field_contact.node-profile-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_custom_layout.widget|weight"] = 14;
  $overrides["field_instance.node-profile-field_do_not_index.widget|weight"] = 15;
  $overrides["field_instance.node-profile-field_event.node-profile-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_govdelivery_topic_ref.node-profile-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_location_address.node-profile-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_address.node-profile-field_profile_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_department.widget|weight"] = 5;
  $overrides["field_instance.node-profile-field_profile_division.display|default|weight"] = 6;
  $overrides["field_instance.node-profile-field_profile_division.widget|weight"] = 6;
  $overrides["field_instance.node-profile-field_profile_email.display|default|label"] = 'above';
  $overrides["field_instance.node-profile-field_profile_email.display|default|module"] = 'text';
  $overrides["field_instance.node-profile-field_profile_email.display|default|type"] = 'text_default';
  $overrides["field_instance.node-profile-field_profile_email.display|default|weight"] = 7;
  $overrides["field_instance.node-profile-field_profile_job_title.widget|weight"] = 7;
  $overrides["field_instance.node-profile-field_profile_leadership.node-profile-field_profile_leadership"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_organization.node-profile-field_profile_organization"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_phone.display|default|label"] = 'above';
  $overrides["field_instance.node-profile-field_profile_phone.display|default|module"] = 'text';
  $overrides["field_instance.node-profile-field_profile_phone.display|default|type"] = 'text_default';
  $overrides["field_instance.node-profile-field_profile_phone.display|default|weight"] = 8;
  $overrides["field_instance.node-profile-field_profile_photo.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-profile-field_profile_photo.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-profile-field_profile_photo.widget|weight"] = 4;
  $overrides["field_instance.node-profile-field_profile_social_media.widget|weight"] = 10;
  $overrides["field_instance.node-profile-field_profile_staff.node-profile-field_profile_staff"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_user.node-profile-field_profile_user"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_quick_search.widget|weight"] = 11;
  $overrides["field_instance.node-profile-field_sub_type.node-profile-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-profile-field_subject.widget|weight"] = 13;
  $overrides["field_instance.node-profile-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-profile-field_topic.widget|weight"] = 12;
  $overrides["field_instance.node-services-body.widget|weight"] = 1;
  $overrides["field_instance.node-services-field_contact.node-services-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-services-field_custom_layout.widget|weight"] = 7;
  $overrides["field_instance.node-services-field_do_not_index.widget|weight"] = 8;
  $overrides["field_instance.node-services-field_event.node-services-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-services-field_files.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-services-field_files.widget|weight"] = 3;
  $overrides["field_instance.node-services-field_govdelivery_topic_ref.node-services-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-services-field_location_address.node-services-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-services-field_quick_search.widget|weight"] = 4;
  $overrides["field_instance.node-services-field_services_photo.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-services-field_services_photo.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-services-field_services_photo.widget|weight"] = 2;
  $overrides["field_instance.node-services-field_sub_type.node-services-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-services-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-services-field_subject.widget|weight"] = 6;
  $overrides["field_instance.node-services-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-services-field_topic.widget|weight"] = 5;
  $overrides["field_instance.node-site_page-body.widget|weight"] = 1;
  $overrides["field_instance.node-site_page-field_contact.node-site_page-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-site_page-field_custom_layout.widget|weight"] = 9;
  $overrides["field_instance.node-site_page-field_do_not_index.widget|weight"] = 10;
  $overrides["field_instance.node-site_page-field_event.node-site_page-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-site_page-field_files.settings|description_field"] = 1;
  $overrides["field_instance.node-site_page-field_files.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-site_page-field_files.widget|weight"] = 4;
  $overrides["field_instance.node-site_page-field_govdelivery_topic_ref.widget|weight"] = 8;
  $overrides["field_instance.node-site_page-field_location_address.node-site_page-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-site_page-field_quick_search.widget|weight"] = 5;
  $overrides["field_instance.node-site_page-field_sub_type.node-site_page-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-site_page-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-site_page-field_subject.widget|weight"] = 7;
  $overrides["field_instance.node-site_page-field_thumbnail_image.label"] = 'Main Image';
  $overrides["field_instance.node-site_page-field_thumbnail_image.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-site_page-field_thumbnail_image.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-site_page-field_thumbnail_image.widget|weight"] = 3;
  $overrides["field_instance.node-site_page-field_thumbnail_image.workbench_access_field"] = 0;
  $overrides["field_instance.node-site_page-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-site_page-field_topic.widget|weight"] = 6;
  $overrides["field_instance.node-webform-body.widget|weight"] = 1;
  $overrides["field_instance.node-webform-field_contact.node-webform-field_contact"]["DELETED"] = TRUE;
  $overrides["field_instance.node-webform-field_custom_layout.widget|weight"] = 5;
  $overrides["field_instance.node-webform-field_do_not_index.widget|weight"] = 6;
  $overrides["field_instance.node-webform-field_event.node-webform-field_event"]["DELETED"] = TRUE;
  $overrides["field_instance.node-webform-field_govdelivery_topic_ref.node-webform-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.node-webform-field_location_address.node-webform-field_location_address"]["DELETED"] = TRUE;
  $overrides["field_instance.node-webform-field_quick_search.widget|weight"] = 2;
  $overrides["field_instance.node-webform-field_sub_type.node-webform-field_sub_type"]["DELETED"] = TRUE;
  $overrides["field_instance.node-webform-field_subject.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-webform-field_subject.widget|weight"] = 4;
  $overrides["field_instance.node-webform-field_topic.widget|settings|shs"] = array(
    'create_new_levels' => FALSE,
    'create_new_terms' => FALSE,
    'force_deepest' => FALSE,
    'node_count' => FALSE,
  );
  $overrides["field_instance.node-webform-field_topic.widget|weight"] = 3;
  $overrides["field_instance.taxonomy_term-blog_terms-field_govdelivery_topic_ref.taxonomy_term-blog_terms-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-calendars-field_govdelivery_topic_ref.taxonomy_term-calendars-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-document_terms-field_govdelivery_topic_ref.taxonomy_term-document_terms-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-event_type-field_govdelivery_topic_ref.taxonomy_term-event_type-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-location_type-field_govdelivery_topic_ref.taxonomy_term-location_type-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-sub_type-field_govdelivery_topic_ref.taxonomy_term-sub_type-field_govdelivery_topic_ref"]["DELETED"] = TRUE;
  $overrides["field_instance.taxonomy_term-topic-field_govdelivery_topic_ref.taxonomy_term-topic-field_govdelivery_topic_ref"]["DELETED"] = TRUE;

 return $overrides;
}
