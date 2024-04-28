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

Conserva* DecoradorConserva::getConserva()
{
	return conserva;
}

ComponenteAbstracto* DecoradorConserva::clonar()
{
	return new DecoradorConserva(decorado, conserva);
}

void DecoradorConserva::guardarCarrito(ostream& archi)
{
	this->conserva->guardarProducto(archi);
	this->decorado->guardarCarrito(archi);
}

ComponenteAbstracto* DecoradorConserva::leerCarrito(istream& archi)
{
	Conserva* conse = nullptr;
	ComponenteAbstracto* deco = nullptr;
	conse->leerProductoConserva(archi);
	deco->leerCarrito(archi);
	return new DecoradorConserva(deco, conse);
}

