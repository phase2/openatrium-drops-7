/**
 * @file
 * Custom scripts for theme.
 */
(function ($) {
  Drupal.behaviors.hideEmptyPanes = {
    attach: function (context, settings) {
      $('#main-wrapper .panel-pane, .pane-pane-oa-form-actions', context).each(function () {
        // Look for empty panels that also don't contain input fields
        // (input fields don't generate text()
        if ($(this).find('input,img,.geofieldMap').length == 0 && $(this).text().trim().length == 0) {
          $(this).css('display', 'none');
        }
      });
      // Check the edit panel at bottom AFTER we have done the above hiding
      $('.pane-oa-edit-minipanel .radix-layouts-content', context).each(function () {
        var text = $(this).find('.panel-pane:visible').text();
        if (text.trim().length == 0) {
          $(this).css('display', 'none');
        }
      });
      $('.oa-responsive-regions-toggle-left', context).each(function () {
        $(this).bind('click', function() {
          $('.navbar-tray').removeClass('active');
        });
      });
    }
  };
})(jQuery);
