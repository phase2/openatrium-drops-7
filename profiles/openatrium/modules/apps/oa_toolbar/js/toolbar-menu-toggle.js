/**
 * @file
 * Defines the behavior of the toolbar menu toggle button.
 */
(function ($) {

  Drupal.behaviors.toolbarMenuButton = {
    attach: function(context, settings) {

      // Atrium nav bar
      var $oa_navbar = $('#oa-navbar');
      var $button = $('#toolbar-menu-button');

      // Navbar module nav bar
      var $tray = $('#navbar-tray');
      var $navbar = $('#navbar-bar');

      if ($navbar.length) {
        // move the shortcuts tray to the top of the admin menu tray
        var $shortcuts = $('#navbar-tray--2 .navbar-lining').children();
        if ($shortcuts.length && $tray.length) {
          var $short_tray = $shortcuts.detach();
          $('#navbar-tray .navbar-lining').prepend($short_tray);
        }
      }
      if ($tray.length && $button.length) {
        $button.unbind('click');
        $tray.removeClass('active'); // start closed
        $('body').removeClass('navbar-tray-open navbar-vertical navbar-horizontal');
        $tray.addClass('navbar-tray-vertical'); // use vertical admin menu
        $tray.removeClass('navbar-tray-horizontal');
        $navbar.removeAttr('data-offset-top');
        $navbar.parent().removeClass('overlay-displace-top navbar-processed');
        $button.click(function(e) {
          $('body').toggleClass('navbar-tray-open');
          $tray.toggleClass('active');

          if ($(this).attr('id') == 'toolbar-menu-button') {
            // If using the Atrium admin button, then place menu beneath button
            var $top = $(this)[0].getBoundingClientRect().top + $(this).outerHeight();
            $tray.attr('style', 'top: ' + $top + 'px !important');
          }
          // When it's stickied, we need to push the tray down.
          else if ($oa_navbar.length && $oa_navbar.css('position') !== 'static') {
            // Use attr for !important to override radix.
            $tray.attr('style', 'top: ' + $oa_navbar.height() + 'px !important');
          }
          else {
            $tray.attr('style', 'top: 0 !important');
          }
        });
        if (typeof(Drupal.displace) != "undefined") {
          Drupal.displace();  // recalculate offsets
        }
      }
    }
  };

  if (localStorage){
    localStorage.setItem('Drupal.navbar.trayVerticalLocked', true);
  }

}(jQuery));
