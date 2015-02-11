(function ($) {
  $(document).ready(function() {
    // Handle toolbar collapse.
    $('.oa-navigation .btn-navbar-menu').click(function(e) {
      e.preventDefault();
      var navMenuCollapse = $('.oa-navigation .nav-menu-collapse');
      var height = (navMenuCollapse.height() == 0) ? 'auto' : 0;
      navMenuCollapse.height(height);
    });

    // adjust the position of the IPE buttons
    var $ipe = $('#panels-ipe-control-container');
    if ($ipe.length) {
      var $main = $('#main');
      var $element = $ipe.detach();
      $main.prepend($element);
    }

    // extend jQuery UI dialog
    // fixes missing Close button in jQuery UI dialogs
    // caused by jQuery being loaded before bootstrap, which is hard to change
    // http://stackoverflow.com/questions/17367736/jquery-ui-dialog-missing-close-icon
    if ($.ui.dialog !== undefined) {
      $.widget( "ui.dialog", $.ui.dialog, {
        open: function() {
          var result = this._super();
          if ('uiDialogTitlebarClose' in this) {
            this.uiDialogTitlebarClose.html("<span class='ui-button-icon-primary ui-icon ui-icon-closethick'></span>");
          }
          return result;
        }
      });
    }
  });

  Drupal.behaviors.fieldset_collapse = {
    attach: function(context, settings) {
      // allow chosen dropdowns within fieldsets to be visible
      if ('chosen' in settings) {
        var selector = settings.chosen.selector;
        $(selector, context)
          .not('#field-ui-field-overview-form select, #field-ui-display-overview-form select, .wysiwyg, .draggable select[name$="[weight]"], .draggable select[name$="[position]"]') //disable chosen on field ui
          .each(function () {
            $(this).parents('.panel-body.fieldset-wrapper, .form-item.form-type-select').first().addClass('chosen-fieldset-wrapper');
        });
      }
    }
  };

  if (Drupal.CTools && typeof Drupal.CTools.CollapsibleCallbacksAfterToggle != 'undefined') {
    Drupal.CTools.CollapsibleCallbacksAfterToggle[Drupal.CTools.CollapsibleCallbacksAfterToggle.length] = function($container, handle, content, toggle) {
      // Older versions of jquery leave behind a overflow:hidden;
      // @see https://www.drupal.org/node/2408807
      if (content.css("overflow") == "hidden") {
        content.css("overflow", "");
      }
    }
  }

  Drupal.behaviors.mobile_nav_behavior = {
    attach: function(context) {
      var isMobile = $('button.navbar-toggle').is(':visible');

      var mobileMenus = ['user','spaces','search'];
      var tracker = 1;

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
        $("."+val+"-mobile-menu").find('>ul, form, >div>ul, .dropdown-menu>ul').each( function() {
          $(this).attr('menu-item', tracker).parent().attr('menu-desktop', tracker);
          tracker++;
        });
      });

      setMenu();

      function setMenu() {
        if (isMobile) {
          // wire the mobile admin
          if($('#toolbar-menu-button').html()) {
            $('#navbar-tray .navbar-menu-administration').attr('menu-desktop', tracker).children('ul').attr('menu-item', tracker).appendTo("#oa-navbar-admin");
            tracker++;
          }
          else {
            $('#oa-navbar button.navbar-toggle.admin').hide();
          }

          // move each menu, Bootstrap handles the menu toggle
          $.each(mobileMenus, function(i, val){
            $("."+val+"-mobile-menu").find('>ul, form, >div>ul, .dropdown-menu>ul').appendTo("#oa-navbar-"+val);
          });
        }
      }

      $(window).resize(function() {
        if ($('button.navbar-toggle').is(':visible') != isMobile) {
          if (isMobile == true) {
            //there was a change, if isMobile was true the change is to false and is now desktop
            //here we want to move the menu items back
            for (var i = 1; i <= tracker; i++) {
              $('.pane-oa-mobile').find("[menu-item='" + i +"']").appendTo("[menu-desktop='" + i +"']");
            }
          }
          isMobile = $('button.navbar-toggle').is(':visible');
          setMenu();
        }
      });
    }
  };

})(jQuery);
