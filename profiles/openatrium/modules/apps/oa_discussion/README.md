Plugin App to provide Discussion Forum functionality.

This is a completely custom module designed to showcase what is possible
within a custom Open Atrium App. It does not require any modules other than
those normally included in oa_core. It demonstrates how extensively custom
content types can be modified to provide a rich collaborative experience. It
demonstrates custom messages and complex Views-based widgets.

Architecture
============

Rather than using the Forums and/or Advanced Forums module, a light-weight
custom forum application was written for Open Atrium. It uses a single
content-type "oa_discussion_post" for both top-level topics as well
as replies. This allows replies to have the full functionality of a main topic
(attachments, etc). Each post/reply has a Parent entityreference field to
indicate which node it is a reply to. When the Parent field is null/empty, the
node is a top-level topic. This allows a reply to be promoted to a top-level
topic by just clearing the Parent field. Entire reply chains or topics can be
moved by simply changing the Parent pointer.

By not using Drupal Comment entities, Discussion replies are less susceptible
to automated spam bots designed to attack Drupal sites. To add additional
antispam protection, modules such as Captcha can be added to the reply form.
If something like Mollum is really needed, normal Drupal comments can still be
enabled, although Mollum has been shown to actually cause more spam in some
cases. In general, anonymous replies and comments should not be allowed on
sites. If public comments/replies are needed, use the
[Open Atrium Wiki (oa_wiki)](http://github.com/phase2/oa_wiki)
content type with comments and Disqus installed rather than using Discussions.

Discussions use the global oa_media field for handling attachments.
Attachments to replies are aggregated in the Document/Media widget that
displays all media attached to replies of a specific topic thread.

Notification settings for Replies are directed to the top-level topic post to
provide consistent notifications within a thread.

A custom message oa_reply is used to alter normal oa_create messages when a
node is being created that is a reply to an existing node. This allows new
replies to reference the parent node in the notification message.

Additional permissions are defined to allow replies to be
created/edited/deleted separately from top-level topics.

Multi-threaded Discussions
--------------------------

OA Discussion was architected to only allow a single level of replies. While
the oa_parent field could (in theory) be used to point a reply to another
reply, other parts of the code (including Views and Widgets) assume the Parent
node is the top-level original post. In general, replies-to-replies is not
recommended for many reasons:

1. Multi-threaded Discussions (replies to replies) has poor usability. Users
   need to scan the entire thread for new content, rather than just looking at
   the bottom of the thread for new replies.

2. Multi-threaded Discussions encourage deeper tangents of discussions that
   often should be their own topics. These sidebars distract from the original
   topic. When using a notification-based discussion such as OA2, being
   notified by these tangential replies often annoys users who subscribed to
   the main topic.

3. Multi-threaded Discussions are a challenge from a performance perspective.
   Since any reply in the database could potentially be shown on page of the
   display, you must query all replies in order to render each page. For
   example, if 20 replies are shown per page, reply #100 could just as easily
   be shown as a reply to #1. You can't use the normal Drupal pager which uses
   SQL to limit the page to the first 20 results of the query.

If a client requires a more complex multi-threaded discussion, similar to
Reddit or Stack Overflow with rich ratings, etc, it is recommended that a new
custom OA2 app is written rather than trying to modify the built-in
Discussions.

Content Types
=============

oa_discussion_post
------------------

Used for both top-level topics as well as replies to existing topics (see
oa_parent field). Additional fields are:

- **oa_parent** - An entityreference field that points to the
  top-level Topic node for a reply. Top-level topics have a null/empty
  oa_parent field.

The full node detail page is panelized to always show the original post
summary at the top, followed by a View of the replies to the topic, followed
by the Reply form widget. Viewing any oa_discussion_post node will always show
this same panels view of the original topic. The only difference when going to
a specific reply detail page is that the specified reply is automatically
expanded in the View and highlighted by a green bar along the left.</p>

A variant of the node/edit form is used to control the column layout of
fields.

Messages
========

oa_reply
--------

Used to replace normal oa_create messages when creating a new reply to an
existing topic node.

Views
=====

oa_discussion
-------------

Contains several view displays for showing discussion content:

- **Discussion Replies** - (widget) Displays the replies to a
  given Parent topic. Used to show the Replies listing below the original
  topic on the main oa_discussion_post content page. Template in
  templates/views-view-fields--open-atrium-discussions–replies.tpl.php

- **Discussion Parent** - (widget) Displays the summary of the
  Parent topic for any reply. Used to show the original post on the
  oa_discussion_post content page. Template in
  templates/views-view-fields--open-atrium-discussions--original-post.tpl.php

- **Discussion Attachments** - (widget) Displays the
  attachments in a thread within the Document/Media widget. Template in
  templates/views-view-fields--open-atrium-discussions–attachments.tpl.php

- **Discussion Topics** - (widget) Displays the list of
  top-level topics in a Space/Section. Intended for display on a Section
  landing page, and added as the default widget on the Discussion Section
  section-type. This is a complex view that performs extensive aggregation to
  count the number of replies within a topic in a performant way. Take great
  care when modifying this view. Template in
  templates/views-view-fields--open-atrium-discussions--discussion-topics.tpl.php

- **User Topics** - (widget) Similar to Discussion Topics, but
  only shows topics created by a specific user. Used on the default user
  dashboard to show the user's posts. As with Discussion Topics, this view
  performs aggregation to count repies within the topic so take care when
  modifying this view. Template in
  templates/views-view-fields--open-atrium-discussions--discussion-user.tpl.php

- **User Reply Topics** - (widget) Similar to Discussion
  Topics, but only shows topics where the user has created a reply. Rather
  than linking the reply, it links to the entire thread. The Reply Count only
  counts the number of replies made by the specified user. Clicking the Last
  update link takes you to the last reply from the specified user. This widget
  is used on the default user dashboard to show a user's replies. Template in
  templates/views-view-fields--open-atrium-discussions--discussion-user-reply.tpl.php
