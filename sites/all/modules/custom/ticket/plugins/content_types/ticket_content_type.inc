<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Ticket Widget'),
  'description' => t('Ticket widget'),
  'category' => t('Node'),
  'render callback' => 'ticket_content_type_render',
  'edit form' => 'ticket_content_type_edit_form',
);

/**
 * Render the custom content type.
 */
function ticket_content_type_render($subtype, $conf, $panel_args, $context) {
 
  // Создаём блок с формой
  $entity = entity_get_controller('ticket')->create();

  if (user_access('administer tickets entities')) {
    $url_permission = !empty($conf['ticket_administer']) ? $conf['ticket_administer'] : 'admin/structure/tickets/manage';
  } else {
    $url_permission = !empty($conf['ticket_not_administer']) ? $conf['ticket_not_administer'] : '';
  }
  
  $block = new stdClass();
  $block->module  = 'ticket';
  $block->content = drupal_get_form('ticket_form', $entity,$url_permission);

  return $block;
}

function ticket_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['ticket_administer'] = array(
    '#type' => 'textfield',
    '#title' => t('Config redirect administer permission'),
    '#size' => 50,
    '#description' => t('Where to redirect the user with administer permission. If left empty, by default will be path: admin/structure/tickets/manage'),
    '#default_value' => !empty($conf['ticket_administer']) ? $conf['ticket_administer'] : '',
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );
  $form['ticket_not_administer'] = array(
    '#type' => 'textfield',
    '#title' => t('Config redirect not administer permission'),
    '#size' => 50,
    '#description' => t('Where to redirect the user with not administer permission. If left empty, by default will be page of ticket'),
    '#default_value' => !empty($conf['ticket_not_administer']) ? $conf['ticket_not_administer'] : '',
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}

function ticket_content_type_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}