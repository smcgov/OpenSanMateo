<?php
/**
 * @file
 * Code for the Opensanmateo Profile Social Media module.
 */




/**
 * Implements hook_form_FORM_ID_alter().
 *
 */
function opensanmateo_profile_social_media_form_node_form_alter(&$form, &$form_state, $form_id) {
  if (
    !property_exists($form['#node'], 'field_social_media')
    || empty($form['field_social_media'])
  ) {
    return;
  }
  
  if (empty($form['field_social_media']['#attached'])) {
    $form['field_social_media']['#attached'] = array();
  }
  if (empty($form['field_social_media']['#attached']['css'])) {
    $form['field_social_media']['#attached']['css'] = array();
  }
  $module_path = drupal_get_path('module', 'opensanmateo_profile_social_media');
  $form['field_social_media']['#attached']['css'][] = $module_path . '/assets/css/opensanmateo_profile_social_media_form_node.css';
  
  foreach(element_children($form['field_social_media']['und'], $sort = FALSE) as $i) {
    if (empty($form['field_social_media']['und'][$i]['field_social_media_title'])) {continue;}
    $form['field_social_media']['und'][$i]['field_social_media_title']['#states'] = array(
      'visible' => array(
        ':input[name="field_social_media[und][' . $i . '][field_social_media_type][und]"]' => array('value' => 'url'),
      ),
    );
  }
  
  if (empty($form['#validate'])) {
    $form['#validate'] = array();
  }
  $form['#validate'][] = 'opensanmateo_profile_social_media_form_node_form_validate';

}


/**
 * Implements hook_form_FORM_ID_alter().
 *
 */
function opensanmateo_profile_social_media_form_node_form_validate(&$form, &$form_state, $form_id) {
// drupal_set_message('<pre>$field ' . print_r($form_state['input']['field_social_media'], 1) . '</pre>');
  foreach($form_state['input']['field_social_media']['und'] as $i => $smfield) {
    $value_field_error_id = 'field_social_media][und][' . $i . '][field_social_media_value][und][0][value';
    $value_field_value = $smfield['field_social_media_value']['und'][0]['value'];
    $title_field_value = $smfield['field_social_media_title']['und'][0]['value'];
    switch ($smfield['field_social_media_type']['und']) {
      case 'email':
        if (!valid_email_address($value_field_value)) {
          form_set_error(
            $value_field_error_id,
            t('A valid email address (e.g. myname@domain.com) is required for the email social media value.')
          );
        }
        break;
      case 'googleplus':
        if (!opensanmateo_profile_social_media_valid_googleplus_id($value_field_value)) {
          form_set_error(
            $value_field_error_id,
            t('A valid G+ ID (e.g. 123456789012345678901 or +MyCustomGoogleURL) is required for the Google Plus social media value.')
          );
        }
        break;
      case 'facebook':
        if (!opensanmateo_profile_social_media_valid_facebook_id($value_field_value)) {
          form_set_error(
            $value_field_error_id,
            t('A valid facebook ID (e.g. my.facebook.name) is required for the Facebook social media value.')
          );
        }
        break;
      case 'twitter':
        if (!opensanmateo_profile_social_media_valid_twitter_id($value_field_value)) {
          form_set_error(
            $value_field_error_id,
            t('A valid twitter ID (e.g. my_twitter_name) is required for the Twitter social media value.')
          );
        }
        break;
      case 'linkedin':
        if (!opensanmateo_profile_social_media_valid_linkedin_id($value_field_value)) {
          form_set_error(
            $value_field_error_id,
            t('A valid linkedin ID (e.g. my_linkedin_name) is required for the LinkedIn social media value.')
          );
        }
        break;
      case 'pinterest':
        if (!opensanmateo_profile_social_media_valid_pinterest_id($value_field_value)) {
          form_set_error(
            $value_field_error_id,
            t('A valid pinterest ID (e.g. mypinterestname123) is required for the Pinterest social media value.')
          );
        }
        break;
      case 'tumblr':
        if (!opensanmateo_profile_social_media_valid_tumblr_id($value_field_value)) {
          form_set_error(
            $value_field_error_id,
            t('A valid tumblr ID (e.g. my-tumblr-name) is required for the tumblr social media value.')
          );
        }
        break;
      case 'url':
        if (!valid_url($value_field_value, TRUE)) {
          form_set_error(
            $value_field_error_id,
            t('A valid URL (e.g. http://somedomain.com?foo) is required for the URL social media value.')
          );
        }
        if (
          empty($title_field_value)
          || check_plain($title_field_value) != $title_field_value
        ) {
          form_set_error(
            $value_field_error_id,
            t(
              'A valid Title field (e.g. !eg) is required for the URL social media value.',
              array(
                '!eg' => (empty($title_field_value) ? 'My Social Media Link' : check_plain($title_field_value)),
              )
            )
          );
        }
        break;
    }
  }
}


/**
 * Validate Google+ IDs
 * 
 * IDs must be in the form of either (for example):
 *   +SeanPOMacCathMoran
 *   104426511016919473313
 *
 * Resulting URL will be https://plus.google.com/+SeanPOMacCathMoran
 */
function opensanmateo_profile_social_media_valid_googleplus_id($id) {
  return
    preg_match('/^[+][a-zA-Z0-9_.-]{4,}$/', $id)
    || preg_match('/[0-9]{21}/', $id);
}

/**
 * Generate Google+ URL
 *
 * Resulting URL will be https://plus.google.com/+SeanPOMacCathMoran
 */
function opensanmateo_profile_social_media_googleplus_url($id) {
  return 'https://plus.google.com/' . $id;
}

/**
 * Validate facebook IDs
 * 
 * IDs must be in the form of (for example):
 *   emanaton.esreverni
 *
 * Resulting URL will be https://www.facebook.com/emanaton.esreverni
 */
function opensanmateo_profile_social_media_valid_facebook_id($id) {
  return preg_match('/^[A-Za-z0-9.]+$/', $id);
}

/**
 * Generate facebook URL
 * 
 * Resulting URL will be https://www.facebook.com/emanaton.esreverni
 */
function opensanmateo_profile_social_media_facebook_url($id) {
  return 'https://www.facebook.com/' . $id;
}

/**
 * Validate twitter IDs
 * 
 * IDs must be in the form of (for example):
 *   emanaton
 *
 * Resulting URL will be https://twitter.com/emanaton
 */
function opensanmateo_profile_social_media_valid_twitter_id($id) {
  return preg_match('/^[A-Za-z0-9_]{1,15}$/', $id);
}

/**
 * Generate twitter URL
 * 
 * Resulting URL will be https://twitter.com/emanaton
 */
function opensanmateo_profile_social_media_twitter_url($id) {
  return 'https://twitter.com/' . $id;
}

/**
 * Validate linkedin IDs
 * 
 * IDs must be in the form of (for example):
 *   239665316
 *   emanaton
 *
 * Resulting URL will be http://www.linkedin.com/in/emanaton
 */
function opensanmateo_profile_social_media_valid_linkedin_id($id) {
  return preg_match('/^[A-Za-z0-9]{5,30}$/', $id);
}

/**
 * Generate linkedin URL
 * 
 * Resulting URL will be http://www.linkedin.com/in/emanaton
 */
function opensanmateo_profile_social_media_linkedin_url($id) {
  return 'http://www.linkedin.com/in/' . $id;
}

/**
 * Validate pinterest IDs
 * 
 * IDs must be in the form of (for example):
 *   maccathmoran
 *
 * Resulting URL will be http://www.pinterest.com/maccathmoran
 */
function opensanmateo_profile_social_media_valid_pinterest_id($id) {
  return preg_match('/^[A-Za-z0-9]{3,15}$/', $id);
}

/**
 * Generate pinterest URL
 * 
 * Resulting URL will be http://www.pinterest.com/maccathmoran
 */
function opensanmateo_profile_social_media_pinterest_url($id) {
  return 'http://www.pinterest.com/' . $id;
}

/**
 * Validate tumblr IDs
 * 
 * IDs must be in the form of (for example):
 *   emanaton
 *
 * Resulting URL will be http://emanaton.tumblr.com/
 */
function opensanmateo_profile_social_media_valid_tumblr_id($id) {
  return preg_match('/^[A-Za-z0-9-]{1,32}$/', $id);
}

/**
 * Generate tumblr URL
 * 
 * Resulting URL will be http://emanaton.tumblr.com/
 */
function opensanmateo_profile_social_media_tumblr_url($id) {
  return 'http://' . $id . '.tumblr.com/';
}

/**
 * Generate email URL
 * 
 * Resulting URL will be mailto:esreverni@emanaotn.com
 */
function opensanmateo_profile_social_media_email_url($id) {
  return 'mailto:' . $id;
}

/**
 * Generate social media URL
 * 
 * Generate url for the indicated social media service using the given the ID
 */
function opensanmateo_profile_social_media_url($smservice, $id) {
  $function = 'opensanmateo_profile_social_media_' . $smservice . '_url';
  if (function_exists($function)) {
    return $function($id);
  }
  elseif ('url' == $smservice) {
    return $id;
  }
  else {
    return '';
  }
}

/**
 * Generate social media title
 * 
 * Generate title for the indicated social media service
 */
function opensanmateo_profile_social_media_title($smservice, $title = '') {
  switch ($smservice) {
    case 'email':
      $title = t('Email');
      break;
    case 'googleplus':
      $title = t('Google +');
      break;
    case 'facebook':
      $title = t('Facebook');
      break;
    case 'twitter':
      $title = t('twitter');
      break;
    case 'linkedin':
      $title = t('LinkedIn');
      break;
    case 'pinterest':
      $title = t('Pinterest');
      break;
    case 'tumblr':
      $title = t('tumblr');
      break;
    case 'url':
      if (empty($title)) {
        $title = 'Site';
      }
      break;
  }
  
  return $title;
}

/**
 * Tell Drupal to also look for template files in the modules folder
 *
 * implements hook_theme_registry_alter
 *
 * @param $theme_registry
 */
function opensanmateo_profile_social_media_theme_registry_alter(&$theme_registry) {
  $path  = drupal_get_path('module', 'opensanmateo_profile_social_media') . '/assets/templates';
  $reg = drupal_find_theme_templates($theme_registry, '.tpl.php', $path);
  foreach ($reg as &$r) {
    $r['type'] = 'module';
  }
  
// drupal_set_message('<pre>' . print_r($reg, 1) . '</pre>');
  $theme_registry += $reg;
}

/**
 * implements hook_preprocess_page
 *
 */
function opensanmateo_profile_social_media_preprocess_page(&$variables) {
  $path  = drupal_get_path('module', 'opensanmateo_profile_social_media');
  drupal_add_css(
    $path . '/assets/css/opensanmateo_profile_social_media.css',
    array(
      'group' => CSS_DEFAULT,
      'every_page' => TRUE,
    )
  );
}
