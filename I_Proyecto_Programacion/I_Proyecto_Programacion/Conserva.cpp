#include "Conserva.h"

Conserva::Conserva() :Producto() {
	envasado = false;
}

Conserva::Conserva(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool envasado)
{
	this->codigo = codigo;
	this->nombreComercial = nombre;
	this->descripcion = descripcion;
	this->precioCosto = precio;
	this->categoria = categoria;
	this->existencia = existencia;
	this->limite = limite;
	this->fechaIngreso = new Fecha;
	this->envasado = envasado;
}

Conserva::~Conserva()
{
}

void Conserva::setEnvasado(bool envasado)
{
	this->envasado = envasado;
}

bool Conserva::getEnvasado()
{
	return this->envasado;
}

string Conserva::toString()
{
	stringstream s;
	s<< "Codigo: " << codigo <<
		"\nNombre: " << nombreComercial <<
		"\nDescripcion: " << descripcion <<
		"\nPrecio: " << precioCosto <<
		"\nCategoria: " << categoria <<
		"\nExistencia: " << existencia <<
		"\nLimite: " << limite <<
		"\nFecha de ingreso: " << *fechaIngreso<<
		"\nEnvasado: ";
	if (envasado) s << "Si" << endl;
	else s << "No " << endl;
	return s.str();
}

Producto* Conserva::clonar()
{
	return new Conserva(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, envasado);
}

void Conserva::guardarProducto(ostream& archi)
{
}

Producto* Conserva::leerProductoConserva(istream& archi)
{
	return nullptr;
}
