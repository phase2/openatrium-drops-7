<?php

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[module]--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
?>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <?php if ($css): ?>
    <style type="text/css">
      <!--
      <?php print $css ?>
      -->
    </style>
    <?php endif; ?>
  </head>
  <body id="mimemail-body" <?php if ($module && $key): print 'class="'. $module .'-'. $key .'"'; endif; ?>>
    <?php if ($css): ?>
      <h2 class="subject"><?php print $subject; ?></h2>
    <?php endif; ?>
    <table class="mail-table">
        <?php if ($recipient_details): ?>
      <tr>
        <td></td>
        <td class="user-badge">
          <a href="<?php print url('user/' . $recipient->uid); ?>">
            <?php print $recipient_details['realname']; ?>
            <?php print $recipient_details['picture']; ?>
          </a>
        </td>
      </tr>
        <?php endif; ?>
      <tr>
        <td class="body"><?php print $body; ?></div></td>
      </tr>
    </table>
  </body>
</html>
