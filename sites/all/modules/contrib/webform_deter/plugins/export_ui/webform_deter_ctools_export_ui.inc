<?php
//drush_log("Hello" . __FILE__ . ':' . __LINE__, 'error');
/**
* Define this Export UI plugin.
*/
$plugin = array(
  'schema' => 'webform_deter_pattern',  // As defined in hook_schema().
  'access' => 'administer webform_deter',  // Define a permission users must have to access these pages.

  // Define the menu item.
  'menu' => array(
    'menu item' => 'webform_deter',
    'menu title' => 'Webform Deter',
    'menu description' => 'Administer webform deter patterns and settings',
  ),

  // Define user interface texts.
  'title singular' => t('pattern'),
  'title plural' => t('patterns'),
  'title singular proper' => t('Webform Deter Pattern'),
  'title plural proper' => t('Webform Deter Patterns'),

  // Define the names of the functions that provide the add/edit forms.
  'form' => array(
    'settings' => 'webform_deter_ctools_export_ui_form',
    // 'submit' and 'validate' are also valid callbacks.
  ),
);


/**
* Define the preset add/edit form.
*/
function webform_deter_ctools_export_ui_form(&$form, &$form_state) {
  $pattern = $form_state['item'];

  $form['pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Pattern'),
    '#maxlength' => 50,
    '#description' => t('Regular expression to run against text input elements, if this pattern matches users will be cautioned against submitting the form.'),
    '#default_value' => $pattern->pattern,
    '#required' => true,
  );

  $form['info']['name']['#type'] = 'textfield';
  $form['info']['name']['#title'] = t('Name');
  $form['info']['name']['#maxlength'] = 50;

  $form['info']['description']['#type'] = 'textfield';
  $form['info']['description']['#title'] = t('Description');
  $form['info']['description']['#maxlength'] = 255;
  $form['info']['description']['#description'] = t('More detailed description of what this pattern is checking for. To help others trying to decode the pattern in the future.');
}

