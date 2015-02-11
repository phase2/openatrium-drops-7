<?php
$plugin = array(
  'component' => 'panelizer_defaults',
  'implement callback' => 'features_template_panelizer',
  'features info callback' => 'features_template_panelizer_info',
  'deleted callback' => 'features_template_panelizer_delete',
);
function features_template_panelizer_info(&$info, $datum) {
  $key = features_template_panelizer_key($datum);
  if (!isset($info['features']['panelizer_defaults']) || !in_array($key, $info['features']['panelizer_defaults'])) {
    $info['features']['panelizer_defaults'][] = $key;
  }
}
function features_template_panelizer($template, $datum) {
  $key = features_template_panelizer_key($datum);
  $fields[$key] = reset($template);
  $fields[$key]->name = $key;
  $fields[$key]->panelizer_key = $datum['bundle_type'];
  $fields[$key]->panelizer_type = $datum['entity_type'];
  return $fields;
}

function features_template_panelizer_delete($datum) {
}

function features_template_panelizer_key($datum) {
  return implode(':', array($datum['entity_type'], $datum['bundle_type'], $datum['mode']));

}
