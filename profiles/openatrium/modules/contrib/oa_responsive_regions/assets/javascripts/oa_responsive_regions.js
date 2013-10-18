/**
 * @file
 * JS for Responsive Panels Regions.
 */

(function ($) {

"use strict";

Drupal.behaviors.responsive_panels_regions = {
  attach: function(context) {
    $(context).find('.responsive-panels-region-toggler').each(function () {
      $(this).bind('click', function() {
        var position = $(this).data().position;
        Drupal.ResponsivePanelsRegions.toggleRegion(position)
      });
    });
  }
};

Drupal.ResponsivePanelsRegions = Drupal.ResponsivePanelsRegions || {
  toggleRegion: function(position) {
    $('body').toggleClass('responsive-panels-region-' + position + '-on');
    $('.btn-' + position).toggleClass('btn-active');
  },
  // Provide some helper classes.
  showRegion: function(position) {
    $('body').addClass('responsive-panels-region-' + position + '-on');
    $('.btn-' + position).addClass('btn-active');
  },
  hideRegion: function(position) {
    $('body').removeClass('responsive-panels-region-' + position + '-on');
    $('.btn-active').removeClass('btn-active');
  }
};

})(jQuery);
