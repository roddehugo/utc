<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $nom = clean($_POST['nom']);
  $prenom = clean($_POST['prenom']);
  $nationalite = clean($_POST['nationalite']);
  $telephone = clean($_POST['telephone']);
  $type_personne = clean($_POST['type_personne']);

  try{
    $db->pdo->beginTransaction();
    $db->save('personne',array('nom'=>$nom,
                            'prenom'=>$prenom,
                            'nationalite' => $nationalite,
                            'telephone' => $telephone
                            ),true);
    $personne_id = $db->lastInsertId('personne_id_seq');
    foreach ($type_personne as $type) {
      $db->save('populaire_personne',array('type' => $type,
                                    'personne_id' => $personne_id,
                                    'type_personne' => $type_personne
                              ),false);
    }

    $db->pdo->commit();

      ?>
      <div class="alert fade in alert-success">
        <button type="button" class="close" data-dismiss="alert">×</button>
        <strong>Bravo !</strong> Personne ajoutée avec succès.
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
