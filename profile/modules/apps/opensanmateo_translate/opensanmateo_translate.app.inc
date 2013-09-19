<?php

/**
 * Implements hook_app_info().
 */
function opensanmateo_translate_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_translate_app_configure_form',
  );
}

/**
 * Provide app spectific settings.
 */
function opensanmateo_translate_app_configure_form() {
  return google_translator_settings_page();
}
