<?php
/**
 * @file
 * Export of all default permissions per SMC-614
 */

/**
 * Helper function to consolidate perms in one place
 */
function _opensanmateo_roles_def_perms() {
  $def_perms = array (
    'view_unpublished' => array(
      'view any unpublished profile content' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'view any unpublished blog_entry content' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'view any unpublished site_page content' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'view any unpublished webform content' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'xmlsitemap' => array(
      'administer xmlsitemap' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'flexslider' => array(
      'administer flexslider' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'sharethis' => array(
      'administer sharethis' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'redirect' => array(
      'administer redirects' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'block' => array(
      'administer blocks' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'fieldable_panels_panes' => array(
      'administer fieldable panels panes' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'create fieldable fieldable_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'edit fieldable fieldable_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'delete fieldable fieldable_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'create fieldable custom_content_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => false,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'edit fieldable custom_content_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => false,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'delete fieldable custom_content_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => false,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'create fieldable rotator_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'edit fieldable rotator_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'delete fieldable rotator_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'create fieldable promo_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'edit fieldable promo_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'delete fieldable promo_panels_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'create fieldable curated_list_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'edit fieldable curated_list_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'delete fieldable curated_list_pane' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'webform' =>
    array (
      'access all webform results' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'access own webform results' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'edit all webform submissions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'delete all webform submissions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'access own webform submissions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'edit own webform submissions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'delete own webform submissions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'addressfield_staticmap' =>
    array (
      'administer addressfield staticmap' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'addthis' =>
    array (
      'administer addthis' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'view addthis' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'apps' =>
    array (
      'administer apps' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'boxes' =>
    array (
      'edit boxes' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer boxes' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'breakpoints' =>
    array (
      'administer breakpoints' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'captcha' =>
    array (
      'administer CAPTCHA settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'skip CAPTCHA' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
    ),
    'comment' =>
    array (
      'administer comments' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'access comments' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'post comments' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'skip comment approval' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'edit own comments' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'comment_notify' =>
    array (
      'administer comment notify' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'subscribe to comments' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'contextual' =>
    array (
      'access contextual links' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'context_field' =>
    array (
      'use context field editor' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'context_ui' =>
    array (
      'administer contexts' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'dashboard' =>
    array (
      'access dashboard' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'delta_ui' =>
    array (
      'administer delta' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'distributed_blocks' =>
    array (
      'administer distributed blocks' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'entity_autocomplete' =>
    array (
      'use entity autocomplete' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'facetapi' =>
    array (
      'administer facets' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'field_collection' =>
    array (
      'administer field collections' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'file_entity' =>
    array (
      'bypass file access' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer file types' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'create files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => false,
      ),
      'view own private files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => false,
      ),
      'view own files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => false,
      ),
      'view private files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'view files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'edit own image files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any image files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own image files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any image files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'download own image files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'download any image files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'edit own video files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any video files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own video files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any video files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'download own video files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'download any video files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'edit own audio files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any audio files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own audio files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any audio files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'download own audio files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'download any audio files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'edit own document files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any document files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own document files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any document files' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'download own document files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'download any document files' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'filter' =>
    array (
      'administer filters' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'use text format full_html' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'use text format raw' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'use text format filtered_html' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'follow' =>
    array (
      'edit own follow links' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'edit site follow links' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'edit any user follow links' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer follow' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'change follow link titles' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'fontyourface' =>
    array (
      'administer @font-your-face' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'googleanalytics' =>
    array (
      'administer google analytics' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'opt-in or out of tracking' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'use PHP for tracking visibility' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'image' =>
    array (
      'administer image styles' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'imce' =>
    array (
      'administer imce' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'menu' =>
    array (
      'administer menu' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'menu_position' =>
    array (
      'administer menu positions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'metatag' =>
    array (
      'administer meta tags' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'edit meta tags' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'node' =>
    array (
      'bypass node access' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer content types' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer nodes' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'access content overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'access content' =>
      array (
        'anonymous user' => true,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'view own unpublished content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'view revisions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'revert revisions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'delete revisions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'create site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit own site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'create webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit own webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'create event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => false,
        'site manager' => false,
      ),
      'edit own event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => false,
        'site manager' => false,
      ),
      'edit any event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => false,
        'site manager' => false,
      ),
      'delete own event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => false,
        'site manager' => false,
      ),
      'delete any event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => false,
        'site manager' => true,
      ),
      'create location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit own location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'create media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit own media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'create blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit own blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'create profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit own profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'edit any profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete own profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'delete any profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'nodeblock' =>
    array (
      'maintain nodeblock' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'oauth_common' =>
    array (
      'access own authorizations' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'access own consumers' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'oauth authorize any consumers' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'oauth register any consumers' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer oauth' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer consumers' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'opensanmateo_search' =>
    array (
      'edit quick search tags' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'panels' =>
    array (
      'use panels dashboard' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer pane access' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'use panels in place editing' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'change layouts in place editing' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panels layouts' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panels styles' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'use panels caching features' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'use panels locks' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'panels_interface' =>
    array (
      'view advanced panel panes' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'panels_mini' =>
    array (
      'create mini panels' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer mini panels' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'path' =>
    array (
      'administer url aliases' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'create url aliases' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'picture' =>
    array (
      'administer pictures' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'publishcontent' =>
    array (
      'publish any content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish any site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish any webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),

      'publish any event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),

      'publish any media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),

      'publish any document content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own document content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable document content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any document content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own document content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable document content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),

      'publish any location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish any blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish any profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish own profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'publish editable profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish any profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish own profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'unpublish editable profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'recaptcha' =>
    array (
      'administer recaptcha' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
    ),
    'revision_scheduler' =>
    array (
      'schedule revisions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'search_api' =>
    array (
      'administer search_api' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'shortcut' =>
    array (
      'administer shortcuts' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'customize shortcut links' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'switch shortcut sets' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'system' =>
    array (
      'administer modules' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer site configuration' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer themes' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer software updates' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer actions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'access administration pages' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'access site in maintenance mode' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'view the administration theme' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'access site reports' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'block IP addresses' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'taxonomy' =>
    array (
      'administer taxonomy' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'toolbar' =>
    array (
      'access toolbar' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'user' =>
    array (
      'administer permissions' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer users' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'access user profiles' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'change own username' =>
      array (
        'anonymous user' => false,
        'authenticated user' => true,
        'administrator' => true,
        'content creator' => true,
        'event creator' => true,
        'editor' => true,
        'site manager' => true,
      ),
      'cancel account' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'select account cancellation method' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'video_embed_field' =>
    array (
      'administer video styles' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'workbench' =>
    array (
      'administer workbench' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'access workbench' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'field_group' =>
    array (
      'administer fieldgroups' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'pathauto' =>
    array (
      'administer pathauto' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'notify of path changes' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'twitter' =>
    array (
      'add twitter accounts' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'add authenticated twitter accounts' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'administer twitter accounts' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'workbench_moderation' =>
    array (
      'view all unpublished content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer workbench moderation' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'bypass workbench moderation' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'view moderation history' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'view moderation messages' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'use workbench_moderation my drafts tab' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'use workbench_moderation needs review tab' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'moderate content from draft to published' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => false,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'moderate content from draft to needs_review' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'moderate content from published to archived' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => false,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'moderate content from archived to draft' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => false,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'moderate content from needs_review to published' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'moderate content from needs_review to draft' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => true,
        'event creator' => false,
        'editor' => true,
        'site manager' => false,
      ),
      'moderate content from archived to published' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => false,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'views' =>
    array (
      'administer views' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'access all views' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'features' =>
    array (
      'administer features' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
      'manage features' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => true,
      ),
    ),
    'panelizer' =>
    array (
      'administer panelizer' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node blog_entry defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node blog_entry overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node blog_entry settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node blog_entry context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node blog_entry layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node blog_entry content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node location defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node location overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node location settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node location context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node location layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node location content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node profile defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node profile overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node profile settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node profile context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node profile layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node profile content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node site_page defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node site_page overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node site_page settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node site_page context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node site_page layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node site_page content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node webform defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node webform overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node webform settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node webform context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node webform layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node webform content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node document defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node document overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node document settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node document context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node document layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node document content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),

      'administer panelizer node event defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node event overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node event settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node event context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node event layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node event content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),

      'administer panelizer node media defaults' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node media overview' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node media settings' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node media context' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer panelizer node media layout' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'administer panelizer node media content' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'page_manager' =>
    array (
      'use page manager' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'administer page manager' =>
      array (
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
  );

  // Add vocabulary-specific terms
  $vocab_perms = array(
    'sub_type' => array(
      'edit' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'delete' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'subject' => array(
      'edit' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'delete' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'topic' => array(
      'edit' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'delete' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
    ),
    'calendars' => array(
      'edit' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'delete' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'govdelivery_topics' => array(
      'edit' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => true,
        'site manager' => true,
      ),
      'delete' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'location_type' => array(
      'edit' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'delete' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
    'event_type' => array(
      'edit' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
      'delete' => array(
        'anonymous user' => false,
        'authenticated user' => false,
        'administrator' => true,
        'content creator' => false,
        'event creator' => false,
        'editor' => false,
        'site manager' => false,
      ),
    ),
  );

  foreach ($vocab_perms as $vocab_name => $perms) {
    $vocab = taxonomy_vocabulary_machine_name_load($vocab_name);
    if (FALSE !== $vocab) {
      foreach ($perms as $perm => $perm_roles) {
        $perm = "{$perm} terms in {$vocab->vid}";
        $def_perms['taxonomy'][$perm] = $perm_roles;
      }
    }
  }

  return $def_perms;
}
