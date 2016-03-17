/**
 * @file
 * JS for Responsive Panels Regions.
 */

(function ($) {

  "use strict";

  // These variables are used for handling the mobile menus on screen resize
  var isMobile = false;
  var mobileMenus = [];
  var tracker = 1;

  function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + cvalue + "; " + expires + "; path=/";
  }

  function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
      var c = ca[i];
      while (c.charAt(0)==' ') c = c.substring(1);
      if (c.indexOf(name) == 0) return c.substring(name.length,c.length);
    }
    return "";
  }

  function saveState(position) {
    // save the toggle state in cookie
    // Cookie plugin not loaded for anonymous users
    if ($.cookie) {
      var state = $('body').hasClass('oa-responsive-region-' + position + '-on');
      setCookie("oa-responsive-regions-" + position, state, 365)
    }
  }

  function getState(position) {
    // return the cookie state
    if ($.cookie) {
      var state = getCookie("oa-responsive-regions-" + position);
      return state;
    }
    return false;
  }

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

  function maxSidebarHeight() {
    var region = $('.oa-responsive-primary');
    var viewport = $(window).height();
    if (region.length) {
      var toolbarHeight = 0;
      var toolbar = $('.panel-panel-inner .oa-responsive-region-bottom.oa-responsive-fixed');
      if (toolbar.length) {
        toolbarHeight += $(toolbar).height();
        $(region).css('padding-bottom', $(toolbar).height());
      }
      var toolbar = $('.panel-panel-inner .oa-responsive-region-top.oa-responsive-fixed');
      if (toolbar.length) {
        toolbarHeight += $(toolbar).height();
        $(region).css('padding-top', $(toolbar).height());
      }
      viewport = viewport - toolbarHeight;
      var h = region.height();
      if (h < viewport) {
        $('.oa-responsive-region-right').each(function() {
          $(this).height(viewport);
        });
        $('.oa-responsive-region-left').each(function() {
          $(this).height(viewport);
        });
      }
    }
  }

  function setMenu() {
    if (isMobile) {
      // wire the mobile admin
      if (($('#toolbar-menu-button').length > 0) && ($('#oa-navbar-admin').length > 0)) {
        $('#navbar-tray .navbar-menu-administration').attr('menu-desktop', tracker)
          .children('ul').attr('menu-item', tracker).appendTo("#oa-navbar-admin .oa-navbar-inner");
        tracker++;
      }
      else {
        $('.oa-navbar button.navbar-toggle.admin').hide();
      }

      // move each menu, Bootstrap handles the menu toggle
      $.each(mobileMenus, function(i, val) {
        $("."+val+"-mobile-menu").each(function() {
          if ($(this).hasClass('oa-mobile-expand')) {
            // defer expanded items
          }
          else {
            $(this).find('.pane-content').appendTo("#oa-navbar-" + val + " .oa-navbar-inner");
          }
        });
      });
      // Now handle submenus to be appended and expanded
      $.each(mobileMenus, function(i, val) {
        $("."+val+"-mobile-menu").each(function() {
          if ($(this).hasClass('oa-mobile-expand')) {
            var item = $(this).find('.pane-content ul.dropdown-menu').appendTo("#oa-navbar-" + val + " .oa-navbar-inner");
            item.addClass('oa-mobile-expanded');
          }
        });
      });
    }
  }

  function fixMobileMenus() {
    if ($('button.navbar-toggle').is(':visible') != isMobile) {
      if (isMobile == true) {
        //there was a change, if isMobile was true the change is to false and is now desktop
        //here we want to move the menu items back
        for (var i = 1; i <= tracker; i++) {
          $('.oa-navbar').find("[menu-item='" + i +"']").appendTo("[menu-desktop='" + i +"']");
        }
      }
      isMobile = $('button.navbar-toggle').is(':visible');
      setMenu();
    }
  }

  function fixColumnWidthOnResize() {
    $('.oa-responsive-primary').each(function () {
      var wrapper = $(this).parent().parent();
      var getInline = $(wrapper).attr('style');
      var inlineWidth = getInline.indexOf('width');

      if (($(window).width() < 992) && (inlineWidth > -1)) {
        // Screen smaller than 992 and we have a width already set
        // We need to clear the width and bring back the first style property
        $(wrapper).attr('style', 'display: block;');
      } else if (($(window).width() > 991 && (inlineWidth == -1))) {
        // Screen is larger than 991 and we do not have a width set yet
        // We need to calculate the width again and set it
        var wrapperLeft = $('.oa-responsive-region-left').outerWidth();
        var width = $(wrapper).outerWidth() + wrapperLeft;
        var percent = Math.floor(width / $(wrapper).parent().outerWidth() * 100);
        $(wrapper).attr('style', 'display: block; width: ' + percent + '%;');
      }
    });
  }

  Drupal.behaviors.responsive_panels_regions = {
    attach: function(context) {
      function getStyle(el){
        // To determine if width uses % or px, we need to use getComputedStyle
        // But it only works when display is none.
        var display = window.getComputedStyle(el).getPropertyValue("display");
        el.style.display = "none";
        var width = window.getComputedStyle(el).getPropertyValue("width");
        el.style.display = display;
        return width;
      }
      $('.oa-responsive-regions-toggle', context).each(function () {
        $(this).bind('click', function() {
          var position = $(this).data().position;
          Drupal.ResponsivePanelsRegions.toggleRegion(position);
        });
      });
      // Compute the sizes of the responsive regions
      var widths = {left: 0, right: 0, top: 0, bottom: 0};
      var heights = {left: 0, right: 0, top: 0, bottom: 0};
      $('.panel-panel-inner > .oa-responsive-region', context).each(function () {
        if ($(this).css('position') == 'absolute') {
          var position = $(this).data().position;
          var wrapper = $(this).parent().parent();
          widths[position] += $(wrapper).outerWidth();
          heights[position] += $(wrapper).outerHeight();
        }
      });
      // We need to copy the css classes from the panels pane div to its
      // parent grid element (parent.parent)
      $('.panel-panel-inner > .oa-responsive-region', context).each(function () {
        var position = $(this).data().position;
        var wrapper = $(this).parent().parent();
        if ((position != 'center') && (position != 'fluid')) {
          $(wrapper).addClass($(this).attr('class'));
          // Prevent absolute positioning on parent row when bar is fixed and expanded
          if ($(wrapper).hasClass('oa-responsive-expand') && $(wrapper).hasClass('oa-responsive-fixed')) {
            $(wrapper).removeClass('oa-responsive-region-' + position);
          }
          // Prevent parent row from being fixed
          $(wrapper).removeClass('oa-responsive-fixed');
        }
        // Regions are initially hidden in css to avoid flicker, so show them now
        $(this).css('display', 'block');
        $(wrapper).parent().addClass('oa-responsive-region-row-' + position);
      });
      // Now adjust the size of the primary region
      $('.oa-responsive-primary', context).each(function () {
        var wrapper = $(this).parent().parent();
        var width = $(wrapper).outerWidth() + widths.left + widths.right;
        var percent = Math.floor(width / $(wrapper).parent().outerWidth() * 100);
        var style = getStyle($(wrapper).get(0));
        // If the original width used % then compute new % otherwise pixels
        if (style && (style != 'auto')) {
          if (style.indexOf('%') >= 0) {
            $(wrapper).css('width', percent + '%');
          }
          else {
            $(wrapper).width(width);
          }
        }
      });
      $('.oa-responsive-regions-toggle', context).each(function () {
        // Restore saved cookie states
        var position = $(this).data().position;
        if (getState(position) == 'true') {
          Drupal.ResponsivePanelsRegions.showRegion(position);
        }
      });
    }
  };

  Drupal.behaviors.mobile_nav_behavior = {
    attach: function(context) {
      isMobile = $('button.navbar-toggle').is(':visible');

      mobileMenus = [];
      // Determine which menu toggles are on page
      $('button.navbar-toggle').each(function () {
        var menuid = $(this).data('target');
        menuid = menuid.replace("#oa-navbar-", "");
        mobileMenus.push(menuid);
      });

      tracker = 1;

      // Handle image in user toggle specially
      var userImg = $('.user-mobile-menu .user-badge img');
      if (userImg.length > 0) {
        var currentUserImg = $('.navbar-toggle.user img');
        // if there is a user image (logged in), then put it into the mobile button
        // but only once.
        if (currentUserImg.length == 0) {
          userImg.clone().appendTo('.navbar-toggle.user');
        }
      }
      else {
        // if no image, then move the Login link
        var currentLink = $('.navbar-toggle.user .user-badge');
        if (currentLink.length == 0) {
          $('.user-mobile-menu .user-badge').clone().appendTo('.navbar-toggle.user');
        }
      }
      $.each(mobileMenus, function(i, val) {
        $("."+val+"-mobile-menu").find('.pane-content').each( function() {
          $(this).attr('menu-item', tracker).parent().attr('menu-desktop', tracker);
          tracker++;
        });
      });

      setMenu();
    }
  };

  Drupal.ResponsivePanelsRegions = Drupal.ResponsivePanelsRegions || {
    toggleRegion: function(position) {
      $('body').toggleClass('oa-responsive-region-' + position + '-on');
      $('.btn-' + position).toggleClass('btn-active');
      saveState(position);
    },
    // Provide some helper classes.
    showRegion: function(position) {
      $('body').addClass('oa-responsive-region-' + position + '-on');
      $('.btn-' + position).addClass('btn-active');
      saveState(position);
    },
    hideRegion: function(position) {
      $('body').removeClass('oa-responsive-region-' + position + '-on');
      $('.btn-active').removeClass('btn-active');
      saveState(position);
    }
  };

  var sidebarHeight = debounce(function(){
    maxSidebarHeight();
  }, 250);
  var fixColumnWidth = debounce(function(){
    fixColumnWidthOnResize();
  }, 250);
  var moveMobileMenus = debounce(function(){
    fixMobileMenus();
  }, 250);

  window.addEventListener('load', sidebarHeight);
  window.addEventListener('resize', sidebarHeight);
  window.addEventListener('resize', fixColumnWidth);
  window.addEventListener('resize', moveMobileMenus);

})(jQuery);
