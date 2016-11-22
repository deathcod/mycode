 
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
require_once('database.php');
error_reporting(E_ALL - E_NOTICE);
ini_set('display_errors', 1);

function check($x)
{
	$x=trim($x," ");
	if(preg_match("/[A-Za-z]/",$x))
		$x=-9999.9;
	if($x=='-'||$x=='')
		$x=-9999.9;
	$x=str_replace(",","",$x);
	$x=str_replace("%","",$x);
	return $x;
}
function multiRequest()
{
	$db=new database();
    $x=file_get_contents("1-1.txt");
	$url_array=preg_split("/\s/", $x);
	$curly = array();
	$mh = curl_multi_init();
	for ($i=3827; $i < 3841; $i+=50) 
	{ 
		for ($j=0; $i+$j <min(3841,$i+50); $j++)
		{
			$curly[$j] = curl_init();
			curl_setopt($curly[$j], CURLOPT_URL,            $url_array[$i+$j]);
			curl_setopt($curly[$j], CURLOPT_HEADER,         0);
			curl_setopt($curly[$j], CURLOPT_RETURNTRANSFER, 1);
			curl_multi_add_handle($mh, $curly[$j]);
		}
		$running = null;
		do {
		curl_multi_exec($mh, $running);
		} while($running > 0);


		// get content and remove handles
		for ($id=0; $id < min(3841,$i+50); $id++)
		{
			$input_lines = curl_multi_getcontent($curly[$id]);
			$input_lines=str_replace("'", "", $input_lines);


			/*===========================================================================*/
			
			$x=info($input_lines);
			if($x["fundname"]==''|| strstr($x["fundname"],'Direct Plan'))
			{
				//curl_multi_remove_handle($mh, $curly[$id]);
				continue;
			}
			$y="insert into mutual_fund_VR values(".(String)($id+$i+1).",'".$x["fundname"]."',".check($x["Growth"]).",".check($x["Dividend"]).",'".$x["Category"]."',";
			preg_match("/([\d.,]*) crore [(]As on ([\d\w, ]*)[)]/", $x["Assets"], $matches);
			$y=$y.check($matches[1]).",'".date("Y-m-d",strtotime($matches[2]))."',";
			preg_match("/([\d.,]*)% [(]As on ([\d\w, ]*)[)]/", $x["Expense"], $matches);
			$y=$y.check($matches[1]).",'".date("Y-m-d",strtotime($matches[2]))."')";
			//print_r($y.";<br>");
			$db->query($y);
			
			/*===========================================================================*/
			
			$x=details($input_lines);
			//print_r($x);
			$y="insert into details values(".(String)($id+$i+1).",'".$x["Benchmark"]."','".$x["Type"]."','";
			$y=$y.date("Y-m-d",strtotime($x["Launch Date"]))."',".check($x["Tenure"]).",'".$x["Riskometer"]."','";
			$y=$y.$x["Risk Grade"]."','".$x["Return Grade"]."',".check($x["Turnover"]).",".check($x["Minimum Investment"]).",".check($x["Minimum Addl Investment"]).",".check($x["Minimum SIP Investment"]).",".check($x["Minimum Withdrawal"]).",".check($x["Minimum Balance"]).",'".$x["Exit Load"]."',".check($x["Return since Launch"]).",'".date("Y-m-d",strtotime($x["Maturity Date"]))."')";
			print_r($y.";<br>");
			$db->query($y);
			
			/*=============================================================================*/
			print_r($id+$i+1);
			$x=peer_comparision($input_lines);
			print_r($x);
			foreach ($x as $value)
			{
				$y="insert into peer_comparision values(".(String)($id+$i+1).",'".$value[0]."','".$value[2]."',".check($value[3]).",".check($value[4]).",".check($value[5]).",".check($value[6]).",".check($value[7]).")";
				$db->query($y);
				print_r($y.";<br>");	
			}
			/*=============================================================================*/
			$x=dividend($input_lines);
			foreach ($x[0] as $iii => $value) {
				$y="insert into dividend values(".(String)($id+$i+1).",'".date("Y-m-d",strtotime($value))."',".check($x[1][$iii]).")";
				$db->query($y);
				print_r($y.";<br>");

			}
			/*=============================================================================*/
			$x=performance($input_lines);
			foreach ($x[0][1] as $key => $value) {
				$y="insert into risk_management values(".(String)($id+$i+1).",'".$value[0]."',".check($value[1]).",".check($value[2]).",".check($value[3]).",".check($value[4]).",".check($value[5]).",".check($value[6]).")";
				$db->query($y);
				print_r($y.";<br>");
			}
			foreach ($x[1][1] as $key => $value) {
				$y="insert into trailing_return values(".(String)($id+$i+1).",'".$value[0]."',".check($value[1]).",".check($value[2]).",".check($value[3]).",".check($value[4]).",".check($value[5]).",".check($value[6]).",".check($value[7]).",".check($value[8]).",".check($value[9]).",".check($value[10]).",".check($value[11]).")";
				$db->query($y);
				print_r($y.";<br>");
			}
			/*=============================================================================*/
			$x=top_holdings($input_lines);
			foreach ($x as $value)
			{
				$y="insert into top_holdings_VR values(".(String)($id+$i+1).",'".$value[0]."','".$value[1]."',".check(end($value)).")";
				$db->query($y);
				print_r($y.";<br>");
			}
			/*=============================================================================*/
			curl_multi_remove_handle($mh, $curly[$id]);
		}
	}
	curl_multi_close($mh);
	//return $result;
}
multiRequest();
/*
	error log
-----------------
* portfolio,risk in performance,details,dividend not working
* 36th url info not there

*/
?>