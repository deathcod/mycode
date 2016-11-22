<?php
error_reporting(E_ALL - E_NOTICE);
ini_set('display_errors', 1);
function executor($url)
{
	$curl=curl_init();
	curl_setopt($curl, CURLOPT_URL,$url);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
	$input_lines = curl_exec($curl);
	return $input_lines;
}
function info($input_lines)
{
	preg_match_all("/(?|<span class=\"(fundname)_rating_sep\">([^<]*)?<\/span>| (Growth):[\s]*<span style=\"font-family:rupee; font-size:14px;[\s]*padding:0;line-height:12px;\">R<\/span> ([\d,.]*)|(Dividend):[\s]*<span style=\"font-family:rupee; font-size:14px;[\s]*padding:0;line-height:12px;\">R<\/span> ([\d,.]*)|(Category):[\s\w<>=\"-:?@.;]*?<a href=\"[^\"]*?\">([^<]*)?<\/a>|(Assets):[\s\w<>=\"-:?@.;]*?<\/span>([^<]*)?<\/td>|(Expense):<\/td>[\s]*?<td>([^<]*)?<\/td>)/", $input_lines, $output_array);
	//return $output_array[1];
	$d=array();
	foreach ($output_array[2] as $id=> $value)
		$d[$output_array[1][$id]]=preg_replace("/[\s]+/"," ",$value);
	return $d;
}
function details($input_lines)
{
	preg_match_all("/(?|(Benchmark):[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Type):[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Launch Date):[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Tenure )[\s\w<>=\"-:?@.;()]*?<td [^>]*?>([^<]*)?<|(Riskometer)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Risk Grade)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Return Grade)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Turnover)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Minimum Investment )[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Minimum Addl Investment)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Minimum SIP Investment)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Minimum Withdrawal)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Minimum Balance)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Exit Load)[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Return since Launch):[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<|(Maturity Date):[\s\w<>=\"-:?@.;]*?<td [^>]*?>([^<]*)?<)/", $input_lines, $output_array);
	$d=array();
	foreach ($output_array[2] as $id => $value)
		$d[$output_array[1][$id]]=preg_replace("/[\s]{2,}/"," ",$value);
	return $d;
}

function peer_comparision($input_lines)
{
	preg_match_all("/<table id=\"fund-snapshot-peer-comparison-table\">[\s\w<>=\"-:?@.;()%]*?<\/table>/", $input_lines, $output_array);
	preg_match_all("/<tr>[\s\w<>=\"-:?@.;()%]*?<\/tr>/", $output_array[0][0], $output_array);
	$d=array();
	foreach ($output_array[0] as $value)
	{
		preg_match_all("/<td(?:>| class)[\s\w<>=\"-:?@.;()%]*?<\/td>/", $value, $out);
		$a=array();
		foreach ($out as $val)
			array_push($a,preg_replace("/(?|<[^>]*?>|[\s]{2,})/","",$val));
		array_push($d,$a[0]);
	}
	return array_slice($d,1);
}
function portfolio($input_lines)
{
	preg_match_all("/<table id=\"fund-snapshot-portfolio-agg\"[\s\w<>=\"-:?@.;()%]*?<\/table>/", $input_lines, $output_array);
	preg_match_all("/<tr>[\s\w<>=\"-:?@.;()%]*?<\/tr>/", $output_array[0][0], $output_array);
	$d=array();
	foreach ($output_array[0] as $value)
	{
		preg_match_all("/<td(?:>| class)[\s\w<>=\"-:?@.;()%]*?<\/td>/", $value, $out);
		$a=array();
		foreach ($out as $val)
			array_push($a,preg_replace("/(?|<[^>]*?>|[\s]{2,})/","",$val));
		array_push($d,$a);
	}
	return array_slice($d,2);
}

function dividend($input_lines)
{
	preg_match_all("/(?|Dividend<\/a>[\s]*?<\/td>[\s]*?<td class=\"\">([^>]*?)<\/td>[\s]*?<td class=\"align_right\">([^>]*)?<\/td>|<td width=\"80px\">([^>]*)<\/td>[\s]*?<td width=\"80px\" class=\"align_right\">([^>]*)<\/td>)/", $input_lines, $output_array);
	return array_slice($output_array, 1);
}

function performance($input_lines)
{
	preg_match_all("/<a href=\"([^\"]*)?\">Performance<\/a>/", $input_lines, $output_array);
	$url="https://www.valueresearchonline.com".$output_array[1][0];
	$input_lines=executor($url);
	$input_lines=str_replace("'", "", $input_lines);
	$dd=array();
	//-------------------------Risk Management-------------------------------
	preg_match_all("/Risk Measures[\s\w<>=\"-:?@.;()%]*?<\/table>/", $input_lines, $output_array);
	preg_match_all("/<tr>[\s\w<>=\"-:?@.;()%]*?<\/tr>/", $output_array[0][0], $output_array);
	$d=array();
	foreach ($output_array[0] as $value)
	{
		preg_match_all("/<td(?:>| class)[\s\w<>=\"-:?@.;()%]*?<\/td>/", $value, $out);
		$a=array();
		foreach ($out[0] as $val)
			array_push($a,preg_replace("/(?|<[^>]*?>|[\s]{2,})/","",$val));
		array_push($d,$a);
	}
	array_push($dd,array("Risk Management",$d));
	//------------------------------Trailing Returns-------------------------
	preg_match_all("/Trailing Returns[\s\w<>=\"-:?@.;()%]*?<\/table>/", $input_lines, $output_array);
	preg_match_all("/<tr>[\s\w<>=\"-:?@.;()%]*?<\/tr>/", $output_array[0][0], $output_array);
	$d=array();
	foreach ($output_array[0] as $value)
	{
		preg_match_all("/<td(?:>| class)[\s\w<>=\"-:?@.;()%]*?<\/td>/", $value, $out);
		$a=array();
		foreach ($out[0] as $val)
			array_push($a,preg_replace("/(?|<[^>]*?>|[\s]{2,})/","",$val));
		array_push($d,$a);
	}
	array_push($dd,array("Trailing Returns",$d));
	return $dd;
}
function top_holdings($input_lines)
{
	preg_match_all("/<a href=\"([^\"]*)?\">Portfolio<\/a>/", $input_lines, $output_array);
	$url="https://www.valueresearchonline.com".$output_array[1][0];
	$input_lines=executor($url);
	$input_lines=str_replace("'", "", $input_lines);
	preg_match_all("/<table id=\"fund-snapshot-port-holdings\" [\s\w<>=\"-:?@.;()%]*?<\/table>/", $input_lines, $output_array);
	preg_match_all("/<tr>[\s\w<>=\"-:?@.;()%]*?<\/tr>/", $output_array[0][0], $output_array);
	$d=array();
	foreach ($output_array[0] as $value)
	{
		preg_match_all("/<td(?:>| class)[\s\w<>=\"-:?@.;()%]*?<\/td>/", $value, $out);
		$a=array();
		$out[0]=array_slice($out[0], 1);
		foreach ($out[0] as $val)
			array_push($a,preg_replace("/(?|<[^>]*?>|[\s]{2,})/","",$val));
		array_push($d,$a);
	}
	return array_slice($d, 2);
}
//$input_lines=executor("https://www.valueresearchonline.com/funds/newsnapshot.asp?schemecode=534");
//return call_all($input_lines);

//return peer_comparision($input_lines);
//return portfolio($input_lines);
//return dividend($input_lines);
//print_r(top_holdings($input_lines));
?>

