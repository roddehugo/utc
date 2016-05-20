<form class="form-horizontal ajaxForm" data-value="Creneau">
  <div class="control-group">
    <label class="control-label" for="grille_id">Grille correspondante</label>
    <div class="controls">
      <select name="grille_id" id="grille_id">
        <?php
        require_once '../classes/db.class.php';
        $mysql = new DB();
        $dirs = $mysql->find("SELECT * FROM grille_programme as gp INNER JOIN chaine as c ON c.nom_chaine=gp.nom_chaine ORDER BY gp.nom_chaine, gp.annee;");
        foreach ($dirs as $k => $v) {
          ?>
            <option value="<?php echo $v['id']; ?>"><?php echo $v['nom_chaine']; ?> (<?php echo $v['annee'] ?>) diffuse de <?php echo $v['heure_debut']; ?> à <?php echo $v['heure_fin']; ?></option>
          <?php
        }
        ?>
      </select>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="control-group">
    <label class="control-label" for="jour">Jour</label>
    <div class="controls">
      <select name="jour" id="jour">
        <option value="lundi">lundi</option>
        <option value="mardi">mardi</option>
        <option value="mercredi">mercredi</option>
        <option value="jeudi">jeudi</option>
        <option value="vendredi">vendredi</option>
        <option value="samedi">samedi</option>
        <option value="dimanche">dimanche</option>
      </select>
      <span class="help-inline"></span>
    </div>
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
  <div class="control-group">
    <label class="control-label" for="audimat">Ajouter les audimats automatiquement ?</label>
    <div class="controls">
      <input type="hidden" name="audimat" value="0" id="audimat_" data-type="bool" class="">
      <input type="checkbox" name="audimat" value="1" id="audimat" data-type="bool" class="" checked>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
