<!DOCTYPE html>
<?php
session_start();
?>
<html>
<head>
  <meta charset="UTF-8">
  <title>logging</title>
  <?php
      if (empty($_POST["login"])) {
}
else
{
  $servername = "localhost";
$username = "root";
$password = "";

$query = "SELECT * FROM User WHERE login='".$_POST["login"]."'";

if(!($database = mysql_connect($servername, $username, $password)))
die("could not connect to db</body></html>");
if(!mysql_select_db("Users", $database))
die("could not open user db</body></html>");
if(!($result = mysql_query($query, $database)))
{
    print("<p> could not execute query</p>");
    die(mysql_error()."</body></html>");
}

    
              if (!empty($_POST["pass"])) 
              {
                if(!strcmp($_POST["pass"],mysql_fetch_row($result)[1]))
                    $_SESSION["login"] = test_input($_POST["login"]);
              }

    }

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
  }
  
  if( isset($_SESSION["login"])  )
{
  echo "<br> you are logged in as ".$_SESSION["login"]." <br>";
  echo "<a href=\"logout.php\">Logout</a><br>";
  die("<a href='form2.php'>back</a></head></html>");

}
?>
</head>

  <form method="post" 
  action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>" >
  <div><input type="text" name="login"  ><span>login</span></div>
  <div><input type="password" name="pass"  ><span>haslo</span></div>
    <div><input type="submit"></div>
</form>



<body>
      <a href="form2.php">back</a>

</body>
</html>