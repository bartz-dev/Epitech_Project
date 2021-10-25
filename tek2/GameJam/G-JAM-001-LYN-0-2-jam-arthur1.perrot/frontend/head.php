<?php
session_start();
$available_langs = array('en','fr');

if(isset($_GET['lang']) && $_GET['lang'] != ''){
    if(in_array($_GET['lang'], $available_langs))
    {
        $_SESSION['lang'] = $_GET['lang'];
    }
}

if ($_SESSION['lang']=='') {
    $_SESSION['lang'] = 'fr';

}

include('languages/'.$_SESSION['lang'].'/lang.'.$_SESSION['lang'].'.php');
?>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="Lord Arthur PERROT">
    <title><?php echo $lang['appname'];?></title>
    <link href="dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="style.css" rel="stylesheet">
  </head>