/**
 * @file mark-as-read.js
 *
 * Marks comments as read as the user brings them in to view. New comments will
 * be expanded, old comments remain collapsed.
 */
(function ($) {

  Drupal.behaviors.commitAsRead = {
    attach: function(context, settings) {
      // Ensure replies exist before we start.
      if ($('.pane-open-atrium-discussions-replies').length === 0) {
        return;
      }

      var IDLE_TIME = 2000; // Milliseconds until considered "idle".
      var READ_THRESHOLD = 100;  // # of px required beyond the top of a comment to consider it read.

      var newComments = $('.view-display-id-replies .oa-list').has('.new-marker .marker');
      var contentBottom = $('.pane-open-atrium-discussions-replies').offset()['top'] +
                          $('.pane-open-atrium-discussions-replies').height();
      var comments = new Array();
      var read = new Array();
      var update;
      var currentPos;

      // Initialize comments.
      newComments.each(function() {
        var nid = this.className.match('nid\-([0-9]*)')[1];
        var pos = $(this).offset()['top'];
        comments.push({'pos': pos, 'nid': nid});
      });

      $(window).resize(markAsRead);
      $(document).scroll(markAsRead);
      markAsRead();


      // Mark only comments that have been scrolled to as read.
      function markAsRead() {
        currentPos = $(document).scrollTop() + $(window).height();
        clearTimeout(update);
        if (currentPos < contentBottom) {
          // Copy so that we can unset inside the forEach.
          commentsCopy = comments.slice();
          commentsCopy.forEach(checkIfRead);
          update = setTimeout(commitAsRead, IDLE_TIME);
        }
        else {
          markAllAsRead();
        }
      }

      // Add comment to the read array if it's been scrolled over.
      function checkIfRead(values, index, array) {
        if (values['pos'] + READ_THRESHOLD < currentPos) {
          read.push(values['nid']);
          comments.splice(index, 1);
        }
      }

      // Mark all comments as read, prevent from further checking.
      function markAllAsRead() {
        comments.forEach(function(values) {
          read.push(values['nid']);
        });
        commitAsRead();
        $(document).unbind('scroll', markAsRead);
        $(window).unbind('resize', markAsRead);
      }

      // AJAX request to mark comments as read in the database.
      function commitAsRead() {
        if (read.length > 0) {
          $.ajax(Drupal.settings.basePath + 'oa_discussion/ajax/mark-read/' + read.join(','));
          read = Array();
        }
      }
    }
  }

})(jQuery);
