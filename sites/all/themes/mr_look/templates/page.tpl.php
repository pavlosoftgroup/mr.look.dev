<header>
 <?php print render($page['top_menu']) ?>
  <div class="head__left">
    <a href="#">(044)345-34-56</a>
    <p class="time">с 10:00 до 20:00</p>
  </div>
  <a class="recall" href="#">Перезвоните мне</a>
  <div class="bin">
    <a href="#"><img src="../images/bin.png" alt=""></a>
    <span class="bin__price">45 780 грн.</span>
  </div>
</header>
<div class="face">
  <?php if ($logo): ?>
    <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
    </a>
  <?php endif; ?>
</div>
<?php if (!empty($primary_nav)): ?>
  <?php print render($primary_nav); ?>
<?php endif; ?>
<nav class="nav__block">
  <ul class="nav__panel">
    <li class="nav__list"><a href="" class="nav__link">Техника <br>Apple</a>
    </li>
    <li class="nav__list"><a href="" class="nav__link">Аксессуары <br>для Apple</a>
    </li>
    <li class="nav__list"><a href="" class="nav__link">Смартфоны и мобильные
        <br>телефоны</a></li>
    <li class="nav__list"><a href="" class="nav__link">Аксессуары <br>для
        смартфонов</a></li>
    <li class="nav__list"><a href="" class="nav__link">Аксессуары <br>для
        планшетов</a></li>
  </ul>
</nav>