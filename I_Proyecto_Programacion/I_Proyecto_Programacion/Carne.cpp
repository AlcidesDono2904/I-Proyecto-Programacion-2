#include "Carne.h"

Carne::Carne()
{
}

Carne::Carne(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio, string nombreEmpresa, string nombreDelAnimal, string parteDelAnimal)
{
	this->codigo = codigo;
	this->nombreComercial = nombre;
	this->descripcion = descripcion;
	this->precioCosto = precio;
	this->categoria = categoria;
	this->existencia = existencia;
	this->limite = limite;
	this->fechaIngreso = new Fecha;
	this->nacional = nacional;
	this->peso = peso;
	ptrPere = new Perecedero(dia, mes, anio);
	this->nombreAnimal = nombreDelAnimal;
	this->parteDelAnimal = parteDelAnimal;
}

Carne::~Carne()
{
}

void Carne::setNombreAnimala(string nombreDelAnimal)
{
	this->nombreAnimal = nombreDelAnimal;
}

void Carne::setParteDelAnimal(string parteDelAnimal)
{
	this->parteDelAnimal = parteDelAnimal;
}

string Carne::getNombreDelAnimal()
{
    return this->nombreAnimal;
}

string Carne::getParteDelAnimal()
{
    return this->parteDelAnimal;
}
