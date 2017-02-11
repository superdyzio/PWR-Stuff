
<!DOCTYPE html>
<?php
session_start();
if (empty($_POST["style"])) {

} 
else {
  if(strcmp($_POST["style"],"style1")==0) {

    setcookie("style","style1", time() + (86400 * 30),"/");
  }
  else   if(strcmp($_POST["style"],"style")==0) 
  {
    setcookie("style","style", time() + (86400 * 30),"/");

  } 
}
?>
<html>
<head>
  <meta charset="UTF-8">
  <title>PHP</title>
  <?php 
if (!empty($_POST["style"])) {
  if(!strcmp($_POST["style"],"style"))
    echo  "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">";
  else if(strcmp($_POST["style"],"style1")==0)
    echo  "<link rel=\"stylesheet\" type=\"text/css\" href=\"style1.css\">";
}

  else  if(isset($_COOKIE["style"]) ) {
    if(strcmp($_COOKIE["style"],"style1")==0 ) {

      echo   "<link rel=\"stylesheet\" type=\"text/css\" href=\"style1.css\">";
    }
    else {
      echo  "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">";
    }
  }
  else
  {
    echo   "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">";
  }
  ?>
</head>

<body>
  <a href="logging.php">logging</a><br>
  <a href="personal.php">Personal data</a><br>
    <a href="logged.php">Logged in only</a>


  <?php

// define variables and set to empty values
  $nameErr = $ageErr= $message=$name = $age = $prefix  =$gender  =$food  = "";



  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["name"])) {
      $nameErr = "Name is required";
    } else {
      $name = test_input($_POST["name"]);
      if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
        $nameErr = "Only letters and white space allowed"; 
      }
    }
    if (empty($_POST["age"])) {
      $ageErr = "age is required";
    } else {
      $age = test_input($_POST["age"]);
      if (preg_match("/[0-9]/",$name)) {
        $ageErr = "Only numbers allowed"; 
      }
    }

    if (empty($_POST["prefix"])) {
      $prefix = "";
    } else {
      $prefix = test_input($_POST["prefix"]);
    }
    if (empty($_POST["message"])) {
      $message = "";
    } else {
      $message = htmlspecialchars($_POST["message"]);
    }

    if (empty($_POST["gender"])) {
      $gender = "";
    } else {
      $gender = test_input($_POST["gender"]);
    }

    if (empty($_POST["food"])) {
      $food = "";
    } else {
      $food = test_input($_POST["food"]);
    }


  }

  function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
  }
  ?>
  <nav>
    <ul>
      <li><a href="strona.html">Back</a></li>
    </ul>
  </nav>
  <?php
  $patterns = array();
  $patterns[0] = '/your/';
  $patterns[1] = '/you\'re/';
  $replacements = array();
  $replacements['first'] = 'my';
  $replacements['second'] = 'I\'m';
  $message= preg_replace($patterns, $replacements, $message);
  ?>
  <form method="post" 
  action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>" >
  <span class="error"> <?php echo $nameErr;?></span>
  <div><input type="text" name="name" autofocus required><span>Podaj imię</span></div>
  <span class="error"> <?php echo $ageErr;?></span>
  <div><input type="text" name="age" required><span>Podaj wiek</span></div>
  <select name="prefix">
    <option value="Mr">Mr</option>
    <option value="Mrs">Mrs</option>
    <option value="Ms">Ms</option>
  </select><br>

  <input type="radio" name="gender" value="Male" checked> Male<br>
  <input type="radio" name="gender" value="Female"> Female<br>

  <input type="radio" name="gender" value="Other"> Other<br>

  <input type="checkbox" name="food" value="Pasta" checked> I like pasta<br>


  <input type="radio" name="style" value="none" checked>  don't change anything <br>
  <input type="radio" name="style" value="style" >  style <br>
  <input type="radio" name="style" value="style1" > 2nd style <br>

  <textarea name="message" rows="10" cols="30" placeholder="<?php echo 'Every ',reset($patterns),'  will be switched to ', reset($replacements),' and ', next($patterns), ' to ', next($replacements), ' - that\'s ', count($replacements),' words';?>">
    <?php echo htmlspecialchars($message); ?></textarea> 
    <br>
    <div><input type="submit"></div>
  </form>



  <?php
  if ($_SERVER["REQUEST_METHOD"] == "POST") {

    define("RESULT", "Your Input:");
    echo "<h2>", RESULT,"</h2>";
    echo $prefix, " ", $name;
    if(!strcmp("Mr", $prefix))
     echo "<br> Jestes panem!";
   echo "<br>";
   echo "you will be ";
   echo ((string) $age)." + 12 = ";
   echo  $age+"12 years";
   echo " in 12 years. Here are some candles: <br>";
   for ($x = 0; $x <= $age; $x++) {
    echo " [*] ";
    if($x==100)
      die('you are dead, no point in printing anything else');
  }
  echo "<br>";
  echo "<br>";
  echo $gender;
  echo "<br>";
  echo $food;
  echo "<br>";
  echo 'your ip is ', $_SERVER['REMOTE_ADDR'];
}
echo "(12*7+3)-(integer)\"12\"=";
echo $show = (12*7+3)-(integer)"12";
echo "<br> ($show==\"75\") -> ";
echo ($show=="75")==true?"prawda":"falsz";
echo "<br> ($show===\"75\") -> ";
echo ($show==="75")==true?"prawda":"falsz";
echo "<br> $show.=\"12\"";
echo "->". $show.="12";
$a = 'hello'; $$a = 'world';
echo "<br><br>\$a = 'hello'; \$\$a = 'world'; echo \"\$a \${\$a}\"; -> ";
echo  "$a"." ${$a}";

if( isset($_SESSION["login"])  )
{
  echo "<br> you are logged in as ".$_SESSION["login"]." <br>";
  echo "<a href=\"logout.php\">Logout</a><br>";

}

?>
<details>
  <summary>Programowanie Systemow Webowych - HTML 2</summary>
  <p> Dawid Perdek, Jakub Granieczny</p>
</details>
</body>

</html>
