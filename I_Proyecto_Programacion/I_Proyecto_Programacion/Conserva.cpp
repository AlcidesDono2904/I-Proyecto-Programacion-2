#include "Conserva.h"

Conserva::Conserva() :Producto() {
	envasado = false;
}

Conserva::Conserva(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool envasado)
:Producto(codigo, nombre, descripcion, precio, categoria, existencia, limite) {
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
		"\nPorcentaje de ganancia: " << Categoria::porceGanancia(categoria) <<
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
	archi <<  01 << '\t'
		<< this->codigo << '\t'
		<< this->nombreComercial << '\t'
		<< this->descripcion << '\t'
		<< this->precioCosto << '\t'
		<< this->existencia << '\t'
		<< this->limite << '\t'
		<< this->envasado << endl;

}

Producto* Conserva::leerProductoConserva(istream& archi)
{
	string cod, nombre, descrip, precio, categ, exist, limi, nombreE, nacio, pes, envasa, aux;
	
	getline(archi, cod, '\t');     
	getline(archi, nombre, '\t'); 
	getline(archi, descrip, '\t'); 
	getline(archi, precio, '\t');  
	getline(archi, exist, '\t');  
	getline(archi, limi, '\t');    
	getline(archi, envasa, '\n');  


	stringstream r1(precio);
	double pre;
	r1 >> pre;

	stringstream r2(exist);
	int exi;
	r2 >> exi;

	stringstream r3(limi);
	int lim;
	r3 >> lim;


	stringstream r4(envasa);
	bool enva;
	r4 >> enva;

	stringstream r(categ);
	string cate;
	r >> cate;
	
	return new Conserva(cod, nombre, descrip, pre, "01", exi, lim, enva);
}
