<?php

/**
 * @file
 * Views definitions for mymodule module.
 */

/**
 * Implements hook_views_data().
 */
function views_study_views_data() {
  $data = array();

  $data['visa_service_order']['table']['group'] = t('Visa_service_order table');
  $data['visa_service_order']['table']['base']  = array(
       'title' => t('Orders'), 
       'help' => t('Stores orders for users'), 
       'field' => 'order_uid'
  );

  $data['visa_service_order']['order_id'] = array(
      'title' => t('Order id'), 
      'help' => t('The order id'), 
      'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => true
      ),
      'sort' => array(
          'handler' => 'views_handler_sort'
      ),
      'filter' => array(
          'handler' => 'views_study_handler_filter_numeric_greater_500'
      )
  ); 
  $data['visa_service_order']['order_hash'] = array(
      'title' => t('Order hash'), 
      'help' => t('The order hash'),
      'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => true
      ),
      'sort' => array(
          'handler' => 'views_handler_sort'
      ),
      'filter' => array(
          'handler' => 'views_handler_filter_string'
      )
  );


  $data['visa_service_order']['order_uid'] = array(
    'title' => t('Order uid'),
    'help' => t('The record order uid.'),
    'field' => array(
        'handler' => 'views_handler_field_user',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
        'base' => 'users',
        'base field' => 'uid',
        'relationship field' => 'order_uid',
        'handler' => 'views_handler_relationship',
        'label' => t('User create order'),
    ),
    'argument' => array(
        'handler' => 'views_handler_argument_user_uid',
        'numeric' => TRUE,
        'validate type' => 'uid',
    ),
  );


  $data['node']['handlername'] = array(
    'title' => t('Name of my handler'),
    'help' => t('Description of my handler.'),
    'field' => array(
      'handler' => 'views_study_handler_handlername',
    ),
  );

  return $data;
}