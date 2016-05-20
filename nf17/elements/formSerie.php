<form class="form-horizontal ajaxForm" data-value="Serie">
  <section class="left">
    <div class="control-group">
      <label class="control-label" for="serie">Nom</label>
      <div class="controls">
        <input class="required" name="nom_serie" data-type="varchar" type="text" id="serie" placeholder="Nom de la série" required>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="theme">Genre</label>
      <div class="controls">
        <select name="theme" id="theme">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $dirs = $mysql->find("SELECT * FROM theme WHERE type_theme = 'serie' ORDER BY nom_theme ;");
          foreach ($dirs as $k => $v) {
            ?>
              <option value="<?php echo $v['nom_theme']; ?>"><?php echo $v['nom_theme']; ?></option>
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
