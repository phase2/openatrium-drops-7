
/**
 *  @file
 *  Attach behaviors to formatter radio select when selecting a media's display
 *  formatter.
 */

(function ($) {
namespace('Drupal.media.formatForm');

Drupal.media.mediaFormatSelected = {};

Drupal.behaviors.mediaFormatForm = {
  attach: function (context, settings) {
    // Add the "Submit" button inside the IFRAME that trigger the behavior of
    // the hidden "OK" button that is outside the IFRAME.
    // @see Drupal.media.browser.validateButtons() for more details.

    // @note I think this should be handled in media.browser.js in
    // Drupal.media.browser.validateButtons but I'm not sure how crufty this
    // particular functionality is. We should evaluate if it is still needed.

    // @TODO can these be added to the content being displayed via form_alter?

    // Adding the buttons should only be done once in order to prevent multiple
    // buttons from being added if part of the form is updated via AJAX
    $('#media-wysiwyg-format-form').once('format', function() {
      $('<a class="button fake-ok">' + Drupal.t('Submit') + '</a>').appendTo($('#media-wysiwyg-format-form')).bind('click', Drupal.media.formatForm.submit);
    });
  }
};

Drupal.media.formatForm.getOptions = function () {
  // Get all the values
  var ret = {}; $.each($('#media-wysiwyg-format-form fieldset#edit-options *').serializeArray(), function (i, field) { ret[field.name] = field.value; });
  return ret;
};

Drupal.media.formatForm.getFormattedMedia = function () {
  var formatType = $("#edit-format").val();
  return { type: formatType, options: Drupal.media.formatForm.getOptions(), html: Drupal.settings.media.formatFormFormats[formatType] };
};

Drupal.media.formatForm.submit = function () {
  // @see Drupal.behaviors.mediaFormatForm.attach().
  var buttons = $(parent.window.document.body).find('#mediaStyleSelector').parent('.ui-dialog').find('.ui-dialog-buttonpane button');
  buttons[0].click();
}

})(jQuery);
