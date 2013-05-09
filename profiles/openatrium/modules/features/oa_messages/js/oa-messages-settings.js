/**
 * @file oa-message-settings.js
 *
 * Provides the tab and check / uncheck all functionality for the user message settings page.
 */
(function ($) {

  Drupal.behaviors.messagesSettings = {
    attach: function(context, settings) {
      var $form = $('#edit-oa-messages');
      var $tabs = $('#messages-tabs');
      
      // Add tab functionality.
      $tabs.find('a').click(function(e) {
        $(this).tab('show');
      });
      $tabs.find('a:first').tab('show');
      
      // Add check / uncheck all buttons to spaces / messages.
      var $spaceLabels = $form.find('.space-label');
      $spaceLabels.each(function() {
        var $checkboxes = $(this).parent().find('input[type="checkbox"]');
        addCheckUncheckAllButtons($(this), $checkboxes);
      });
      
      var $messageLabels = $form.find('.checkbox-table th:not(:first-child)');
      var index = 2;
      var paneId = false;
      $messageLabels.each(function() {
        var $pane = $(this).parents('.tab-pane');
        
        // Reset index on new tab pane.
        if (paneId && $pane.attr('id') !== paneId) {
          index = 2;
        }
        paneId = $pane.attr('id');
        
        var $checkboxes = $pane.find('.checkbox-table td:nth-child(' + index + ') input[type="checkbox"]');
        addCheckUncheckAllButtons($(this), $checkboxes);
        index++;
      });
    }
  }
  
  // Add check / uncheck all buttons to an element.
  function addCheckUncheckAllButtons(element, checkboxes) {
    var buttons  = '<div class="check-buttons">';
        buttons += '  <a class="btn check-all"><i class="icon-ok"></i></a>';
        buttons += '  <a class="btn uncheck-all"><i class="icon-remove"></i></a>';
        buttons += '</div>';
    $(element).append(buttons);
    
    $(element).find('.check-all').click(function() {
      console.log($(checkboxes));
      $(checkboxes).attr('checked', true);
    });
    $(element).find('.uncheck-all').click(function() {
      $(checkboxes).attr('checked', false);
    });
  }

})(jQuery);