#include "Abarrote.h"

Abarrote::Abarrote() :ProduPerecedero(), nombreEmpresa("")
{
}

Abarrote::Abarrote(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio, string nombreEmpresa)
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
	this->nombreEmpresa = nombreEmpresa;
	ptrPere = new Perecedero(dia, mes, anio);
}

Abarrote::~Abarrote()
{
}

void Abarrote::setNombreEmpresa(string nombreEmpresa)
{
	this->nombreEmpresa = nombreEmpresa;
}

string Abarrote::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

string Abarrote::toString()
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
		"\nNombre de la Empresa: " << nombreEmpresa <<
		"\nFecha de vencimiento: " << *ptrPere << endl;
	return s.str();
}

Producto* Abarrote::clonar()
{
	return new Abarrote(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia,limite, nacional, peso, fechaIngreso->getDia(), fechaIngreso->getMes(), fechaIngreso->getAnio(), nombreEmpresa );
}
