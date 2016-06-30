<?php

    // configuration
    require("../includes/config.php");
   
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("password_form.php", ["title" => "Password"]);
        
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    
        
         if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your password is different!");
        }
        $rows = query(" UPDATE users SET hash = ? WHERE username = ?", crypt($_POST["password"]), $_SESSION["username"]);
       if ($rows === FALSE){
        apologize("wrong password");
}
redirect("/");

    }

?>
