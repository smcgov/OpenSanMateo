<?php

/*
 * implements hook_apps_app_info
 */
function openpublic_translation_content_apps_app_info() {
  return array(
    'configure form' => 'openpublic_translation_content_configure',
  );
}

/*
 * configure form for openpublic translation content app
 */
function openpublic_translation_content_configure($form, $form_state) {
  $form = array();
  $detects = array();

  # Point to Langauge page
  $form['setup'] = array(
    '#type' => 'fieldset',
    '#title' => 'Language Setup',
  );
  $langs = array();
  foreach(language_list() as $code => $lang) {
    $langs[$code] = $lang->name;
  }
  $lang_last = array_pop($langs);
  $langs_string = implode(" and ", array(implode(', ', $langs), $lang_last));
  $und_query = db_select("node", 'n');
  $und_query->condition('n.language', 'und', '=');
  $count_of_und =$und_query->countQuery()->execute()->fetchField();
  $count_of_und_menu = db_select("menu_links", 'l')
    ->condition('l.language', 'und', '=')
    ->countQuery()->execute()->fetchField();
  
  include_once 'includes/language.inc';
  
  //find the current language detection methods enabled
  $negotation = language_negotiation_info();
  $active = variable_get("language_negotiation_language");
  foreach($active as $key=> $stuff) {
    if (isset($negotation[$key])) {
      $detects[$key] = $negotation[$key]['name'];
    }
  }
  $detect_last = array_pop($detects);
  $detects_string = empty($detects) ? $detect_last : implode(" and ", array(implode(', ', $detects), $detect_last));

  global $language;
  $form['setup']['table'] = array(
    '#theme' => 'table',
    '#header' => array("Status", "Step", "Instructions", "Action"),
    '#rows' => array(
      'lang' => array(
        'data'=> array(
          theme("image", array("path" => "misc/watchdog-ok.png", "alt"=>"OK")),
          t("Language Setup"),
          t("Currently the site in enabled for @langs, to administer this or add more please see the !language_config_link.", array('@langs' => $langs_string, '!language_config_link'=> l('Language Configuration Page', 'admin/config/regional/language', array('query'=>drupal_get_destination())))),
          l('Language Configuration Page', 'admin/config/regional/language', array('query'=>drupal_get_destination())),
        ),
      ),
      'trans' => array(
        'data'=> array(
          theme("image", array("path" => "misc/watchdog-ok.png", "alt"=>"OK")),
          t("String Translation"),
          t('Drupal Provides an interface to translate the administion pages on the  !language_config_link.', array('!language_config_link'=> l('Translation Interface Page', 'admin/config/regional/translate',array('query'=>drupal_get_destination())))),
          l('Translation Inteface Page', 'admin/config/regional/translate',array('query'=>drupal_get_destination())),
        ),
      ),
      'detect' => array(
        'data'=> array(
          theme("image", array("path" => "misc/watchdog-ok.png", "alt"=>"OK")),
          t("Language Detection"),
          t('Drupal Provides Multiple ways to detect which language is used this can be change on the !language_config_link. Currently the following are in place @current_detect.', array('!language_config_link'=> l('Translation Interface Page', 'admin/config/regional/language/configure',array('query'=>drupal_get_destination())), '@current_detect' => $detects_string )),
          l('Language Detection Page', 'admin/config/regional/language/configure',array('query'=>drupal_get_destination())),
        ),
      ),
      'und' => array(
        'data'=> array(
          theme("image", array("path" => "misc/watchdog-ok.png", "alt"=>"OK")),
          t("Convert Content"),
          t('When there is only one language on a site all content is labeled with the undefined language, this site has @count such items. If they stay undefined they can not be translated. From here you can convert all of them in mass to the default langague(@default_lang).', array('@count' => $count_of_und, '@default_lang' => $language->native)),
        l('Convert Undefined Content', 'admin/config/regional/convert-und',array('query'=>drupal_get_destination())),
        ),
      ),
      'und_menu' => array(
        'data'=> array(
          theme("image", array("path" => "misc/watchdog-ok.png", "alt"=>"OK")),
          t("Convert Menus"),
          t('When there is only one language on a site all menu items are labeled with the undefined language, this site has @count such items. If they stay undefined they can not be translated. From here you can convert all of them in mass to the default langague(@default_lang).', array('@count' => $count_of_und_menu, '@default_lang' => $language->native)),
          l('Convert Undefined Menus', 'admin/config/regional/convert-und-menu',array('query'=>drupal_get_destination())),
        ),
      ),
    ),
  );
  # if we only have one language lets warn the user
  if(empty($langs)) {
    $form['setup']['table']['#rows']['lang']['data']['2'] = t('Currently only one language is configured please add additional languages on the !language_config_link.',array('!language_config_link'=> l('Language Configuration Page', 'admin/config/regional/language', array('query'=>drupal_get_destination()))));
    $form['setup']['table']['#rows']['lang']['data']['3'] = l('Add Language', 'admin/config/regional/language/add', array('query'=>drupal_get_destination()));
    $form['setup']['table']['#rows']['lang']['data']['0'] = theme("image", array("path" => "misc/watchdog-error.png", "alt"=>"Requires Changes"));
    $form['setup']['table']['#rows']['lang']['class'][] = 'error';
  }
  if(empty($detects)) {
    $form['setup']['table']['#rows']['detect']['data']['0'] = theme("image", array("path" => "misc/watchdog-error.png", "alt"=>"Requires Changes"));
    $form['setup']['table']['#rows']['detect']['data']['2'] .= t('With only the Default detection select, there will be no way to change the sites language.');
    $form['setup']['table']['#rows']['detect']['class'][] = 'error';
    $form['setup']['table']['#rows']['detect']['data']['3'] = l('Enable Detection Method', 'admin/config/regional/language/configure',array('query'=>drupal_get_destination()));
  }
  if($count_of_und > 0) {
    $form['setup']['table']['#rows']['und']['class'][] = 'warning';
    $form['setup']['table']['#rows']['und']['data']['0'] = theme("image", array("path" => "misc/watchdog-warning.png", "alt"=>"Warning"));
  }

  if($count_of_und_menu > 0) {
    $form['setup']['table']['#rows']['und_menu']['class'][] = 'warning';
    $form['setup']['table']['#rows']['und_menu']['data']['0'] = theme("image", array("path" => "misc/watchdog-warning.png", "alt"=>"Warning"));
  }

  #allow for views to not get alter with a language filter
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => 'Options',
  );
  $form['options']['enable_switcher'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable the Language Switcher block',
    '#description' => t('OpenPublic Translation Content will add a context placing the Language Switcher block in the sidebar.'),
    '#default_value' => variable_get('openpublic_translation_enable_switcher', 1),
  );

  #allow for views to not get alter with a language filter
  $form['views'] = array(
    '#type' => 'fieldset',
    '#title' => 'Langauge View Alters',
  );
  $views = array();
  foreach(views_get_enabled_views() as $view) {
    if($view->base_table =='node') {
      $views[$view->name] = $view->human_name ? $view->human_name : $view->name;
    }
  }
  $views_selected = variable_get('openpublic_translation_content_excluded_views', array());
  $form['views']['views_excluded'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Views that should Not be Alter to filter on Language',
    '#description' => t('OpenPublic Translation Content will add a filter to all views to filter on the current language, any views selected here will not have that filter added.'),
    '#options' => $views,
    '#default_value' => $views_selected,
  );
  $form['sumbit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );
  return $form;
}

/*
 * implement submit for openpublic_translation_content_configure form
 */
function openpublic_translation_content_configure_submit($form, &$form_state) {
  #save value of excluded views
  variable_set('openpublic_translation_content_excluded_views', $form_state['values']['views_excluded']);
  variable_set('openpublic_translation_enable_switcher', $form_state['values']['enable_switcher']);
  openpublic_translation_content_enable_context($form_state['values']['enable_switcher']);
}
