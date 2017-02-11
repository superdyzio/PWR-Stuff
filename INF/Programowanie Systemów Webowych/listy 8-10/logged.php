<!DOCTYPE html>

<html>
<head>
  <meta charset="UTF-8">
  <title>secret</title>
<?php
session_start();
  if( isset($_SESSION["login"])  )
  {
    print("This is a secret page, for logged users only <br>
        you are logged in as ".$_SESSION["login"]."</head></html> ");

  }
  else
  {

header('Location: form2.php');

exit;
}
?>