/**
 * @file
 * Javascript for oa_core's space_type/section_type functionality.
 */
(function ($) {
  Drupal.behaviors.oaCoreSpaceType = {
    attach: function (context, settings) {
      var self = this;

      // The default response to oaCoreSpaceTypeChange: select the Panelizer
      // default for this space_type.
      $(document).on('oaCoreSpaceTypeChange', function (e) {
        var $layout_selector = $('select:[name="panelizer[page_manager][name]"]', context);

        if (!e.override && e.options.layout) {
          // Override panelizer layout selector.
          $layout_selector.val(e.options.layout);
        }
      });

      // Setup controls to trigger the oaCoreSpaceTypeChange event.
      $(settings.oaCoreSpaceTypeSelector, context).change(function() {
        self.updateSection(context, settings);
      });
      $('input:[name="field_oa_section_override[und]"]', context).change(function() {
        self.updateSection(context, settings);
        self.setLayoutVisibility(this);
      });

      // Trigger it immediately on page load.
      self.updateSection(context, settings);
      self.setLayoutVisibility($('input:[name="field_oa_section_override[und]"]', context));
    },

    setLayoutVisibility: function(element) {
      $('.pane-panelizer-form-default').toggle($(element).is(':checked'));
    },

    updateSection: function(context, settings) {
      var spaceTypeSelector = $(settings.oaCoreSpaceTypeSelector, context),
          spaceType = spaceTypeSelector.length ? spaceTypeSelector.val() : settings.oaCoreSpaceType;

      if (spaceType && settings.oaCoreSpaceTypeOptions[spaceType]) {
        // Trigger the 'oaCoreSpaceTypeChange' event which other modules can
        // respond to.
        $.event.trigger({
          type: 'oaCoreSpaceTypeChange',
          spaceType: spaceType,
          options: settings.oaCoreSpaceTypeOptions[spaceType],
          override: $('input:[name="field_oa_section_override[und]"]:checked', context).length
        });
      }
    }
  };
})(jQuery);
