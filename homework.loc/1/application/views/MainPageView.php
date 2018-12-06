<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Главная</title>
	<link rel="stylesheet" type="text/css" href="styles/MainPage.css">
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
		<div class="items">	
			<? foreach ($items as $key => $value) { ?>
				<form action="order" method="get" accept-charset="utf-8">
					<div class="item">
						<div class="item-fill"></div>
						<img src="https://picsum.photos/200/200/?image=<? echo $value; ?>" alt="" class="item-img">
						<div class="item-text"><? echo $key; ?></div>
						<input type="number" name="img-id" value="<? echo $value; ?>" style="display: none;">
						<button type="submit" class="item-click"></button>
					</div>
				</form>
			<? } ?>
		</div>
	</div>
</body>
</html>