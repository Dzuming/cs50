<form action="register.php" method="post">
<div >
<table>
<tr>
<th> Transaction </th>
<th> Date/Time </th>
<th> Symbol </th>
<th> Shares  </th>
<th> Price </th>
</tr>
    <?php foreach ($history as $histories): ?>

    <tr >
        <td><?= $histories["transaction"] ?></td>
        <td><?= $histories["date"] ?></td>
        <td><?= $histories["symbol"] ?></td>
        <td><?= $histories["shares"] ?></td>
        <td><?= "$" .$histories["price"] ?></td>
    </tr>
<?php endforeach ?>

</table>

</div>
<div>
     <a href="index.php">Return</a> to a portfolio
</div>
</form>

