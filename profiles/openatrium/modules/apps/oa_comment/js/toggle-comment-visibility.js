/**
 * @file
 * Javascript for comments.
 *
 * This file handles the expanding/collapsing of individual comments, all
 * comments at once, and moving a comment to the top and expanding it if the url
 * contains the comment hash.
 */

(function ($) {
  Drupal.behaviors.adjustComments = {
    attach: function(context, settings) {
      $('.oa-list.oa-comment .oa-pullout-left', context).each(function() {
        if ($(this).width() > 25) {
          // for wide comment ids, add extra padding to first paragraph.
          $(this).parents('.accordion-toggle').find('.oa-comment-reply-body p:nth-child(1)').css('text-indent', ($(this).width() - 25) + 'px');
        }
      });
    }
  };

  Drupal.behaviors.toggleReplyVisibility = {
    attach: function(context, settings) {
      var expandText = '<i class="icon-plus"></i> ' + Drupal.t('Expand All');
      // Add a div that will contain the 'Expand/Collapse All' button if these
      // selectors have no content.
      if ($.trim($('.oa-comment').html())) {
        $('#comments, .pane-node-comments').once('comments', function() {
          $(this).prepend('<div id="toggle-comment-visibility" class="btn btn-default">' + expandText + '</div>');
        });
      }
      var toggle = $('#toggle-comment-visibility');
      var replies = $('.oa-comment .oa-list-header');
      var expand = true;
      var collapseText = '<i class="icon-minus"></i> ' + Drupal.t('Collapse All');

      toggle.click(function(event) {
        event.preventDefault();
        // $replies.collapse(expand ? 'show' : 'hide');
        // Due to a bug in bootstrap's collapse, bodies that have been expanded
        // by default (By adding the class "in") are collapsed the first time
        // you run .collapse('show');. Use the above if this gets fixed.
        if (expand) {
          replies.each(function() {
            if (!$(this).hasClass('in')) {
              $(this).removeClass('oa-comment-hide');
            }
          });
        }
        else {
          replies.addClass('oa-comment-hide');
        }

        expand = !expand;
        toggle.html(expand ? expandText : collapseText);

        // Get rid of 'new' marker on initial pageload.
        $('.oa-list.oa-comment').find('.new-marker').empty();
      });

      $('.accordion-toggle .oa-list-header:not(.oa-list-header-processed)', context).addClass('oa-list-header-processed').click(function() {
        $(this).toggleClass('oa-comment-hide');
        if ($(this).hasClass('oa-comment-is-new') && !$(this).hasClass('oa-comment-new-processed')) {
          $(this).addClass('oa-comment-new-processed');
          $(this).parent().parent().find('.new-marker').empty();
        }
      });

      // This will expand the comment with the same hash that exists in the url.
      $(window).bind('load hashchange', function() {
        // Get the fragment that contains the comment number.
        var hash = document.location.hash;
        if (hash) {
          // Expand that comment.
          $(hash).next().find('.oa-list-header').toggleClass('oa-comment-hide');
          // Get the height of the fixed oa-navbar.
          var nav = $('#oa-navbar').height();
          // Scroll to the top - the height of the navbar.
          window.scrollTo(0, $(hash).offset().top - nav);
        }
        // If the comment is new then expand it.
        $('.oa-comment-is-new').each(function() {
          $(this).removeClass('oa-comment-hide');
        });
      });

      // Override ctools so we not only dismiss the modal but trigger a page
      // reload when the modal is closed. The WYSIWYG buttons vanish on the
      // underlying page when the modal is closed.
      // @todo: Figure out why the WYSIWYG buttons go missing and remove this
      // temporary hack.
      $('.ctools-close-modal', context).once('ctools-close-modal').click(function() {
        Drupal.CTools.Modal.dismiss();
        location.reload();
        return false;
      });
    }
  };
})(jQuery);
