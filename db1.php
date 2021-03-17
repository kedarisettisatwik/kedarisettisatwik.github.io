<?php
      include_once "dbconn.php";
 $user = $_POST['name1'];
 $email = $_POST['email1'];
 $password = $_POST['message1'];
$sql = mysqli_query($conn, "SELECT user FROM chats");
  $movedb = mysqli_query($conn,"INSERT INTO chats (name,email,message) VALUES ('{$user}','{$email}','{$password}')");  
 if($movedb){
    echo "thank you for writting review";
   }else{
    echo "Data  transfer failed";
   }
?>