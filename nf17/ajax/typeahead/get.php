<?php
require_once "../../classes/db.class.php";

if(!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {

  //On est bien dans une requete en AJAX
  if (isset($_GET['value'])) {
    $db = new DB();
    if(isset($_GET['value']) && $_GET['value']=="ville"){
      $result = $db->find("SELECT DISTINCT nom,cp FROM maps_ville;",null,false);
      if(isset($result)){
        echo json_encode($result);
      }else{
        echo json_encode(array('error' => $db->lastQuery()));
      }
    }
  }

}else{
  header('Location: 404.php');
  die();
}

?>