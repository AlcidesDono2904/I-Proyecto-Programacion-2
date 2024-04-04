#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(ComponenteAbstracto* dec, Embutido* emb) {
	decorado = dec;
	embutido = emb;
}

DecoradorEmbutido::~DecoradorEmbutido() {}

std::string DecoradorEmbutido::toString() {
	return "Embutido: " + embutido->toString() + "\n" + decorado->toString();
}