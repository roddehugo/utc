<form class="form-horizontal ajaxForm" data-value="PublicVise">
 <div class="control-group">
      <label class="control-label" for="nom_emission">Emission</label>
      <div class="controls">
        <select name="nom_emission" id="nom_emission">
          <?php
          require_once '../classes/db.class.php';
          $db = new DB();
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
  <div class="control-group">
      <label class="control-label" for="type_public">Type de public</label>
      <div class="controls">
        <select name="type_public[]" id="type_public" multiple="multiple">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $moyens = $mysql->find("SELECT * FROM public ORDER BY type_public;");
          foreach ($moyens as $k => $v) {
            ?>
              <option value="<?php echo $v['type_public']; ?>"><?php echo $v['type_public']; ?></option>
            <?php
          }
          ?>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
