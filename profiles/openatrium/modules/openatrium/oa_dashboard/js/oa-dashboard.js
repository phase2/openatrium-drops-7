/**
 * @file
 * Manage spacing for dashboard and navbar tray.
 */
(function ($) {

  Drupal.behaviors.oaDashboard = {
    attach: function(context, settings) {
      var $tray = $('#navbar .navbar-tray');
      var $button = $('#toolbar-menu-button');
      var $navbar = $('#oa-navbar');

      $(window).resize(function() {
        if ($navbar.css('position') == 'static') {
          $('body').css('padding-top', '0');
        }
        else if (settings.oa_toolbar_sticky == 1) {
          $('body').css('padding-top', $navbar.height() + 10);
        }
      });
      $(window).resize();
    }
  }

}(jQuery));
