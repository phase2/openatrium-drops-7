<?php
/**
 * @file
 * This template handles the layout of oa_modal.
 */
?>
<div id="<?php print $modal_id; ?>" class="modal hide fade" tabindex="-1" role="dialog" aria-labelledby="<?php print "$modal_id-header"; ?>" aria-hidden="true">
    <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">x</button>
        <h3 id="<?php print "$modal_id-header"; ?>"><?php print $title; ?></h3>
    </div>
    <div class="modal-body">
      <?php print $body; ?>
    </div>
    <div class="modal-footer">
        <button class="btn" data-dismiss="modal" aria-hidden="true"><?php print t('Close'); ?></button>
    </div>
</div>

