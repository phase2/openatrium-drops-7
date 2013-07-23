/**
 * @file
 * Javascript for oa_buttons
 */
(function ($) {
  Drupal.behaviors.oaButtons = {
    attach: function (context, settings) {
      var _self = this;
      $('select:[name="field_oa_section[und]"], select:[name="field_oa_space_type[und]"]', context).change(function() {
        _self.updateSection(context);
      });

      $('input:[name="field_oa_section_override[und]"]', context).change(function() {
        _self.updateSection(context);
        _self.setLayoutVisibility(this);
      });
      _self.updateSection(context);
      _self.setLayoutVisibility($('input:[name="field_oa_section_override[und]"]', context));
    },
    setLayoutVisibility: function(element) {
      if ($(element).is(':checked')) {
        $('.pane-panelizer-form-default').show();
      }
      else {
        $('.pane-panelizer-form-default').hide();
      }
    },
    updateSection: function(context) {
      var section = $('select:[name="field_oa_section[und]"], select:[name="field_oa_space_type[und]"]', context).val();
      if (section && Drupal.settings.oaButtons[section]) {
        var layout = Drupal.settings.oaButtons[section].layout;
        var $layout_selector = $('select:[name="panelizer[page_manager][name]"]', context);
        var override = $('input:[name="field_oa_section_override[und]"]:checked', context).length;

        if (!override && layout) {
          // Override panelizer layout selector.
          $layout_selector.val(layout);

          // Override allowed node types.
          $('#edit-field-oa-node-types input:checkbox', context).attr({checked: false});
          for (var type in Drupal.settings.oaButtons[section].node_options) {
            $('#edit-field-oa-node-types input:checkbox:[value="' + Drupal.settings.oaButtons[section].node_options[type] + '"]', context).attr({checked: true});
          }
        }
      }
    }
  };
})(jQuery);
