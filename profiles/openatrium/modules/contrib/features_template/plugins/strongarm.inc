<?php
$plugin = array(
  'component' => 'variable',
  'implement callback' => 'features_template_strongarm_template',
  'features info callback' => 'features_template_strongarm_info',
  'deleted callback' => 'features_template_strongarm_delete',
);
function features_template_strongarm_info(&$info, $datum) {
  $key = features_template_strongarm_key($datum);
  if (!isset($info['features']['variable']) || !in_array($key, $info['features']['variable'])) {
    $info['features']['variable'][] = $key;
  }
}
function features_template_strongarm_template($template, $datum) {
  $key = features_template_strongarm_key($datum);
  $fields[$key] = reset($template);
  $fields[$key]->name = $key;
  return $fields;
}

function features_template_strongarm_delete($datum) {
  $key = features_template_strongarm_key($datum);
  variable_del($key);
}

function features_template_strongarm_key($datum) {
  return $datum['name'];

}
