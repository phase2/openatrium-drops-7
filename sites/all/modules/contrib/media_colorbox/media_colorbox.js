(function ($) {

/**
 * Media Colorbox behavior.
 */
Drupal.behaviors.initMediaColorbox = {
  attach: function (context, settings) {
    if (!$.isFunction($.colorbox)) {
      return;
    }
    var enableAudioPlaylist = false;
    $('a.media-colorbox', context).once('init-media-colorbox', function() {
      // Merge Colorbox settings with Media Colorbox settings from data attributes.
      var options = jQuery.extend({}, settings.colorbox);
      var mediaColorboxSettings = {};
      if($(this).data('mediaColorboxFixedWidth')>0){
        mediaColorboxSettings = {width: $(this).data('mediaColorboxFixedWidth')};
        jQuery.extend(options, mediaColorboxSettings); 
      }
      if($(this).data('mediaColorboxFixedHeight')>0){
        mediaColorboxSettings = {height: $(this).data('mediaColorboxFixedHeight')};
        jQuery.extend(options, mediaColorboxSettings); 
      }
           
      //set up the callback and listener to goto to next slide
      $(this).colorbox(options);
      if($(this).data('mediaColorboxAudioPlaylist')){
        enableAudioPlaylist = true;
      }
    });
    
    //set up the callback and listener to goto to next slide
    $(document).bind('cbox_complete', function(){
      if(enableAudioPlaylist){
        $("audio").bind("ended", function(event){
          setTimeout($.colorbox.next, 100);
        });
      }
      //TOOD revisit to possibly make this an external setting
      //allows the clicking of any img being displayed to goto next slide of gallery
      $("img").bind("click", function (event){
        setTimeout($.colorbox.next, 0);
      });
      $("img").css('cursor', 'pointer');
    });
    
  }
};

})(jQuery);
