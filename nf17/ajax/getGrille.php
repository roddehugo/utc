<?php

require '../classes/db.class.php';
require '../classes/session.class.php';
require '../bootstrap.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  $db = new DB();

  if(isset($_GET['nom_chaine'])){
    $nom_chaine = clean($_GET['nom_chaine']);

    $films = $db->find("SELECT * FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN film_creneau as fc ON fc.creneau = c.id
      INNER JOIN film as f ON fc.film=f.nom_film
      INNER JOIN personne as p ON p.id = f.id_realisateur
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    $documentaires = $db->find("SELECT * FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN documentaire_creneau as fc ON fc.creneau = c.id
      INNER JOIN documentaire as d ON fc.docu=d.nom_docu
      INNER JOIN personne as a ON a.id = d.id_animateur
      INNER JOIN personne as r ON r.id = d.id_realisateur
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    $series = $db->find("SELECT * FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN serie_creneau as fc ON fc.creneau = c.id
      INNER JOIN serie as s ON fc.serie=s.nom_serie
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    $journaux = $db->find("SELECT * FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN journal_creneau as fc ON fc.creneau = c.id
      INNER JOIN journal as j ON fc.journal=j.nom_journal
      INNER JOIN personne as a ON a.id = j.id_animateur
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    echo json_encode(array('films'=>$films,'documentaires'=>$documentaires,'series'=>$series,'journaux'=>$journaux));
  }else{
    echo json_encode(array('error' => "Pas de grille"));
  }
}else{
  header('Location: 404.php');
  die();
}
