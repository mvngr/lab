<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Добавление</title>
	<link rel="stylesheet" type="text/css" href="styles/AddImage.css">
	<!-- Общие для всех -->
	<link href="https://fonts.googleapis.com/css?family=Roboto" rel="stylesheet">
	<link rel="stylesheet" type="text/css" href="styles/default.css">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<script type="text/javascript" charset="utf-8">
		$('#')
	</script>
</head>
<body>
	<div class="menu">
		<p><a href="/1/">Главная</a></p>
		<p><a href="/1/add_image">Добавление</a></p>
	</div>
	<div class="content">
		<form action="" method="get" accept-charset="utf-8">
			<div class="union">
				<button name="refresh" class="refresh">↺</button>
				<input type="text" name="text" autofocus>
				<img src="https://picsum.photos/500/500/?image=<?=@$id?>" alt="">
				<input type="text" name="img-id" value="<?=@$id?>" style="display: none;">
			</div>
			<button type="submit" name="add" class="add">Добавить</button>
		</form>
	</div>
</body>
</html>