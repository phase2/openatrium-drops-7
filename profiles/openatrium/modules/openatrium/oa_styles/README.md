Open Atrium Styles
==================

This contains information on how to use some of the reusable styles and
components within Open Atrium.


Pane Styles
===========

Well
----
This creates a style for the Bootstrap Well that can be used on any Panels
Pane.  The Well style can be seen here:

http://twitter.github.com/bootstrap/components.html#misc

The Pane provides configuration options for a small, normal, and
large Well. (This refers to the padding of the Well).


Components
==========

Modal
-----
This component allow for easier use of a Bootstrap Modal.

http://twitter.github.com/bootstrap/javascript.html#modals

Bootstrap Modals allow for streamlined used of Modals with defined Header,
Body and Actions.  The use case here allows you to use a theme function to
quickly have the skeleton of the Modal in place and to define a link/button
that will dynamically populate the Modal Body.  For starters you need to
define the Modal with an optional ID and optional Title (although you likely
want to specify both).

To define the modal (put the skeleton content on on the page):

    theme('oa_styles_modal', array('modal_id' => 'oa-modal', 'title' => t('Modal Title')));

To use the Modal:

    l(t('Show Modal'), 'body/content.html', array('attributes' => array('data-toggle' => 'modal', 'data-target' => '#oa-modal')));

The link will popup the Modal and replace the body of the Modal with the content of the href, body/content.html.
