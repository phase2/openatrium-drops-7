<?php
/**
 * @file
 * This template handles the layout of oa_modal.
 */
?>

<!-- Modal -->
<div class="modal fade" id="<?php print $modal_id; ?>" tabindex="-1" role="dialog" aria-labelledby="<?php print "$modal_id-header"; ?>" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h3 id="<?php print "$modal_id-header"; ?>"><?php print $title; ?></h3>
      </div>
      <div class="modal-body">
        <?php print $body; ?>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal"><?php print t('Close'); ?></button>
      </div>
    </div>
  </div>
</div>