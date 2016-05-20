<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $nom_journal = clean($_POST['nom_journal']);
  $id_animateur = clean($_POST['id_animateur']);
  $langue = clean($_POST['langue']);
  $nom_pays = clean($_POST['nom_pays']);
  $creneau_id = clean($_POST['creneau_id']);

  try{
    $db->pdo->beginTransaction();
    $db->save('journal',array('nom_journal'=>$nom_journal,
                            'id_animateur' => $id_animateur,
                            'langue' => $langue,
                            'nom_pays' => $nom_pays
                            ),false);
    $db->save('journal_creneau',array('journal' => $nom_journal,
                                    'creneau' => $creneau_id
                              ),false);
    $db->pdo->commit();

      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Journal ajouté avec succès.
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
