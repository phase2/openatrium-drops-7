(function($) {

  Drupal.behaviors.oa_toolbar_search = {
    attach: function(context, settings) {
      var $form = $('.toolbar-search form');
      var $search_bar = $form.find('.search-text');
      var $dropdown = $form.find('.dropdown-menu');
      var $dropdown_toggle = $form.find('.dropdown-toggle');

      if ($form.length) {
        $form.submit(function() {
          var term = $search_bar.val();
          var type = $dropdown.find('input:checked').val();
          $form.attr('action', determineSearchPath(term, type, settings.oa_search.space));
        });

        $dropdown.click(function(e) {
          e.stopPropagation();
        });
      }
    }
  };

  Drupal.behaviors.oa_sidebar_search = {
    attach: function(context, settings) {
      var $form = $('.pane-oa-sidebar-search form');
      var $search_bar = $form.find('.search-text');
      var $options = $form.find('.options');

      if ($form.length) {
        $form.submit(function() {
          var term = $search_bar.val();
          var type = $options.find('input:checked').val();
          $form.attr('action', determineSearchPath(term, type, settings.oa_search.space));
        });
      }
    }
  };

  function determineSearchPath(term, type, space) {
    var path = 'search' + '/' + (type === 'users' ? 'user' : 'node') + '/' + term;
    if (type === 'this_space') {
      // %3A instead of : because of some weird double encoding on the backend.
      path += '?f[0]=' + encodeURIComponent('og_group_ref%3Atitle:' + space);
    }
    return path;
  }

})(jQuery);
