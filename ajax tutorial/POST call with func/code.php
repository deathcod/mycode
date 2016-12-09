<?php

if(isset($_POST["fname"]) || isset($_POST["lname"]))
{
	echo "name is : ".$_POST["fname"].$_POST["lname"];
}

?>