/**
 * @file
 * Manage spacing for dashboard and navbar tray.
 */

(function ($) {

  Drupal.behaviors.oaDashboard = {
    attach: function(context, settings) {
      var $oa_navbar = $('#oa-navbar');
      var $navbar = $('#navbar-bar');
      var $oa_responsive_navbar = $('#oa-responsive-regions-navbar');

      var $height = 0;
      if ($navbar.length) {
        // if using OA navbar, hide the navbar module's nav bar and remove its offset
        $navbar.hide();
        $navbar.removeAttr('data-offset-top');
      }
      if ($oa_navbar.length) {
        if ($oa_navbar.css('position') !== 'static') {
          $oa_navbar.attr('data-offset-top', '');
          $height = $oa_navbar.height();
        }
        else if ($oa_responsive_navbar.length) {
          $oa_responsive_navbar.attr('data-offset-top', '');
          $height = $oa_responsive_navbar.height();
        }
      }
      if (typeof(Drupal.displace) != "undefined") {
        Drupal.displace();  // recalculate offsets
      }
      else if ($height > 0) {
        // navbar not being used, so just offset the body padding
        $('body').css('padding-top', $height);
      }
    }
  }

}(jQuery));
