<?php
/**
 * implements hook_sanmateo_master_is_set
 *
 * PARAM base: a url of the master site to which I am the slave!
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
 * implements hook_sanmateo_is_master_set
 *
 * PARAM is_master: a bool that states if this is the master site
 *
 * THis is called when ever this site is set as master or not master
 * It can be used when other items need to be udpated
 */
function hook_sanmateo_is_master_set($is_master) {
  if($is_master) {
    module_enable(array('openid_provider'));
  }
  else {
    module_disable(array('openid_provider'));
  }
}

