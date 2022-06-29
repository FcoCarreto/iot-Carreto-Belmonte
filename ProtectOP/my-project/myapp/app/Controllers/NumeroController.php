<?php 
namespace App\Controllers;
use CodeIgniter\Controller;
use App\Models\Numeros;
class NumeroController extends BaseController{
    public function index(){
            echo view('templates/header');
            echo view('charts/grafica');
            echo view('templates/footer');  
    }

    public function datosGraficas(){ 
        $graficaModel=new Numeros();
        $data=$graficaModel->findAll();
        echo json_encode($data);
    } 
    
    public function arduino(){
        helper(['form']);
        if ($this->request->getMethod()=='post'){
            $NumModel = new Numeros();
            $Data=['distance'=> $this->request->getVar('distance'),'counter'=> $this->request->getVar('counter')];
            $NumModel->insert($Data);
            return "Exito";    
        }
        return "GET";
    }
}