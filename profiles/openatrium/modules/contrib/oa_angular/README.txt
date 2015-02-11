Provides the AngularJS libraries used in Open Atrium

NOTE: This module is similar in some ways to the AngularJS project in that it provides a bridge between Drupal and the AngularJS libraries. If you are just looking for ways to integrate your Drupal site with AngularJS, use the AngularJS module. The Open Atrium Angular module includes the AngularJS libraries directly that are needed specifically for Open Atrium front-end apps. In addition, helper functions for Open Atrium App developers are provided to make it easier to include Angular within Panels Panes, such as how the OA Sitemap and OA Files apps work.

When using the oa_angular_add() function to add angular modules to a page, if the library isn't found within the oa_angular module itself, then it will use a remote CDN. But the intent of this module is to localize all of the AngularJS libraries needed for Open Atrium so a CDN is not required.

INCLUDED

Angular Core (v1.3.7)
---------------------
angular
angular-sanitize
angular-cookies

Other
-----
ngDraggable - provides directives for drag/drop
ng-modules - allows multiple angular modules on the same page (replaces ng-app)
ng-treecontrol - a hierarchical treeview directive
