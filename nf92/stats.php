<?php
require 'classes/session.class.php';
require 'classes/db.class.php';
$session = new Session();

if ($session->isLogged()){
        $mysql = new DB();
        $etudiants = $mysql->find("SELECT AVG(notes.note) as moyenne, SUM(notes.note) as somme, ABS(etudiants.note_esp - SUM(notes.note)) as diff, etudiants.* FROM notes INNER JOIN etudiants ON notes.etu_id = etudiants.id GROUP BY etudiants.id ORDER BY diff ASC;");
        $no_vote = $mysql->find("SELECT * FROM etudiants LEFT JOIN notes ON notes.etu_id = etudiants.id WHERE notes.etu_id is NULL;");
        $nombre = count($etudiants);
        $votes = $mysql->find("SELECT count(*) as votes FROM genererNumVote;");
        $nb_notes = $mysql->find("SELECT count(note) as total, nom, prenom FROM notes INNER JOIN etudiants ON notes.etu_id = etudiants.id GROUP BY etu_id;");
}else{
     header('Location: login.php');
     die();
}

$css_for_layout = 'marketing';
$title_for_layout = 'Election de Miss &amp; Mister NF92';
$script_for_layout = 'stats';
ob_start();
?>

<div class="span12">
 <?php
  require "notif.php";
  ?>
  <h4>Statistiques</h4>
      <div class="alert alert-success">
      Il y a actuellement <strong><?php echo $nombre; ?> candidats</strong> pour les éléctions.
      <br>
       Il y a actuellement <strong><?php echo $votes[0]['votes']; ?> votes</strong> enregistrés .
      </div>
      <center>
        <div id="chart_div" style="margin-left:10%; width:90%; height: 400px;"></div>
      </center>
       <table class="table table-bordered table-hover"> 
        <thead>
            <tr>
                <td>Rang</td>
                <td>Nom</td>
                <td>Prénom</td>
                <td>Age</td>
                <td>Branche</td>
                <td>Sexe</td>
                <td>Note espérée</td>
                <td>Moyenne (/10)</td>
                <td>Total obtenu</td>
                <td>Différence</td>
            </tr>
        </thead>
        <tbody>
                
        <?php
        foreach($etudiants as $k => $v){         // On lit le tableau PHP des étudiants
        ?>
        <tr <?php echo ($k==0) ? 'class="info"' : ""; ?>>
                <td><?php echo $k+1; ?></td>
                <td><?php echo $v['nom']; ?></td>
                <td><?php echo $v['prenom']; ?></td>
                <td><?php echo $v['age']; ?></td>
                <td><?php echo $v['branche']; ?></td>
                <td><?php echo $v['sexe']; ?></td>  
                <td><?php echo $v['note_esp']; ?></td>  
                <td><?php echo round($v['moyenne'],3); ?></td>
                <td><?php echo $v['somme']; ?></td>
                <td><?php echo $v['diff']; ?></td>
        </tr>
        <?php } //endforeach ?>
        </tbody>
      </table>
      <?php if(count($no_vote) > 0 ): ?>

      <center><h5>A la suite, les étudiants qui n'ont pas encore reçu de note.</h5></center>

      <table class="table table-bordered table-hover"> 
         <thead>
            <tr>
                <td>Nom</td>
                <td>Prénom</td>
                <td>Age</td>
                <td>Branche</td>
                <td>Sexe</td>
                <td>Note espérée</td>
            </tr>
        </thead>
        <tbody>
        <?php
        foreach($no_vote as $k => $v){         // On lit le tableau PHP des étudiants
        ?>
        <tr>
                <td><?php echo $v['nom']; ?></td>
                <td><?php echo $v['prenom']; ?></td>
                <td><?php echo $v['age']; ?></td>
                <td><?php echo $v['branche']; ?></td>
                <td><?php echo $v['sexe']; ?></td>  
                <td><?php echo $v['note_esp']; ?></td>  
        </tr>
        <?php } //endforeach ?>   
        </tbody>
      </table> 
    <?php endif; ?>
</div>
<script type="text/javascript" src="https://www.google.com/jsapi"></script>
<script type="text/javascript">
  google.load("visualization", "1", {packages:["corechart"]});
  google.setOnLoadCallback(drawChart);
  function drawChart() {
    var data = google.visualization.arrayToDataTable([
      ['Étudiant', 'Nombre de votes par étudiants'],
      <?php foreach ($nb_notes as $k => $v) {
        echo "['".$v['nom']." ".$v['prenom']."', ".$v['total']."],\n";
      } ?>
    ]);

    var options = {
      title: 'Nombre de votes pour chaque étudiant'
    };

    var chart = new google.visualization.PieChart(document.getElementById('chart_div'));
    chart.draw(data, options);
  }
</script>

<?php 
$content_for_layout = ob_get_contents();
ob_clean();
require 'views/layout.phtml';
?>
