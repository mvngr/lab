<?php
class MainPageModel extends CI_Model {
 	function __construct() {
 		parent::__construct();
 		$this->load->database();
 	}

 	function loadItemsText(){
 		$res = array();
 			
 		$Q = $this->db->query("select name, img_id from items;")->result();
 		foreach($Q as $row)
 		{
 			$res[$row->name] = $row->img_id;
 		}
 		return $res;
 	}
}