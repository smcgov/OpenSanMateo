<?php
/**
 * @file
 * opensanmateo_frontend.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_frontend_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_wysiwyg_default_profiles_alter().
 */
function opensanmateo_frontend_wysiwyg_default_profiles_alter(&$data) {
  if (isset($data['full_html'])) {
    $data['full_html']['settings']['block_formats'] = 'p,h2,h3,h4,h5,h6,div'; /* WAS: 'p,address,pre,h2,h3,h4,h5,h6,div' */
    $data['full_html']['settings']['css_path'] = '%bprofiles/sanmateo/themes/smc_base/css/elements/editor.css'; /* WAS: '' */
    $data['full_html']['settings']['css_setting'] = 'self'; /* WAS: 'theme' */
  }
}

/**
 * Implements hook_fontyourface_features_default_font().
 */
function opensanmateo_frontend_fontyourface_features_default_font() {
  return array(
    'Trade Gothic® Bold' => array(
      'name' => 'Trade Gothic® Bold',
      'enabled' => 1,
      'url' => 'http://webfonts.fonts.com/en-US/Project/ChooseFonts?ViewDetails=T&ViewFontID=675331&AddFontToPalette=T',
      'provider' => 'fonts_com',
      'css_selector' => '<none>',
      'css_family' => 'Trade Gothic W01 Bold',
      'css_style' => '',
      'css_weight' => '',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:7:"details";O:8:"stdClass":14:{s:6:"CDNKey";s:394:"d44f19a684109620e4841570a090e818b6e1f8bb1aa6c724e3502e54f23ab0790139640509a9364e91c202ffdd8b90c6cfc5ed6c7b94f12524c9050aa76ff703934899c0f2e2bea4b44f0a1322079528e39466b83a6c257fdec06cb45a2da095d4b0cc8ae6cfd3a7377d9e7c8507d67865bf6d394ebaf53be45254930a78fc75b7018fbb528dffe41ec8d29c54110cd2fd6aca6e979fb62a74b56c1f8887a6d3b588981d2b6f67122d942a0052f6f04fbf796f0038cccd290f4c1e22ab0468c3e5539432ab";s:16:"EnableSubsetting";N;s:3:"EOT";s:36:"2e9af08f-0faf-45e3-9767-78a700434af3";s:11:"FontCSSName";s:21:"Trade Gothic W01 Bold";s:14:"FontFondryName";s:8:"Linotype";s:6:"FontID";s:6:"675331";s:12:"FontLanguage";s:7:"Latin 1";s:8:"FontName";s:19:"Trade Gothic® Bold";s:19:"FontPreviewTextLong";s:40:"Quick Brown Fox Jumped Over The Lazy Dog";s:8:"FontSize";s:5:"80532";s:14:"IsDownloadable";s:4:"true";s:3:"SVG";s:36:"d5153ad4-7c93-4757-9147-640e69ec4801";s:3:"TTF";s:36:"955ee494-66b2-4eb2-8f19-bc3a088df16d";s:4:"WOFF";s:36:"f51d24dd-8256-43c6-ba1a-6aeae9d3f262";}s:10:"project_id";s:36:"1b4ab7ba-bb64-4f70-bd43-9f3401f4dd20";}',
    ),
    'Trade Gothic® Bold Oblique' => array(
      'name' => 'Trade Gothic® Bold Oblique',
      'enabled' => 1,
      'url' => 'http://webfonts.fonts.com/en-US/Project/ChooseFonts?ViewDetails=T&ViewFontID=675346&AddFontToPalette=T',
      'provider' => 'fonts_com',
      'css_selector' => '<none>',
      'css_family' => 'TradeGothicW01-BoldObl',
      'css_style' => '',
      'css_weight' => '',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:7:"details";O:8:"stdClass":14:{s:6:"CDNKey";s:394:"d44f19a684109620e4841570a090e818b6e1f8bb1aa6c724e3502e54f23ab0790139640509a9364e91c202ffdd8b90c6cfc5ed6c7b94f12524c9050aa76ff703934899c0f2e2bea4b44f0a1322079528e39466b83a6c257fdec06cb45a2da095d4b0cc8ae6cfd3a7377d9e7c8507d67865bf6d394ebaf53be45254930a78fc75b7018fbb528dffe41ec8d29c54110cd2fd6aca6e979fb62a74b56c1f8887a6d3b588981d2b6f67122d942a0052f6f04fbf796f0038cccd290f4c1e22ab0468c3e5539432ab";s:16:"EnableSubsetting";N;s:3:"EOT";s:36:"5c90cd43-1e43-418c-b94c-e0687d8c2dc4";s:11:"FontCSSName";s:22:"TradeGothicW01-BoldObl";s:14:"FontFondryName";s:8:"Linotype";s:6:"FontID";s:6:"675346";s:12:"FontLanguage";s:7:"Latin 1";s:8:"FontName";s:27:"Trade Gothic® Bold Oblique";s:19:"FontPreviewTextLong";s:40:"Quick Brown Fox Jumped Over The Lazy Dog";s:8:"FontSize";s:5:"80016";s:14:"IsDownloadable";s:4:"true";s:3:"SVG";s:36:"ee5ac1bd-d9cf-43b7-8e09-407b4c5d4e9e";s:3:"TTF";s:36:"e721a83e-fd4b-4dd9-82fd-76f3108e7e16";s:4:"WOFF";s:36:"746f551e-eccf-461a-93a8-b885802a32a5";}s:10:"project_id";s:36:"1b4ab7ba-bb64-4f70-bd43-9f3401f4dd20";}',
    ),
    'Trade Gothic® Light' => array(
      'name' => 'Trade Gothic® Light',
      'enabled' => 1,
      'url' => 'http://webfonts.fonts.com/en-US/Project/ChooseFonts?ViewDetails=T&ViewFontID=675355&AddFontToPalette=T',
      'provider' => 'fonts_com',
      'css_selector' => '<none>',
      'css_family' => 'Trade Gothic W01 Light',
      'css_style' => '',
      'css_weight' => '',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:7:"details";O:8:"stdClass":14:{s:6:"CDNKey";s:394:"d44f19a684109620e4841570a090e818b6e1f8bb1aa6c724e3502e54f23ab0790139640509a9364e91c202ffdd8b90c6cfc5ed6c7b94f12524c9050aa76ff703934899c0f2e2bea4b44f0a1322079528e39466b83a6c257fdec06cb45a2da095d4b0cc8ae6cfd3a7377d9e7c8507d67865bf6d394ebaf53be45254930a78fc75b7018fbb528dffe41ec8d29c54110cd2fd6aca6e979fb62a74b56c1f8887a6d3b588981d2b6f67122d942a0052f6f04fbf796f0038cccd290f4c1e22ab0468c3e5539432ab";s:16:"EnableSubsetting";N;s:3:"EOT";s:36:"1d699af3-0e50-4c4b-a343-42d071e85714";s:11:"FontCSSName";s:22:"Trade Gothic W01 Light";s:14:"FontFondryName";s:8:"Linotype";s:6:"FontID";s:6:"675355";s:12:"FontLanguage";s:7:"Latin 1";s:8:"FontName";s:20:"Trade Gothic® Light";s:19:"FontPreviewTextLong";s:40:"Quick Brown Fox Jumped Over The Lazy Dog";s:8:"FontSize";s:6:"120000";s:14:"IsDownloadable";s:4:"true";s:3:"SVG";s:36:"d918b947-5fcb-42e2-8286-a98a801876de";s:3:"TTF";s:36:"8e50278c-45cd-4808-b774-24767d958f17";s:4:"WOFF";s:36:"537b145a-6a7d-4787-81d9-7228d3a42458";}s:10:"project_id";s:36:"1b4ab7ba-bb64-4f70-bd43-9f3401f4dd20";}',
    ),
    'Trade Gothic® Light Oblique' => array(
      'name' => 'Trade Gothic® Light Oblique',
      'enabled' => 1,
      'url' => 'http://webfonts.fonts.com/en-US/Project/ChooseFonts?ViewDetails=T&ViewFontID=675358&AddFontToPalette=T',
      'provider' => 'fonts_com',
      'css_selector' => '<none>',
      'css_family' => 'TradeGothicW01-LightObl',
      'css_style' => '',
      'css_weight' => '',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:7:"details";O:8:"stdClass":14:{s:6:"CDNKey";s:394:"d44f19a684109620e4841570a090e818b6e1f8bb1aa6c724e3502e54f23ab0790139640509a9364e91c202ffdd8b90c6cfc5ed6c7b94f12524c9050aa76ff703934899c0f2e2bea4b44f0a1322079528e39466b83a6c257fdec06cb45a2da095d4b0cc8ae6cfd3a7377d9e7c8507d67865bf6d394ebaf53be45254930a78fc75b7018fbb528dffe41ec8d29c54110cd2fd6aca6e979fb62a74b56c1f8887a6d3b588981d2b6f67122d942a0052f6f04fbf796f0038cccd290f4c1e22ab0468c3e5539432ab";s:16:"EnableSubsetting";N;s:3:"EOT";s:36:"b1721311-de06-4277-8dcb-bf39e072b75e";s:11:"FontCSSName";s:23:"TradeGothicW01-LightObl";s:14:"FontFondryName";s:8:"Linotype";s:6:"FontID";s:6:"675358";s:12:"FontLanguage";s:7:"Latin 1";s:8:"FontName";s:28:"Trade Gothic® Light Oblique";s:19:"FontPreviewTextLong";s:40:"Quick Brown Fox Jumped Over The Lazy Dog";s:8:"FontSize";s:6:"136404";s:14:"IsDownloadable";s:4:"true";s:3:"SVG";s:36:"198ed3e2-0cdf-496f-a0ef-86da8d4dde55";s:3:"TTF";s:36:"6b9ca17d-cb9d-43bb-8b43-93670b45b83f";s:4:"WOFF";s:36:"c357a65e-dd87-4d11-8063-db04802d44c0";}s:10:"project_id";s:36:"1b4ab7ba-bb64-4f70-bd43-9f3401f4dd20";}',
    ),
    'Trade Gothic® Oblique' => array(
      'name' => 'Trade Gothic® Oblique',
      'enabled' => 1,
      'url' => 'http://webfonts.fonts.com/en-US/Project/ChooseFonts?ViewDetails=T&ViewFontID=675361&AddFontToPalette=T',
      'provider' => 'fonts_com',
      'css_selector' => '<none>',
      'css_family' => 'Trade Gothic W01 Obl',
      'css_style' => '',
      'css_weight' => '',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:7:"details";O:8:"stdClass":14:{s:6:"CDNKey";s:394:"d44f19a684109620e4841570a090e818b6e1f8bb1aa6c724e3502e54f23ab0790139640509a9364e91c202ffdd8b90c6cfc5ed6c7b94f12524c9050aa76ff703934899c0f2e2bea4b44f0a1322079528e39466b83a6c257fdec06cb45a2da095d4b0cc8ae6cfd3a7377d9e7c8507d67865bf6d394ebaf53be45254930a78fc75b7018fbb528dffe41ec8d29c54110cd2fd6aca6e979fb62a74b56c1f8887a6d3b588981d2b6f67122d942a0052f6f04fbf796f0038cccd290f4c1e22ab0468c3e5539432ab";s:16:"EnableSubsetting";N;s:3:"EOT";s:36:"59fa12c0-25c9-4c0c-bd1e-32204311d86d";s:11:"FontCSSName";s:20:"Trade Gothic W01 Obl";s:14:"FontFondryName";s:8:"Linotype";s:6:"FontID";s:6:"675361";s:12:"FontLanguage";s:7:"Latin 1";s:8:"FontName";s:22:"Trade Gothic® Oblique";s:19:"FontPreviewTextLong";s:40:"Quick Brown Fox Jumped Over The Lazy Dog";s:8:"FontSize";s:6:"100232";s:14:"IsDownloadable";s:4:"true";s:3:"SVG";s:36:"09f52831-e1cf-48be-9c1e-2d1577e420b7";s:3:"TTF";s:36:"7062b4ff-265a-4366-b34f-443ec5cc2dad";s:4:"WOFF";s:36:"1c164451-034c-41f5-9542-390709016510";}s:10:"project_id";s:36:"1b4ab7ba-bb64-4f70-bd43-9f3401f4dd20";}',
    ),
    'Trade Gothic® Roman' => array(
      'name' => 'Trade Gothic® Roman',
      'enabled' => 1,
      'url' => 'http://webfonts.fonts.com/en-US/Project/ChooseFonts?ViewDetails=T&ViewFontID=675364&AddFontToPalette=T',
      'provider' => 'fonts_com',
      'css_selector' => '<none>',
      'css_family' => 'Trade Gothic W01 Roman',
      'css_style' => '',
      'css_weight' => '',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:7:"details";O:8:"stdClass":14:{s:6:"CDNKey";s:394:"d44f19a684109620e4841570a090e818b6e1f8bb1aa6c724e3502e54f23ab0790139640509a9364e91c202ffdd8b90c6cfc5ed6c7b94f12524c9050aa76ff703934899c0f2e2bea4b44f0a1322079528e39466b83a6c257fdec06cb45a2da095d4b0cc8ae6cfd3a7377d9e7c8507d67865bf6d394ebaf53be45254930a78fc75b7018fbb528dffe41ec8d29c54110cd2fd6aca6e979fb62a74b56c1f8887a6d3b588981d2b6f67122d942a0052f6f04fbf796f0038cccd290f4c1e22ab0468c3e5539432ab";s:16:"EnableSubsetting";N;s:3:"EOT";s:36:"413d9688-00d4-47c4-bb55-656a0cd396e9";s:11:"FontCSSName";s:22:"Trade Gothic W01 Roman";s:14:"FontFondryName";s:8:"Linotype";s:6:"FontID";s:6:"675364";s:12:"FontLanguage";s:7:"Latin 1";s:8:"FontName";s:20:"Trade Gothic® Roman";s:19:"FontPreviewTextLong";s:40:"Quick Brown Fox Jumped Over The Lazy Dog";s:8:"FontSize";s:6:"101520";s:14:"IsDownloadable";s:4:"true";s:3:"SVG";s:36:"853e2a9b-4057-42a5-ad7e-0762cda0b13c";s:3:"TTF";s:36:"e741f29c-bc18-4343-bff3-db2465a0be3e";s:4:"WOFF";s:36:"c4aef0d4-bfcf-4790-acf5-909881f411e8";}s:10:"project_id";s:36:"1b4ab7ba-bb64-4f70-bd43-9f3401f4dd20";}',
    ),
  );
}
