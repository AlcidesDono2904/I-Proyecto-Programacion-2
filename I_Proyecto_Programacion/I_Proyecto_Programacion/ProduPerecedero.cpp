#include "ProduPerecedero.h"

ProduPerecedero::ProduPerecedero():Producto(), nacional(false), peso(0), ptrPere(NULL)
{
}

ProduPerecedero::ProduPerecedero(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio)
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
}

ProduPerecedero::~ProduPerecedero()
{
	ptrPere = NULL;
}

void ProduPerecedero::setNacional(bool nacional)
{
	this->nacional = nacional;
}

void ProduPerecedero::setPeso(double peso)
{
	this->peso = peso;
}

bool ProduPerecedero::getNacional()
{
    return nacional;
}

double ProduPerecedero::getPeso()
{
    return peso;
}
