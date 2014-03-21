/**
 * @file
 * Javascript for oa_buttons
 */
(function ($) {
  Drupal.behaviors.oaButtons = {
    attach: function (context, settings) {
      $(document).on('oaCoreSpaceTypeChange', function (e) {
        var type;
        if (!e.override && e.options.layout) {
          // Override allowed node types.
          $('#edit-field-oa-node-types input:checkbox', context).attr({checked: false});
          for (type in e.options.node_options) {
            $('#edit-field-oa-node-types input:checkbox:[value="' + e.options.node_options[type] + '"]', context).attr({checked: true});
          }
        }
      });
    }
  };
})(jQuery);
