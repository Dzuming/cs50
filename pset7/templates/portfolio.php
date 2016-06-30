<form action="register.php" method="post">
<div >
<a class="link" href="quote.php">Quote</a>
<a class="link" href="buy.php">Buy</a>
<a class="link" href="sell.php">Sell</a>
<a class="link" href="history.php">History</a>
<a class="link" href="password.php">Password</a>
<a class="link" href="logout.php">Log Out</a>

<table>
<tr>
<th> Symbol </th>
<th> Name </th>
<th> Share </th>
<th> Price  </th>
<th> Total </th>
</tr>
    <?php foreach ($positions as $position): ?>

    <tr >
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= "$" .$position["price"] ?></td>
        <td><?= "$" .$position["value"] ?></td>
    </tr>
<?php endforeach ?>

</table>
<h4>Available cash: <?= "$" .$_SESSION["cash"] ?></h4>
</div>
</form>
    

