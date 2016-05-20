<?php
require 'classes/session.class.php';
require 'classes/db.class.php';
$session = new Session();

if (!$session->isLogged()){
  header('Location: login.php');
  die();
} 
        
$mysql = new DB();
$etudiants = $mysql->find("SELECT * FROM etudiants;");

foreach ($etudiants as $k => $v) {
  $id = $v['id'];
  $etu_for_script[$id] = $v; 
}

$css_for_layout = 'marketing';
$script_for_layout = 'modify';
$inline_script = 'var etudiants = '.json_encode($etu_for_script);
$title_for_layout = 'Election de Miss &amp; Mister NF92';
ob_start();
?>
<div class="span12">
    <?php
    require "notif.php";
    ?>
 
  <h4>Selectionner un candidat</h4>
  <div class="span6">
    <select id="inputSelMod">
          <option class="muted" value="null">Séléctionner un étudiant</option>
          <?php foreach($etudiants as $k => $v): ?>
                  <option value="<?php echo $v['id']; ?>">
                          <?php echo $v['nom']." ".$v['prenom']; ?>
                  </option>                                
          <?php endforeach; ?>
          
    </select>
  </div>
  <div class="span4">
    <button id="delete" style="display:none;" data-etu="" class="btn btn-danger">Supprimer l'étudiant</button>
  </div>
  <div class="clearfix"></div>
  <div id="formMod" style="display:none;">
    <h4>Modifier le candidat</h4>
 
          <form class="form-horizontal ajaxForm" action="modify" method="post">
          <input type="hidden" name="data[id]" id="inputId">
          <div class="control-group">
                  <label class="control-label" for="inputNom">Nom</label>
                  <div class="controls">
                          <input type="text" data-type="varchar" name="data[nom]" id="inputNom" placeholder="Nom">
                  </div>
          </div>
          <div class="control-group">
                  <label class="control-label" for="inputPrenom">Prénom</label>
                  <div class="controls">
                          <input type="text" data-type="varchar" name="data[prenom]" id="inputPrenom" placeholder="Prénom">
                  </div>
          </div>
          <div class="control-group">
                  <label class="control-label" for="inputAge">Age</label>
                  <div class="controls">
                          <input type="text" data-type="age" name="data[age]" id="inputAge" placeholder="Age">
                  </div>
          </div>
          <div class="control-group">
                  <label class="control-label" for="inputSexe">Sexe</label>
                  <div class="controls">
                          <select id="inputSexe" name="data[sexe]">
                                  <option value="H">Homme</option>
                                  <option value="F">Femme</option>
                           </select>
                  </div>
          </div>
          <div class="control-group">
                  <label class="control-label" for="inputBranche">Branche</label>
                  <div class="controls">
                         <select id="inputBranche" name="data[branche]">
                                  <option value="TC">TC</option>
                                  <option value="GM">GM</option>
                                  <option value="GSM">GSM</option>
                                  <option value="GI">GI</option>
                                  <option value="GP">GP</option>
                                  <option value="GB">GB</option>
                           </select>
                  </div>
          </div>
          <div class="control-group">
                    <label class="control-label" for="inputNoteEsp">Note espérée</label>
                    <div class="controls">
                            <input type="text" data-type="note_esp" name="data[note_esp]" id="inputNoteEsp" placeholder="Note espérée">
                    </div>
          </div>
           <div class="form-actions">
                  <button type="submit" class="btn btn-primary">Modifier !</button>
                  <button type="reset" class="btn">Annuler</button>
           </div>
          </form>
  </div> <!-- FIN FormMod -->
</div>
<?php 
$content_for_layout = ob_get_contents();
ob_clean();
require 'views/layout.phtml';
?>
