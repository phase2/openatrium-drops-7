<?php

/**
 * Email notifier.
 */
class MessageDigestWeek extends MessageDigest {
  public function getInterval() {
    return '1 week';
  }
}
