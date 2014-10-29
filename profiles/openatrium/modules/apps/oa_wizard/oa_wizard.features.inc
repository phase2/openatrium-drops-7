<?php
/**
 * @file
 * oa_wizard.features.inc
 */

/**
 * Implements hook_default_oa_wizard().
 */
function oa_wizard_default_oa_wizard() {
  $items = array();
  $items['section_wizard'] = entity_import('oa_wizard', '{
    "bundle" : "wizard",
    "language" : "und",
    "name" : "section_wizard",
    "title" : "Section Wizard",
    "created" : "0",
    "changed" : "0",
    "data" : null,
    "field_wizard_steps" : { "und" : [
        {
          "value" : "title: Title | fields: [title]\\r\\ntitle: Section Type | fields: [field_oa_section]\\r\\ntitle: Section Visibility | fields: [field_oa_group_ref,field_oa_team_ref,field_oa_user_ref]",
          "format" : null,
          "safe_value" : "title: Title | fields: [title]\\r\\ntitle: Section Type | fields: [field_oa_section]\\r\\ntitle: Section Visibility | fields: [field_oa_group_ref,field_oa_team_ref,field_oa_user_ref]"
        }
      ]
    },
    "field_wizard_type" : { "und" : [ { "value" : "oa_section" } ] }
  }');
  $items['space_wizard'] = entity_import('oa_wizard', '{
    "bundle" : "wizard",
    "language" : "und",
    "name" : "space_wizard",
    "title" : "Space Wizard",
    "created" : "0",
    "changed" : "0",
    "data" : null,
    "field_wizard_steps" : { "und" : [
        {
          "value" : "title: Title | fields: [title]\\r\\ntitle: Space Type | fields: [field_oa_space_type]\\r\\ntitle: Space Access | fields: [group_access]",
          "format" : null,
          "safe_value" : "title: Title | fields: [title]\\r\\ntitle: Space Type | fields: [field_oa_space_type]\\r\\ntitle: Space Access | fields: [group_access]"
        }
      ]
    },
    "field_wizard_type" : { "und" : [ { "value" : "oa_space" } ] }
  }');
  return $items;
}
