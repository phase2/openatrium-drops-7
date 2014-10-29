<?php
/**
 * @file
 * MailhandlerMultipleEmailAuthenticate  class.
 */

class MailhandlerMultipleEmailAuthenticate extends MailhandlerAuthenticate {

  public function authenticate(&$message, $mailbox) {
    list($fromaddress, $fromname) = _mailhandler_get_fromaddress($message['header'], $mailbox);
    $uid = 0;
    if ($address = multiple_email_find_address($fromaddress)) {
      $uid = $address->uid;
    }
    return $uid;
  }
}
