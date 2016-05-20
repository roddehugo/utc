<?php
require 'classes/session.class.php';
require 'classes/db.class.php';
$session = new Session();

if (!$session->isLogged()){
     header('Location: login.php');
     die();
}

$css_for_layout = 'marketing';
$title_for_layout = 'Election de Miss &amp; Mister NF92';
$script_for_layout='add';
ob_start();
?>

<div class="span12">
  <?php
  require "notif.php";
  ?>
  <h4>Ajouter un candidat</h4>
        <form class="form-horizontal ajaxForm" action="add" method="post">
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
                    <label class="control-label" data-type="note_esp" for="inputNoteEsp">Note espérée</label>
                    <div class="controls">
                            <input type="text" name="data[note_esp]" id="inputNoteEsp" placeholder="Note espérée">
                    </div>
            </div>
            <div class="form-actions">
                <button type="submit" class="btn btn-primary">Ajouter !</button>
                <button type="reset" class="btn">Annuler</button>
            </div>
        </form>
</div>
<?php 
$content_for_layout = ob_get_contents();
ob_clean();
require 'views/layout.phtml';
?>
