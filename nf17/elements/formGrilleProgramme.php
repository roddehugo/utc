<form class="form-horizontal ajaxForm" data-value="GrilleProgramme">
  <div class="control-group">
    <label class="control-label" for="nom_chaine">Chaine</label>
    <div class="controls">
      <select name="nom_chaine" id="nom_chaine">
        <?php
        require_once '../classes/db.class.php';
        $mysql = new DB();
        $dirs = $mysql->find("SELECT nom_chaine FROM chaine ORDER BY nom_chaine;");
        foreach ($dirs as $k => $v) {
          ?>
            <option value="<?php echo $v['nom_chaine']; ?>"><?php echo $v['nom_chaine']; ?></option>
          <?php
        }
        ?>
      </select>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="control-group">
    <label class="control-label" for="annee">Année</label>
    <div class="controls">
      <input class="required" name="annee" data-type="integer" type="number" id="annee" placeholder="2013" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
