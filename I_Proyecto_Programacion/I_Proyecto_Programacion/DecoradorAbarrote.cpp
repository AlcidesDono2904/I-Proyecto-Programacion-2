#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(ComponenteAbstracto* dec, Abarrote* aba ) {
	decorado = dec;
	abarrote = aba;
}

std::string DecoradorAbarrote::toString() {
	return "Abarrote: " + abarrote->toString() + "\n" + decorado->toString();
}

DecoradorAbarrote::~DecoradorAbarrote() {}

ComponenteAbstracto* DecoradorAbarrote::getDecorado()
{
	return decorado;
}

Abarrote* DecoradorAbarrote::getAbarrote()
{
	return abarrote;
}

ComponenteAbstracto* DecoradorAbarrote::clonar()
{
	return new DecoradorAbarrote(decorado, abarrote);
}


void DecoradorAbarrote::guardarCarrito(ostream& archi) {
	this->abarrote->guardarProducto(archi);
	this->decorado->guardarCarrito(archi);
}

ComponenteAbstracto* DecoradorAbarrote::leerCarrito(istream& archi)
{
	Abarrote* aba = nullptr;
	ComponenteAbstracto* deco = nullptr;
	aba->leerProductoAbarrote(archi);
	deco->leerCarrito(archi);
	return new DecoradorAbarrote(deco, aba);
}
