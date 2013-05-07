/**
 * @file navbar.js
 *
 * Defines the behavior of the Drupal administration navbar.
 */
(function ($, undefined) {

"use strict";

/**
 * Attach toggling behavior and notify the overlay of the navbar.
 */
Drupal.behaviors.navbar = {
  attach: function(context, settings) {
    var $navbar = $(context).find('#navbar').once('navbar');
    if ($navbar.length) {
      var $bar = $navbar.find('.navbar-bar');
      var $tray = $navbar.find('.navbar-tray');
      var $trigger = $navbar.find('.toggle-tray');
      // Instanstiate the bar.
      if ($bar.length) {
        Navbar.bar = new Navbar($bar);
      }
      // Instantiate the tray.
      if ($tray.length && $trigger.length) {
        Navbar.tray = new TraySlider($tray, $trigger);
      }
    }
  }
};
/**
 * Store references to the Navbar and TraySlider objects in the Navbar object.
 *
 * These references will be available in Drupal.Navbar.bar and
 * Drupal.Navbar.tray.
 */
$.extend(Navbar, {
  bar: null,
  tray: null
});
/**
 * A navbar is an administration action button container.
 */
function Navbar ($navbar) {
  this.$navbar = $navbar;
  // Recalculate the offset top on screen resize.
  var setHeight = $.proxy(this, 'setHeight');
  // Use debounce if it exists.
  setHeight = ('debounce' in Drupal) ? Drupal.debounce(setHeight, 250) : setHeight;
  $(window)
    .on({
      'resize.navbar': setHeight
    });
  // Navbar event handlers.
  this.$navbar
    .on({
      'setup.navbar': setHeight
    })
    .trigger('setup');
};

/**
 * Extend the prototype of the TraySlider class.
 */
$.extend(Navbar.prototype, {
  /**
   * The height of the navbar offsets the top of the page content.
   *
   * Page components can register with the offsettopchange event to know when
   * the height of the navbar changes.
   */
  setHeight: function() {
    this.height = this.$navbar.outerHeight();
    this.$navbar.attr('data-offset-top', this.height);
    // Alter the padding on the top of the body element.
    // @todo, this should be moved to drupal.js and register for
    // the offsettopchange event.
    $('body').css('paddingTop', this.height);
    $(document).trigger('offsettopchange');
  }
});
/**
 *
 */
function TraySlider ($tray, $trigger) {
  this.$tray = $tray;
  this.$trigger = $trigger;
  // Initiate the object.
  this.state = 'closed';
  this.ui = {
    'activeClass': 'active',
    'trayOpenBodyClass': 'menu-tray-open'
  };
  // Add a click handler to the toggle.
  this.$trigger
    .on({
      'setup.navbar': $.proxy(this, 'toggleTrigger'),
      'click.navbar': $.proxy(this, 'handleTriggerClick'),
      'toggled.navbar': $.proxy(this, 'toggleTrigger')
    })
    .trigger('setup', this.state);
  // The tray has a couple setup methods to run.
  var setup = $.Callbacks();
  setup.add($.proxy(this, 'renderAccordion'));
  setup.add($.proxy(this, 'displace'));
  this.$tray
    // Register event handlers.
    .on({
      'setup.navbar': setup.fire,
      'toggled.navbar': $.proxy(this, 'toggleTray')
    })
    // The tray will be positioned at the edge of the window.
    .addClass('positioned')
    // Triger setup.
    .trigger('setup', this.state);
  // Register for offsettopchange events.
  $(document)
    .on({
      // Offset value vas changed by a third party script.
      'offsettopchange.navbar': $.proxy(this, 'displace')
    });
};
/**
 * Extend the prototype of the TraySlider class.
 */
$.extend(TraySlider.prototype, {
  /**
   *
   */
  handleTriggerClick: function (event) {
    event.preventDefault();
    event.stopImmediatePropagation();
    this.state = (this.state === 'closed') ? 'open' : 'closed';
    this.$tray.trigger('toggled', this.state);
    this.$trigger.trigger('toggled', this.state);
  },
  /**
   *
   */
   toggleTrigger: function (event, state) {
    this.$trigger[((state === 'open') ? 'add' : 'remove') + 'Class'](this.ui.activeClass);
  },
  /**
   *
   */
  toggleTray: function (event, state) {
    this.$tray[((state === 'open') ? 'add' : 'remove') + 'Class'](this.ui.activeClass);
    // Add a class to the body so it can be styled to react to the tray.
    $('body')[((state === 'open') ? 'add' : 'remove') + 'Class'](this.ui.trayOpenBodyClass);
  },
  /**
   *
   */
  displace: function (event) {
    this.$tray.css({
      'top': this.computeOffsetTop() + 'px'
    });
  },
  /**
   * Sum all [data-offset-top] values and cache it.
   * @todo move this out of tableheader.js into a move generic place like drupal.js.
   */
  computeOffsetTop: function () {
    var $offsets = $('[data-offset-top]');
    var value, sum = 0;
    for (var i = 0, il = $offsets.length; i < il; i++) {
      value = parseInt($offsets[i].getAttribute('data-offset-top'), 10);
      sum += !isNaN(value) ? value : 0;
    }
    this.offsetTop = sum;
    return sum;
  },
  /**
   * Accordion behavior.
   */
  renderAccordion: function (event) {
    event.stopPropagation();
    var context = this;
    this.$tray.find('.navbar-menu > .menu').each(function (index, element) {
      var $root = $(this).addClass('root');
        // Wrap the list in a div to provide a positioning context.
      var $wrapper = $root.wrap($('<div>')
        .css({
            height: '100%',
            position: 'relative'
          })
          .addClass('fleximenu')
        )
        .parent()
        // Bind event handlers.
        .on({
          'setup.navbar': context.accordionSetup
        });
      // Create a set of list-manipulation callbacks.
      // Called when items are added or removed.
      var listUpdate = $.Callbacks();
      // Set visibility
      listUpdate.add(context.initItems);
      listUpdate.add($.proxy(context, 'markListLevels', $root));
      listUpdate.add($.proxy(context, 'setLevelVisibility', $root, 1));
      $wrapper
        .on('listChange.navbar', listUpdate.fire)
        .on('clean.navbar.accordionMode', 'li', context.cleanItem)
        .on('activate.navbar.accordionMode', 'li', context.activateItem)
        .on('click.navbar.accordionMode', '.handle', context.accordionToggle)
        .trigger('setup');
    });
  },
  accordionSetup: function (event) {
    event.stopPropagation();
    // Mark up the lists and items.
    $(this)
    .trigger('listChange');

  },
  cleanItem: function (event) {},
  activateItem: function (event) {},
  accordionToggle: function (event) {
    // The toggle.
    var $toggle = $(this);
    var $item = $toggle.closest('li');
    var $list = $item.children('ul');
    var isHidden = $list.hasClass('dormant');
    // Toggle the item open state.
    $item
      [((isHidden) ? 'add' : 'remove') + 'Class']('open');
    // Toggle the item list visibility.
    $list
      ['slide' + ((isHidden) ? 'Down' : 'Up')]()
      [((isHidden) ? 'remove' : 'add') + 'Class']('dormant');
    // Twist the toggle.
    $toggle
      [((isHidden) ? 'add' : 'remove') + 'Class']('open');

  },
  initItems: function (event) {
    // The accordion wrapper.
    var $wrapper = $(this);
    var rootClass = 'root';
    var boxClass = 'box';
    var handleClass = 'handle';
    // Get lists and items.
    var $root = $wrapper.children('.' + rootClass);
    var $ul = $wrapper.find('ul').once('fleximenu');
    var $li = $wrapper.find('li').once('fleximenu');
    // Basic setup
    $ul
      .each(function (index, element) {
        $(this).data('navbar', {
          processed: false,
          type: 'list',
          level: NaN
        });
      });
    // Initialize items and their links.
    $li
      .each(function (index, element) {
        $(this).data('navbar', {
          processed: false,
          type: 'item'
        });
      })
      // Add a class to item links.
      .children('a')
      .wrap(
        $('<div>', {
          'class': boxClass
        })
      )
      .end()
      // Add a handle to each list item if it has a menu.
      .each(function (index, element) {
        var $item = $(this);
        if ($item.children('ul').length > 0) {
          $item
            .children('.' + boxClass)
            .prepend(
              $('<span>', {
                'class': handleClass,
                text: ''
              })
            );
        }
      });
  },
  /**
   * Adds a level class to each list based on its depth in the menu.
   */
  markListLevels: function ($lists, level, event) {
    level = (typeof level === 'object') ? 1 : level;
    $lists
    .addClass('level-' + level)
    .each(function (index, element) {
      $(this).data().navbar.level = level;
    });
    $lists = $lists.children('li').children('ul');
    if ($lists.length > 0) {
      this.markListLevels($lists, (level + 1));
    }
  },
  setLevelVisibility: function ($lists, visibleAfter) {
    var level;
    $lists
    .each(function (index, element) {
      var $this = $(this);
      level = $(this).data().navbar.level;
      if (level > visibleAfter) {
        $this.addClass('dormant');
      }
      else {
        $this.addClass('visible');
      }
    });
    $lists = $lists.children('li').children('ul');
    if ($lists.length > 0) {
      this.setLevelVisibility($lists, visibleAfter);
    }
  }
});

// Assign the Navbar obect to the Drupal namespace.
Drupal.Navbar = Navbar;
}(jQuery));
