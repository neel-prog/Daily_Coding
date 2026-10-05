<?php

$name = $_POST['name'];
$email = $_POST['email'];
$age = $_POST['age'];

$errors = [];

if (!preg_match("/^[a-zA-Z ]{2,50}$/", $name)) {
    $errors[] = "Invalid name.";
}

if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    $errors[] = "Invalid email.";
}

if (!filter_var($age, FILTER_VALIDATE_INT) || $age < 18 || $age > 100) {
    $errors[] = "Age must be between 18 and 100.";
}

if (!empty($errors)) {
    foreach ($errors as $error) {
        echo "<p>$error</p>";
    }
    exit;
}

echo "Validation successful.";

?>