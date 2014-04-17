<?php

// echo '<pre>$field ' . print_r(array_keys(get_defined_vars()), 1) . '</pre>';
// echo '<pre>$field ' . print_r(array_keys($items[0]['entity']['field_collection_item'][227]), 1) . '</pre>';
// echo '<pre>$field ' . print_r($items[0]['entity']['field_collection_item'][227]['field_social_media_type']['#items'][0]['value'], 1) . '</pre>';
// echo '<pre>$field ' . print_r($items[0]['entity']['field_collection_item'][227]['field_social_media_value']['#items'][0]['value'], 1) . '</pre>';
// echo '<pre>$field ' . print_r($items[0]['entity']['field_collection_item'][227]['field_social_media_title']['#items'][0]['value'], 1) . '</pre>';

$smlinks = '';
foreach ($items as $item) {
  $fields = array_pop($item['entity']['field_collection_item']);
  $smtype = $fields['field_social_media_type']['#items'][0]['value'];
  $smvalue = $fields['field_social_media_value']['#items'][0]['value'];
  $smtitle = $fields['field_social_media_title']['#items'][0]['value'];
  $smtitle = opensanmateo_profile_social_media_title($smtype, $smtitle);
  
// $smurl = opensanmateo_profile_social_media_url($smtype, $smvalue);
// echo '<pre>$field ' . print_r(array($smtype, $smvalue, $smtitle, $smurl), 1) . '</pre>';

  $smlinks .= 
    '<div class="profile-social-media-link profile-social-media-' . $smtype . '">'
      . l(
        $smtitle,
        opensanmateo_profile_social_media_url($smtype, $smvalue),
        array(
          'attributes' => array(
            'target' => '_blank',
          ),
        )
      )
    . '</div>';
  
}

echo '<div class="profile-social-media-links">' . $smlinks . '</div>';