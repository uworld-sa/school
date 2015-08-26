<?php

class views_study_handler_handlername extends views_handler_field {
  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['field_category'] = array(
      'table' => 'field_data_field_category',
      'field' => 'field_category_tid',
    );
  }

  /**
   * Loads additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['option_a'] = array('default' => '');
    $options['option_b'] = array('default' => '');

    return $options;
  }

  /**
   * Creates the form item for the options added.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['option_a'] = array(
      '#type' => 'textfield',
      '#title' => t('class'),
      '#default_value' => $this->options['option_a'],
      '#description' => t('Some description.'),
      '#weight' => -10,
    );

    $form['option_b'] = array(
      '#type' => 'textfield',
      '#title' => t('data-follow_name'),
      '#default_value' => $this->options['option_b'],
      '#description' => t('Some description.'),
      '#weight' => -9,
    );
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    return format_string('<span class="@option_a" data-follow_name="@option_b">' . t('Term id') . ':@field_category_tid</span>', array(
      '@field_category_tid' => $values->field_data_field_category_field_category_tid,
      '@option_a' => $this->options['option_a'],
      '@option_b' => $this->options['option_b'],
    ));
  }
}