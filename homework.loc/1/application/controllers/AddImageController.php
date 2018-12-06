<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class AddImageController extends CI_Controller {

	public function __construct(){
		parent::__construct();
		$this->load->model('AddImageModel');
	}

	public function index()
	{
		$data = array();
		if($this->input->get('refresh') || !$this->input->get('text'))
		{
			$data['id'] =  rand(0, 1024); 
		}
		else
		{
			if($this->input->get('img-id') && $this->input->get('text'))
			{
				$this->AddImageModel->add_image($this->input->get('img-id'), $this->input->get('text'));
				header('Location: /1/order?img-id='.$this->input->get('img-id'));
			}
		}
		$this->load->view('AddImageView', $data);
	}
}
