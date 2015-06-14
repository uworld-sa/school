<?php
/**
 * Created by PhpStorm.
 * User: sergey
 * Date: 09.06.15
 * Time: 23:17
 */
/*
function new_bartik_theme_registry_alter(&$theme_registry) {
    $theme_path = path_to_theme();

    // Radios.
    if (isset($theme_registry['select'])) {
        $theme_registry['select']['type'] = 'theme';
        $theme_registry['select']['theme path'] = drupal_get_path('theme','new_bartik');
        $theme_registry['select']['template'] = drupal_get_path('theme','new_bartik') . '/templates/fields/field--type-select';
        unset($theme_registry['select']['function']);
    }
}
*/

function new_bartik_select($variables) {
    $element = $variables['element'];
    element_set_attributes($element, array('id', 'name', 'size'));
    _form_set_class($element, array('form-select custom_class'));

    // Now we implement our own custom function for theming the options.
    // Change THEME to your theme name.
    return '<select' . drupal_attributes($element['#attributes']) . '>'
    . new_bartik_form_select_options($element) . '</select>';
}


function new_bartik_form_select_options($element, $choices = NULL) {
    if (!isset($choices)) {
        $choices = $element['#options'];
    }
    // array_key_exists() accommodates the rare event
    // where $element['#value'] is NULL.
    // isset() fails in this situation.
    $value_valid = isset($element['#value'])
        || array_key_exists('#value', $element);
    $value_is_array = $value_valid && is_array($element['#value']);
    $options = '';
    foreach ($choices as $key => $choice) {
        if (is_array($choice)) {
            $options .= '<optgroup label="' . $key . '">';
            $options .= form_select_options($element, $choice);
            $options .= '</optgroup>';
        }
        elseif (is_object($choice)) {
            $options .= form_select_options($element, $choice->option);
        }
        else {
            $key = (string) $key;

            // Get option attributes if set.
            // The attributes are added to the parent select element,
            // which we can access here ($element)
            // The #option_attributes have the same keys as the #option
            // elements, and can be added here to the current option by key
            $attributes = "";
            $element['#option_attributes'][$key]['class'] = 'custom_option_class';

            if (isset($element['#option_attributes'][$key])) {
                $attributes = drupal_attributes($element['#option_attributes'][$key]);
            }

            // check if this element is selected
            if ($value_valid
                && (!$value_is_array && (string) $element['#value'] === $key
                    || ($value_is_array && in_array($key, $element['#value'])))) {
                $selected = ' selected="selected"';
            } else {
                $selected = '';
            }

            // Here we add the attributes to the option
            $options .= '<option ' . $attributes
                . ' value="' . check_plain($key) . '"' . $selected . '>'
                . check_plain($choice) . '</option>';
        }
    }
    return $options;
}

function new_bartik_preprocess_node(&$variables) {
	if (module_exists('context')) {
		$contexts = context_active_contexts();
		

		if ( isset($contexts['desktop'])) {
			$variables ['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__desktop';
		}
		if ( isset($contexts['mobile'])) {
			$variables ['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__mobile';
		}
	}

}
