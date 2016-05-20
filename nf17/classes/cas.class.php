<?php
require_once("curl.class.php");

class Cas {

    public static function login_url($url){
        return 'https://cas.utc.fr/cas/login?service='.$url.'?action=validate';
    }

    public static function logout_url($url){
        return 'https://cas.utc.fr/cas/logout?url='.$url;
    }

    public static function validate_url($url, $ticket){
        if(isset($ticket)){
            $curl = new CURL();
            $url = 'https://cas.utc.fr/cas/serviceValidate?service='.$url.'?action=validate&ticket='.$ticket;
            return trim($curl->get($url));
        }else {
            throw new NotFoundException('Aucun ticket n\'a été récupéré.');
        }
    }

}
?>
