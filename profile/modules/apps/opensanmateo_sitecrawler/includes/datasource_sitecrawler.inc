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
drupal_set_message('BEFORE opensanmateo_sitecrawler_search_api_item_type_info_alter <pre>' . print_r($item->uri,1) . '</pre>');
    return array(
      'path' => 'http://www.emanaton.com/',
      'options' => array(
        'external' => TRUE,
      ),
    );
//     if ($this->entityType == 'file') {
//       return array(
//         'path' => file_create_url($item->uri),
//         'options' => array(
//           'entity_type' => 'file',
//           'entity' => $item,
//         ),
//       );
//     }
//     $url = entity_uri($this->entityType, $item);
//     return $url ? $url : NULL;
  }

}