<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $type_public = $_POST['type_public'];
  $nom_emission = clean($_POST['nom_emission']);

  try{
    $db->pdo->beginTransaction();
    foreach ($type_public as $type) {
      $type=clean($type);
      $db->save('vise',array('type_public' => $type,'nom_emission'=>$nom_emission),false);
    }
    $db->pdo->commit();
      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Type de public ajouté avec succès.
      </div>
      <?php
  }catch(PDOException $e){
    $db->pdo->rollBack();
      ?>
      <div class="alert fade in alert-error">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Erreur !</strong> <?php echo $db->lastQuery(); ?>
      </div>
      <?php
  }

}else{
  header('Location: 404.php');
  die();
}
