<?php

require 'classes/db.class.php';
require 'classes/session.class.php';
require 'bootstrap.php';

$db = new DB();
$session = new Session();

$title_for_layout = 'Statistiques';
ob_start();

//Select

$chaines = $db->find("SELECT nom_chaine FROM chaine ORDER BY nom_chaine;");
?>
<script type="text/javascript" src="https://www.google.com/jsapi"></script>
    <script type="text/javascript">
    
      // Load the Visualization API and the piechart package.
      google.load('visualization', '1.0', {'packages':['corechart']});
      
      // Set a callback to run when the Google Visualization API is loaded.
      google.setOnLoadCallback(drawChart);

      // Callback that creates and populates a data table, 
      // instantiates the pie chart, passes in the data and
      // draws it.
      function drawChart() {

        // Create the data table.
          var data = new google.visualization.DataTable();
          // Add columns
          data.addColumn('number', 'Semaine');
          data.addColumn('number', 'La Samulienne');
          data.addColumn('number', 'Solide TV');
          data.addColumn('number', 'Terminal TV Show');
          data.addColumn('number', 'Texas TV');
          data.addRows(53);
         
         <?php $dirs = $db->find("SELECT semaine,sum(nb_spectateur) as sum FROM audimat as a JOIN creneau as c ON c.id=a.creneau_id 
  JOIN grille_programme as gp ON gp.id=c.grille_id WHERE gp.nom_chaine='La Samulienne' GROUP BY semaine ORDER BY semaine asc;");?>
          <?php foreach ($dirs as $k => $v): 
         

          echo "data.setCell( " ; echo $k; echo" , 0, "; echo " {$v['semaine']} ); ";  
          echo "data.setCell( ";  echo $k; echo" , 1,  "; echo" {$v['sum']});";
          endforeach ; ?>
          // pour la 2er chaine
         <?php $dirs = $db->find("SELECT semaine,sum(nb_spectateur) as sum FROM audimat as a JOIN creneau as c ON c.id=a.creneau_id 
  JOIN grille_programme as gp ON gp.id=c.grille_id WHERE gp.nom_chaine='Solide TV' GROUP BY semaine ORDER BY semaine asc;");?>
          <?php foreach ($dirs as $k => $v): 
          
          echo "data.setCell( ";  echo $k; echo" , 2,  "; echo" {$v['sum']});";
          endforeach ; ?>
          // pour la 3er chaine
         <?php $dirs = $db->find("SELECT semaine,sum(nb_spectateur) as sum FROM audimat as a JOIN creneau as c ON c.id=a.creneau_id 
  JOIN grille_programme as gp ON gp.id=c.grille_id WHERE gp.nom_chaine='Terminal TV Show' GROUP BY semaine ORDER BY semaine asc;");?>
          <?php foreach ($dirs as $k => $v): 
          
          echo "data.setCell( ";  echo $k; echo" , 3,  "; echo" {$v['sum']});";
          endforeach ; ?>
          // pour la 4er chaine
         <?php $dirs = $db->find("SELECT semaine,sum(nb_spectateur) as sum FROM audimat as a JOIN creneau as c ON c.id=a.creneau_id 
  JOIN grille_programme as gp ON gp.id=c.grille_id WHERE gp.nom_chaine='Texas TV' GROUP BY semaine ORDER BY semaine asc;");?>
          <?php foreach ($dirs as $k => $v): 
          

          echo "data.setCell( ";  echo $k; echo" , 4,  "; echo" {$v['sum']});";
          endforeach ; ?>

        // Set chart options
        var options = {'title':'Audiences pour les chaines',
                       'width':922,
                       'height':500};

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('chart_div'));
        chart.draw(data, options);
      }

      google.setOnLoadCallback(drawPie);
      function drawPie() {
            var data = google.visualization.arrayToDataTable([
              ['Public Visé', 'Nombre'],
          <?php $dirs = $db->find("SELECT type_public,count(type_public) as sum FROM vise GROUP BY type_public ORDER BY sum asc;");?>
          
          <?php $str = "";
          foreach ($dirs as $k => $v): 
          $str .= "['".html_entity_decode($v['type_public'],ENT_QUOTES, "UTF-8")."',  {$v['sum']}],";
          endforeach ; 

          $str = substr($str, 0, -1);
          echo $str;
          ?>

            ]);

            var options = {
              title: 'Part de public visé'
            };

            var pie = new google.visualization.PieChart(document.getElementById('pie_div'));
            pie.draw(data, options);
      }

      google.setOnLoadCallback(drawPie2);
      function drawPie2() {
            var data = google.visualization.arrayToDataTable([
              ['Type d\'emission', 'Nombre'],
          <?php $dirs = array(); $dirs['Films'] = $db->find("SELECT count(*) as sum FROM film;");?>
          <?php $dirs['Journaux'] = $db->find("SELECT count(*) as sum FROM journal;");?>
          <?php $dirs['Séries'] = $db->find("SELECT count(*) as sum FROM serie;");?>
          <?php $dirs['Documentaires'] = $db->find("SELECT count(*) as sum FROM documentaire;");?>
          
          <?php $str2 = "";
          foreach ($dirs as $k => $v): 
          $str2 .= "['$k',  {$v[0]['sum']}],";
          endforeach ; 

          $str2 = substr($str2, 0, -1);
          echo $str2;
          ?>

            ]);

            var options = {
              title: 'Type d\'emission'
            };

            var pie2 = new google.visualization.PieChart(document.getElementById('pie2_div'));
            pie2.draw(data, options);
      }
      google.setOnLoadCallback(drawChart2);
      function drawChart2() {
        var data = new google.visualization.DataTable();
          // Add columns
          data.addColumn('string', 'Nom du film');
          data.addColumn('number', 'Telespectateurs');
          data.addRows(3);
         
         <?php $dirs = $db->find("SELECT fc.film as fcf,a.nb_spectateur as anb FROM film_creneau as fc ,audimat  as a WHERE fc.creneau=a.creneau_id AND fc.semaine=a.semaine ORDER BY a.nb_spectateur desc LIMIT 3;");?>
          <?php foreach ($dirs as $k => $v): 
         

          echo "data.setCell( " ; echo $k; echo" , 0, "; echo " '{$v['fcf']}' ); ";  
          echo "data.setCell( ";  echo $k; echo" , 1,  "; echo" {$v['anb']});";
          endforeach ; ?>

        var options = {
          title: 'TOP 3 des films',
          vAxis: {title: 'Nombre de vues',  titleTextStyle: {color: 'red'}}
        };

        var chart2 = new google.visualization.BarChart(document.getElementById('chart2_div'));
        chart2.draw(data, options);
      }
    </script>

	<div class="row-fluid">
		<div class="page-header">
			<h2>Statistiques</h2>
		</div>
	</div>

  <div class="row-fluid">
    <div class="span3" id="sidebar">
    <!-- <form class="form-inline" method=post action="statistiques.php" id="chaineForm">
      <label for="chaine_id">Chaine : </label>
      <select name="chaine_id" id="chaine_id">
          <option value="null">Choisir</option>
        <?php foreach ($chaines as $k => $v): ?>
            <option value="<?php echo $v['nom_chaine']; ?>"><?php echo $v['nom_chaine']; ?></option>
        <?php endforeach ?>
      </select>
        <button type="submit" class="btn-primary">Choisir</button>
    </form> -->
    </div>
    <div class="span9" id="main-content">
      <div id="chart_div"  style="width: 100%; height: 500px;"></div>
      <div id="pie_div"  style="width: 100%; height: 500px;"></div>
    	<div id="pie2_div"  style="width: 100%; height: 500px;"></div>
      <div id="chart2_div"  style="width: 100%; height: 500px;"></div>

    </div>
  </div>
  <?php 
  if(isset($_POST['chaine_id'])){
    $chaine= clean($_POST['chaine_id']);
    $dirs = $db->find("SELECT semaine,sum(nb_spectateur) as sum FROM audimat as a JOIN creneau as c ON c.id=a.creneau_id 
  JOIN grille_programme as gp ON gp.id=c.grille_id WHERE gp.nom_chaine='$chaine' GROUP BY semaine ORDER BY semaine asc;");
  ?>
   

  <?php
  }
      
  ?>

<?php 
$content_for_layout = ob_get_contents();
ob_clean();
require 'views/layout.phtml';
?>
