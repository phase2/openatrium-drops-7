/**
 * @file toggle-reply-visibility.js
 *
 * Expands / collapses all replies.
 */
(function ($) {

  Drupal.behaviors.toggleReplyVisibility = {
    attach: function(context, settings) {
      var $toggle = $('#toggle-reply-visibility');
      var $replies = $('.oa-discussion-reply .oa-list-header');
      var expand = true;
      var expandText = '<i class="icon-plus"></i> ' + Drupal.t('Expand All');
      var collapseText = '<i class="icon-minus"></i> ' + Drupal.t('Collapse All');

      $toggle.html(expandText);
      $toggle.click(function() {
        // $replies.collapse(expand ? 'show' : 'hide');
        // Due to a bug in bootstrap's collapse, bodies that have been expanded
        // by default (By adding the class "in") are collapsed the first time
        // you run .collapse('show');. Use the above if this gets fixed.
        if (expand) {
          $replies.each(function() {
            if (!$(this).hasClass('in')) {
              $(this).removeClass('oa-discussion-hide');
            }
          });
        }
        else {
          $replies.addClass('oa-discussion-hide');
        }

        expand = !expand;
        $toggle.html(expand ? expandText : collapseText);
      });

      $('.accordion-toggle .oa-list-header').click(function() {
        $(this).toggleClass('oa-discussion-hide');
      });
    }
  };

})(jQuery);
