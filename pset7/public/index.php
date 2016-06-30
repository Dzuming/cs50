<?php

    // configuration
    require("../includes/config.php"); 
    $rows = query("SELECT id, shares, symbol FROM Portfolio where id = ?",  $_SESSION["id"]);
    $positions = [];
foreach ($rows as $row)
{
    $stock = lookup($row["symbol"]);
    if ($stock !== false)
    {
        $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
            "value" => $stock["price"] * $row["shares"]
        ];
    }
}
    // render portfolio
   render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);

?>
