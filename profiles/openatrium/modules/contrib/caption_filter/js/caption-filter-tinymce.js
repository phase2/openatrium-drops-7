/**
 * @file
 * Functionality for aligning images with captions in tinyMCE.
 *
 * This file heavily based off of the WordPress "wpEditImage" plugin.
 * @see http://core.svn.wordpress.org/branches/3.2/wp-includes/js/tinymce/plugins/wpeditimage/editor_plugin.dev.js
 *
 * Additionally some code is based off the general WordPress editor.js file:
 * @see http://core.svn.wordpress.org/branches/3.2/wp-admin/js/editor.dev.js
 */
(function() {
  tinymce.create('tinymce.plugins.CaptionFilter', {

    init : function(ed, url) {
      var t = this;
      t.url = url;

      function _do_filter(ed, o) {
        o.content = Drupal.captionFilter.toHTML(o.content, 'tinymce');
      };

      // Load custom CSS for editor contents on startup.
      ed.onInit.add(function() {
        // Load custom CSS for editor contents on startup.
        var cssFile = ed.getParam('captionfilter_css', '');
        if (cssFile) {
          ed.dom.loadCSS(cssFile);
        }
      });

      // Resize the caption wrapper when the image is soft-resized by the user.
      ed.onMouseUp.add(function(ed, e) {
        // Webkit (Safari/Chrome) and Opera currently don't have resize handles.
        if (tinymce.isWebKit || tinymce.isOpera)
          return;

        var img = ed.selection.getNode();
        if (img.nodeName == 'IMG') {
          window.setTimeout(function(){
            var width;
            var captionInner = ed.dom.getParent(img, 'div.caption-inner');

            width = ed.dom.getAttrib(img, 'width') || img.width;
            width = parseInt(width, 10);

            if (captionInner && width != (parseInt(ed.dom.getStyle(captionInner, 'width'), 10))) {
              ed.dom.setStyle(captionInner, 'width', width);
              ed.execCommand('mceRepaint');
            }
          }, 100);
        }
      });

      // When pressing Return inside a caption move the cursor to a new parapraph under it.
      ed.onKeyPress.add(function(ed, e) {
        var n, captionInner, captionWrapper, P;

        if (e.keyCode == 13 && !e.shiftKey) {
          n = ed.selection.getNode();
          captionInner = ed.dom.getParent(n, 'div.caption-inner');
          captionWrapper = ed.dom.getParent(captionInner, 'div.caption');

          if (captionInner && captionWrapper) {
            P = ed.dom.create('p', {}, '&nbsp;');
            ed.dom.insertAfter(P, captionWrapper);

            if (P.firstChild)
              ed.selection.select(P.firstChild);
            else
              ed.selection.select(P);
            tinymce.dom.Event.cancel(e);
            return false;
          }
        }
        // When pressing the Backspace key (Delete on Macs), don't go backwards
        // into the caption area.
        else if (e.keyCode == 8) {
          n = ed.selection.getNode();
          var previousNode = n.previousSibling;
          if (previousNode && previousNode.nodeName == 'DIV' && ed.dom.hasClass(previousNode, 'caption')) {
            // focusOffset is supported by all modern browsers (IE9+). Users of
            // older browsers will be able to delete into the caption.
            if (typeof(ed.selection.getSel().focusOffset) == 'number' && ed.selection.getSel().focusOffset == 0) {
              tinymce.dom.Event.cancel(e);
              return false;
            }
          }
        }
      });

      // Set up a handler to float the caption tag instead of the image when
      // left or right aligning. Also allow the "Cleanup" button to remove
      // alignment entirely from the caption.
      ed.onBeforeExecCommand.add(function(ed, cmd, ui, val, o) {
        if ('JustifyLeft' == cmd || 'JustifyRight' == cmd || 'JustifyCenter' == cmd || 'RemoveFormat' == cmd) {
          var n, align, wrapperClass, captionWrapper;
          n = ed.selection.getNode();

          if (n.nodeName == 'IMG') {
            captionWrapper = ed.dom.getParent(n, 'div.caption');

            if (captionWrapper) {
              // Remove the existing alignment class.
              captionWrapper.className = captionWrapper.className.replace(/caption-(left|center|right)\s?/g, '');
              // Add a new class based on the new alignment (if needed).
              if ('RemoveFormat' != cmd) {
                align = cmd.substr(7).toLowerCase();
                wrapperClass = 'caption-' + align;
                ed.dom.addClass(captionWrapper, wrapperClass);
  
                if (align == 'center')
                  ed.dom.addClass(captionWrapper, 'mceIEcenter');
                else
                  ed.dom.removeClass(captionWrapper, 'mceIEcenter');

                // Stop the image itself from being affected.
                o.terminate = true;
              }

              ed.execCommand('mceRepaint');
            }
          }
        }
      });

      // Set up a handler for the entire editor. Used on initialization.
      ed.onBeforeSetContent.add(_do_filter);

      // Set up another handler for when a module uses mceSetContent, which only
      // applies to the current selection, not the entire editor.
      ed.onBeforeSetContent.add(function(ed, o) {
        ed.selection.onBeforeSetContent.add(_do_filter);
      });

      ed.onPostProcess.add(function(ed, o) {
        o.content = Drupal.captionFilter.toTag(o.content);
      });
    },

    getInfo : function() {
      return {
        longname : 'Caption Filter',
        author : 'Nathan Haug',
        authorurl : 'http://quicksketch.org',
        infourl : '',
        version : "1.0"
      };
    }
  });

  tinymce.PluginManager.add('captionfilter', tinymce.plugins.CaptionFilter);
})();
