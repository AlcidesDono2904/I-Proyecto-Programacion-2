#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(DecoradorAbstracto* dec, Embutido* emb) {
	decorado = dec;
	embutido = emb;
}

DecoradorEmbutido::~DecoradorEmbutido() {}

std::string DecoradorEmbutido::toString() {
	return "Embutido: " + embutido->getDescripcion() + "\n" + decorado->toString();
}