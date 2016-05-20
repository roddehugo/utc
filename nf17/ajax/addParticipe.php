<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $personne_id = clean($_POST['personne_id']);
  $nom_emission = clean($_POST['nom_emission']);
  $type_personne = clean($_POST['type_personne']);
  if($db->save('participe',array(
    'personne_id' => $personne_id,
    'nom_emission' => $nom_emission,
    'type_personne' => $type_personne),false) ){
      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Participant ajouté avec succès.
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
