#include "Embutido.h"

Embutido::Embutido():Carne(), marca(""), ptrEmpaque(NULL)
{
}


Embutido::Embutido(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio, string nombreEmpresa, string nombreDelAnimal, string parteDelAnimal, string marca, bool tripa)
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
	this->marca = marca;
	ptrEmpaque = new Empaque(tripa);
}

Embutido::~Embutido()
{
	if (ptrEmpaque) delete ptrEmpaque;
}

void Embutido::setMarca(string marca)
{
	this->marca = marca;
}

string Embutido::getMarca()
{
    return marca;
}

string Embutido::toString()
{
	stringstream s;
	s << "Codigo: " << codigo <<
		"\nNombre: " << nombreComercial <<
		"\nDescripcion: " << descripcion <<
		"\nPrecio: " << precioCosto <<
		"\nCategoria: " << categoria <<
		"\nExistencia: " << existencia <<
		"\nLimite: " << limite <<
		"\nFecha de ingreso: " << *fechaIngreso <<
		"\nFecha de vencimiento: " << *ptrPere <<
		"\nNombre del Animal: " << nombreAnimal <<
		"\nParte del Animal: " << parteDelAnimal <<
		"\nMarca: " << marca << '\n'
		<< *ptrEmpaque << endl;
	return s.str();
}
