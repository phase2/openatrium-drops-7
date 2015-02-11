<?php

if (module_exists('views')) {
  $plugin = array(
    'title' => t('Render Views filters as an autocomplete widget'),
    'description' => t('Provides an autocomplete widget for Views filters on this field.'),
    'class' => 'EntityReferenceBehavior_ViewsAutocomplete',
    'behavior type' => 'field',
  );
}
