<?php
/**
 * @file
 * MailhandlerMultipleEmailAuthenticate  class.
 */

class MailhandlerMultipleEmailAuthenticate extends MailhandlerAuthenticate {

  public function authenticate(&$message, $mailbox) {
    list($fromaddress, $fromname) = _mailhandler_get_fromaddress($message['header'], $mailbox);
    if ($address = multiple_email_find_address($fromaddress)) {
      $message['authenticated_uid'] = $address->uid;
    }
    else {
      // Authentication failed. Try as anonymous.
      $message['authenticated_uid'] = 0;
    }
  }
}
