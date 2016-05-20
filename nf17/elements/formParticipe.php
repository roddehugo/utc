<form class="form-horizontal ajaxForm" data-value="Participe">
  <section class="left">
    <div class="control-group">
      <label class="control-label" for="personne_id">Personne</label>
      <div class="controls">
        <select name="personne_id" id="personne_id">
          <?php
          require_once '../classes/db.class.php';
          $db = new DB();
          $sieges = $db->find("SELECT * FROM personne ORDER BY prenom, nom;");
          foreach ($sieges as $k => $v) {
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
      <label class="control-label" for="nom_emission">Emission</label>
      <div class="controls">
        <select name="nom_emission" id="nom_emission">
          <?php
          require_once '../classes/db.class.php';
          $films = $db->find("SELECT DISTINCT nom_film FROM film ORDER BY nom_film;");
          ?>
          <optgroup label="Films">
          <?php
          foreach ($films as $k => $v) {
            ?>
              <option value="<?php echo $v['nom_film']; ?>"><?php echo $v['nom_film']; ?></option>
            <?php
          }
          ?>
          </optgroup>
          <optgroup label="Séries">
          <?php
          $series = $db->find("SELECT DISTINCT nom_serie FROM serie ORDER BY nom_serie;");
          foreach ($series as $k => $v) {
            ?>
              <option value="<?php echo $v['nom_serie']; ?>"><?php echo $v['nom_serie']; ?></option>
            <?php
          }
          ?>
          </optgroup>
          <optgroup label="Journaux">
          <?php
          $journals = $db->find("SELECT DISTINCT nom_journal FROM journal ORDER BY nom_journal;");
          foreach ($journals as $k => $v) {
            ?>
              <option value="<?php echo $v['nom_journal']; ?>"><?php echo $v['nom_journal']; ?></option>
            <?php
          }
          ?>
          </optgroup>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
  </section>
  <section class="right">
    <div class="control-group">
      <label class="control-label" for="type_personne">Type d'émission</label>
      <div class="controls">
        <select name="type_personne" id="type_personne">
              <option value="film">Film</option>
              <option value="serie">Série</option>
              <option value="journal">Journal</option>
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
