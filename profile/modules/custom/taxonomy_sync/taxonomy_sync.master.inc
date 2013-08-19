<?php
/**
 * access callback for list pages
 */
function taxonomy_sync_list_access($name) {
  $is_master = taxonomy_sync_is_master($name);
  if(!$is_master) {
    $client_ip = $_SERVER["REMOTE_ADDR"];
    watchdog(TAXONOMY_SYNC_WATCHDOG, 'Term list requested for non-master vocabulary @name by client @client_ip', array('@name' => $name, '@client_ip' => $client_ip), WATCHDOG_WARNING);
  }
  return $is_master;
}

/**
 * Menu callback to generate list of terms for client request
 */
function taxonomy_sync_list($name) {
  $payload = array(
    'name' => $name,
    'tree' => FALSE,
    'error' => FALSE,
    'error message' => '',
  );
  try {
    $payload['tree'] = taxonomy_sync_get_tree($name);
  }
  catch (TaxonomySyncMissingVocabulary $e) {
    watchdog(TAXONOMY_SYNC_WATCHDOG, 'Term list requested for non-existent vocabulary @name by client @client_ip', array('@name' => $name, '@client_ip' => $client_ip), WATCHDOG_WARNING);
    $payload['error message'] = $e->message;
    $payload['error'] = 'TaxonomySyncMissingVocabulary';
  }
  drupal_json_output($payload);
}

/**
 * return if this site is the master for the named vocabulary
 * PARAM name: machine name of a vocabulary
 * RETURN bool
 */
function taxonomy_sync_is_master($name) {
  return variable_get(TAXONOMY_SYNC_MASTER_PREFIX . $name, FALSE);
}

/*
 * Function to pull a tree of data on a machine name
 */
function taxonomy_sync_get_tree($name) {
   if($voc = taxonomy_vocabulary_machine_name_load($name)) {
     $tree = taxonomy_get_tree($voc->vid);
     return $tree;
   }
   else {
    throw TaxonomySyncMissingVocabulary("No vocabulary $name");
   }
}



