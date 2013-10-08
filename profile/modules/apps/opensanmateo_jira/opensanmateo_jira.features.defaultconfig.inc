<?php
/**
 * @file
 * opensanmateo_jira.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function opensanmateo_jira_defaultconfig_features() {
  return array(
    'opensanmateo_jira' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function opensanmateo_jira_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jira_issue_collector_code';
  $strongarm->value = '<script type="text/javascript" src="https://jira.phase2technology.com/s/en_USh7818h-1988229788/6105/36/1.4.0-m3/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector.js?collectorId=fee94595"></script>
';
  $export['jira_issue_collector_code'] = $strongarm;

  return $export;
}
