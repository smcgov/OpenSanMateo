<?php

/**
 * implementation of hook_panels_layouts
 */
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
    'left' => t('Sidebar'),
    'nav' => t('Navigation'),
    'middle' => t('Main'),
    'right' => t('Secondary'),
    'bottom' => t('Bottom'),
  ),
);