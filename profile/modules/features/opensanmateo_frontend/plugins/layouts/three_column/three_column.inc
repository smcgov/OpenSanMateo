<?php

/**
 * implementation of hook_panels_layouts
 */
//function smc_base_three_column_panels_layouts() {
  // Plugin definition
  //$items['three_column'] = array(
$plugin = array(
  'title' => t('Three Column Layout'),
  'category' => t('San Mateo Layouts'),
  'icon' => 'three_column.png',
  'theme' => 'three_column',
  'theme arguments' => array('id', 'content'),
  //'admin css' => 'three_column_admin.css',
  'css' => 'three_column.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Facets & Navigation'),
    'middle' => t('Main'),
    'right' => t('Secondary'),
    'bottom' => t('Bottom'),
  ),
);
  
  //return $items;
//}


/*
// Plugin definition.
$plugin = array(
  'title' => t('Two column 30/70 stacked'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_30_70_stacked.png',
  'theme' => 'twocol_30_70_stacked',
  'css' => 'twocol_30_70_stacked.css',
  'regions' => array(
    'header' => t('Header'),
    'top' => t('Top'),
    'left' => t('Left'),
    'right' => t('Right'),
    'footer' => t('Footer'),
  ),
);
*/