/**
 * @file
 * Javascript for the OA wizards.
 */

(function ($) {

  Drupal.ajax.prototype.commands.oaWizardRedirect = function(ajax, response, status) {
    // Redirect as requested.
    window.location.href = response.url;
  };

  Drupal.ajax.prototype.commands.oaWizardNew = function(ajax, response, status) {
    // called when the ajax for adding node has completed
    // trigger an event to notify anybody who might need the node data
    $(document).trigger('oaWizardNew', response.node);
  };

  Drupal.behaviors.oaWizard = {
    attach: function (context, settings) {
      var $steps = settings.oa_wizard.steps;
      /* $steps is an array of wizard steps.  Each element is an array of key->values
       'title' : The title of the step (shown in header)
       'fields' : An array of field names to be placed in this step
       'help' : The help text for this step
       'showhelp' : TRUE to show help text, false to hide help text
       */
      var $form = $('.node-form');

      // Bind a keypress on escape for closing the modalContent
      wizardKeyHandler = function(event) {
        // Enter or Down-arrow
        if ((event.keyCode == 13) || (event.keyCode == 40)) {
          var $next = $('#oa-wizard .tab-pane.active .oa-wizard-next');
          if (($next.length > 0) && !$next[0].disabled) {
            event.preventDefault();
            $next.first().trigger('click');
            return false;
          }
          else if (event.keyCode == 13) {
            $('#modal-content form').trigger('submit');
            return false;
          }
        }
        // Up-arrow
        else if (event.keyCode == 38) {
          var $prev = $('#oa-wizard .tab-pane.active .oa-wizard-prev');
          if (($prev.length > 0) && !$prev[0].disabled) {
            event.preventDefault();
            $prev.first().trigger('click');
            return false;
          }
        }
      };

      // only add wizard HTML the first time in case this is in response
      // to an error in the previous submit
      if ($("#oa-wizard").length == 0) {

        $('body').once('oa-wizard', function() {
          $(document).keydown(wizardKeyHandler);
        });

        ////
        // Set up HTML Stubs
        ////

        // Set up the Nav Container HTML
        var $navItems = $("<ul/>", {
          "class": "nav",
          "role": "tablist",
          html: $("<li/>", {
            html: $("<a/>", {
              "class": "toggle-nav",
              "href": "#",
              click: function (e) {
                e.preventDefault();
                $('#oa-wizard').toggleClass('open');
              }
            }).append(
              $("<span/>", {
                "class": "glyphicon glyphicon-th-list"
              })
              )
          })
        });

        // Set Up the Tab Container HTML
        var $tabContent = $("<div/>", {
          "class": "tab-content"
        });

        ////
        // Step Through $steps array
        ////

        $.each($steps, function (key, value) {
          var tab = "",
            fields = value['fields'],
            prevState = (key == 0 ? "disabled" : "enabled"),
            nextState = (key == Object.keys($steps).length - 1 ? "disabled" : "enabled");

          // clean button container
          var $buttons = $("<div/>", {
            "class": "buttons"
          });

          // clean tab container
          var $tab = $("<div/>", {
            "class": "tab-pane",
            "id": "tab" + (key + 1)
          });

          ////
          // Append all Navigation Items
          ////

          $("<li/>", {
            html: $("<a/>", {
              "href": "#tab" + (key + 1),
              "role": "tab",
              "data-toggle": "tab",
              text: value['title']
            }).append(
              $("<span/>", {
                  "class": "badge",
                  text: key + 1
                }
              ))
          }).appendTo($navItems);

          ////
          // Append Fields and buttons to tab content
          ////

          $.each(fields, function (i, field) {
            field = field.replace(/[_]/g, "-");
            if (field == "title") {
              $(".form-item-title").detach().appendTo($tab);
            }
            else {
              $('.field-name-' + field).detach().appendTo($tab);
            }
          });

          // create prev/next buttons
          var $prevButton = $("<button/>", {
            "class": "btn btn-primary oa-wizard-prev",
            "type": "button",
            href: "#",
            text: "Previous",
            click: function (e) {
              e.preventDefault();
              $('#oa-wizard').find('[data-toggle="tab"]').eq(key - 1).tab('show');
            }
          }).attr(prevState, "");

          var $nextButton = $("<button/>", {
            "class": "btn btn-primary oa-wizard-next",
            "type": "button",
            href: "#",
            text: "Next",
            click: function (e) {
              e.preventDefault();
              $('#oa-wizard').find('[data-toggle="tab"]').eq(key + 1).tab('show');
            }
          }).attr(nextState, "");

          // Append Buttons
          $buttons.append($prevButton).append($nextButton);

          if (nextState == 'disabled') {
            // do not use #edit-actions id since resubmitting form after error
            // changes id to #edit-actions--1
            $('.form-actions').detach().appendTo($buttons);
          }

          // place buttons at bottom of tab
          $buttons.appendTo($tab);

          // Add tab to tabContent container
          $tab.appendTo($tabContent);

        });

        ////
        // Put it all together
        ////

        var $html = $("<div/>", {
          "class": "",
          "id": "oa-wizard",
          html: $("<div/>", {
            "class": "row",
            html: $navItems
          }).append(
            $('<div/>', {
              "class": "content",
              html: $tabContent
            }))
        });

        ////
        // Hide original form, insert new wizard and show 1st tab
        ////

        $form.find('div').hide();
        $form.prepend($html);
      }

      // show first item
      $('#oa-wizard').find('[data-toggle="tab"]').eq(0).tab('show');
    }
  }

}(jQuery));

