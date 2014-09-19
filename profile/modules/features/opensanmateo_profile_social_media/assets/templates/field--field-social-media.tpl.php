<?php

$smlinks = '';
foreach ($items as $item) {
  $fields = array_pop($item['entity']['field_collection_item']);
  $smtype = $fields['field_social_media_type']['#items'][0]['value'];
  $smvalue = $fields['field_social_media_value']['#items'][0]['value'];
  $smtitle = $fields['field_social_media_title']['#items'][0]['value'];
  $smtitle = opensanmateo_profile_social_media_title($smtype, $smtitle);
  
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

$smlinks = check_markup($smlinks, 'obfuscate_email_link');

echo '<div class="profile-social-media-links">' . $smlinks . '</div>';