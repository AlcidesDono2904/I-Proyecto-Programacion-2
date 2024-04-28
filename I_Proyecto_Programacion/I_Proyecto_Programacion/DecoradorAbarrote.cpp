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

ComponenteAbstracto* DecoradorAbarrote::clonar()
{
	return new DecoradorAbarrote(decorado, abarrote);
}


void DecoradorAbarrote::guardarCarrito(ostream& archi) {
	this->abarrote->guardarProducto(archi);
}

ComponenteAbstracto* DecoradorAbarrote::leerCarrito(istream&)
{
	return nullptr;
}
