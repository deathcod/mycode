<meta http-equiv="refresh" content="55" > 
<?php
/*
$url="http://www.moneycontrol.com/india/mutualfunds/mfinfo/09/47/latestnav/CFC_fc/1";
$curl=curl_init();
curl_setopt($curl, CURLOPT_URL,$url);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
$input_lines = curl_exec($curl);
preg_match_all("/<li class=\"fundhd\">Scheme: ([^<]*)<[\s\w<>=\"-\/\/:?@.;]*?class='bl_12'>([^<]*)<\/a><\/p><\/td>[\s]*<td align=\"right\">([^<]*)<\/td>[\s]*<td align=\"right\" class=\"PR5\"><span style=\"color:[^\"]*\">([^<]*)</", $input_lines, $output_array);
print_r($output_array[1]);
curl_close($curl);
//<li class="fundhd">Scheme: ([^<]*)<[\s\w<>=\"-\/\/:?@.;]*?class='bl_12'>([^<]*)</a></p></td>[\s]*<td align="right">([^<]*)</td>[\s]*<td align="right" class="PR5"><span style="color:#d60614">([^<]*)<
*/
require_once('dsp_scrap.php');
error_reporting(E_ALL - E_NOTICE);
ini_set('display_errors', 1);
$mff=array
	(
		//'CEL'=>'Large Cap',
		//'CES'=>'Small & Mid Cap',
		//'CED'=>'Diversified Equity',
		//'CEI'=>'Thematic - Infrastructure',
		//'CEE'=>'ELSS',
		//'CSP'=>'Sector - Pharma & Healthcare',
		//'CSB'=>'Sector - Banking & Finance',
		//'CSF'=>'Sector - FMCG',
		//'CST'=>'Sector - Technology',
		//'CSO'=>'Sector - Others',
		//'CIN'=>'Index',
		//'CRG'=>'RGESS',
		//'CEA'=>'Arbitrage & Arbitrage Plus',
		//'CBA'=>'Balanced',
		//'CDL'=>'Debt Long Term',
		//'CDS'=>'Debt Short Term',
		//'COF'=>'Credit Opportunities Funds',
		//'CFS'=>'Floating Rate Debt - Short Term',
		//'CFL'=>'Floating Rate Debt - Long Term',
		//'CUD'=>'Ultra Short Term Debt',
		//'CGS'=>'Gilt Short Term',
		//'CGL'=>'Gilt Long Term',
		//'CMA'=>'MIP Aggressive',
		//'CMC'=>'MIP Conservative',
		//'CLQ'=>'Liquid',
		//'CEG'=>'International / Global Commodities',
		//'CIG'=>'Gold ETF',
		//'CFE'=>'Fund of Funds - Equity oriented',
		//'CFH'=>'Fund of Funds - Hybrid oriented',
		//'CFD'=>'Fund of Funds - Debt oriented',
		//'CFC'=>'Fund of Funds - Commodity oriented',
		//'CDC'=>'Capital Protection Funds',
		'CDH'=>'Debt Oriented Hybrid Speciality Funds',
		'CEH'=>'Equity Oriented Hybrid Speciality Funds'
	);

function create_url($mff)
{
	$url_array=array();
	foreach ($mff as $key => $value)
		array_push($url_array,"http://www.moneycontrol.com/india/mutualfunds/mfinfo/09/47/latestnav/".$key."_fc/");
	return $url_array;
}
//print_r(create_url($mff));
function create_table_name($mff)
{
	$table_name=array();
	foreach ($mff as $key => $value)
	{
		//echo "create table mutual_funds_family_".$key." (url varchar(500) UNIQUE,store_array  LONGTEXT);<br>";
		//echo "drop table mutual_funds_family_".$key.";<br>";
		array_push($table_name, "mutual_funds_family_".$key);
	}
	return $table_name;
}
create_table_name($mff);
function multiRequest($mff)
{
	$link = mysql_connect("localhost","ffqjqvqmev","GD4RWwtaAV") or die("cannot connect");
    mysql_select_db("ffqjqvqmev", $link);
    $table_name=create_table_name($mff);
 	$url_array=create_url($mff);
	$curly = array();
	$mh = curl_multi_init();
	foreach ($url_array as $id => $d)
	{
		$curly[$id] = curl_init();
		$url = $d."1";
		curl_setopt($curly[$id], CURLOPT_URL,            $url);
		curl_setopt($curly[$id], CURLOPT_HEADER,         0);
		curl_setopt($curly[$id], CURLOPT_RETURNTRANSFER, 1);
		curl_multi_add_handle($mh, $curly[$id]);
	}
	$running = null;
	do {
	curl_multi_exec($mh, $running);
	} while($running > 0);


	// get content and remove handles
	foreach($curly as $id => $c)
	{
		$input_lines = curl_multi_getcontent($c);
		preg_match_all("/<a href=\"([^\"]*)\" class=\"bl_12\" onmouseover/", $input_lines, $output_array);
		$ccurly = array();
		$mmh = curl_multi_init();
		$length=sizeof($output_array[1]);
		echo $length;
		for ($i=0; $i <$length ; $i+=50)
		{ 
			for($j=$i;$j<min($length,$i+50);$j++)
			{
				$ccurly[$j-$i] = curl_init();
				$url = $url_array[$id].$output_array[1][$j];
				print_r($url."<br>");
				curl_setopt($ccurly[$j-$i], CURLOPT_URL,            $url);
				curl_setopt($ccurly[$j-$i], CURLOPT_HEADER,         0);
				curl_setopt($ccurly[$j-$i], CURLOPT_RETURNTRANSFER, 1);
				curl_multi_add_handle($mmh, $ccurly[$j-$i]);
			}

			$rrunning = null;
			do {
			curl_multi_exec($mmh, $rrunning);
			} while($rrunning > 0);
			for($j=$i;$j<min($length,$i+50);$j++)
			{
				$iinput_lines = curl_multi_getcontent($ccurly[$j-$i]);
				$curr_array=serialize(call_all($iinput_lines));
				$curr_url=$url_array[$id].$output_array[1][$j];

				$query="select * from ".$table_name[$id]." where url='".$curr_url."' limit 1";
				echo $query."<br>";
				//$file=fopen("1.txt", a);
				//fwrite($file, $query."\n");
				//fclose($file);
				if(mysql_num_rows(mysql_query($query))==0)
				{
					$query="insert into ".$table_name[$id]." values ('".$curr_url."','".$curr_array."')";
					mysql_query($query);
				}
				curl_multi_remove_handle($mmh, $ccurly[$j-$i]);
			}
			//for ($i=0; $i < 1000000; $i++);
		}
		//break;
		//for ($i=0; $i < 1000000; $i++);
		curl_multi_remove_handle($mh, $c);
		curl_multi_close($mmh);
	}	
	curl_multi_close($mh);
	//return $result;
}
multiRequest($mff);
?>