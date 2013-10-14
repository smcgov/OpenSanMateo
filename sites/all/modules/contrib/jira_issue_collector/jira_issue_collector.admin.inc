<?php

/**
 * @file
 * Administration for the JIRA Issue Collector module.
 */

/**
 * Implements admin settings form.
 */
function jira_issue_collector_admin_settings_form($form, &$form_state) {
  $form['code'] = array(
    '#type' => 'fieldset',
    '#title' => t('Embed code'),
    '#collapsible' => FALSE,
  );

  $form['code']['jira_issue_collector_code'] = array(
    '#type' => 'textarea',
    '#title' => t('Code to insert'),
    '#default_value' => variable_get('jira_issue_collector_code', ''),
    '#required' => TRUE,
    '#description' => t('Your JIRA Issue Collector embed code in either direct embed or jQuery format. You can find a list of our existing collectors at %url.', array('%url' => 'https://your-jira-installation/secure/admin/ViewGlobalCollectors!default.jspa')),
  );

  $form['code']['jira_issue_collector_url'] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#disabled' => TRUE,
    '#value' => variable_get('jira_issue_collector_url', ''),
    '#description' => t('The URL to the javascript code for your JIRA Issue Collector. This has been automatically determined from the code inserted above.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="jira_issue_collector_url"]' => array('value' => ''),
      ),
    ),
  );

  // Render the role overview.
  $form['role_vis_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Role specific visibility settings'),
    '#collapsible' => TRUE,
  );

  $form['role_vis_settings']['jira_issue_collector_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Role specific visibility'),
    '#default_value' => variable_get('jira_issue_collector_roles', array()),
    '#options' => user_roles(),
    '#description' => t('Show JIRA Issue Collector only for the selected role(s). If none of the roles are selected, the collector will be shown for all roles. If a user has any of the roles checked, the collector will be shown for the user.'),
  );

  // Page specific visibility configurations.
  $form['page_vis_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page specific visibility settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $access = user_access('use PHP for JIRA Issue Collector visibility');
  $visibility = variable_get('jira_issue_collector_visibility', 0);
  $pages = variable_get('jira_issue_collector_pages', '');

  if ($visibility == 2 && !$access) {
    $form['page_vis_settings'] = array();
    $form['page_vis_settings']['visibility'] = array('#type' => 'value', '#value' => 2);
    $form['page_vis_settings']['pages'] = array('#type' => 'value', '#value' => $pages);
  }
  else {
    $options = array(t('Show collector on every page except the listed pages.'), t('Show collector on the listed pages only.'));
    $description = t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.",
      array(
        '%blog' => 'blog',
        '%blog-wildcard' => 'blog/*',
        '%front' => '<front>',
      ));

    if (module_exists('php') && $access) {
      $options[] = t('Show if the following PHP code returns <code>TRUE</code> (PHP-mode, experts only).');
      $description .= ' ' . t('If the PHP-mode is chosen, enter PHP code between %php. Note that executing incorrect PHP-code can break your Drupal site.', array('%php' => '<?php ?>'));
    }
    $form['page_vis_settings']['jira_issue_collector_visibility'] = array(
      '#type' => 'radios',
      '#title' => t('Page specific visibility'),
      '#options' => $options,
      '#default_value' => $visibility,
    );
    $form['page_vis_settings']['jira_issue_collector_pages'] = array(
      '#type' => 'textarea',
      '#title' => t('Pages'),
      '#default_value' => $pages,
      '#description' => $description,
      '#wysiwyg' => FALSE,
    );
  }

  return system_settings_form($form);
}

/**
 * Form validation handler for jira_issue_collector_admin_settings_form().
 *
 * @see jira_issue_collector_admin_settings_form()
 */
function jira_issue_collector_admin_settings_form_validate($form, &$form_state) {
  $code = $form_state['values']['jira_issue_collector_code'];
  // JIRA can be hosted at any domain so to detect the URL for the Issue
  // Collector we look for an attribute containing an url with the collectorId
  // argument.
  // Example of valid URL:
  // https://jira-instance/some-path/com.atlassian.jira.collector.plugin.jira
  // -issue-collector-plugin:issuecollector/com.atlassian.jira.collector.plugin
  // .jira-issue-collector-plugin:issuecollector.js?collectorId=abcd1234.
  if (preg_match('/"(http[^"]+\?collectorId=[0-9a-f]+)"/im', $code, $matches) && valid_url($matches[1], TRUE)) {
    $form_state['values']['jira_issue_collector_url'] = $matches[1];
  }
  else {
    form_set_error('jira_issue_collector_code', t('Unable to determine URL for JIRA Issue Collector script from the code. Please verify that you inserted the correct value.'));
  }
}
