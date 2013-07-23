/**
 * @file
 * Bind the colorpicker event to the Colors form element.
 */

(function ($) {

Drupal.behaviors.colors = {
  attach: function() {

    var farb = $.farbtastic('#colors-colorpicker');

    // Loop over each calendar_color type.
    $('.colorpicker-input').each(function() {

      // Set the background colors of all of the textfields appropriately.
      farb.linkTo(this);

      // When clicked, they get linked to the associated farbtastic colorpicker.
      $(this).click(function () {
        farb.linkTo(this);
      });
    });
  }
};

})(jQuery);
