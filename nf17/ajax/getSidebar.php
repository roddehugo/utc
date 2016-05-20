<?php

require '../classes/db.class.php';
require '../classes/session.class.php';
require '../bootstrap.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  $db = new DB();

  if(isset($_POST['nom_chaine'])){
    $nom_chaine = clean($_POST['nom_chaine']);

    $chaine = $db->find("SELECT * FROM chaine as c
      INNER JOIN siege_social as ss ON ss.id = c.siege_id
      INNER JOIN directeur_programme as dp ON dp.nom_dir = c.nom_dir
      WHERE c.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    $films = $db->find("SELECT DISTINCT nom_film, annee_sortie, p.nom, p.prenom, nom_studio, langue, nom_pays FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN film_creneau as fc ON fc.creneau = c.id
      INNER JOIN film as f ON fc.film=f.nom_film
      INNER JOIN personne as p ON p.id = f.id_realisateur
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    $documentaires = $db->find("SELECT DISTINCT nom_docu, r.nom, r.prenom, a.nom as anom, a.prenom as aprenom, theme, nom_studio, langue, nom_pays FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN documentaire_creneau as fc ON fc.creneau = c.id
      INNER JOIN documentaire as d ON fc.docu=d.nom_docu
      INNER JOIN personne as a ON a.id = d.id_animateur
      INNER JOIN personne as r ON r.id = d.id_realisateur
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    $series = $db->find("SELECT DISTINCT nom_serie, nom_studio, langue, nom_pays,genre  FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN serie_creneau as fc ON fc.creneau = c.id
      INNER JOIN serie as s ON fc.serie=s.nom_serie
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));

    $journaux = $db->find("SELECT DISTINCT nom_journal, a.nom, a.prenom, langue, nom_pays  FROM grille_programme as gp
      INNER JOIN creneau as c ON gp.id=c.grille_id
      INNER JOIN journal_creneau as fc ON fc.creneau = c.id
      INNER JOIN journal as j ON fc.journal=j.nom_journal
      INNER JOIN personne as a ON a.id = j.id_animateur
      WHERE gp.nom_chaine = :nom_chaine;",array('nom_chaine'=>$nom_chaine));
    ?>
    <!--Sidebar content-->
    <div class="accordion" id="accordion">
      <div class="accordion-group">
        <div class="accordion-heading">
          <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion" href="#collapseOne">
            Informations
          </a>
        </div>
        <div id="collapseOne" class="accordion-body collapse in">
          <div class="accordion-inner" id="side-informations">
            <strong>Nom de la chaine</strong> : <?php echo $chaine[0]['nom_chaine']; ?><br>
            <strong>Active</strong> : <?php echo ($chaine[0]['active']=="1") ? "Oui" : "Non"; ?><br>
            <strong>Plage de diffusion</strong> : <?php echo $chaine[0]['heure_debut']; ?> - <?php echo $chaine[0]['heure_fin']; ?><br>
            <strong>Directeur</strong> : <?php echo $chaine[0]['nom_dir']; ?> (<?php echo $chaine[0]['date_embauche']; ?>)<br>
            <strong>Siège social</strong> : <?php echo $chaine[0]['rue']; ?>, <?php echo $chaine[0]['ville']; ?> <?php echo $chaine[0]['code_postal']; ?>
          </div>
        </div>
      </div>
      <div class="accordion-group">
        <div class="accordion-heading">
          <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordion" href="#collapseTwo">
            Liste des émissions
          </a>
        </div>
        <div id="collapseTwo" class="accordion-body collapse">
          <div class="accordion-inner" id="side-emissions">
            <strong>Films</strong><br>
              <?php foreach ($films as $k => $v): ?>
                <?php echo $v['nom_film'] ?>
                <ul>
                  <li>Année de sortie : <?php echo $v['annee_sortie']; ?></li>
                  <li>Réalisateur : <?php echo $v['prenom']." ".$v['nom']; ?></li>
                  <li>Studio : <?php echo $v['nom_studio']; ?></li>
                  <li>Langue : <?php echo $v['langue']; ?></li>
                  <li>Pays : <?php echo $v['nom_pays']; ?></li>
                </ul>
              <?php endforeach ?>
               <strong>Séries</strong><br>
              <?php foreach ($series as $k => $v): ?>
                <?php echo $v['nom_serie'] ?>
                <ul>
                  <li>Genre : <?php echo $v['genre']; ?></li>
                  <li>Studio : <?php echo $v['nom_studio']; ?></li>
                  <li>Langue : <?php echo $v['langue']; ?></li>
                  <li>Pays : <?php echo $v['nom_pays']; ?></li>
                </ul>
              <?php endforeach ?>
               <strong>Documentaires</strong><br>
              <?php foreach ($documentaires as $k => $v): ?>
                <?php echo $v['nom_docu'] ?>
                <ul>
                  <li>Réalisateur : <?php echo $v['prenom']." ".$v['nom']; ?></li>
                  <li>Animateur : <?php echo $v['aprenom']." ".$v['anom']; ?></li>
                  <li>Thème : <?php echo $v['theme']; ?></li>
                  <li>Studio : <?php echo $v['nom_studio']; ?></li>
                  <li>Langue : <?php echo $v['langue']; ?></li>
                  <li>Pays : <?php echo $v['nom_pays']; ?></li>
                </ul>
              <?php endforeach ?>
              <strong>Journaux</strong><br>
              <?php foreach ($journaux as $k => $v): ?>
                <?php echo $v['nom_journal'] ?>
                <ul>
                  <li>Animateur : <?php echo $v['prenom']." ".$v['nom']; ?></li>
                  <li>Langue : <?php echo $v['langue']; ?></li>
                  <li>Pays : <?php echo $v['nom_pays']; ?></li>
                </ul>
              <?php endforeach ?>
          </div>
        </div>
      </div>
    </div>

    <?php

  }else{
    echo "Pas de chaine";
  }
}else{
  header('Location: 404.php');
  die();
}
