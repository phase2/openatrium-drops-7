/**
 * @file
 * Manage tweaks for oa_events.
 */

(function ($) {

  Drupal.behaviors.oaEvents = {
    attach: function(context, settings) {
      var $required = $('.node-oa_event-form #edit-field-oa-date .form-required');
      if ($required.length) {
        // Move the required markers up to the block title
        $required = $required.detach();
        $('.node-oa_event-form .fieldset-legend').append($required[0]);
      }

      // update the end date when the start date is changed
      var $start_date = $('#edit-field-oa-date-und-0-value-datepicker-popup-0');
      var $end_date   = $('#edit-field-oa-date-und-0-value2-datepicker-popup-0');
      if ($start_date.length && $end_date.length) {
        $start_date.data('oldval', $start_date.val());
        $start_date.change(function() {
          // only change end date if it hasn't already changed
          if ($start_date.data('oldval') == $end_date.val()) {
            $end_date.val($(this).val());
          }
          $start_date.data('oldval', $start_date.val());
        });
      }
    }
  }

}(jQuery));
