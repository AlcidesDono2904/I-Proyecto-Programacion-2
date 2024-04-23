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

void Abarrote::guardarProducto(ostream& archi)
{
	archi << this->categoria << '\t'
		<< this->nombreComercial << '\t'
		<< this->descripcion << '\t'
		<< this->precioCosto << '\t'
		<< this->codigo << '\t'
		<< this->existencia << '\t'
		<< this->limite << '\t'
		<< this->nacional << '\t'
		<< this->peso << '\t';	
	this->ptrPere->getVencimiento()->guardarFecha(archi);
	archi << this->nombreEmpresa << '\n';
	
}

Producto* Abarrote::leerProductoAbarrote(istream& archi)
{
	string cod, nombre, descrip, precio, categ, exist, limi, nombreE, nacio, pes;
	Fecha* fech;
	
	getline(archi, categ, '\t');
	getline(archi, nombre, '\t');
	getline(archi, descrip, '\t');
	getline(archi, precio, '\t');
	getline(archi, cod, '\t');
	getline(archi, exist, '\t');
	getline(archi, limi, '\t');
	getline(archi, nacio, '\t');
	getline(archi, pes, '\t');
	
	fech = Fecha::leerFecha(archi);
	getline(archi, nombreE, '\n');
	

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

	


	return new Abarrote(cod, nombre, descrip, pre, categ, exi, lim, nac, pe, fech->getDia(), fech->getMes(), fech->getAnio(), nombreE);

}
