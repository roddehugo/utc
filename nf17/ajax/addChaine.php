<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $nom_chaine = clean($_POST['nom_chaine']);
  $heure_debut = clean($_POST['heure_debut']);
  $heure_fin = clean($_POST['heure_fin']);
  $active = clean($_POST['active']);
  $nom_dir = clean($_POST['nom_dir']);
  $siege_id = clean($_POST['siege_id']);
  $moyens = array_map("clean",$_POST['moyens']);

  if($db->save('chaine',array('nom_chaine' => $nom_chaine, 'heure_debut' => $heure_debut, 'heure_fin' => $heure_fin, 'active' => $active, 'nom_dir' => $nom_dir, 'siege_id' => $siege_id),false) ){
      foreach ($moyens as $v) {
        $db->save('utilise',array('nom_chaine' => $nom_chaine, 'genre' => $v),false);
      }
      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Chaine télé ajoutée avec succès.
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
