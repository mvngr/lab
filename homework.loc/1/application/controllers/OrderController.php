<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class OrderController extends CI_Controller {

	public function __construct(){
		parent::__construct();
		$this->load->model('OrderModel');
		$this->load->helper('download');
	}

	public function index()
	{
		$data = array();
		if($this->input->get('img-id'))
		{
			$data['id'] = $this->input->get('img-id'); //передаем id в view
			$data['title'] = $this->OrderModel->get_title($data['id']);

			if(isset($_GET['download']))
			{
				$this->OrderModel->download_image($this->input->get('img-id'));
			}
		}
		else
		{
			header('Location: /1/');
			exit();
		}
		$this->load->view('OrderView', $data);
	}
}
