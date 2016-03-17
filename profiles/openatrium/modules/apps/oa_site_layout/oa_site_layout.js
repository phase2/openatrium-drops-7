/**
 * @file
 * Handle javascript for site layout widgets
 */

(function ($) {

  Drupal.behaviors.oaSiteLayout = {
    attach: function (context, settings) {
      if (settings.oa_site_layout.action_buttons.length > 0) {
        $(settings.oa_site_layout.action_buttons, context).each(function() {
          // hide any action buttons that we are showing elsewhere
          $(this).css('display', 'none');
        });
      }
    },
  };

})(jQuery);

