Drupal.settings.spotlight_settings = Drupal.settings.spotlight_settings || {};

(function ($) {

 /**
  * Get the total displacement of given region.
  *
  * @param region
  *   Region name. Either "top" or "bottom".
  *
  * @return
  *   The total displacement of given region in pixels.
  */
  if (Drupal.overlay) {
    Drupal.overlay.getDisplacement = function (region) {
      var displacement = 0;
      var lastDisplaced = $('.overlay-displace-' + region + ':last');
      if (lastDisplaced.length) {
        displacement = lastDisplaced.offset().top + lastDisplaced.outerHeight();

        // In modern browsers (including IE9), when box-shadow is defined, use the
        // normal height.
        var cssBoxShadowValue = lastDisplaced.css('box-shadow');
        var boxShadow = (typeof cssBoxShadowValue !== 'undefined' && cssBoxShadowValue !== 'none');
        // In IE8 and below, we use the shadow filter to apply box-shadow styles to
        // the toolbar. It adds some extra height that we need to remove.
        if (!boxShadow && /DXImageTransform\.Microsoft\.Shadow/.test(lastDisplaced.css('filter'))) {
          displacement -= lastDisplaced[0].filters.item('DXImageTransform.Microsoft.Shadow').strength;
          displacement = Math.max(0, displacement);
        }
      }
      return displacement;
    };
  };

 /**
  * Form behavior for Spotlight
  */
 Drupal.behaviors.panopolySpotlight = {
   attach: function (context, settings) {
     if ($('.field-name-field-basic-spotlight-items').length) {
       $('.field-name-field-basic-spotlight-items').each(function() {
         var rotation_time = $(this).find('.panopoly-spotlight-buttons-wrapper').data('rotation-time');
         var $slides = $(this);
         $slides.tabs().tabs("rotate", rotation_time, true);
         // $('.field-name-field-basic-spotlight-items').css('height', $('.field-name-field-basic-spotlight-items').height());
         // $('.field-name-field-basic-spotlight-items').css('overflow', 'hidden');

         // Navigation is hidden by default, display it if JavaScript is enabled.
         $slides.find('.panopoly-spotlight-buttons-wrapper').css('display', 'block');

         $slides.find('.panopoly-spotlight-pause-play').bind('click', function(event) {
           event.preventDefault();
           if ($(this).hasClass('paused')) {
             $slides.tabs().tabs("rotate", rotation_time, true);
             $(this).text(Drupal.t('Pause'));
             $(this).removeClass('paused');
           }
           else {
             $slides.tabs().tabs("rotate", 0, false);
             $slides.find('.ui-tabs-nav li a').attr('tabindex', 0);
             $(this).text(Drupal.t('Play'));
             $(this).addClass('paused');
           }
         });
       });
     }
   }
 }

 /**
  * Create responsive magic for Table Widget
  */
 Drupal.behaviors.panopolyWidgetTables = {
   attach: function (context, settings) {

     $('table.tablefield', context).each(function() {
       var table = $(this); // cache table object.
       var head = table.find('thead th');
       var rows = table.find('tbody tr').clone(); // appending afterwards does not break original table.

       // create new table
       var newtable = $(
         '<table class="mobile-table">' +
         '  <tbody>' +
         '  </tbody>' +
         '</table>'
       );

       // cache tbody where we'll be adding data.
       var newtable_tbody = newtable.find('tbody');

       rows.each(function(i) {
         var cols = $(this).find('td');
         var classname = i % 2 ? 'even' : 'odd';
         cols.each(function(k) {
           var new_tr = $('<tr class="' + classname + '"></tr>').appendTo(newtable_tbody);
           new_tr.append(head.clone().get(k));
           new_tr.append($(this));
         });
       });

       $(this).after(newtable);
     });

   }
 }
})(jQuery);
