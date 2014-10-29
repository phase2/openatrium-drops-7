<?php
/**
 * @file
 * MailhandlerAuthenticateDefault class.
 */

class MailhandlerAuthenticateDefault extends MailhandlerAuthenticate {

  public function authenticate(&$message, $mailbox) {
    list($fromaddress, $fromname) = _mailhandler_get_fromaddress($message['header'], $mailbox);
    $uid = 0;
    if ($from_user = user_load_by_mail($fromaddress)) {
      $uid = $from_user->uid;
    }
    return $uid;
  }

}
