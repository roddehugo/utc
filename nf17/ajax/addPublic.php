<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $type_public = clean($_POST['type_public']);

  if($db->save('public',array('nom_dir' => $type_public),false) ){
      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Type de public ajouté avec succès.
      </div>
      <?php
  }else{
      ?>
      <div class="alert fade in alert-error">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Erreur !</strong> <?php echo $db->lastError(); ?>
      </div>
      <?php
  }

}else{
  header('Location: 404.php');
  die();
}
