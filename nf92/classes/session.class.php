<?php 
class Session {
 
    function __construct() {
        session_start();
    }
 
    public function read($key) {
        return isset($_SESSION[$key]) ? $_SESSION[$key] : false;
    }
 
    public function write($key, $value) {
        $_SESSION[$key] = $value;
    }

    public function del($key) {
        $_SESSION[$key] = null;
    }
 
    public function login($login,$pass) {
        $_SESSION['authentication_ip'] = $_SERVER['REMOTE_ADDR'];
        $_SESSION['login'] = $login;
        $_SESSION['pass'] = md5($pass);
    }
 
    public function logout() {
        $_SESSION = array();
        session_unset();
        session_destroy();
    }

    public function flush(){
        $_SESSION = array();
    }
 
    public function isLogged() {
        return isset($_SESSION['authentication_ip']) && $_SESSION['authentication_ip'] == $_SERVER['REMOTE_ADDR'];
    }

    public function setNotif($msg = "", $type = "success"){
		if ($msg != "") {
			$_SESSION['message'] = array('notifs' => array('msg' => $msg, 'type' => $type));
		}
	}
    public function emptyNotif(){
        $_SESSION['message'] = array();
    }
}
