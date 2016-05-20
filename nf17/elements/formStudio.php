<h4>Les données présentes</h4>
<p>
<?php
  require_once '../classes/db.class.php';
  $mysql = new DB();
  $dirs = $mysql->find("SELECT * FROM studio ORDER BY nom_studio;");
  foreach ($dirs as $k => $v) {
    ?>
      <span class="badge badge-info"><?php echo $v['nom_studio']; ?></span>
    <?php
  }
?>
</p>
<br>
<form class="form-horizontal ajaxForm" data-value="Studio">
  <div class="control-group">
    <label class="control-label" for="nom_studio">Nom du Studio</label>
    <div class="controls">
      <input class="required" name="nom_studio" data-type="varchar" type="text" id="nom_studio" placeholder="Nom" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
