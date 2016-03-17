/**
 * @file
 * Javascript for oa_notifications module.
 */
(function ($) {

  Drupal.behaviors.oaNotifications = {
    attach: function (context, settings) {
      $('ul#contextual-tabs .flag-wrapper a').removeClass('btn flag');
      $('ul#contextual-tabs .flag-message, ul#contextual-tabs .flag-throbber, ul#contextual-tabs .flag-wrapper i').remove();

      // Take control of notification removal ajax links on node/add form
      $('body.page-node-add .pane-node-form-oa-notifications .remove-link a').once('oa-notify-processed', function () {
        $(this).on('click', function (e) {
          var parent = $(this).parent().parent('li');
          var removed = $('.pane-node-form-oa-notifications input.oa-notifications-remove');
          // Save list of items that have been removed via javascript.
          var value = removed.val() + ',' + parent.data('remove');
          removed.val(value);
          // Hide the element that we removed.
          parent.hide();
          e.preventDefault();
          return false;
        });
      });

      // Show/hide expand all button
      $('.oa-notify-details').each(function () {
        var hasDetails = $(this).siblings('.has-details');
        if (hasDetails.length > 0) {
          $(this).show();
        }
        else {
          $(this).hide();
        }
      });
    }
  };

})(jQuery);
