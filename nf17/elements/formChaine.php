<form class="form-horizontal ajaxForm" data-value="Chaine">
  <section class="left">
    <div class="control-group">
      <label class="control-label" for="chaine">Chaine</label>
      <div class="controls">
        <input class="required" name="nom_chaine" data-type="varchar" type="text" id="chaine" placeholder="Nom" required>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="active">Activer la chaîne ?</label>
      <div class="controls">
        <input type="hidden" name="active" value="0" id="active_" data-type="bool" class="">
        <input type="checkbox" name="active" value="1" id="active" data-type="bool" class="">
        <span class="help-inline"></span>
      </div>
    </div>
    <div>
     <span><strong>Plage de diffusion : </strong></span>
    </div>
    <div class="control-group">
      <label class="control-label" for="heure_debut">Début</label>
      <div class="controls">
        <input class="required" name="heure_debut" data-type="time" type="text" id="heure_debut" placeholder="06:00:00" required>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="heure_fin">Fin</label>
      <div class="controls">
        <input class="required" name="heure_fin" data-type="time" type="text" id="heure_fin" placeholder="23:00:00" required>
        <span class="help-inline"></span>
      </div>
    </div>
  </section>
  <section class="right">
    <div class="control-group">
      <label class="control-label" for="nom_dir">Directeur de programme</label>
      <div class="controls">
        <select name="nom_dir" id="nom_dir">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $dirs = $mysql->find("SELECT * FROM directeur_programme ORDER BY nom_dir;");
          foreach ($dirs as $k => $v) {
            ?>
              <option value="<?php echo $v['nom_dir']; ?>"><?php echo $v['nom_dir']; ?> (<?php echo $v['date_embauche']; ?>)</option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="siege_id">Siège social</label>
      <div class="controls">
        <select name="siege_id" id="siege_id">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $sieges = $mysql->find("SELECT * FROM siege_social ORDER BY code_postal;");
          foreach ($sieges as $k => $v) {
            ?>
              <option value="<?php echo $v['id']; ?>"><?php echo $v['rue']; ?>, <?php echo $v['ville']; ?> (<?php echo $v['code_postal']; ?>)</option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="genre">Moyens de diffusion</label>
      <div class="controls">
        <select name="moyens[]" id="genre" multiple="multiple">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $moyens = $mysql->find("SELECT * FROM moyen_diffusion ORDER BY genre;");
          foreach ($moyens as $k => $v) {
            ?>
              <option value="<?php echo $v['genre']; ?>"><?php echo $v['genre']; ?></option>
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
