<?php

require 'classes/db.class.php';
require 'classes/session.class.php';

$mysql = new DB();
$session = new Session();

if (!$session->isLogged()){
  header('Location: login.php');
  die();
} 

if (isset($_GET['id']) && $_GET['id'] > 0) {
    $id = htmlspecialchars($_GET['id']);
    $etudiants = $mysql->find("SELECT * FROM etudiants WHERE id = $id;");

    echo json_encode($etudiants[0]);
}
