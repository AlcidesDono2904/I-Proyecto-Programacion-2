#include "ProduPerecedero.h"

ProduPerecedero::ProduPerecedero():Producto(), nacional(false), peso(0), ptrPere(NULL)
{
}

ProduPerecedero::ProduPerecedero(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio)
:Producto(codigo, nombre, descripcion, precio, categoria, existencia, limite) {
	this->nacional = nacional;
	this->peso = peso;
	ptrPere = new Perecedero(dia, mes, anio);
}

ProduPerecedero::~ProduPerecedero()
{
	if (ptrPere) delete ptrPere;
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
