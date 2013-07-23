<?php
/**
 * @file
 * Provides theming for oa_sidebar_search widget.
 *
 * $options - Options to provide the search upon submitting.
 */
?>

<div class="toolbar-search">
  <form action="search/site" method="post">
    <div class="input-append">
      <input type="text" class="search-text">
      <button type="submit" class="btn submit">
        <i class="icon-search"></i><span class="element-invisible"><?php print t('Search Button');?></span>
      </button>
    </div>
    <ul class="options">
    <?php $checked = TRUE; ?>
    <?php foreach ($options as $option => $label): ?>
      <li>
        <label class="radio">
          <input type="radio" name="searchOptions" value="<?php print $option; ?>" <?php print $checked ? 'checked' : ''; ?>>
          <?php print $label; ?>
        </label>
      </li>
      <?php $checked = FALSE; ?>
    <?php endforeach; ?>
    </ul>
  </form>
</div>