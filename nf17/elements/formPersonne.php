<form class="form-horizontal ajaxForm" data-value="Personne">
  <section class="left">
    <div class="control-group">
      <label class="control-label" for="nom">Nom</label>
      <div class="controls">
        <input class="required" name="nom" data-type="varchar" type="text" id="nom" placeholder="Nom" required>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="prenom">Prénom</label>
      <div class="controls">
        <input class="required" name="prenom" data-type="varchar" type="text" id="prenom" placeholder="Prénom" required>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="nationalite">Nationalité</label>
      <div class="controls">
        <select name="nationalite" id="nationalite">
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
      <label class="control-label" for="telephone">Téléphone</label>
      <div class="controls">
        <input name="telephone" data-type="phone" type="text" id="telephone" placeholder="Téléphone">
        <span class="help-inline"></span>
      </div>
    </div>
  </section>
  <section class="right">
    <div class="control-group">
      <label class="control-label" for="type_personne">Type de personne</label>
      <div class="controls">
        <select name="type_personne" id="type_personne">
              <option value="acteur">Acteur</option>
              <option value="animateur">Animateur</option>
        </select>
        <span class="help-inline"></span>
      </div>
    </div>
    <div class="control-group">
      <label class="control-label" for="type_public">Personne populaire auprès de</label>
      <div class="controls">
        <select name="type_public" id="type_public" multiple="multiple" size="8 ">
          <?php
          require_once '../classes/db.class.php';
          $mysql = new DB();
          $sieges = $mysql->find("SELECT type_public FROM public ORDER BY type_public;");
          foreach ($sieges as $k => $v) {
            ?>
              <option value="<?php echo $v['type_public']; ?>"><?php echo $v['type_public']; ?></option>
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
