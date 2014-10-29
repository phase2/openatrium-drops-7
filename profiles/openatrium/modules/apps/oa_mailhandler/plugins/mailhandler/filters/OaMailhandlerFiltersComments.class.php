<?php
/**
 * @file
 * OaMailhandlerFiltersComments class.
 */

class OaMailhandlerFiltersComments extends MailhandlerFilters {
  /**
   * Whether or not to fetch message, based on headers.
   *
   * @param $header
   *   Message headers
   * @return
   *   TRUE if comment, FALSE otherwise
   */
  function fetch($header) {
    // For a comment it must be a reply.
    if (!isset($header->in_reply_to)) {
      return FALSE;
    }

    // Replies to oa_discussion_posts don't count as comments.
    $node = oa_mailhandler_get_node_from_subject($header->subject);
    return empty($node) || $node->type != 'oa_discussion_post';
  }
}
