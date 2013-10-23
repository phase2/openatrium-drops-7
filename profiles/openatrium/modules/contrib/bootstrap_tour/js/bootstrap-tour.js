(function($) {
  Drupal.behaviors.bootstrapTour = {
    attach: function(context) {
      var tourConfig = Drupal.settings.bootstrapTour.tour;
      if (!tourConfig) {
        return;
      }

      var t = new Tour({ storage: window.localStorage });
      $.each(tourConfig.steps, function(index, step) {
        var options = {
          title: step.title,
          content: step.content,
          placement: step.placement,
          animation: true
        }
        if (step.path) {
          if (step.path.trim() == '<front>') {
            options.path = '/';
          } else {
            options.path = '/' + step.path;
          }
          if (step.path.indexOf('?tour') === -1 && step.path.indexOf('&tour') === -1) {
            options.path += '?tour=' + tourConfig.name + '&step=' + index;
          }
        }
        if (step.selector == '') {
          options.orphan = true;
        } else {
          options.element = step.selector;
        }
        t.addSteps([options])
      });

      if (tourConfig.force && tourConfig.isFirstStep) {
        // Manually restart if "force" is true and we're on the path of the first step.
        t.restart();
      } else {
        t.start();
      }
      $(window).trigger('resize');
    }
  }
})(jQuery);

