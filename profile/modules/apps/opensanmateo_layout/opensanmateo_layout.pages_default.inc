<?php
/**
 * @file
 * opensanmateo_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function opensanmateo_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'OSM Platform Base',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'nav' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'e9a737a8-1723-4a49-9ecc-c8f7fbb72bbe';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9fb29f1c-cf33-4ba1-bd8c-4d47dc17a8b6';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9fb29f1c-cf33-4ba1-bd8c-4d47dc17a8b6';
    $display->content['new-9fb29f1c-cf33-4ba1-bd8c-4d47dc17a8b6'] = $pane;
    $display->panels['middle'][0] = 'new-9fb29f1c-cf33-4ba1-bd8c-4d47dc17a8b6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9fb29f1c-cf33-4ba1-bd8c-4d47dc17a8b6';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'OSM Platform Profile Pages',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'profile' => 'profile',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'one_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'nav' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '76394c3d-d1ed-470a-8459-09a2e3cad6fc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4be24654-c7fa-4b64-9d3a-089413809e1f';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4be24654-c7fa-4b64-9d3a-089413809e1f';
    $display->content['new-4be24654-c7fa-4b64-9d3a-089413809e1f'] = $pane;
    $display->panels['middle'][0] = 'new-4be24654-c7fa-4b64-9d3a-089413809e1f';
    $pane = new stdClass();
    $pane->pid = 'new-8e013b23-22c0-43e0-bc71-72c48d23d523';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'opensanmateo_search-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 1,
      'pager_id' => '1',
      'items_per_page' => '3',
      'exposed' => array(
        'filter-search_api_site_hash' => array(
          'expose_to_visitor' => 0,
        ),
        'search_api_site_hash' => '1',
        'type_op' => '=',
        'type' => array(
          'blog_entry' => 'blog_entry',
        ),
        'search_api_multi_aggregation_8' => '',
        'sort_by' => 'search_api_aggregation_1',
        'sort_order' => 'ASC',
      ),
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Blog Entries',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8e013b23-22c0-43e0-bc71-72c48d23d523';
    $display->content['new-8e013b23-22c0-43e0-bc71-72c48d23d523'] = $pane;
    $display->panels['middle'][1] = 'new-8e013b23-22c0-43e0-bc71-72c48d23d523';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4be24654-c7fa-4b64-9d3a-089413809e1f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panelizer_node';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panelizer_node';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Custom Panelizer',
    'context' => 'argument_entity_id:node_1',
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'custom layout',
            'php' => '$field = field_get_items(\'node\', $contexts[\'argument_entity_id:node_1\']->data, \'field_custom_layout\');
return $field[0][\'value\'];',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view_panelizer_node'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function opensanmateo_layout_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = '403_page';
  $page->task = 'page';
  $page->admin_title = '403 Page';
  $page->admin_description = '';
  $page->path = 'access-denied';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_403_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = '403_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'nav' => NULL,
      'middle' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '403 Access Denied';
  $display->uuid = 'bbd0917b-32a2-423e-8bfa-b3f61ea54f3b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-99944fff-3852-4e66-a277-c1bd7c09e866';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h2 style="text-align: center;">Access Denied.</h2>

<p style="text-align: center;">You do not have permission to access this page.</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '99944fff-3852-4e66-a277-c1bd7c09e866';
    $display->content['new-99944fff-3852-4e66-a277-c1bd7c09e866'] = $pane;
    $display->panels['middle'][0] = 'new-99944fff-3852-4e66-a277-c1bd7c09e866';
    $pane = new stdClass();
    $pane->pid = 'new-8501890d-f2a0-4010-bcf1-0aa27ca93817';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8501890d-f2a0-4010-bcf1-0aa27ca93817';
    $display->content['new-8501890d-f2a0-4010-bcf1-0aa27ca93817'] = $pane;
    $display->panels['middle'][1] = 'new-8501890d-f2a0-4010-bcf1-0aa27ca93817';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-99944fff-3852-4e66-a277-c1bd7c09e866';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['403_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = '404_page';
  $page->task = 'page';
  $page->admin_title = '404 Page';
  $page->admin_description = '';
  $page->path = 'not-found';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_404_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = '404_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'nav' => NULL,
      'middle' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '539d9099-0217-49df-80dc-465b9b03149b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c6c1ab4b-495b-4351-912a-b20c7eb3676d';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h2 style="text-align: center;">Sorry, That page doesn&#39;t exist.</h2>
<p>&nbsp;</p>
<p>The page you requested could not be found, either contact your webmaster or try again. Use your browsers Back button to navigate to the page you have prevously come from</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c6c1ab4b-495b-4351-912a-b20c7eb3676d';
    $display->content['new-c6c1ab4b-495b-4351-912a-b20c7eb3676d'] = $pane;
    $display->panels['middle'][0] = 'new-c6c1ab4b-495b-4351-912a-b20c7eb3676d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c6c1ab4b-495b-4351-912a-b20c7eb3676d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['404_page'] = $page;

  return $pages;

}
