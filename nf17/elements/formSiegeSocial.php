<form class="form-horizontal ajaxForm" data-value="SiegeSocial">
  <div class="control-group">
    <label class="control-label" for="rue">Rue</label>
    <div class="controls">
      <input class="required" name="rue" data-type="varchar" type="text" id="rue" placeholder="39 bis, rue Notre Dame" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="control-group">
    <label class="control-label" for="ville">Ville</label>
    <div class="controls">
      <input class="required typeahead" name="ville" data-type="varchar" type="text" id="ville" placeholder="Compiègne" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="control-group">
    <label class="control-label" for="code_postal">Code Postal</label>
    <div class="controls">
      <input class="required" name="code_postal" data-type="integer" type="number" id="code_postal" placeholder="60200" required>
      <span class="help-inline"></span>
    </div>
  </div>
  <div class="form-actions">
    <button type="submit" class="ajaxSubmit btn btn-primary">Ajouter</button>
    <button type="reset" class="btn">Remettre à zéro</button>
  </div>
</form>
