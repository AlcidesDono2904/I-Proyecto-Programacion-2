#pragma once
#include "ProduPerecedero.h"

class Abarrote: public ProduPerecedero
{
private:
	string nombreEmpresa;
public:
	Abarrote();
	Abarrote(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio, string nombreEmpresa);
	virtual ~Abarrote();
	void setNombreEmpresa(string nombreEmpresa);
	string getNombreEmpresa();
	string toString();
};

