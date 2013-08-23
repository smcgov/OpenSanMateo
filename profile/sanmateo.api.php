<?php
/**
 * implements hook_sanmateo_master_is_set
 *
 * THis is called when ever the master url is changed
 * It can be used when other items need to be udpated
 */
function hook_sanmateo_master_is_set($base) {
  if ($base) {
    openid_autocreate_regex_set('administrator', array("/^https?:\/\/$base/"));
  }
  else {
    openid_autocreate_regex_set('administrator', array());
  }
}

/**
 * implements hook_sanmateo_master_is_set
 *
 * THis is called when ever this site is set as master or not master
 * It can be used when other items need to be udpated
 */
function hook_sanmateo_master_is_set($is_master) {
  if($is_master) {
    module_enable(array('openid_provider'));
  }
  else {
    module_disable(array('openid_provider'));
  }
}
