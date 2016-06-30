<?php
require("../includes/config.php"); 
   //  if user reached page via POST (as by submitting a form via POST)
 if ($_SERVER["REQUEST_METHOD"] == "POST")
    {     
     
    $stock = lookup($_POST["symbol"]);
    $rows = query("SELECT id, shares, symbol FROM Portfolio where id = ? and symbol = ? ",  $_SESSION["id"], $_POST["symbol"]);
    
$del = query("DELETE FROM Portfolio where id = ? and symbol = ? ",  $_SESSION["id"], $_POST["symbol"]);
if ($del !== FALSE)
{
$value =  $stock["price"] * $rows[0]["shares"];  
 $_SESSION["cash"] += $value;
}
 $history = query("INSERT INTO history(id, transaction, date, symbol, shares, price) VALUES (?, ?, Now(), ?, ?, ?)"
                ,$_SESSION["id"], "SELL", strtoupper($_POST["symbol"]),$rows[0]["shares"], $stock["price"]);




 redirect("/");
}
else
{
         $rows = query("SELECT id, shares, symbol FROM Portfolio where id = ? ",  $_SESSION["id"]);
        render("sell_form.php", ["positions" => $rows, "title" => "sell_form"]);
    }

?>
