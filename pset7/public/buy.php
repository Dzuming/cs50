<?php
require("../includes/config.php"); 
   //  if user reached page via POST (as by submitting a form via POST)
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
$stock = lookup($_POST["symbol"]);
$value = $stock["price"] * $_POST["shares"];
if ($stock["symbol"] !== $_POST["symbol"])
{
apologize (" Insert correct stock name");
}
if ($value > $_SESSION["cash"])
{
apologize (" You don't have certain cash");
}
if (preg_match("/^\d+$/", $_POST["shares"]))
{        
$insert = query("INSERT INTO Portfolio (id, symbol, shares) VALUES (?, ?, ?) 

ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)"
, $_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"]);
$_SESSION["cash"] -= $value;
}
else
{
apologize ("Insert correct  amount of stocks");
}
if ($insert === false)
                {
                    apologize("Error while buying shares");
                }
                 $history = query("INSERT INTO history(id, transaction, date, symbol, shares, price) VALUES (?, ?, Now(), ?, ?, ?)"
                ,$_SESSION["id"], "BUY", strtoupper($_POST["symbol"]),$_POST["shares"], $stock["price"]);
 redirect("/");
}

else
{

render("buy_form.php",  ["title" => "buy"]);
    }
?>
