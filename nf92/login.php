<?php
	require 'classes/session.class.php';
	require 'classes/db.class.php';

	$session = new Session();

	if ($session->isLogged()){
	  $session->setNotif("Vous vous êtes connecté avec succès !");
		header('Location: stats.php');
	}else{
	$session->del('login');
	$session->del('password');
	}
	
	if(isset($_POST['data'])){
		// Si il y a des données envoyées par post
		$login = (isset($_POST['data']['login'])) ? $_POST['data']['login'] : '';
		$pass  = (isset($_POST['data']['pass']))  ? $_POST['data']['pass']  : '';

		if (($login == "admin") && ($pass == "nf92")){
		  $session->login($login, $pass);
			$session->setNotif("Vous vous êtes connecté avec succès !");
			header('Location: stats.php');
		}else{
			$session->setNotif("Vous avez du faire une erreur .. !",'error');
		}
	}

$css_for_layout = 'login';
$title_for_layout = 'Election de Miss &amp; Mister NF92';
require "views/login.phtml";
?>
