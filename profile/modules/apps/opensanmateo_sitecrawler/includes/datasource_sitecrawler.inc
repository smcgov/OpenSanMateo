<?php

/**
 * 
 */
class OpenSanMateoSiteCrawlerEntityDataSourceController extends SearchApiEntityDataSourceController {

  
  /**
   * Get a URL at which the item can be viewed on the web.
   *
   * @param $item
   *   An item of this controller's type.
   *
   * @return
   *   Either an array containing the 'path' and 'options' keys used to build
   *   the URL of the item, and matching the signature of url(), or NULL if the
   *   item has no URL of its own.
   */
  public function getItemUrl($item) {
    if ('sitecrawler_page' == $item->type) {
      drupal_set_message('OpenSanMateoSiteCrawlerEntityDataSourceController getItemUrl sitecrawler_page <pre>' . print_r($item->nid,1) . '</pre>');
      watchdog('actions', '<pre>getItemUrl: ' . print_r($item,1) . '</pre>');
      return array(
        'path' => 'http://www.emanaton.com/',
        'options' => array(
          'external' => TRUE,
        ),
      );
    }
    
    return parent::getItemUrl($item);
  }

}