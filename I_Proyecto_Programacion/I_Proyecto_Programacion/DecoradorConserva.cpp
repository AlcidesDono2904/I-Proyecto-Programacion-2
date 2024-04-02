#include "DecoradorConserva.h"

DecoradorConserva::DecoradorConserva(DecoradorAbstracto* dec, Conserva* cons) {
	decorado = dec;
	conserva = cons;
}

DecoradorConserva::~DecoradorConserva() {}

std::string DecoradorConserva::toString() {
	return "Conserva: " + conserva->getDescripcion() + "\n" + decorado->toString();
}