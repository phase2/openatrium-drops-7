<?php
/**
 * @file
 * Template file for OA Responsive regions drawer toggle.
 */
?>

<div id='oa-mobile-<?php print $menuid; ?>' class='<?php print $classes; ?> <?php print $menuid; ?> <?php print $breakpoints; ?>'>
  <button type="button" data-toggle="collapse" data-target="#oa-navbar-<?php print $menuid; ?>"
          class="oa-mobile-icon btn btn-navbar navbar-toggle <?php print $menuid; ?> <?php print $btn_class; ?>">
    <span class="sr-only">Toggle <?php print $menuid; ?> navigation</span>
    <span class="<?php print $icon; ?>"></span>
  </button>
  <div id="oa-navbar-<?php print $menuid; ?>" class="collapse">
    <div class="oa-navbar-inner"></div>
  </div>
</div>
