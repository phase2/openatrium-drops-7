<?php $align = 'right'; // override alignment for oa_radix backwards compatibility ?>
<?php if ($show_title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
<?php if ($show_author): ?>
<div class="oa-users-submitted align-<?php print $align;?>">
  <?php if ($align == 'left'):?>
    <div class="user-badge">
      <?php if (!empty($picture)):?>
        <span class="oa-user-picture"><?php print $picture; ?></span>
      <?php endif; ?>
      <?php if (!empty($userlink)):?>
        <span><?php print $userlink; ?></span>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <div class="oa-description">
    <?php if (!empty($label)):?>
      <?php print $label; ?>
    <?php endif; ?>
    <?php if (!empty($date)):?>
      <?php print $date; ?>
    <?php endif; ?>
    <?php if (($align == 'right') && (!empty($bylabel))):?>
      <?php print $bylabel; ?>
    <?php endif; ?>
  </div>
  <?php if ($align == 'right'):?>
    <div class="user-badge">
      <?php if (!empty($userlink)):?>
        <span><?php print $userlink; ?></span>
      <?php endif; ?>
      <?php if (!empty($picture)):?>
        <span class="oa-user-picture"><?php print $picture; ?></span>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
<?php endif; ?>
