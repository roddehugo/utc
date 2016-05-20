<?php

require '../classes/db.class.php';
require '../bootstrap.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  $db = new DB();
  $grille_id = clean($_POST['grille_id']);
  $jour = clean($_POST['jour']);
  $heure_debut = clean($_POST['heure_debut']);
  $heure_fin = clean($_POST['heure_fin']);
  $audimat = clean($_POST['audimat']);

  $others = $db->find("SELECT count(*) as nb FROM creneau
              WHERE grille_id = $grille_id
                AND jour = '$jour'
                AND ( heure_fin BETWEEN '$heure_debut' AND '$heure_fin'
                OR heure_debut BETWEEN '$heure_debut' AND '$heure_fin' );");

  $grille = $db->find("SELECT count(*) as nb FROM grille_programme as gp
    INNER JOIN chaine as c ON c.nom_chaine=gp.nom_chaine WHERE gp.id = $grille_id
    AND c.heure_debut <= '$heure_debut' AND c.heure_fin >= '$heure_fin';");

  $valid = $grille[0]['nb'];
  $nb = $others[0]['nb'];
  if($nb == 0 && $valid > 0){
    try{
      $db->pdo->beginTransaction();

      $db->save('creneau',array('jour' => $jour,'heure_debut'=>$heure_debut,'heure_fin'=>$heure_fin,'grille_id' => $grille_id),true);
      $creneau_id = $db->lastInsertId('creneau_id_seq');

      if ($audimat) {
        for ($i=1; $i < 54; $i++) {
          $db->save('audimat',array(
            'semaine'=>$i,
            'creneau_id'=>$creneau_id,
            'nb_spectateur'=>rand(0,1000)),false);
        }
      }
      $db->pdo->commit();
    ?>
        <div class="alert fade in alert-success">
          <button type="button" class="close" data-dismiss="alert">×</button>
          <strong>Bravo !</strong> Creneau ajoutée avec succès.
        </div>
    <?php
    }catch(PDOException $e) {
      $db->pdo->rollBack();
    ?>
        <div class="alert fade in alert-error">
          <button type="button" class="close" data-dismiss="alert">×</button>
          <strong>Erreur !</strong> <?php echo $db->lastError(); ?>
        </div>
    <?php
    }
  }else{
    ?>
    <div class="alert fade in alert-error">
      <button type="button" class="close" data-dismiss="alert">×</button>
      <strong>Erreur !</strong> Impossible de chevaucher deux créneaux ou le créneau dépasse de la plage de diffusion de la chaine
    </div>
    <?php
  }

}else{
  header('Location: 404.php');
  die();
}
