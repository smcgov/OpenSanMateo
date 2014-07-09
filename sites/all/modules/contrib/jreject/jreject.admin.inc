<?php
/**
 * @file
 * @brief Admin screen forms to configure the jReject module.
 *
 * @author Domenic Santangelo (entendu) http://drupal.org/user/173461
 */

/**
 * jReject main configuration. Admin screen called by the menu system,
 * see jreject.module.
 */
function jreject_configure_system() {
  $conf = variable_get('jreject_options_alpha', array());
  $form = array();
  $form['jreject_enable'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('jreject_enable', FALSE),
    '#title' => t('Enable jReject'),
  );
  $form['jreject_header'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#maxlength' => 256,
    '#default_value' => $conf['header'],
    '#title' => t('Modal header message'),
  );
  $form['jreject_paragraph1'] = array(
    '#type' => 'textarea',
    '#cols' => 60,
    '#rows' => 5,
    '#default_value' => $conf['paragraph1'],
    '#title' => t('Modal paragraph 1'),
    '#description' => t('You are encouraged to keep this brief.'),
  );
  $form['jreject_paragraph2'] = array(
    '#type' => 'textarea',
    '#cols' => 60,
    '#rows' => 5,
    '#default_value' => $conf['paragraph2'],
    '#title' => t('Modal paragraph 2'),
    '#description' => t('You are encouraged to keep this brief.'),
  );
  $form['jreject_closeMessage'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#maxlength' => 256,
    '#default_value' => $conf['closeMessage'],
    '#title' => t('Modal close message'),
  );
  $form['jreject_closeLink'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#maxlength' => 256,
    '#default_value' => $conf['closeLink'],
    '#title' => t('Modal close message'),
  );
  $form['jreject_closeURL'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#maxlength' => 256,
    '#default_value' => $conf['closeURL'],
    '#title' => t('Modal close URL'),
    '#description' => "If you want to send your users somewhere special when they click the close link, enter the destination here.",
  );
  $form['submit'] = array(
    "#type" => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * jReject options configuration. Admin screen called by the menu system,
 * see jreject.module.
 */
function jreject_configure_options() {
  $conf = variable_get('jreject_options_beta', array());
  $form = array();
  $form['jreject_close'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf["close"],
    '#title' => t('Allow closing of modal window?'),
  );
  $form['jreject_closeESC'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['closeESC'],
    '#title' => t('Allow closing the modal window with the ESC key?'),
  );
  $form['jreject_closeCookie'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['closeCookie'],
    '#title' => t('Remember if the window was closed by setting a cookie?'),
  );
  $form['jreject_overlayBgColor'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#maxlength' => 7,
    '#default_value' => $conf['overlayBgColor'] ? $conf['overlayBgColor'] : '#000',
    '#title' => t('Overlay background color'),
    '#description' => "Enter a custom overlay background color in hex.",
  );
  $form['jreject_overlayOpacity'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#maxlength' => 7,
    '#default_value' => $conf['overlayOpacity'] ? $conf['overlayOpacity'] : '0.8',
    '#title' => t('Background opacity'),
    '#description' => "Enter a value from 0-1.",
  );
  $form['jreject_fadeInTime'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#maxlength' => 7,
    '#default_value' => $conf['fadeInTime'] ? $conf['fadeInTime'] : 'fast',
    '#title' => t('Modal fade-in speed'),
    '#description' => "Enter a value ('slow','medium','fast' or integer in ms)",
  );
  $form['jreject_fadeOutTime'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#maxlength' => 7,
    '#default_value' => $conf['fadeOutTime'] ? $conf['fadeOutTime'] : 'fast',
    '#title' => t('Modal fade-out speed'),
    '#description' => "Enter a value ('slow','medium','fast' or integer in ms)",
  );
  $form['submit'] = array(
    "#type" => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * jReject browser rejection configuration. Admin screen called by the menu system,
 * see jreject.module.
 */
function jreject_configure_browsers() {
  $form = array();
  $form['intro'] = array(
    '#type' => 'item',
    '#markup' => '<p>Select the browser types and versions you want to display the modal popup for:</p>',
  );
  $conf = variable_get('jreject_browser_config', array());
  $browsers = array("msie" => array("Internet Explorer" => range(5, 10)),
                    "firefox" => array("Firefox" => range(2, 24)),
                    "chrome" => array("Chrome" => range(1, 30)),
                    "safari" => array("Safari" => range(1, 6)),
                    "opera" => array("Opera" => range(1, 16)),
                    );
  foreach ($browsers as $machine_name => $details) {
    foreach ($details as $human_name => $versions) {
      $form[$machine_name] = array(
        '#type' => 'fieldset',
        '#title' => t('@name', array("@name" => $human_name)),
        '#tree' => TRUE,
        '#collapsible' => TRUE,
      );
      foreach ($versions as $v) {
        $form[$machine_name][$v] = array(
          '#type' => 'checkbox',
          '#default_value' => isset($conf[$machine_name][$v]) ? $conf[$machine_name][$v] : 0,
          '#title' => t('@name @version', array("@name" => $human_name, "@version" => $v)),
        );
      }
    }  
  }
  $form['submit'] = array(
    "#type" => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * jReject alternatives configuration. Admin screen called by the menu system,
 * see jreject.module.
 */
function jreject_configure_alternatives() {
  $conf = variable_get('jreject_browser_alternatives', array());
  $form = array();
  $form['intro'] = array(
    '#type' => 'item',
    '#markup' => '<p>Select which browsers you\'d like to present as upgrades in the modal window.
                      It is recommended that you choose at least three.</p>',
  );
  $form['jreject_msie'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['msie'],
    '#title' => t('Internet Explorer'),
  );
  $form['jreject_firefox'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['firefox'],
    '#title' => t('Firefox'),
  );
  $form['jreject_safari'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['safari'],
    '#title' => t('Safari'),
  );
  $form['jreject_opera'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['opera'],
    '#title' => t('Opera'),
  );
  $form['jreject_chrome'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['chrome'],
    '#title' => t('Chrome'),
  );
  $form['jreject_gcf'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['gcf'],
    '#title' => t('Google Chrome Frame'),
    '#description' => t('If selected, this option will only appear for users of Internet Explorer.'),
  );
  $form['submit'] = array(
    "#type" => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * Submit functions for the above forms.
 */
function jreject_configure_browsers_submit($form, &$form_state) {
  variable_del('jreject_browser_config');
  $config = array();
  foreach ($form_state['values'] as $k => $item) {
    if (is_array($item)) {
      $config[$k] = $item;
    }
  }
  variable_set('jreject_browser_config', $config);
  drupal_set_message(t("Saved browser settings."));
}

function jreject_configure_system_submit($form, &$form_state) {
  variable_del('jreject_options_alpha');
  $config = jreject_prepare_settings($form_state);
  variable_set('jreject_options_alpha', $config);
  variable_set('jreject_enable', $form_state['values']['jreject_enable']);
  drupal_set_message(t("Saved options."));
}

function jreject_configure_options_submit($form, &$form_state) {
  variable_del('jreject_options_beta');
  $config = jreject_prepare_settings($form_state);
  variable_set('jreject_options_beta', $config);
  drupal_set_message(t("Saved options."));
}

function jreject_configure_alternatives_submit($form, &$form_state) {
  variable_del('jreject_browser_alternatives');
  $config = jreject_prepare_settings($form_state);
  variable_set('jreject_browser_alternatives', $config);
  drupal_set_message(t("Saved options."));
}

/**
 * Utility: prepares form values to be saved.
*/
function jreject_prepare_settings($form_state) {
  $config = array();
  foreach ($form_state['values'] as $k => $item) {
    if (strpos($k, "jreject_") === 0) {
      $config[substr($k, 8, strlen($k))] = $item;
    }
  }
  return $config;
}
