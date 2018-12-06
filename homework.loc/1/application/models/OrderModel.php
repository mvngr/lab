<?php
class OrderModel extends CI_Model {
	function __construct() {
		parent::__construct();
		$this->load->database();
	}

	function download_image($img_id)
	{
		$path = file_get_contents('https://picsum.photos/1000/1000/?image='.$img_id);
		$name = 'picture-'.$img_id.'.jpg';
		force_download($name, $path); //скачивание картинки
		header('Location: /order?img-id='.$img_id);
		exit();
	}
	function get_title($img_id)
	{
		$Q = $this->db->query("SELECT name FROM items WHERE img_id = ". $img_id)->result();
		if($Q)
			return $Q[0]->name;
		else
			return 'Упс.. Что-то пошло не так!';
	}
}