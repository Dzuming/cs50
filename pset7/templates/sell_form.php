<form action="sell.php" method="post">

 <fieldset>
<div class="control-group">
            <select id="sold" name="symbol">
                <option value =''>choose stock to sell</option>

    <?php  foreach ($positions as $position) {

      echo '<option  value="'. $position["symbol"] . '">' . $position["symbol"] .  '</option> ';
      }
 ?>
 </select>
</div>
<div class="form-group">
            <button type="submit" class="sell">Sell</button>
        </div>
 
  </fieldset>
</form>      
<div>
     <a href="index.php">Return</a> to a portfolio
</div>    

