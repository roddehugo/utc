<?php 

/**
* DB
*/
class DB{

	public $pdo;
	private $default = array(
		'datasource' => 'Database/Mysql',
		'persistent' => false,
		'host' => 'localhost',
		'login' => '',
		'password' => '',
		'database' => '',
		'prefix' => '',
		'encoding' => 'utf8',
	);
	public $messages = array();
	public $lastId;

	function __construct($default = null){
		if (!isset($default)) {
			$default = $this->default;
		}
		try{
		    $this->pdo = new PDO('mysql:host='.$default['host'].';dbname='.$default['database'], $default['login'], $default['password']);
			$messages['db'] = "DB initialized";
		}catch(Exception $e){
	        print_r('Erreur : '.$e->getMessage().'<br />');
	       	print_r('N° : '.$e->getCode());
	       	die("Erreur dans la construction de DB");
		}
	}

	public function lastInsertId(){
		return $this->lastId;
	}

	public function find($query = "", $array = null){
		if ($query != "") {
			if (!isset($array)) {
				$req = $this->pdo->query($query); 
			}else{
				$req = $this->pdo->prepare($query);
				$req->execute($array);
			}
			$datas = $req->fetchAll(PDO::FETCH_ASSOC);
   			$req->closeCursor();
			$messages['last_query'] = $query;
			return $datas;
		}
		return false;
	}

	public function save($table = "", $array = null){
		if ($table != "" && isset($array)) {
			$query = ($table == "notes") ? "INSERT INTO notes VALUES (" : "INSERT INTO $table VALUES ( null,";
			foreach ($array as $k => $v) {
				$query .= " :".$k.",";
			}
			$query = substr($query, 0, -1);
			$query .= ");";
			$messages['last_query'] = $query;
			$req = $this->pdo->prepare($query);
			$req->execute($array);
			$this->lastId = $this->pdo->lastInsertId();
			return true;
		}
		return false;
	}

	public function update($table, $array = null, $condition = null){
		if ($table != "" && $condition != "" && isset($array)) {
			$query = "UPDATE $table SET";

			foreach ($array as $k => $v) {
				$query .= " $k=:$k,";
			}
			
			$query = substr($query, 0, -1);
			$query .= " WHERE $condition ;";
			$messages['last_query'] = $query;
			$req = $this->pdo->prepare($query);
			$req->execute($array);
			return true;
		}
		return false;
	}

	public function delete($table, $condition){
		if ($table != "" && $condition != "") {
			$query = "DELETE FROM $table WHERE $condition";
			$messages['last_query'] = $query;
			$req = $this->pdo->exec($query);
			return true;
		}
		return false;
	}

	public function genererNumVote(){
		$query = "INSERT INTO genererNumVote VALUES (null);";
		$messages['last_query'] = $query;
		$req = $this->pdo->query($query);
		return $this->pdo->lastInsertId();
	}

	public function getEtu($id){
		if (isset($id) && $id > 0) {
			$query = "SELECT nom, prenom FROM etudiants WHERE etudiants.id = $id LIMIT 1;";
			$req = $this->pdo->query($query);
			$datas = $req->fetchAll(PDO::FETCH_ASSOC);
   			$req->closeCursor();
			$messages['last_query'] = $query;
			return $datas[0];
		}
		return false;
	}

}
