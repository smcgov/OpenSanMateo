<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
  
?><!--[if lt IE 8]><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd"><![endif]--><!--[if !IE]><!--><!DOCTYPE html><!--<![endif]-->
<!--[if lt IE 7]><html class="ie ie6 lte9 lte8 lte7" lang="<?php print $language->language; ?>"><![endif]-->
<!--[if IE 7]><html class="ie ie7 lte9 lte8 lte7" lang="<?php print $language->language; ?>"><![endif]-->
<!--[if IE 8]><html class="ie ie8 lte9 lte8" lang="<?php print $language->language; ?>"><![endif]-->
<!--[if IE 9]><html class="ie ie9 lte9" lang="<?php print $language->language; ?>"><![endif]-->
<!--[if gt IE 9]><html> <![endif]-->
<!--[if !IE]><!--><html class="" lang="<?php print $language->language; ?>"><!--<![endif]-->
<!-- paulirish.com/2008/conditional-stylesheets-vs-css-hacks-answer-neither/ -->
<head>
  <meta http-equiv="X-UA-Compatible" content="IE=EDGE" />
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <!-- IE Fix for HTML5 Tags -->
	<!--[if lt IE 9]>
	<script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
	<script src="//ie7-js.googlecode.com/svn/version/2.1(beta4)/IE9.js"></script>
	<![endif]-->
  
  <?php print $scripts; ?>
  
	
	<script type="text/javascript">
    // first, create the object that contains
    // configuration variables
    MTIConfig = {};
    // next, add a variable that will control
    // whether or not FOUT will be prevented
    MTIConfig.EnableCustomFOUTHandler = true // true = prevent FOUT
	</script>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link" class="clearfix">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
