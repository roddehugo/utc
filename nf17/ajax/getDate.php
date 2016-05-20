<?php
require '../classes/db.class.php';
require '../classes/session.class.php';
require '../bootstrap.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {

	date_default_timezone_set('Europe/Berlin');
   	echo strftime('%B %Y', $_POST['time']); ?> - Semaine n° <span id="num_semaine"><?php echo strftime('%W', $_POST['time'])+1;
}else{
  header('Location: 404.php');
  die();
}
