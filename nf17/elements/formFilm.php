<form class="form-horizontal ajaxForm" data-value="Film">
  <section class="left">
    <div class="control-group">
      <label class="control-label" for="film">film</label>
      <div class="controls">
        <input class="required" name="nom_film" data-type="varchar" type="text" id="film" placeholder="Nom du film" required>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="annee_sortie">Année de sortie</label>
      <div class="controls">
        <input class="required" name="annee_sortie" data-type="integer" type="text" id="annee_sortie" placeholder="2013" required>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="semaine">Semaine de diffusion</label>
      <div class="controls">
        <select name="semaine" id="semaine">
          <?php
          for ($i=1; $i < 54; $i++) {
          ?>
          <option value="<?php echo $i; ?>"><?php echo $i; ?></option>
          <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="id_realisateur">Réalisateur</label>
      <div class="controls">
        <select name="id_realisateur" id="id_realisateur">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $dirs = $mysql->find("SELECT * FROM personne ORDER BY nom, prenom;");
          foreach ($dirs as $k => $v) {
            ?>
              <option value="<?php echo $v['id']; ?>"><?php echo $v['prenom']; ?> <?php echo $v['nom']; ?></option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="nom_studio">Studio</label>
      <div class="controls">
        <select name="nom_studio" id="nom_studio">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $sieges = $mysql->find("SELECT * FROM studio ORDER BY nom_studio;");
          foreach ($sieges as $k => $v) {
            ?>
              <option value="<?php echo $v['nom_studio']; ?>"><?php echo $v['nom_studio']; ?></option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
  </section>
  <section class="right">
    <div class="control-group">
      <label class="control-label" for="langue">Langue</label>
      <div class="controls">
        <select name="langue" id="langue">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $dirs = $mysql->find("SELECT * FROM version ORDER BY langue;");
          foreach ($dirs as $k => $v) {
            ?>
              <option value="<?php echo $v['langue']; ?>"><?php echo $v['langue']; ?></option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="nom_pays">Pays</label>
      <div class="controls">
        <select name="nom_pays" id="nom_pays">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $sieges = $mysql->find("SELECT * FROM pays ORDER BY nom_pays;");
          foreach ($sieges as $k => $v) {
            ?>
              <option value="<?php echo $v['nom_pays']; ?>"><?php echo $v['nom_pays']; ?></option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="creneau_id">Creneau de diffusion</label>
      <div class="controls">
        <select name="creneau_id" id="creneau_id">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $sieges = $mysql->find("SELECT c.*, gp.nom_chaine, gp.annee FROM creneau as c
                                  INNER JOIN grille_programme as gp ON gp.id = c.grille_id
                                  WHERE c.id NOT IN (SELECT creneau FROM documentaire_creneau)
                                    AND c.id NOT IN (SELECT creneau FROM film_creneau)
                                    AND c.id NOT IN (SELECT creneau FROM serie_creneau)
                                    AND c.id NOT IN (SELECT creneau FROM journal_creneau)
                                  ORDER BY nom_chaine, annee, jour, heure_debut, heure_fin;");
          foreach ($sieges as $k => $v) {
            ?>
              <option value="<?php echo $v['id']; ?>"><?php echo $v['nom_chaine']; ?> - <?php echo $v['annee']; ?> <?php echo $v['jour']; ?> <?php echo $v['heure_debut']; ?> <?php echo $v['heure_fin']; ?></option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
  </section>
  <div class="clearfix"></div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
