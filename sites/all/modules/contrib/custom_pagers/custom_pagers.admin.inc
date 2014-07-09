<?php
/**
 * @file
 * Admin functionality for the custom pagers module.
 */

// Lists all current custom pagers, and provides a link to the edit page.
/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function custom_pagers_page() {
  $pagers = _custom_pagers_load_all_pagers(TRUE);

  $header = array(t('Title'), t('Node list'), t('Visibility'), '');

  $rows = array();
  foreach ($pagers as $pager) {
    $row = array();
    $row[] = $pager->title;
    $row[] = !empty($pager->list_php) ? t('PHP snippet') : t('%view_name view', array('%view_name' => $pager->view));
    $row[] = !empty($pager->visibility_php) ? t('PHP snippet') : t('%node_type nodes', array('%node_type' => implode(',', $pager->node_type)));
    $row[] =  l(t('edit'), 'admin/structure/custom_pagers/edit/' . $pager->pid);
    $rows[] = $row;
  }
  if (count($rows) == 0) {
    $rows[] = array(array(
        'data' => t('No custom pagers have been defined.'),
        'colspan' => 3,
      ));
  }

  $rows[] = array(array(
      'data' => l(t('Add a new custom pager'), 'admin/structure/custom_pagers/add'),
      'colspan' => 2,
    ));

  return theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 * Displays an edit form for a custom pager record.
 */
function custom_pagers_form($form, &$form_state, $pid = NULL) {
  if (isset($pid) && $pager = _custom_pagers_load_pager($pid)) {
    $form['pid'] = array(
      '#type' => 'hidden',
      '#value' => $pid,
    );
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => $pid ? $pager->title : '',
  );


  $form['position'] = array(
    '#type' => 'select',
    '#title' => t('Pager position'),
    '#required' => TRUE,
    '#options' => array(
      'top' => t("Above the node's body"),
      'bottom' => t("Below the node's body"),
      'both' => t("Both above and below the node's body"),
      'block' => t("In a sidebar block"),
    ),
    '#description' => t('The node type(s) this custom pager will apply to.'),
    '#default_value' => $pid ? $pager->position : NULL,
  );

  $form['visibility'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#title' => t('Pager visibility'),
    '#description' => t('Determine what nodes this pager should be displayed on.'),
  );

  // Warn the user they're about to override custom code.
  if ((!empty($pager->visibility_php)) && !user_access('use php in custom pagers')) {
    $form['visibility']['php'] = array(
      '#type' => 'item',
      '#title' => t('Note'),
      '#value' => t('This pager uses custom PHP snippets to control visibility. You do not have permission to use PHP snippets, and the changes you make to this field will be ignored.'),
    );
  }
  $form['visibility']['node_type'] = array(
    '#type' => 'select',
    '#title' => t('By node type'),
    '#required' => TRUE,
    '#multiple' => TRUE,
    '#options' => node_type_get_names(),
    '#description' => t('If the PHP field is filled in, this field will be ignored.'),
    '#default_value' => $pid ? explode(',', $pager->node_type) : NULL,
  );

  $form['visibility']['visibility_php'] = array(
    '#type' => 'textarea',
    '#title' => t('By PHP snippet'),
    '#access' => user_access('use php in custom pagers'),
    '#description' => t('Use a snippet of PHP to return TRUE or FALSE. Note that this code has access to the $node variable, and can check its type or any other property. If this field is filled out, the <em>By node type</em> field will be ignored.'),
    '#default_value' => $pid ? $pager->visibility_php : '',
  );

  $form['node_list'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#title' => t('Pager node list'),
    '#description' => t('Determine how the list of nodes for this pager should be generated.'),
  );

  // Warn the user they're about to override custom code, or if Views
  // is missing and PHP permissions haven't been granted.
  if (!user_access('use php in custom pagers')) {
    if (!empty($pager->list_php)) {
      $form['node_list']['note'] = array(
        '#type' => 'item',
        '#title' => t('Note'),
        '#value' => t('This pager uses custom PHP snippets to generate a list of nodes. You do not have permission to use PHP snippets, and the changes you make to this field will be ignored.'),
      );
    }
    elseif (!module_exists('views')) {
      $form['node_list']['warning'] = array(
        '#type' => 'item',
        '#title' => t('Warning'),
        '#value' => t('The Views module is not installed, and you do not have permission to use PHP snippets to configure the node. You can save this custom pager, but it will not appear until the node list is properly configured.'),
      );
    }
  }

  $form['node_list']['list_php'] = array(
    '#type' => 'textarea',
    '#title' => t('Use PHP snippet'),
    '#access' => user_access('use php in custom pagers'),
    '#default_value' => $pid ? $pager->list_php : '',
    '#description' => t('Use a snippet of PHP to populate the pager. The snippet should return an array of node ids in the order they should be browsed. If this field is filled out, the <em>Use a view</em> and <em>View arguments</em> fields will be ignored.'),
  );

  if (module_exists('views')) {
    $options = array();

    $all_views = views_get_all_views();
    foreach ($all_views as $view) {
      // Only views that have fields will work for our purpose.
      if (!empty($view->display['default']->display_options['fields']) && $view->base_table == 'node') {
        $options[$view->name] = $view->name;
      }
    }

    $form['node_list']['view'] = array(
      '#type' => 'select',
      '#title' => t('Use a view'),
      '#required' => TRUE,
      '#options' => $options,
      '#description' => t('A view used to populate the pager. The nodes will appear in the pager in the same order they are displayed in the view. If the PHP field is populated, this will be ignored.'),
      '#default_value' => $pid ? $pager->view : NULL,
    );

    $form['node_list']['args'] = array(
      '#type' => 'textarea',
      '#title' => t('View arguments'),
      '#required' => FALSE,
      '#description' => t('A return-delimited list of arguments to pass into the selected view. If Token.module is enabled, placeholder tokens like [type] and [author] can be used.'),
      '#default_value' => $pid ? $pager->args : NULL,
    );

    $form['help'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Placeholder tokens'),
      '#description' => t("The following placeholder tokens can be used when passing arguments into the view. Each will be replaced with the correct values at runtime."),
    );

    if (module_exists('token')) {
      $form['help']['tokens'] = array(
        '#theme' => 'token_tree',
        '#token_types' => array('node'),
      );
    }
    else {
      $form['help']['#description'] = t("To use dynamic placeholder tokens in your pager arguments (the ID of the current node or currently logged in user, for example), download and install the <a href='@token'>Token module</a> from Drupal.org.", array('@token' => 'http://www.drupal.org/project/token'));
      $form['help']['#collapsible'] = FALSE;
      $form['help']['#collapsed'] = FALSE;
    }
  }

  $form['node_list']['reverse_list'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reverse the list of nodes'),
    '#return_value' => 1,
    '#description' => t("The natural list view ordering for an archive is the opposite of the natural 'previous/next' order for a pager. As such, reversing the pager list is useful when using a single view for paging and other sorted lists (pages, blocks, etc)."),
    '#default_value' => $pid ? $pager->reverse_list : NULL,
  );

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  if ($pid) {
    $form['buttons']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
    );
  }

  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function custom_pagers_form_submit(&$form, &$form_state) {
  if ($form_state['values']['op'] == t('Delete')) {
    _custom_pagers_delete_pager($form_state['values']['pid']);
  }
  else {
    $pager = (object) $form_state['values'];
    $pager->node_type = implode(',', $pager->node_type);
    _custom_pagers_save_pager($pager);
  }
  $form_state['redirect'] = 'admin/structure/custom_pagers';
}
