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

  });

  Drupal.behaviors.mobile_nav_behavior = {
    attach: function(context) {
      var isMobile = $('button.navbar-toggle').is(':visible');

      var mobileMenus = ['user','spaces','search'];
      var tracker = 1;

      $('.user-mobile-menu .user-badge img').clone().appendTo('.navbar-toggle.user');
      $.each(mobileMenus, function(i, val){
        $("."+val+"-mobile-menu").find('>ul, form, >div>ul, .dropdown-menu>ul').each(function(){
          $(this).attr('menu-item', tracker).parent().attr('menu-desktop', tracker);
          tracker++;
        });
      })

      setMenu()

      function setMenu(){
        if(isMobile){
          //wire the mobile admin
          if($('#toolbar-menu-button').html()){
            $('#navbar-tray .navbar-menu-administration').attr('menu-desktop', tracker).children('ul').attr('menu-item', tracker).appendTo("#oa-navbar-admin");
            tracker++;
          }else{
            $('#oa-navbar button.navbar-toggle.admin').hide();
          }

          //move each menu, Bootstrap handles the menu toggle
          $.each(mobileMenus, function(i, val){
            $("."+val+"-mobile-menu").find('>ul, form, >div>ul, .dropdown-menu>ul').appendTo("#oa-navbar-"+val);
          });
        }
      }

      $( window ).resize(function() {
        if($('button.navbar-toggle').is(':visible') != isMobile){
          if(isMobile == true){
            //there was a change, if isMobile was true the change is to false and is now desktop
            //here we want to move the menu items back
            for( var i = 1; i <= tracker; i++ ){
              $('.oa-navigation').find("[menu-item='" + i +"']").appendTo("[menu-desktop='" + i +"']");
            }
          }
          isMobile = $('button.navbar-toggle').is(':visible');
          setMenu();
        }
      })
    }
  };

})(jQuery);
