(function ($) {

Drupal.fullcalendar.plugins.fullcalendar_create = {
  options: function (fullcalendar, settings) {
    if (!settings.fullcalendar_create) {
      return;
    }
    settings = settings.fullcalendar_create;

    Drupal.ajax.prototype.commands.fullcalendar_create_reload = function (ajax, data, status) {
      location.reload();
    };

    var options = {};
    if (settings.select) {
      options.selectable = true;
      options.select = function (startDate, endDate, allDay, jsEvent, view) {
        if (settings.days && !settings.days[$.fullCalendar.formatDate(startDate, 'dddd')]) {
          return;
        }

        var ajax = new Drupal.ajax('main', fullcalendar.$calendar[0], {
          event: 'fullcalendar_create_add_select',
          url: '/fullcalendar_create/ajax/add/' + settings.node_type,
          submit: {
            fullcalendar_create_start_date: $.fullCalendar.formatDate(startDate, 'u'),
            fullcalendar_create_end_date: $.fullCalendar.formatDate(endDate, 'u'),
            fullcalendar_create_date_field: settings.date_field
          }
        });
        $(ajax.element)
          .bind('fullcalendar_create_add_select', Drupal.CTools.Modal.clickAjaxLink)
          .trigger('fullcalendar_create_add_select');
        this.unselect();
      };
    }
    if (settings.click) {
      options.dayClick = function (date, allDay, jsEvent, view) {
        if (settings.days && !settings.days[$.fullCalendar.formatDate(date, 'dddd')]) {
          return;
        }

        var ajax = new Drupal.ajax('main', fullcalendar.$calendar[0], {
          event: 'fullcalendar_create_add_click',
          url: '/fullcalendar_create/ajax/add/' + settings.node_type,
          submit: {
            fullcalendar_create_start_date: $.fullCalendar.formatDate(date, 'u'),
            fullcalendar_create_date_field: settings.date_field
          }
        });
        $(ajax.element)
          .bind('fullcalendar_create_add_click', Drupal.CTools.Modal.clickAjaxLink)
          .trigger('fullcalendar_create_add_click');
      };
    }
    return options;
  }
};


}(jQuery));
