<?php function is_active($page){
	$filename = basename($_SERVER ['SCRIPT_NAME']);
	return $page == $filename;
} ?>

<ul class="nav nav-pills">
  <li <?php echo is_active("index.php") ? 'class="active"': ""; ?>><a href="index.php">Accueil</a></li>
  <li <?php echo is_active("add.php") ? 'class="active"': ""; ?>><a href="add.php">Ajouter un étudiant</a></li>
  <li <?php echo is_active("modify.php") ? 'class="active"': ""; ?>><a href="modify.php">Modifier un étudiant</a></li>
  <li <?php echo is_active("stats.php") ? 'class="active"': ""; ?>><a href="stats.php">Statistiques</a></li>
  <li <?php echo is_active("logout.php") ? 'class="active"': ""; ?>><a href="logout.php">Se déconnecter</a></li>
</ul>
