<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    $data = [2];
   $data = explode(",",$_GET["geo"]);
   if ( isset($data[0]))
   { 
$places = query("SELECT *  FROM places WHERE place_name LIKE ? OR admin_name1 LIKE ? OR postal_code LIKE ? ORDER BY place_name OR admin_name1 OR postal_code  ASC   "
   , $data[0], $data[0], $data[0] );
  }  

else if ( isset($data[1]))
   { 
$places = query("SELECT *  FROM places WHERE place_name LIKE ? OR admin_name1 LIKE ? OR postal_code LIKE  ?  "
   , $data[1], $data[1], $data[1] );
  }
  else if ( isset($data[1]))
   { 
$places = query("SELECT *  FROM places WHERE place_name LIKE ? OR admin_name1 LIKE ? OR postal_code LIKE ? "
   , $data[2], $data[2], $data[2] );
  }   
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>
