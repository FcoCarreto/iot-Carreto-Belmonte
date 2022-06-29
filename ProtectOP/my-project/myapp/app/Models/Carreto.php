<?php
namespace App\Models;
use CodeIgniter\Model;
class Carreto extends Model{
    protected $table='habitacion';
    protected $primaryKey='id';
    protected $returnType='array';
    protected $allowedFields=['distance','counter'];

}