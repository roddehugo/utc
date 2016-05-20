<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $nom_docu = clean($_POST['nom_docu']);
  $theme = clean($_POST['theme']);
  $id_animateur = clean($_POST['id_animateur']);
  $id_realisateur = clean($_POST['id_realisateur']);
  $nom_studio = clean($_POST['nom_studio']);
  $langue = clean($_POST['langue']);
  $nom_pays = clean($_POST['nom_pays']);
  $creneau_id = clean($_POST['creneau_id']);

  try{
    $db->pdo->beginTransaction();
    $db->save('documentaire',array('nom_docu'=>$nom_docu,
                            'theme'=>$theme,
                            'id_realisateur' => $id_realisateur,
                            'id_animateur' => $id_animateur,
                            'nom_studio' => $nom_studio,
                            'langue' => $langue,
                            'nom_pays' => $nom_pays
                            ),false);
    $db->save('documentaire_creneau',array('docu' => $nom_docu,
                                    'creneau' => $creneau_id
                              ),false);
    $db->pdo->commit();

      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Documentaire ajouté avec succès.
      </div>
      <?php
  }catch (PDOException $e){
    $db->pdo->rollBack();
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
