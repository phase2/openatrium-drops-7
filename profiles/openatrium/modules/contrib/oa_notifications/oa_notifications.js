/**
 * @file
 * Javascript for oa_notifications module.
 */
(function ($) {

  Drupal.behaviors.oaNotifications = {
    attach: function (context, settings) {
      $('ul#contextual-tabs .flag-wrapper a').removeClass('btn flag');
      $('ul#contextual-tabs .flag-message, ul#contextual-tabs .flag-throbber, ul#contextual-tabs .flag-wrapper i').remove();
    }
  };

})(jQuery);
