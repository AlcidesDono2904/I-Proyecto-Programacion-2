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
	archi << this->categoria << '\t'
		<< this->nombreComercial << '\t'
		<< this->descripcion << '\t'
		<< this->precioCosto << '\t'
		<< this->codigo << '\t'
		<< this->existencia << '\t'
		<< this->limite << '\t'
		<< this->envasado << '\n';
	/*
	this->fechaIngreso->guardarFecha(archi);*/

}

Producto* Conserva::leerProductoConserva(istream& archi)
{
	string cod, nombre, descrip, precio, categ, exist, limi, nombreE, nacio, pes, envasa;
	

	getline(archi, categ, '\t');
	getline(archi, nombre, '\t');
	getline(archi, descrip, '\t');
	getline(archi, precio, '\t');
	getline(archi, cod, '\t');
	getline(archi, exist, '\t');
	getline(archi, limi, '\t');
	getline(archi, nacio, '\t');
	getline(archi, pes, '\t');
	getline(archi, envasa, '\n');
	//fech = Fecha::leerFecha(archi);


	stringstream r1(precio);
	double pre;
	r1 >> pre;

	stringstream r2(exist);
	int exi;
	r2 >> exi;

	stringstream r3(limi);
	int lim;
	r3 >> lim;

	stringstream r5(nacio);
	bool nac;
	r5 >> nac;

	stringstream r6(pes);
	double pe;
	r6 >> pe;

	stringstream r4(envasa);
	bool enva;
	r4 >> enva;

	
	return new Conserva(cod, nombre, descrip, pre, categ, exi, lim, enva);
}
