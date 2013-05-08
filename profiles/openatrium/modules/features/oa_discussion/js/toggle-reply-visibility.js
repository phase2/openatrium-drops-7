/**
 * @file toggle-reply-visibility.js
 *
 * Expands / collapses all replies.
 */
(function ($) {

  Drupal.behaviors.toggleReplyVisibility = {
    attach: function(context, settings) {
      var $toggle = $('#toggle-reply-visibility');
      var $replies = $('.oa-discussion-reply .accordion-body');
      var expand = true;
      var expandText = '<i class="icon-plus"></i> Expand All';
      var collapseText = '<i class="icon-minus"></i> Collapse All';
      
      $toggle.html(expandText);
      $toggle.click(function() {
        // $replies.collapse(expand ? 'show' : 'hide');
        // Due to a bug in bootstrap's collapse, bodies that have been expanded
        // by default (By adding the class "in") are collapsed the first time
        // you run .collapse('show');. Use the above if this gets fixed.
        if (expand) {
          $replies.each(function() {
            if (!$(this).hasClass('in')) {
              $(this).collapse('show');
            }
          });
        }
        else {
          $replies.collapse('hide');
        }
        
        expand = !expand;
        $toggle.html(expand ? expandText : collapseText);
      });
    } 
  };

})(jQuery);