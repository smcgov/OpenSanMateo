<?php

function phase2_document_apps_app_info() {
  return array(
    //Demo Content
    'demo content description' => 'Creates sample content to show services',
    //The perfered way for an app to provide demo content is to have a module 
    //that when enabled will add demo content, and when disabled will removed 
    //demo content
    //this module should be a submodule or part of the manifest dependent modules
    'demo content module' => 'phase2_document_demo',

    'configure form' => 'openpublic_serives_app_configure_form', // This form will be render on the app config pag
  );
}

function phase2_document_apps_configure_form() {
  return array();
}
