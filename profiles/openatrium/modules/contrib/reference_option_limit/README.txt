Reference options limit module
==============================

This module allows reference fields of several types to have their available
options limited by the values of other fields in the current entity.

Requirements
------------

- Drupal core 7.8 or higher, due to our use of hook_field_widget_form_alter().

Example
-------

Suppose you want news stories to be marked as being about a sport and a
particular team for that sport, perhaps using taxonomy terms for both.

To make editing easier, you would probably like want the 'team' dropdown to
be limited to just teams for the current news story's sport.

To achieve this with this module, add the 'sport' field to both news story 
nodes and team taxonomy terms. Hence the team 'Chudley Cannons' would have
as its team taxonomy term 'Quidditch'.

(This probably entails taxonomy term reference fields on terms
themselves... which was bound to happen with FieldAPI sooner or later.)

Thus, when editing a news story node, selecting 'Quidditch' as the sport
will cause the team reference field to update to show only teams which
also have Quidditch' as their* sport.

Setup
-----

Suppose:
- the option limited field (i.e. the field you want to limit) is on
  entity type A.
- this field points to (i.e., refers to) entities of type B.

1. Add your entity reference field on entity type A as normal. This will be the
  option limited field.
2. Add a field to entity type A whose values will be used to limit the option
  limited field.
3. Add the *same field* to entity type B.
4. Return to the option limited field settings and select field B as your
  matching field.

Terminology
-----------

- option limited field: a field whose type is some sort of reference, whose
   reference options we limit with this module.
- matching field: a field whose values we use to limit the options in an
   option limited field. We do this by requiring that the field be applied
   to both:
   - the entity bundle that bears the option limited field itself
   - the entity bundle(s) that the option limited field may refer to
