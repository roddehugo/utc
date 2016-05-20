<form class="form-horizontal ajaxForm" data-value="Directeur">
  <div class="control-group">
    <label class="control-label" for="nom">Nom</label>
    <div class="controls">
      <input class="required" name="nom" data-type="varchar" type="text" id="nom" placeholder="Nom" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="control-group">
    <label class="control-label" for="dateEmbauche">Date d'embauche</label>
    <div class="controls">
      <input class="required" name="date" data-type="date" type="date" id="dateEmbauche" placeholder="DD/MM/YYYY" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
