#include "Carne.h"

Carne::Carne()
{
}

Carne::Carne(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio, string nombreDelAnimal, string parteDelAnimal)
:ProduPerecedero( codigo,  nombre, descripcion, precio,  categoria, existencia,  limite,  nacional, peso, dia,  mes,  anio) {
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

string Carne::toString()
{
	return string();
}


