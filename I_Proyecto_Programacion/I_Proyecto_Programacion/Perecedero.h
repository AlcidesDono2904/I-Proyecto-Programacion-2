#pragma once
#include "Fecha.h"
#include <sstream>
#include <iostream>

using namespace std;

class Perecedero
{
protected:
	Fecha* vencimiento;
public:
	Perecedero(Fecha* vencimiento);
	Perecedero(int dia, int mes, int anio);
	virtual ~Perecedero();
	virtual string toString();

	friend ostream& operator<<(ostream& salida, const Perecedero& f);
};

