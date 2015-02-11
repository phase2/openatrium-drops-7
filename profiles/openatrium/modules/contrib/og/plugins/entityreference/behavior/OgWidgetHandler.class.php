<?php

/**
 * OG behavior handler.
 */
class OgWidgetHandler extends EntityReference_BehaviorHandler_Abstract {

  public function access($field, $instance) {
    return ($field['settings']['handler'] == 'og' || strpos($field['settings']['handler'], 'og_') === 0) && $instance['widget']['type'] == 'og_complex';
  }

  /**
   * Override EntityReferenceHandler::settingsForm().
   */
  public function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);

    $settings = !empty($instance['settings']['behaviors']['og_widget']) ? $instance['settings']['behaviors']['og_widget'] : array();
    $settings += array(
      'default' => array(
        'widget_type' => 'options_select',
        'widget_settings' => array(),
      ),
      'admin' => array(
        'widget_type' => 'entityreference_autocomplete',
        'widget_settings' => array(),
      ),
    );

    $field_types = array(
      'default' => array(
        'title' => t('Default widget type'),
        'description' => t('The widget type of the field as it will appear to the user.'),
      ),
      'admin' => array(
        'title' => t('Administrator widget type'),
        'description' => t('The widget type of the field that will appear only to a user with "Administer group" permission.'),
      ),
    );

    module_load_include('inc', 'field_ui', 'field_ui.admin');
    $widget_types = field_ui_widget_type_options('entityreference');
    unset($widget_types['og_complex']);
    $field_info_widget_types = field_info_widget_types();

    foreach ($field_types as $field_type => $value) {
      $settings_id = 'og-' . $field_type . '-settings';
      $form[$field_type]['widget_type'] = array(
        '#type' => 'select',
        '#title' => $value['title'],
        '#required' => TRUE,
        '#options' => $widget_types,
        '#default_value' => $settings[$field_type]['widget_type'],
        '#description' => $value['description'],
        '#ajax' => array(
          'callback' => 'og_' . $field_type . '_settings_form_ajax',
          'wrapper' => $settings_id,
          'method' => 'replace',
          'event' => 'change',
        ),
      );
      $form[$field_type]['widget_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('@title Settings', array('@title' => $value['title'])),
        '#tree' => TRUE,
        '#attributes' => array(
          'id' => $settings_id,
        ),
      );
      if ($settings[$field_type]['widget_type'] && !empty($field_info_widget_types[$settings[$field_type]['widget_type']])) {
        $widget_type = $field_info_widget_types[$settings[$field_type]['widget_type']];
        $current_settings = isset($settings[$field_type]['widget_settings']) ?  $settings[$field_type]['widget_settings'] : array();
        $fake_instance = array(
          'widget' => array(
            'type' => $settings[$field_type]['widget_type'],
            'module' => $widget_type['module'],
            'settings' => $current_settings,
          ) + $instance['widget'],
        ) + $instance;
        $additions = module_invoke($widget_type['module'], 'field_widget_settings_form', $field, $fake_instance);
        if ($additions) {
          $form[$field_type]['widget_settings'] += $additions;
        }
      }
    }

    // Field access settings.
    $form['access_override'] = array(
      '#title' => t('Allow entity access to control field access'),
      '#description' => t('By default, the <em>administer group</em> permission is required to directly edit this field. Selecting this option will allow access to anybody with access to edit the entity.'),
      '#type' => 'checkbox',
      '#default_value' => isset($settings['access_override']) ? $settings['access_override'] : FALSE,
    );

    return $form;
  }

}
