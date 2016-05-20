<h4>Les données présentes</h4>
<p>
<?php
  require_once '../classes/db.class.php';
  $mysql = new DB();
  $dirs = $mysql->find("SELECT nom_theme FROM theme WHERE type_theme = 'documentaire' ORDER BY nom_theme;");
  foreach ($dirs as $k => $v) {
    ?>
      <span class="badge badge-info"><?php echo $v['nom_theme']; ?></span>
    <?php
  }
?>
</p>
<br>
<form class="form-horizontal ajaxForm" data-value="Theme">
  <div class="control-group">
    <label class="control-label" for="nom_theme">Thème de documentaire</label>
    <div class="controls">
      <input class="required" name="nom_theme" data-type="varchar" type="text" id="nom_theme" placeholder="Nom" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <input type="hidden" value="documentaire" name="type_theme">
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
