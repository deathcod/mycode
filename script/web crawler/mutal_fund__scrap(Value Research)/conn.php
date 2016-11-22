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
error_reporting(E_ALL - E_NOTICE);
ini_set('display_errors', 1);
require_once('dsp_scrap.php');
require_once('database.php');
$mff=array
	(
		'CEL'=>'Large Cap',
		'CES'=>'Small & Mid Cap',
		'CED'=>'Diversified Equity',
		'CEI'=>'Thematic - Infrastructure',
		'CEE'=>'ELSS',
		'CSP'=>'Sector - Pharma & Healthcare',
		'CSB'=>'Sector - Banking & Finance',
		'CSF'=>'Sector - FMCG',
		'CST'=>'Sector - Technology',
		'CSO'=>'Sector - Others',
		'CIN'=>'Index',
		'CRG'=>'RGESS',
		'CEA'=>'Arbitrage & Arbitrage Plus',
		'CBA'=>'Balanced',
		'CDL'=>'Debt Long Term',
		'CDS'=>'Debt Short Term',
		'COF'=>'Credit Opportunities Funds',
		'CFS'=>'Floating Rate Debt - Short Term',
		'CFL'=>'Floating Rate Debt - Long Term',
		'CUD'=>'Ultra Short Term Debt',
		'CGS'=>'Gilt Short Term',
		'CGL'=>'Gilt Long Term',
		'CMA'=>'MIP Aggressive',
		'CMC'=>'MIP Conservative',
		'CLQ'=>'Liquid',
		'CEG'=>'International / Global Commodities',
		'CIG'=>'Gold ETF',
		'CFE'=>'Fund of Funds - Equity oriented',
		'CFH'=>'Fund of Funds - Hybrid oriented',
		'CFD'=>'Fund of Funds - Debt oriented',
		'CFC'=>'Fund of Funds - Commodity oriented',
		'CDC'=>'Capital Protection Funds',
		'CDH'=>'Debt Oriented Hybrid Speciality Funds',
		'CEH'=>'Equity Oriented Hybrid Speciality Funds'
	);

function check($x)
{
	if(preg_match("/[A-Za-z]/",$x))
		$x=-9999.9;
	if($x=='-')
		$x=-9999.9;
	$x=	str_replace(",","",$x);
	return $x;
}
function create_table_name($mff)
{
	$table_name=array();
	foreach ($mff as $key => $value)
		array_push($table_name, "mutual_funds_family_".$key);
	return $table_name;
}
function nn($mff)
{
    $table_name=create_table_name($mff);
    $db=new database();
    $ww=0;
    for ($i=0; $i < 34; $i++)
    {
    	$x=$db->get_array("select * from ".$table_name[$i]);
	   	mutual_fund($ww,$x,$db,$table_name[$i]);
	   	returns_new($ww,$x,$db,$table_name[$i]);
	   	absolute_returns($ww,$x,$db,$table_name[$i]);
	   	Investment_Info_new($ww,$x,$db,$table_name[$i]);
	   	portfolio_new($ww,$x,$db,$table_name[$i]);
	   	$ww+=sizeof($x);
    }
}
function mutual_fund($ww,$x,$db,$table_name)
{
	$length=sizeof($x);
	for ($i=0; $i < $length; $i++)
	{
		$z=unserialize($x[$i][1]);
		$y="insert into mutual_fund values(".(string)($i+$ww).",'".$z[0]."','".$z["FUND FAMILY"]."','".$z["FUND CLASS"]."','".str_replace("mutual_funds_family_","",$table_name)."')";
		//print_r($y."<br>");
		$db->query($y);
	}
}
function returns_new($ww,$x,$db,$table_name)
{
	$length=sizeof($x);
	print_r($table_size);
	for ($i=0; $i < $length; $i++)
	{
		$z=unserialize($x[$i][1]);
		foreach ($z["Returns"] as $value)
		{
			$y="insert into returns values(".(string)($i+$ww).",'".strtolower($value[0])."',".check($value[1]).",".check($value[2]).")";
			//print_r($y.";<br>");
			$db->query($y);
		}
	}
}
function absolute_returns($ww,$x,$db,$table_name)
{
	$length=sizeof($x);
	for ($i=0; $i < $length; $i++)
	{
		$z=unserialize($x[$i][1]);
		foreach ($z["Absolue Returns"] as $value)
		{
			$y="insert into absolute_returns values(".(string)($i+$ww);
			foreach ($value as $v)
				$y=$y.",".check($v);
			$y=$y.")";
			//print_r($y.";<br>");
			$db->query($y);
		}
	}
}
function Investment_Info_new($ww,$x,$db,$table_name)
{
	$length=sizeof($x);
	for ($i=0; $i < $length; $i++)
	{
		$z=unserialize($x[$i][1]);

		$y="insert into scheme_details values(";
		$value=$z["Investment Info"][0][1];
		$y=$y.(string)($i+$ww).",'".strtolower($value[0][1])."','".strtolower($value[1][1])."','";
		$y=$y.date("Y-m-d",strtotime($value[2][1]))."','";
		$y=$y.$value[3][1]."',";

		$val=preg_replace("/[()]/","",$value[4][1]);
		$val=split(" ",$val);
		$y=$y.check($val[0]).",'";
		$y=$y.date("Y-m-d",strtotime($val[1]))."',";

		$y=$y.check(str_replace("Rs.","",$value[5][1])).",'".strtolower($value[6][1])."','".$value[7][1]."','".strtolower($value[8][1])."','".strtolower($value[9][1])."');";		
		print_r($y."<br>");
		$db->query($y);
		//break;
		//--------------------------------------------------------
		$value=$z["Investment Info"][1][1];
		$y="insert into load_details values(";
		$y=$y.(string)($i+$ww).",'";
		$y=$y.$value[0][1]."',".check(str_replace("%","",$value[1][1])).",'".strtolower($value[2][1])."')";
		print_r($y.";<br>");
		$db->query($y);
	}
}
function portfolio_new($ww,$x,$db,$table_name)
{
	$length=sizeof($x);
	for ($i=0; $i < $length; $i++)
	{
		$z=unserialize($x[$i][1]);
		foreach ($z["Portfolio"][0][1] as $value)
		{
			$y="insert into top_holdings values(".(string)($i+$ww).",'".$value[0]."','".$value[1]."',".check($value[2]).",".check($value[3]).")";
			print_r($y.";<br>");
			$db->query($y);
		}
		foreach ($z["Portfolio"][1][1] as $value)
		{
			$y="insert into sector_allocation values(".(string)($i+$ww).",'".$value[0]."',".check($value[1]).",".check($value[2]).",".check($value[3]).")";
			print_r($y.";<br>");
			$db->query($y);
		}
		foreach ($z["Portfolio"][2][1] as $value)
		{
			$y="insert into asset_allocation values(".(string)($i+$ww).",'".$value[0]."',".check($value[1]).")";
			print_r($y.";<br>");
			$db->query($y);
		}
		$value=$z["Portfolio"][3][1];
		$y="insert into concentration(id,Top_3,Top_5,Top_10) values(".(string)($i+$ww).",".check($value[0]).",".check($value[1]).",".check($value[2]).")";
		print_r($y."<br>");
		$db->query($y);
	}
}
nn($mff);
?>