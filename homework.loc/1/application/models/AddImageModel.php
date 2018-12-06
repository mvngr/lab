<?php
class AddImageModel extends CI_Model {
 	function __construct() {
 		parent::__construct();
 		$this->load->database();
 	}

 	function add_image($img_id, $text)
 	{
 		$this->db->query("INSERT INTO `items` (`id`, `name`, `img_id`) VALUES (NULL, '". $text ."', '". $img_id ."');");
 		return;
 	}
}