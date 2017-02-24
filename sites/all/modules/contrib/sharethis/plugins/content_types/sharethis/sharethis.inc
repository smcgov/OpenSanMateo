<?php

/**
 * @file
 * Main file of the sharethis plugin.
 */

$plugin = array(
  'title' => t('ShareThis Widget'),
  'description' => t('ShareThis Widget pane'),
  'category' => t('Widgets'),
  'required context' => array(
    new ctools_context_optional(t('Entity'), 'entity'),
  ),
  'defaults' => array(
    'path' => 'global',
    'path-external' => '',
  ),
);

/**
 * Sharethis content type render function.
 */
function sharethis_sharethis_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!empty($context[0])) {
    $entity_type = end($context[0]->type);
    $uri = entity_uri($entity_type, $context[0]->data);
    $url = url($uri['path'], array('absolute' => TRUE));
    $title = entity_label($entity_type, $context[0]->data);
  }
  elseif ($conf['path'] == 'external') {
    $url = $conf['path-external'];
    $title = variable_get('site_name', '');
  }
  else {
    $path = ($conf['path'] == 'global') ? '<front>' : $_GET['q'];
    $url = url($path, array('absolute' => TRUE));
    $title = ($conf['path'] == 'current') ? drupal_get_title() : variable_get('site_name', '');
  }

  $block = new stdClass();
  $block->module = 'sharethis';
  $block->content = theme('sharethis', array(
    'data_options' => sharethis_get_options_array(),
    'm_path' => $url,
    'm_title' => $title,
  ));

  return $block;
}

/**
 * Sharethis content type edit form.
 */
function sharethis_sharethis_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $description = t('Context or Global - Use context if available or default to Global.');
  $description .= '<br />';
  $description .= t('External - Useful in iframes (Facebook Tabs, etc.)');
  $form['path'] = array(
    '#type' => 'select',
    '#title' => t('Path to share'),
    '#options' => array(
      'global' => t('Context or Global'),
      'external' => t('External URL'),
    ),
    '#description' => $description,
    '#default_value' => $conf['path'],
  );

  $form['path-external'] = array(
    '#type' => 'textfield',
    '#title' => t('External URL'),
    '#default_value' => $conf['path-external'],
    '#states' => array(
      'visible' => array(
        ':input[name="path"]' => array('value' => 'external'),
      ),
    ),
  );

  return $form;
}

/**
 * Validates the sharethis content type edit form.
 */
function sharethis_sharethis_content_type_edit_form_validate($form, &$form_state) {
  if (($form_state['values']['path'] == 'external') && (!valid_url($form_state['values']['path-external'], TRUE))) {
    form_set_error('path-external', t('Invalid URL'));
  }
}

/**
 * Sharethis content type edit form submit handler.
 */
function sharethis_sharethis_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('path', 'path-external') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
