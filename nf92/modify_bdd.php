<?php
require 'classes/session.class.php';
require 'classes/db.class.php';
$session = new Session();

if ($session->isLogged()){
        if(isset($_POST['data'])){
              $data = $_POST['data'];
              $erreur = false;
              foreach($data as $k => $v){
                  $data[$k] = htmlspecialchars($v);
                  switch ($k) {
                    case 'nom':
                      $erreur = ($v == "") ? true : false;
                    case 'prenom':
                      $erreur = ($v == "") ? true : false;
                    case 'age':
                      $erreur = ($v < 7 || $v > 77) ? true : false;
                      break;
                    case 'note_esp':
                      $erreur = ($v < 0 || $v > 500) ? true : false;
                      break;
                  }
              }

              if($erreur){
                  $retour = array('message' => "Une erreur est parvenue. Veuillez vérifier les champs. Merci.", 'type' => 'error');
              }else{
                  $mysql = new DB();
                  $mysql->update('etudiants', array(
                          'nom' => $data['nom'], 
                          'prenom' => $data['prenom'], 
                          'age' => $data['age'], 
                          'sexe' => $data['sexe'], 
                          'branche' => $data['branche'],
                          'note_esp' => $data['note_esp']
                      ),
                      "etudiants.id = ".$data['id']);
                  $retour = array('message' => "Etudiant modifié avec succès", 'type' => 'success');
              }
              echo json_encode($retour);
        }
}else{
  header('Location: login.php');
  die();
} 
