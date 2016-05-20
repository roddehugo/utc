<h4>Les données présentes</h4>
<p>
<?php
  require_once '../classes/db.class.php';
  $mysql = new DB();
  $dirs = $mysql->find("SELECT * FROM public ORDER BY type_public;");
  foreach ($dirs as $k => $v) {
    ?>
      <span class="badge badge-info"><?php echo $v['type_public']; ?></span>
    <?php
  }
?>
</p>
<br>
<form class="form-horizontal ajaxForm" data-value="Public">
  <div class="control-group">
    <label class="control-label" for="type_public">Type de public visé</label>
    <div class="controls">
      <input class="required" name="type_public" data-type="varchar" type="text" id="type_public" placeholder="Nom" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
