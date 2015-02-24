/**
 * @file
 * Opens the media browser then edit field
 */

(function ($) {

/**
 * Attach behaviors to media element browse fields.
 */
Drupal.behaviors.oaFilesUpload = {
  attach: function (context, settings) {
    $('a:not(.oa-files-processed)[href*="oa-files/upload"]', context).addClass('oa-files-processed').each(function() {
      var $link = $(this);
      $(this).click(function() {
        Drupal.media.popups.mediaBrowser(function(selected) {
          var browserSrc = settings.oa_files_upload_url + '/';
          for (key in selected) {
            browserSrc += selected[key].fid + '+';
          }
          browserSrc += '/js-return?render=oa-files-popup';
          if ($link[0].search) {
            browserSrc += '&' + $link[0].search.substr(1);
          }
          var mediaIframe = Drupal.media.popups.getPopupIframe(browserSrc, 'oaFilesUpload');
          mediaIframe.bind('load', {}, function (e) {
            // Return can be json or a page, want to act on the json.
            var parsed_json;
            var frame_html = $('#json-encode', this.contentWindow.document).html();
            if (!frame_html) {
              return;
            }
            try {
              parsed_json = JSON.parse(frame_html)
            }
            catch(err) {
              return;
            }
            if (parsed_json) {
              for (var i in parsed_json) {
                if (parsed_json.hasOwnProperty(i) && parsed_json[i]['command'] && Drupal.ajax.prototype.commands[parsed_json[i]['command']]) {
                  Drupal.ajax.prototype.commands[parsed_json[i]['command']](Drupal.ajax.prototype, parsed_json[i], 'success');
                }
              }
              mediaIframe.dialog("close");
            }
          });
          var dialogOptions = Drupal.media.popups.getDialogOptions();
          var dialog = mediaIframe.dialog(dialogOptions);
          Drupal.media.popups.sizeDialog(dialog);
          Drupal.media.popups.resizeDialog(dialog);
          Drupal.media.popups.scrollDialog(dialog);

        }, settings.oa_files_media_options.global, {}, settings.oa_files_media_options.widget);
        return false;
      })
    });
  },
};

})(jQuery);

