<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Stock price"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["stock"]))
        {
       
            apologize("enter stock");
        }
        
    
        // query database for user
        $stock = lookup($_POST["stock"]);
        
        // if we found user, check password
        if ($stock === false)
        {
            apologize("Stock invalid");
            }
            else{
            render("quote_result.php", ["title" => "Quote", "symbol" => $stock["symbol"], "name" => $stock["name"], "price" => $stock["price"]]);
            }
            }
            
?>
