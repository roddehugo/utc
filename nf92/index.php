<?php

require 'classes/db.class.php';
require 'classes/session.class.php';

$mysql = new DB();
$session = new Session();

$etudiants = $mysql->find("SELECT * FROM etudiants LEFT JOIN notes ON notes.etu_id = etudiants.id GROUP BY etudiants.id;");

$css_for_layout = 'marketing';
$script_for_layout = 'vote_form';
$title_for_layout = 'Election de Miss &amp; Mister NF92';
ob_start();
?>
 <div class="span12">
          <h4>Candidats A12</h4>
          <p><em>Note les étudiants qui, selon toi, méritent le plus d'être Miss or Mister NF92 !</em></p>
          <form action="vote" method="post" class="ajaxForm">
               <table class="table table-bordered table-hover"> 
                        <thead>
                            <tr>
                                <td>Nom</td>
                                <td>Prénom</td>
                                <td>Age</td>
                                <td>Branche</td>
                                <td>Sexe</td>
                                <td>Note espérée</td>
                                <td>Vote (sur 10)</td>
                            </tr>
                        </thead>
                        <tbody>
                        
        <?php
           foreach ($etudiants as $k => $v) {
        ?>
                <tr>
                        <td><?php echo $v['nom']; ?></td>
                        <td><?php echo $v['prenom']; ?></td>
                        <td><?php echo $v['age']; ?></td>
                        <td><?php echo $v['branche']; ?></td>
                        <td><?php echo $v['sexe']; ?></td>  
                        <td><?php echo $v['note_esp']; ?></td>  
                        <?php // En dessous : créé un tableau $data=array(); avec comme clé : $id_user ?>
                        <td>
                        <label class="inline checkbox">
                                <input type="checkbox" data-type="no_vote" name="data[<?php echo $v['id']; ?>][no_vote]" checked="true"> Je ne souhaite pas voter pour ce candidat !
                        </label> 
                        <select class="inline select input-mini input-select" style="display:none;" data-type="note" name="data[<?php echo $v['id']; ?>][note]" >
                                <?php
                                for ($i = 0; $i <= 10 ; $i++){
                                
                                      echo '<option value="'.$i.'">'.$i.'</option>';
                                }
                                ?>
                        </select>   
                        
                        </td>               
                </tr>
        <?php } ?>
                     </tbody>
               </table>
               <div class="form-actions">
                <?php /*if(isset($_COOKIE['nf92_vote']) && $_COOKIE['nf92_vote'] == true){
                       echo "Vous avez déjà voté, et il n'y a qu'un seul vote par personne. Revenez l'année prochaine !";
                }else{
                       echo '<input type="submit" class="btn btn-large btn-primary" value="Voter !">';
                }*/
                ?>
                <input type="submit" class="btn btn-large btn-primary" value="Voter !">
                <input type="reset" class="btn btn-large" value="Annuler">
                </div>
        </form>
        </div>
<?php 
$content_for_layout = ob_get_contents();
ob_clean();
require 'views/layout.phtml';
?>
