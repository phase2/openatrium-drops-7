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
})(jQuery);
