<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class MainPageController extends CI_Controller {

	public function __construct(){
		parent::__construct();
		$this->load->model('MainPageModel');
	}

	public function index()
	{
		$data = array();
		$data['items'] = $this->MainPageModel->loadItemsText();

		$this->load->view('MainPageView', $data);
	}
}
