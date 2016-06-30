/**
 * scripts.js
 *
 * Computer Science 50
 * Problem Set 7
 *
 * Global JavaScript, if any.
 */
 $(document).ready(function(){
     $('.sell').click(function(){
     var $e = $('#sold').find(":selected").text();
     var $d = "choose stock to sell";
     if ($e == $d )
     {
alert("ERROR!\n" + $d);
 }
 else
 {
 alert("You sold " + $e);
 }
     });
});

