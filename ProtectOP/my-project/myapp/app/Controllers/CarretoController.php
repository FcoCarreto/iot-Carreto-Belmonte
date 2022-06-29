<?php
namespace App\Controllers;

use App\Models\Carreto;

class CarretoController extends BaseController
{
    public function index()
    {                   
        helper(['html']);

        $CarretoModel = new Carreto();
        $data['datos'] = $CarretoModel->findAll();
        
        echo view('templates/header');
        echo view('user/tabla',$data);
        
        echo view('templates/footer');
        echo view('templates/nav');
      
        
    }
    




}