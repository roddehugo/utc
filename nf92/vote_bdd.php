<?php

require 'classes/db.class.php';
require 'classes/session.class.php';

$mysql = new DB();
$session = new Session();

if(isset($_POST['data'])){
        $data = $_POST['data'];
        $erreur = false;
        $vote_id = $mysql->genererNumVote();
        foreach($data as $etu_id => $v){
                $note = htmlspecialchars($v['note']);
                $no_vote = (isset($v['no_vote']) && $v['no_vote'] == "on") ? true : false;
                if(!$no_vote){
                    if($note < 0 || $note > 10){
                        $retour = array('message' => "La note doit être comprise entre 0 et 10 !", 'type' => 'error');
                    }else{
                        $mysql->save('notes', array('idvote' => $vote_id, 'etu_id' => $etu_id, 'note' => $note)); // Appelle de la fonction pour enregistrer les données
                        $retour = array('message' => "Le vote a été pris en compte. Merci, revenez demain pour pouvoir voter à nouveau.", 'type' => 'success');
                        setcookie('nf92_vote', true, (time() + 365*24*3600));
                    }
                }
        }
        echo json_encode($retour);
}
