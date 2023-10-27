<?php
    $size = $_POST['size'];

    echo "<table border='1px solid black'><tbody>";
    for($i=1; $i<=$size; $i++)
    {  
        echo"<tr>";
        for($j=1; $j<=$size; $j++)
        {
            $result = $i*$j;
            echo("<td style='text-align:center; border:1px solid gray; padding:5px'>".$result."</td>");
        }
        echo"</tr>";
    }
    echo "</tbody></table>";
?>