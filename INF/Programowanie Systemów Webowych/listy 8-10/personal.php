<!DOCTYPE html>
<?php
session_start();
?>
<html>
<head>
  <meta charset="UTF-8">
  <title>personal</title>
  </head>
<body>

  <?php
  if( isset($_SESSION["login"]) )
  {
    $loginses=$_SESSION["login"];
    $servername = "localhost";
    $username = "root";
    $password = "";

    $query = "SELECT * FROM User WHERE login='".quotemeta($loginses)."'";

    if(!($database = mysql_connect($servername, $username, $password)))
      die("could not connect to db</body></html>");
    if(!mysql_select_db("Users", $database))
      die("could not open user db</body></html>");
    if(!($result = mysql_query($query, $database)))
    {
      print("<p> could not execute query</p>");
      die(mysql_error()."</body></html>");
    }
    $row = mysql_fetch_row($result);

    $login=$row[0];
    $pass=$row[1];
    $name=$row[2];
    $surname=$row[3];
    mysql_close($database);

  }
  else
    {$login="";
  $pass="";
  $name="";
  $surname="";
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

}
if(isset($_POST["submit"]))
{
  $login=$_POST["login"];
  $pass=$_POST["pass"];
  $name=$_POST["name"];
  $surname=$_POST["surname"];
  if(!preg_match("/^[a-zA-Z ]*$/",$name)||!preg_match("/^[a-zA-Z ]*$/",$surname))
  {
    echo "in name and surname only letters and whitespace allowed";
  }
  else
  {
    $servername = "localhost";
    $username = "root";
    $password = "";
    if(isset($_SESSION["login"]))
      $query = "UPDATE User SET login='".quotemeta($login)."', password='".quotemeta($pass)."', Name='".quotemeta($name)."', Surname='".quotemeta($surname)."' WHERE login='".$_SESSION["login"]."'";
    else
      $query="INSERT INTO User ( login, password, Name, Surname ) VALUES ('".quotemeta($login)."', '".quotemeta($pass)."', '".quotemeta($name)."', '".quotemeta($surname)."')";
    if(!($database = mysql_connect($servername, $username, $password)))
      die("could not connect to db");
    if(!mysql_select_db("Users", $database))
      die("could not open user db");
    if(!($result = mysql_query($query, $database)))
    {
      print("<p> could not execute query</p>");
      die(mysql_error());
    }
    if(isset($_SESSION["login"]))
      $_SESSION["login"]=$login;
    echo "data submitted to the database";
    mysql_close($database);
  }
}

if(!isset($_POST["submit"])||(!preg_match("/^[a-zA-Z ]*$/",$name)||!preg_match("/^[a-zA-Z ]*$/",$surname)))
{
  print("

<form method='post' 
action='personal.php' >
<div><input type='text' name='login' value=".$login." ><span>login</span></div>
<div><input type='password' name='pass'  value=".$pass."><span>haslo</span></div>
<div><input type='text' name='name'  value=".$name."><span>imie</span></div>
<div><input type='text' name='surname' value=".$surname." ><span>nazwisko</span></div>

<div><input type='submit' name='submit'></div>
</form>");

}
?>
  <a href="form2.php">back</a>

</body>
</html>