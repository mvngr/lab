<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Оформление</title>
	<link rel="stylesheet" type="text/css" href="styles/Order.css?id=<?=rand()?>">
	<!-- Общие для всех -->
	<link rel="stylesheet" type="text/css" href="styles/default.css">
	<meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
	<div class="menu">
		<p><a href="/1/">Главная</a></p>
		<p><a href="/1/add_image">Добавление</a></p>
	</div>
	<div class="content">
		<div id="left">
			<img src="https://picsum.photos/1000/1000/?image=<?=$id?>" class="main-img">
		</div>
		<div id="right">
			<h1><?=$title;?></h1>
			<h2>Размеры</h2>
			<p>
				<span class="category">Ширина:</span> 1000px
			</p>
			<p>
				<span class="category">Высота:</span> 1000px
			</p>
			<h2>Скачивание</h2>
			<form action="" method="get" accept-charset="utf-8">
				<input type="number" name="img-id" value="<?=$id?>" style="display: none;">
				<button type="submit" name="download" id="download-btn">Получить</button>
			</form>
			<p>
				<div class="description">
					*Данные изображения взяты с сайта <a target="_blank" href="https://picsum.photos/">picsum.photos</a>
				</div>
			</p>
		</div>
	</div>
</body>
</html>