#include "Embutido.h"

Embutido::Embutido():Carne(), marca(""), ptrEmpaque(NULL)
{
}


Embutido::Embutido(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio, string nombreDelAnimal, string parteDelAnimal, string marca, bool tripa)
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

Producto* Embutido::clonar()
{
	return new Embutido(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, nacional, peso, ptrPere->getVencimiento()->getDia(), ptrPere->getVencimiento()->getMes(), ptrPere->getVencimiento()->getAnio(), nombreAnimal, parteDelAnimal, marca, ptrEmpaque->getTripa());
}

void Embutido::guardarProducto(ostream& archi)
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
	archi << this->nombreAnimal << '\t'
		<< this->parteDelAnimal << '\t'
		<< this->marca << '\t'
		<< this->ptrEmpaque->getTripa() << '\n';
}

Producto* Embutido::leerProductoEmbutido(istream& archi)
{
	string cod, nombre, descrip, precio, categ, exist, limi, nombreAni, parteAni, marc, trip, nacio, pes;
	Fecha* fech;
	ProduPerecedero* pere = nullptr;
	Empaque* empa = nullptr;
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
	getline(archi, nombreAni, '\t');
	getline(archi, parteAni, '\t');
	getline(archi, marc, '\t');
	getline(archi, trip, '\n');

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

	stringstream r4(trip);
	bool tri;
	r3 >> tri;

	
	return new Embutido(cod, nombre, descrip, pre, categ, exi, lim, nac, pe, fech->getDia(), fech->getMes(), fech->getAnio(), nombreAni, parteAni, marc, tri);

}
