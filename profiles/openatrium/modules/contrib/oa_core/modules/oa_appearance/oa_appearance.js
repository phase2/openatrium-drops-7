/**
 * @file
 * Manage spacing for banners in oa_appearance.
 */

(function ($) {

  var $total_height;

  Drupal.behaviors.oaAppearance = {
    attach: function(context, settings) {
      var $oa_navbar = $('#oa-navbar', context);
      var $banner = $('.oa-banner', context);
      if ($oa_navbar.length && $banner.length) {
        var $height = $oa_navbar.height();
        var $width = $oa_navbar.width();
        $total_height = $height;
        $banner.each( function(index) {
          if (!$(this).hasClass('oa-banner-appeared') &&
              !$(this).hasClass('oa-banner-hidden')) {
            // set the image sizes before image gets loaded
            var $img_width = $(this).attr('data-width');
            var $img_height = $(this).attr('data-height');
            if ($img_width > 0) {
              // stretched banner image
              var $new_width = $new_height * $img_width / $img_height;
              var $new_height = $img_height * $width / $img_width;
              if ($(this).parents('#oa-navbar').length) {
                // this image is within the navbar
                $total_height -= $(this).height();
                $total_height += $new_height;
              }
              $(this).css('height', $new_height);
              $(this).addClass('oa-banner-hidden');
              var $image = $('.oa-banner-overlay-img', this);
              if ($image.length) {
                $image.css('width', '100%');
              }
            }
            else {
              // non-stretching banner image
              $(this).addClass('oa-banner-appeared');
            }
          }
        });
        if ($total_height > 0) {
          $oa_navbar.height($total_height);
          $('body').css('padding-top', $total_height);
        }
        if (typeof(Drupal.displace) != "undefined") {
          Drupal.displace();  // recalculate offsets
        }
      }
    }
  }

  $(window).load(function() {
    var $oa_navbar = $('#oa-navbar');
    var $image = $('.oa-banner-overlay-img');
    var $banner = $('.oa-banner');
    if ($banner.length) {
      $banner.css( 'height', 'auto'); // let the banner resize from now on
      $banner.addClass('oa-banner-appeared');
      $banner.removeClass('oa-banner-hidden');
    }
    // this is needed to allow bootstrap tour to display correctly
    $(window).trigger('resize');
  });

}(jQuery));
