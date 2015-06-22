<?php
/**
 * @file
 * Provides theming for oa_sidebar_search widget.
 *
 * $options - Options to provide the search upon submitting.
 */
?>

<div class="toolbar-search">
  <form action="search/site" method="post" role="form">
    <div class="input-append form-group">
      <input type="text" class="search-text form-control" name="search_text">
      <button type="submit" class="btn btn-default btn-primary submit">
        <i class="icon-search"></i><span
          class="element-invisible"><?php print t('Search Button'); ?></span>
      </button>
    </div>
    <?php if (count(array_filter($options)) == 1): ?>
      <div class="options element-invisible <?php print $extra_classes ?>">
        <input type="radio" name="searchOptions"
               value="<?php $keys = array_keys($options); print reset($keys); ?>"
               checked>
      </div>
    <?php else: ?>
      <ul class="options <?php print $extra_classes ?>">
        <?php $checked = TRUE; ?>
        <?php foreach ($options as $option => $label): ?>
          <li class="radio">
            <label class="radio">
              <input type="radio" name="searchOptions"
                     value="<?php print $option; ?>" <?php print $checked ? 'checked' : ''; ?>>
              <?php print $label; ?>
            </label>
          </li>
          <?php $checked = FALSE; ?>
        <?php endforeach; ?>
      </ul>
    <?php endif; ?>
    <?php if (!empty($spaces)): ?>
      <?php print $spaces; ?>
    <?php endif; ?>
  </form>
</div>
