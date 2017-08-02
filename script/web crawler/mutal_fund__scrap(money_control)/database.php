<?php
/*
	Database class using mysqli
	Functions : 
	* database(): constructor initilized for connection
	* query($query) - To query the database
	* indb($table,$field,$value): Function to check whether a value exists in some column of some table
	* get_count($table)-Function to get number of rows
	* get_first($query)-Function to get first row of a query
	* get_first_first($query)-Function to get first row first column.
	* mres($str)- securing sql statement
	* function close()- close database
*/
class database {
	var $host = "localhost";
	var $username = /*username*/;
	var $password = /*password*/;
	var $db = "ffqjqvqmev";
	var $connection;
	function database() {
		$this->connection = mysqli_connect($this->host, $this->username, $this->password);
		if (!$this->connection) {
			die ("Could not connect to the database: <br />". mysqli_error($this->connection));
		}
		$db_select = mysqli_select_db( $this->connection , $this->db );
		if (!$db_select) {
			die ("Could not select the database: <br />". mysqli_error($this->connection));
		}
	}

	function query($query) {
		$result = mysqli_query(  $this->connection , $query);
		if (!$result) {
			die ("Could not query the database: <br /> $query ". mysqli_error($this->connection));
		}
		return $result;
	}

	function indb($table , $field , $value) {
		$results = $this->query("SELECT $field FROM $table WHERE $field = '$value' ");
		if(mysqli_num_rows($results))
			return true;
		else	
			return false;
	}

	function get_count($table) {
		$query = "SELECT count(*) FROM $table";
		$result = $this->query($query);
		$r = mysqli_fetch_array($result);
		return $r[0];
	}

	function get_first($query) {
		#Execute Query
		$result = $this->query($query);
		$r = mysqli_fetch_array($result);
		return $r;
	}

	function get_first_first($query) {
		#Execute Query
		$result = $this->query($query);
		$r = mysqli_fetch_array($result);
		return $r[0];
	}
	function get_array( $query )
	{
		$result = $this->query($query);
		$vals = array();
		
		if(mysqli_num_rows($result) > 0)
		{
			while($r = mysqli_fetch_array($result))
			{
				$vals[] = $r;
			}
		}
		else
		{
			return false;
		}
		
		return $vals;
	}
	function mres($str)
	{
		return mysqli_real_escape_string($this->connection, $str);
	}

	function close() {
		mysqli_close($this->connection);
	}
}
?>