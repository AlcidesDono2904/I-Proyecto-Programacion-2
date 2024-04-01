#include "Producto.h"

Producto::Producto(){
	this->codigo = "";
	this->nombreComercial = "";
	this->descripcion = "";
	this->precioCosto = 0;
	this->categoria = "";
	this->existencia = 0;
	this->limite = 0;
	this->fechaIngreso = new Fecha;
}


Producto::Producto(std::string codigo, std::string nombre, std::string descripcion, double precio, std::string categoria, int existencia, int limite){
	this->codigo = codigo;
	this->nombreComercial = nombre;
	this->descripcion = descripcion;
	this->precioCosto = precio;
	this->categoria = categoria;
	this->existencia = existencia;
	this->limite = limite;
	this->fechaIngreso = new Fecha;
}

Producto::~Producto(){
	if (fechaIngreso) delete fechaIngreso;
}

std::string Producto::getCodigo(){
	return codigo;
}

std::string Producto::getNombreComercial(){
	return nombreComercial;
}

std::string Producto::getDescripcion(){
	return descripcion;
}

double Producto::getPrecioCosto(){
	return precioCosto;
}

std::string Producto::getCategoria(){
	return categoria;
}

int Producto::getExistencia(){
	return existencia;
}

int Producto::getLimite(){
	return limite;
}

Fecha* Producto::getFechaIngreso(){
	return fechaIngreso;
}

void Producto::setCodigo(std::string codigo){
	this->codigo = codigo;
}

void Producto::setNombreComercial(std::string nombre){
	this->nombreComercial = nombre;
}

void Producto::setDescripcion(std::string descripcion){
	this->descripcion = descripcion;
}

void Producto::setPrecioCosto(double precio){
	this->precioCosto = precio;
}

void Producto::setCategoria(std::string categoria){
	this->categoria = categoria;
}

void Producto::setExistencia(int existencia){
	this->existencia = existencia;
}

void Producto::setLimite(int limite){
	this->limite = limite;
}

void Producto::setFechaIngreso(Fecha* fecha){
	this->fechaIngreso = fecha;
}

std::string Producto::toString(){
	std::stringstream ss;
	ss << "Codigo: " << codigo <<
		"\nNombre: " << nombreComercial <<
		"\nDescripcion: " << descripcion <<
		"\nPrecio: " << precioCosto <<
		"\nCategoria: " << categoria <<
		"\nExistencia: " << existencia <<
		"\nLimite: " << limite <<
		"\nFecha de ingreso: " << fechaIngreso;
		
	return ss.str();
}
