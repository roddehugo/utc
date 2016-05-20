<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $nom_serie = clean($_POST['nom_serie']);
  $theme = clean($_POST['theme']);
  $nom_studio = clean($_POST['nom_studio']);
  $langue = clean($_POST['langue']);
  $nom_pays = clean($_POST['nom_pays']);
  $creneau_id = clean($_POST['creneau_id']);

  try{
    $db->pdo->beginTransaction();
    $db->save('serie',array('nom_serie'=>$nom_serie,
                            'genre'=>$theme,
                            'nom_studio' => $nom_studio,
                            'nom_pays' => $nom_pays,
                            'langue' => $langue
                            ),false);
    $db->save('serie_creneau',array('serie' => $nom_serie,
                                    'creneau' => $creneau_id
                              ),false);
    $db->pdo->commit();

      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Série ajoutée avec succès.
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
