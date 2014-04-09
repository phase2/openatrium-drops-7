(function($) {
  Drupal.behaviors.bootstrapTour = {
    attach: function(context) {

      var tourConfig = Drupal.settings.bootstrapTour.tour;
      if (!tourConfig) {
        return;
      }

      Tour.prototype._isRedirect = function(path, currentPath) {
        if (path == null || path == Drupal.settings.basePath) {
          return false;
        }
        // Override the isRedirect function so that we can support non-clean-URLs.
        currentPath = '/' + (location.pathname+location.search).substr(1)
        currentPath = currentPath.replace(Drupal.settings.basePath, '/');
        path = path.replace(Drupal.settings.basePath, '/');
        if (path !== '/') {
          return (path !== currentPath);
        } else {
          return (currentPath.indexOf('?q=') !== -1);
        }
      }

      var path = Drupal.settings.basePath;
      var prev = Drupal.t("« Prev");
      var next = Drupal.t("Next »");
      var endtour = Drupal.t("End Tour");
      var t = new Tour({
        storage: window.localStorage,
        basePath: path,
        template: "<div class='popover tour'> \
          <div class='arrow'></div> \
          <h3 class='popover-title'></h3> \
          <div class='popover-content'></div> \
          <nav class='popover-navigation'> \
              <div class='btn-group'> \
                  <button class='btn btn-default' data-role='prev'>"+prev+"</button> \
                  <button class='btn btn-default' data-role='next'>"+next+"</button> \
              </div> \
              <button class='btn btn-default' data-role='end'>"+endtour+"</button> \
          </nav> \
          </div>"
      });

      $.each(tourConfig.steps, function(index, step) {
        var options = {
          title: step.title,
          content: step.content,
          placement: step.placement,
          animation: true
        }
        if (step.path) {
          options.path = '';
          if (step.path.trim() != '<front>') {
            if (!tourConfig.cleanUrls) {
              options.path += '?q=' // Don't need the first / in this case.
            }
            options.path += step.path;
          }
          if (step.path.indexOf('?tour') === -1 && step.path.indexOf('&tour') === -1) {
            if (!tourConfig.cleanUrls) {
              options.path += '&';
            } else {
              options.path += '?';
            }
            options.path += 'tour=' + tourConfig.name;
            if (!(tourConfig.isFirstStep && index == 0)) {
              options.path += '&step=' + index;
            }
          }
        }

        if (step.selector == '') {
          options.orphan = true;
        } else {
          options.element = step.selector;
        }
        console.log(options);
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

