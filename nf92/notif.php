<?php 
$notif = $session->read('message');
if (isset($notif['notifs'])) {
  $m = $notif['notifs'];
?>
    <div class="alert <?php echo (isset($m['type'])) ? "alert-".$m['type'] : "alert-info" ?>">
    <button type="button" class="close" data-dismiss="alert">&times;</button>
    <?php echo $m['msg']; ?>
    </div>
<?php
$session->del('message');
}
?>
