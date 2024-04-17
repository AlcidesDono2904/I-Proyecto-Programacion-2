#include "Perecedero.h"

Perecedero::Perecedero(Fecha* vencimiento)
{
	this->vencimiento = vencimiento;
}

Perecedero::Perecedero(int dia, int mes, int anio)
{
	vencimiento = new Fecha(dia, mes, anio);
}

Fecha* Perecedero::getVencimiento()
{
	return vencimiento;
}

Perecedero::~Perecedero()
{
}

string Perecedero::toString()
{
	stringstream s;
	s << vencimiento;
	return s.str();
}

ostream& operator<<(ostream& salida, const Perecedero& f)
{
	salida << f.vencimiento->getDia() << "/" << f.vencimiento->getMes() << "/" << f.vencimiento->getAnio();
	return salida;
}
