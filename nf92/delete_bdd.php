<?php

require 'classes/db.class.php';
require 'classes/session.class.php';

$mysql = new DB();
$session = new Session();

if(isset($_POST['id'])){
    $id = $_POST['id'];
    if($mysql->delete('etudiants',"id=$id")){
        $retour = array('message' => "Étudiant supprimé avec succès", 'type' => 'success');
    }else{
        $retour = array('message' => "Une erreur est survenue lors de la suppression de l'étudiant. Aucune ligne supprimée.", 'type' => 'error');
    }
    echo json_encode($retour);
}
