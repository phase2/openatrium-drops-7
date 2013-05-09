Fieldable Panel Panes support multiple bundles, but at this time there is no
UI to create bundles.

Bundles can be created in a module via hook_entity_info_alter(). The code
will look something like this:

function MYMODULE_entity_info_alter(&$entity_info) {
  $entity_info['fieldable_panels_pane']['bundles']['my_bundle_name'] = array(
    'label' => t('My bundle name'),
    'pane category' => t('My category name'),
    'pane top level' => FALSE, // set to true to make this show as a top level icon
    'pane icon' => '/path/to/custom/icon/for/this/pane.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_panes_type',
      'bundle argument' => 4,
      // Note that this has all _ replaced with - from the bundle name.
      'real path' => 'admin/structure/fieldable-panels-panes/manage/my-bundle-name',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );
}

Fields are then added to your bundle as normal through the Manage Fields and
Display Fields tabs in the UI.

You can use this hook to rename or remove the default bundle but remember that
doing so will break any content currently using that bundle. If you do this
be sure to also fix any content already using it.
