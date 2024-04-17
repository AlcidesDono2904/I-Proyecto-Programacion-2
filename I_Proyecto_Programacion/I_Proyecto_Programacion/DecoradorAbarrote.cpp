#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(ComponenteAbstracto* dec, Abarrote* aba ) {
	decorado = dec;
	abarrote = aba;
}

std::string DecoradorAbarrote::toString() {
	return "Abarrote: " + abarrote->toString() + "\n" + decorado->toString();
}

DecoradorAbarrote::~DecoradorAbarrote() {}

ComponenteAbstracto* DecoradorAbarrote::clonar()
{
	return new DecoradorAbarrote(decorado, abarrote);
}
