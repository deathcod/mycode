<?php
function executor($url)
{
	$curl=curl_init();
	curl_setopt($curl, CURLOPT_URL,$url);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
	$input_lines = curl_exec($curl);
	return call_all($input_lines);
}
function returns($input_lines)
{
	preg_match_all("/<td><span class=\"b_13\">([^<]*)<\/span><\/td>[\s]*?<td class=\"rgt\"><span class=\"gr_12\">([^<]*)<\/span><\/td>[\s]*?<td class=\"rgt\">([^<]*)<\/td>/", $input_lines, $output_array);
	$d=array();
	$length=sizeof($output_array[1]);
	for ($i=0; $i < $length; $i++)
		$d[$i]=array(
					$output_array[1][$i],
					$output_array[2][$i],
					$output_array[3][$i]);
	return $d;
}
//print_r(returns($input_lines));
function absolue_returns($input_lines)
{
	preg_match_all("/<td><span class=\"b_13\" align=\"left\">([^<]*)<\/span><\/td>[\s]*<td class=\"rgt\"><span class=\"(?|r_12|gr_12|bl_12)\">([^<]*)<\/span><\/td>[\s]*<td class=\"rgt\"><span class=\"(?|r_12|gr_12|bl_12)\">([^<]*)<\/span><\/td>[\s]*<td class=\"rgt\"><span class=\"(?|r_12|gr_12|bl_12)\">([^<]*)<\/span><\/td>[\s]*<td class=\"rgt\"><span class=\"(?|r_12|gr_12|bl_12)\">([^<]*)<\/span><\/td>[\s]*<td class=\"rgt\"><span class=\"(?|r_12|gr_12|bl_12)\">([^<]*)<\/span><\/td>/", $input_lines, $output_array);
	$d=array();
	$length=sizeof($output_array[1]);
	for ($i=0; $i < $length; $i++)
		$d[$i]=array(
					$output_array[1][$i],
					$output_array[2][$i],
					$output_array[3][$i],
					$output_array[4][$i],
					$output_array[5][$i],
					$output_array[6][$i]);
	return $d;
}
//print_r(absolue_returns($input_lines));
function performance($input_lines)
{
	preg_match_all("/<td valign=\"top\" class=\"PA3 brdb bl_13\">([^<]*)<\/td>[\s]*?<td align=\"right\" valign=\"top\" class=\"[^\"]*\">([^<]*)<\/td>[\s]*?<td align=\"right\" valign=\"top\" class=\"[^\"]*\">([^<]*)<\/td>[\s]*?<td align=\"right\" valign=\"top\" class=\"[^\"]*\">([^<]*)<\/td>[\s]*?<td align=\"right\" valign=\"top\" class=\"[^\"]*\">([^<]*)<\/td>[\s]*?<td align=\"right\" valign=\"top\" class=\"[^\"]*\">([^<]*)<\/td>[\s]*?<td align=\"right\" valign=\"top\" class=\"[^\"]*\">([^<]*)<\/td>[\s]*?<td align=\"right\" valign=\"top\" class=\"[^\"]*\">([^<]*)<\/td>/", $input_lines, $output_array);
	$d=array();
	$length=sizeof($output_array[1]);
	for ($i=0; $i < $length; $i++)
		$d[$i]=array(
					$output_array[1][$i],
					$output_array[2][$i],
					$output_array[3][$i],
					$output_array[4][$i],
					$output_array[5][$i],
					$output_array[6][$i],
					$output_array[7][$i],
					$output_array[8][$i]);
	return $d;
}
//print_r(performance($input_lines));
function Investment_Info($input_lines)
{
	$a=array();
	$a[0][0]="Scheme details";
	$a[1][0]="Load Details";
	$a[2][0]="Contact Details";
	preg_match_all("/<table width=\"100%\" class=\"invtbl\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">[\s\w<>=\"-:?@.;]*?<\/table>/", $input_lines, $output_array);
	for ($j=0; $j < 3; $j++)
	{
		preg_match_all("/<th[^>]*>[\s]*([^<]*)<\/th>[\s]*<td[^>]*>[\s]*(.*)?</", $output_array[0][$j], $output);
		$d=array();
		$length=sizeof($output[1]);
		for ($i=0; $i < $length; $i++)
			$d[$i]=array($output[1][$i],preg_replace("/<[^>]*>/","",$output[2][$i]));
		$a[$j][1]=$d;
	}
	return $a;
}
//print_r(
//Investment_Info($input_lines);
function portfolio($input_lines)
{
	$a=array();
	$a[0][0]="Top Holdings";
	$a[1][0]="Sector Allocation";
	$a[2][0]="Assest Allocation";
	$a[3][0]="Concentration";
	preg_match_all("/<td>(.*)?<\/td>[\s]*?<td>([^<]*)<\/td>[\s]*?<td class=\"rgt\">([^<]*)<\/td>[\s]*<td class=\"rgt\">([^<]*)<\/td>/", $input_lines, $output_array);
	$d=array();
	$length=sizeof($output_array[1]);
	for ($i=0; $i < $length; $i++)
		$d[$i]=array(
					preg_replace("/<[^>]*>/","",$output_array[1][$i]),
					$output_array[2][$i],
					$output_array[3][$i],
					$output_array[4][$i]);
	$a[0][1]=$d;
	preg_match_all("/<td>(.*)?<\/td>[\s]*?<td>([^<]*)<\/td>[\s]*?<td width=\"20%\" class=\"rgt\">([^<]*)<\/td>[\s]*<td width=\"20%\" class=\"rgt\">([^<]*)<\/td>/", $input_lines, $output_array);
	$d=array();
	$length=sizeof($output_array[1]);
	for ($i=0; $i < $length; $i++)
		$d[$i]=array(
					$output_array[1][$i],
					$output_array[2][$i],
					$output_array[3][$i],
					$output_array[4][$i]);
	$a[1][1]=$d;
	preg_match_all("/<td(?: width=\"70%\")?>([^<]*)<\/td>[\s]*<td(?: width=\"30%\")? class=\"rgt\">([^<]*)<\/td>[\s]*<\/tr>/", $input_lines, $output_array);
	$d=array();
	$length=sizeof($output_array[1]);
	for ($i=0; $i < $length; $i++)
		$d[$i]=array(
					$output_array[1][$i],
					$output_array[2][$i]);
	$a[2][1]=$d;
	preg_match_all("/<tr>[\s]*<td>([^<]*)<\/td>[\s]*<td>([^<]*)<\/td>[\s]*<\/tr>/", $input_lines, $output_array);
	$top=array("Top 3"=>"-","Top 5"=>"-","Top 10"=>"-");
	$top[$output_array[1][0]]=$output_array[2][0];
	$top[$output_array[1][1]]=$output_array[2][1];
	$top[$output_array[1][2]]=$output_array[2][2];
	$a[3][1]=array($top["Top 3"],$top["Top 5"],$top["Top 10"]);
	return $a;
}
//print_r(portfolio($input_lines));
function call_all($input_lines)
{
	$input_lines = utf8_decode($input_lines);
	$input_lines= utf8_encode(str_replace(utf8_decode("�"), "", $input_lines));
	preg_match_all("/FUND FAMILY : (.*)?<\/a> <span class=\"PL10\">FUND CLASS : (.*)?<\/a><\/span>|<input type=\"hidden\" name=\"scheme_name\" id=\"scheme_name\" value=\"([^\"]*)\">/", $input_lines, $output_array,PREG_SET_ORDER);
	$a=array(
		$output_array[1][3],
		"FUND FAMILY" => preg_replace("/<[^>]*>/","",$output_array[0][1]),
		"FUND CLASS" => preg_replace("/<[^>]*>/","",$output_array[0][2]),
		"Returns"=>returns($input_lines),
		"Absolue Returns"=>absolue_returns($input_lines),
		"Performance"=>performance($input_lines),
		"Investment Info"=>Investment_Info($input_lines),
		"Portfolio"=>portfolio($input_lines)
		);
	return $a;
}
//print_r(call_all($input_lines));
//print_r(executor("http://www.moneycontrol.com/india/mutualfunds/mfinfo/09/47/latestnav/CEL_fc/mutual-funds/nav/l-t-equity-fund-direct-plan/MCC309"));

/*
http://www.moneycontrol.com/india/mutualfunds/mfinfo/09/47/latestnav/CED_fc/mutual-funds/nav/dsp-blackrock-3-years-close-ended-equity-fund-direct-plan/MDS1126

http://www.moneycontrol.com/mutual-funds/nav/dsp-blackrock-micro-cap-fund-regular-plan/MDS076
*/
?>

