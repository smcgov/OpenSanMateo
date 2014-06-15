<?php

/**
 * 
 */
class OpenSanMateoSiteCrawlerEntityDataSourceController extends SearchApiExternalDataSourceController {

  
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
    return 'http://www.emanaton.com/';
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