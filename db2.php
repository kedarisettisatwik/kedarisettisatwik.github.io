<?php
      include_once "dbconn.php";
 $name1 = $_POST['name1'];
 $password1 = $_POST['password1'];


$sqll = mysqli_query($conn, "SELECT * FROM chats WHERE user = '{$name1}' AND password = '{$password1}'");
if (mysqli_num_rows($sqll) > 0){
    echo "you can start chatting..";
    $_SESSION['userfrom'] = $name1;
}else{
  echo "name or password is wrong";
}
?>