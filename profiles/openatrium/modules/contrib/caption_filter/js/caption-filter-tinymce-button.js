/**
 * @file
 * Functionality for implementing the caption filter button in tinyMCE.
 */
var CaptionFilterButton = {
  init : function() {
    var ed = tinyMCEPopup.editor;
    var node = ed.selection.getNode();
    var p = ed.dom.getParents(node, 'DIV');
    var f = document.forms[0];

    // Only pre-populate values if we're inside an existing caption.
    if (p[0] && ed.dom.hasClass(p[0], 'caption-inner')
      && p[1] && ed.dom.hasClass(p[1], 'caption')) {
      // Parse the entire caption block to get the original [caption] tag.
      var tag = Drupal.captionFilter.toTag(p[1].outerHTML);

      // Extract the caption.
      var caption = tag.match(/^\[caption.*\]\<img.*\><p class="caption-text">(.*)<\/p>\[\/caption\]$/);
      if (caption[1]) {
        f.caption.value = caption[1];
      }

      // Extract the alignment.
      var align = tag.match(/^\[caption align=\"(.*)\"\].*\[\/caption\]$/);
      if (align[1]) {
        f.align.value = align[1];
      }
    }
  },

  insert : function() {
    var ed = tinyMCEPopup.editor;
    var node = ed.selection.getNode();
    var p = ed.dom.getParents(node, 'DIV');
    var align = document.forms[0].align.value;
    var caption = document.forms[0].caption.value;
    var image;
    var tag;
    var replace = false;
    // If we're inside an existing caption...
    if (p[0] && ed.dom.hasClass(p[0], 'caption-inner')
      && p[1] && ed.dom.hasClass(p[1], 'caption')) {
      replace = true;
      // Recall the original [caption] tag.
      tag = Drupal.captionFilter.toTag(p[1].outerHTML);
      // Select the outer DIV so we can replace the entire thing.
      ed.selection.select(p[1]);
        // If we're in an existing caption, parse it from the [caption] tag.
      var parse = tag.match(/^\[caption.*\](\<img.*\>)<p class="caption-text">(.*)<\/p>\[\/caption\]$/);
        if (parse[1]) {
          image = parse[1];
        }
    }
    // Get the image HTML.
    else if (node.nodeName === 'IMG') {
      // If we're on the image, just use it.
      image = node.outerHTML;
    }
    var newtag = '[caption';
    if (align == 'right' || align == 'left') {
      newtag += ' align="' + align + '"';
    }
    newtag += ']' + image + '<p class="caption-text">' + caption + '</p>' + '[/caption]';

    // Create the new [caption] tag.
    
    if (replace === true){
    	ed.dom.remove(p[1], false);
        ed.execCommand('mceReplaceContent', false, newtag);
 
    } else {
        ed.execCommand('mceReplaceContent', false, newtag);
    }
    tinyMCEPopup.close();
  }
};

tinyMCEPopup.onInit.add(CaptionFilterButton.init, CaptionFilterButton);
