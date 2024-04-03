#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(ComponenteAbstracto* dec, Abarrote* aba ) {
	decorado = dec;
	abarrote = aba;
}

std::string DecoradorAbarrote::toString() {
	return "Abarrote: " + abarrote->getDescripcion()+ "\n" + decorado->toString();
}

DecoradorAbarrote::~DecoradorAbarrote() {}