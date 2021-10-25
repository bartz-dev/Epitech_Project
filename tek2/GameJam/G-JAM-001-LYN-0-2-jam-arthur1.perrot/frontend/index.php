<!doctype html>
<html lang="en">
<?php include 'head.php' ?>

<body>

    <?php include 'sidebar.php' ?>

    <main class="col-md-9 ms-sm-auto col-lg-10 px-md-4">
        <h2><?php echo $lang['game'];?></h2>
        <canvas class="my-4 w-100" id="myGame" width="1000" height="200"></canvas>

        <h2><?php echo $lang['chat'];?></h2>
        <canvas class="my-4 w-100" id="Chat" width="1000" height="400"></canvas>
    </main>

    <script src="dist/js/bootstrap.bundle.min.js"></script>
    <script src="app.js"></script>
    <script src="https://kit.fontawesome.com/68d2203743.js" crossorigin="anonymous"></script>
</body>
</html>