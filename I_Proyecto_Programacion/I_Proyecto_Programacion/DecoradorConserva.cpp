#include "DecoradorConserva.h"

DecoradorConserva::DecoradorConserva(ComponenteAbstracto* dec, Conserva* cons) {
	decorado = dec;
	conserva = cons;
}

DecoradorConserva::~DecoradorConserva() {}

std::string DecoradorConserva::toString() {
	return "Conserva: " + conserva->toString() + "\n" + decorado->toString();
}

ComponenteAbstracto* DecoradorConserva::getDecorado()
{
	return decorado;
}

ComponenteAbstracto* DecoradorConserva::clonar()
{
	return new DecoradorConserva(decorado, conserva);
}

void DecoradorConserva::guardarCarrito(ostream& archi)
{
	this->conserva->guardarProducto(archi);
}

ComponenteAbstracto* DecoradorConserva::leerCarrito(istream&)
{
	return nullptr;
}

