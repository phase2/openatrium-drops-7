/**
 * @file
 * Manage spacing for dashboard and navbar tray.
 */

document.documentElement.className = 'js';

(function ($) {

  var $use_mouseover;

  function debounce(func, wait, immediate) {
    var timeout;
    return function() {
      var context = this, args = arguments;
      var later = function() {
        timeout = null;
        if (!immediate) func.apply(context, args);
      };
      var callNow = immediate && !timeout;
      clearTimeout(timeout);
      timeout = setTimeout(later, wait);
      if (callNow) func.apply(context, args);
    };
  }

  Drupal.behaviors.oaDashboard = {
    attach: function(context, settings) {
      // Remove Radix dropdown on hover.

      $use_mouseover = ('oa_toolbar' in settings) ? settings.oa_toolbar.mouseover : false;

      var $navbar = $('#navbar-bar');
      if ($navbar.length) {
        // if using OA navbar, hide the navbar module's nav bar and remove its offset
        $navbar.hide();
        $navbar.removeAttr('data-offset-top');
      }
    }
  };

  function unbindMouse(selector) {
    $(selector).each(function () {
      $(this).unbind('mouseenter');
      $(this).unbind('mouseleave');
      $(this).unbind('focusin');
      $(this).unbind('focusout');
      $(this).unbind('click.oa-radix.dropdown');
      if ($(this).is('.dropdown')) {
        var toggle = $('a.dropdown-toggle', $(this));
        if ((toggle.length > 0) && (toggle.attr('href') != '')) {
          toggle.data('href', toggle.attr('href'));
          toggle.attr('href', '');
        }
      }
    });
  }

  function fixMouseOverLoad() {
    // Always remove dropdown hover for mobile menus
    unbindMouse('.oa-responsive-regions-mobile.radix-dropdown-processed');
    fixMouseOver();
  }

  // Helper function to show the dropdown.
  // These two functions taken from radix.script.js
  function show(dropdown) {
    if (!$(dropdown).hasClass('open')) {
      $('>[data-toggle="dropdown"]', dropdown).trigger('click.bs.dropdown');
    }
  }

  // Helper function to hide the dropdown.
  function hide(dropdown) {
    if ($(dropdown).hasClass('open')) {
      $('>[data-toggle="dropdown"]', dropdown).trigger('click.bs.dropdown');
    }
  }

  function fixMouseOver() {
    if (!$use_mouseover) {
      unbindMouse('.radix-dropdown-processed');
    }
    else if ($(document).width() < 768) {
      unbindMouse('.radix-dropdown-processed');
    }
    else {
      // Restore some mouseover on larger screens
      $('.radix-dropdown-processed').each(function () {
        if ($(this).not('.oa-responsive-regions-mobile')) {
          // Show dropdown on hover and focus.
          $(this).on('mouseenter.radix.dropdown', function(e) {
            show($(this));
          });
          $(this).on('mouseleave.radix.dropdown', function(e) {
            hide($(this));
          });
          $(this).on('click.oa-radix.dropdown', function(e) {
            hide($(this));
          });
          // Restore any links
          if ($(this).is('.dropdown')) {
            var toggle = $('a.dropdown-toggle', $(this));
            if ((toggle.length > 0) && (toggle.attr('href') == '') && (toggle.data('href') != '')) {
              toggle.attr('href', toggle.data('href'));
              toggle.data('href', '');
            }
          }
        }
      });
      // Don't allow mouse-over menus in main content area
      unbindMouse('#main .radix-dropdown-processed');
    }
  }

  var updateMouseOver = debounce(function(){
    fixMouseOver();
  }, 250);
  var updateMouseOverLoad = debounce(function(){
    fixMouseOverLoad();
  }, 250);

  window.addEventListener('load', updateMouseOverLoad);
  window.addEventListener('resize', updateMouseOver);

}(jQuery));
