#include "DecoradorConserva.h"

DecoradorConserva::DecoradorConserva(ComponenteAbstracto* dec, Conserva* cons) {
	decorado = dec;
	conserva = cons;
}

DecoradorConserva::~DecoradorConserva() {}

std::string DecoradorConserva::toString() {
	return "Conserva: " + conserva->toString() + "\n" + decorado->toString();
}