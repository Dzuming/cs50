<?php

    // configuration
    require("../includes/config.php"); 
    $result = query("SELECT id, transaction, date, symbol, shares, price FROM history where id = ?",  $_SESSION["id"]);
    $history = [];
foreach ($result as $row)
{
        $history[] = [
            "transaction" => $row["transaction"],
            "date" => $row["date"],
            "symbol" => $row["symbol"],
            "shares" => $row["shares"],
            "price" => $row["price"],
            
        ];
    }

    // render portfolio
   render("history_form.php", ["history" => $history, "title" => "history_form"]);

?>
