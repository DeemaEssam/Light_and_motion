<?php
$servername = "localhost";
$username = "test";
$password = "test";
$dbname = "robot";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$lightLevel = $_GET['light'];
$motionDetected = $_GET['motion'] == '1' ? true : false;

$sql = "INSERT INTO sensor_data (light_level, motion_detected) VALUES ('$lightLevel', '$motionDetected')";

if ($conn->query($sql) === TRUE) {
  echo "New record created successfully";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>