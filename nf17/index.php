<?php

require 'classes/db.class.php';
require 'classes/session.class.php';
require 'bootstrap.php';

$db = new DB();
$session = new Session();

$title_for_layout = 'Administration des chaines';
ob_start();

//Select

$chaines = $db->find("SELECT nom_chaine FROM chaine ORDER BY nom_chaine;");
?>

	<div class="row-fluid">
		<div class="page-header">
			<h2>
				Vue tabulaire
			</h2>
		</div>
		<form class="form-inline" id="chaineForm">
			<label for="grille_id">Chaine : </label>
			<select name="grille_id" id="grille_id">
					<option value="null">Choisir une chaine</option>
				<?php foreach ($chaines as $k => $v): ?>
	    			<option value="<?php echo $v['nom_chaine']; ?>"><?php echo $v['nom_chaine']; ?></option>
				<?php endforeach ?>
			</select>
		</form>
	</div>

<div class="row-fluid">
    <div class="span3" id="sidebar">

    </div>
    <div class="span9" id="main-content">
    	<!--Body content-->
			<?php
			date_default_timezone_set('Europe/Berlin');
			$time = mktime(0,0,0,1,1,2013);
			?>
			<div id="semaine">
				<span class="left span2"><a class="badge badge-info prev" href="#">&lt;&lt;</a></span>
				<span class="middle span8 text-center" id="semaine-text"><?php echo strftime('%B %Y', $time); ?> - Semaine n° <span id="num_semaine"><?php echo strftime('%W', $time)+1; ?></span></span>
				<span class="right span2"><a class="badge badge-info pull-right next" href="#">&gt;&gt;</a></span>
			</div>
			<div class="clearfix"></div>
			<table class="table table-bordered table-condensed" id="grille">
				<thead>
					<tr id="jours">
						<th>Heure</th>
						<th>Lundi</th>
						<th>Mardi</th>
						<th>Mercredi</th>
						<th>Jeudi</th>
						<th>Vendredi</th>
						<th>Samedi</th>
						<th>Dimanche</th>
					</tr>
				</thead>
				<tbody>
					<?php for($i = 0; $i < 24*4; $i++): ?>
						<tr>
							<?php if ($i%4==0): ?>
								<?php $j = 0; ?>
								<td style="vertical-align:middle;" rowspan="4" class="heure"><?php echo date("H:i",strtotime("+".($i/4)." hour",$time)); ?></td>
							<?php endif ?>
							<td class="jour lundi h-<?php echo intval(date("H",strtotime("+".floor($i/4)." hour ",$time)))."-".intval(date('i',strtotime("+ ".$j." minutes",$time))); ?>"></td>
							<td class="jour mardi h-<?php echo intval(date("H",strtotime("+".floor($i/4)." hour ",$time)))."-".intval(date('i',strtotime("+ ".$j." minutes",$time))); ?>"></td>
							<td class="jour mercredi h-<?php echo intval(date("H",strtotime("+".floor($i/4)." hour ",$time)))."-".intval(date('i',strtotime("+ ".$j." minutes",$time))); ?>"></td>
							<td class="jour jeudi h-<?php echo intval(date("H",strtotime("+".floor($i/4)." hour ",$time)))."-".intval(date('i',strtotime("+ ".$j." minutes",$time))); ?>"></td>
							<td class="jour vendredi h-<?php echo intval(date("H",strtotime("+".floor($i/4)." hour ",$time)))."-".intval(date('i',strtotime("+ ".$j." minutes",$time))); ?>"></td>
							<td class="jour samedi h-<?php echo intval(date("H",strtotime("+".floor($i/4)." hour ",$time)))."-".intval(date('i',strtotime("+ ".$j." minutes",$time))); ?>"></td>
							<td class="jour dimanche h-<?php echo intval(date("H",strtotime("+".floor($i/4)." hour ",$time)))."-".intval(date('i',strtotime("+ ".$j." minutes",$time))); ?>"></td>
							<?php $j+=15; ?>
						</tr>
					<?php endfor; ?>
				</tbody>
			</table>
    </div>
  </div>

<script>
	var chaines = <?php echo json_encode($chaines); ?>;
	var time = <?php echo $time; ?>;
</script>

<?php
$content_for_layout = ob_get_contents();
ob_clean();
require 'views/layout.phtml';
?>
