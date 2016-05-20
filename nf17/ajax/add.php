<?php

require '../classes/db.class.php';
require '../classes/session.class.php';
$session = new Session();

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
  //On est bien dans une requete en AJAX
  /*Exemple
  $mysql = new DB();
  if($result = $mysql->find("SELECT DISTINCT profil FROM form_profils;",null,false)){
  	echo json_encode($result);
  }else{
  	echo json_encode(array('error' => $mysql->lastQuery()));
  }
  */



}else{
  header('Location: 404.php');
  die();
}
