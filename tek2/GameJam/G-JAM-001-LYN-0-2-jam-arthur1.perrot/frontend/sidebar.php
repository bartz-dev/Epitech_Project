<div class="d-flex flex-column p-3 text-white bg-dark" style="width: 280px;">
    <p class="text-center fs-4"><?php echo $lang['plist'];?></p>
  <hr>
  <ul class="nav nav-pills flex-column mb-auto">
    <li class="nav-item">
      <a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ" class="nav-link active"><i class="fas fa-user"></i> Your Username</a>
    </li>
    <li>
      <a href="#" class="nav-link text-white">
        <i class="fas fa-user-secret"></i> <?php echo $lang['opponent'];?></a>
    </li>
  </ul>
  <hr>
  
  <div class="dropdown">
    <a href="#" class="d-flex align-items-center text-white text-decoration-none dropdown-toggle" id="dropdownUser1" data-bs-toggle="dropdown" aria-expanded="false">
      <img src="https://github.com/huntervcx.png" alt="ardour" width="32" height="32" class="rounded-circle me-2">
      <strong><?php echo $lang['appname'];?></strong>
    </a>
    <ul class="dropdown-menu dropdown-menu-dark text-small shadow" aria-labelledby="dropdownUser1">
      <li><a class="dropdown-item" href="#"><?php echo $lang['newroom'];?></a></li>
      <li><a class="dropdown-item" href="#"><?php echo $lang['username'];?></a></li>
      <li><hr class="dropdown-divider"></li>
      <li><a class="dropdown-item" href="<?php echo $url;?>?lang=fr"><?php echo $lang['lang_to_fr'];?></a></li>
      <li><a class="dropdown-item" href="<?php echo $url;?>?lang=en"><?php echo $lang['lang_to_en'];?></a></li>
    </ul>
  </div>
</div>