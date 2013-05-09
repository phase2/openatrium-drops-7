/**
 * @file
 * Defines the behavior of the toolbar menu toggle button.
 */
(function ($) {

  Drupal.behaviors.toolbarMenuButton = {
    attach: function(context, settings) {
      var $tray = $('#navbar .navbar-tray');
      var $button = $('#toolbar-menu-button');
      var $navbar = $('#oa-navbar');

      if ($button.length) {
        // if using the button in toolbar, hide the navbar module's nav bar
        $('#navbar .navbar-bar').hide();
      }
      if ($tray.length && $button.length) {
        $button.unbind('click');
        $button.click(function(e) {
          $('body').toggleClass('menu-tray-open');
          $tray.toggleClass('active');

          // When it's stickied, we need to push the tray down.
          if (settings.oa_toolbar_sticky == 1 && $navbar.css('position') !== 'static') {
            // Use attr for !important to override radix.
            $tray.attr('style', 'top: ' + $navbar.height() + 'px !important');
          }
          else {
            $tray.attr('style', 'top: 0 !important');
          }
        });
      }
    }
  }

}(jQuery));
