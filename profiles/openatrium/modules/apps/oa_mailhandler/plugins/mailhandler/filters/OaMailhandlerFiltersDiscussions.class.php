<?php
/**
 * @file
 * OaMailhandlerFiltersDiscussions class.
 */

class OaMailhandlerFiltersDiscussions extends MailhandlerFilters {
  /**
   * Whether or not to fetch message, based on headers.
   *
   * @param $header
   *   Message headers
   * @return
   *   TRUE if node, FALSE otherwise
   */
  function fetch($header) {
    // For a discussion post it must be a reply.
    if (!isset($header->in_reply_to)) {
      return FALSE;
    }

    // Only discussion posts.
    $node = oa_mailhandler_get_node_from_subject($header->subject);
    return $node && $node->type == 'oa_discussion_post';
  }
}
