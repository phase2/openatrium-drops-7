<?php
/**
 * @file
 * Provides theming for oa_toolbar_search widget.
 *
 * $options - Options to provide the search upon submitting.
 */
?>

<div class="toolbar-search">
  <form action="search/site" method="post">
    <div class="input-append">
      <input type="text" class="search-text">
      <div class="btn-group">
        <button type="submit" class="btn submit <?php print $oa_toolbar_btn_class; ?>">
          <i class="icon-search"></i>
        </button>
        <button class="btn dropdown-toggle <?php print $oa_toolbar_btn_class; ?>" data-toggle="dropdown">
          <span class="caret"></span>
        </button>
        <ul class="dropdown-menu options">
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
      </div>
    </div>
  </form>
</div>