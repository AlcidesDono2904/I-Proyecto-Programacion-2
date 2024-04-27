#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(ComponenteAbstracto* dec, Embutido* emb) {
	decorado = dec;
	embutido = emb;
}

DecoradorEmbutido::~DecoradorEmbutido() {}

std::string DecoradorEmbutido::toString() {
	return "Embutido: " + embutido->toString() + "\n" + decorado->toString();
}

ComponenteAbstracto* DecoradorEmbutido::clonar()
{
	return new DecoradorEmbutido(decorado, embutido);
}
//double DecoradorEmbutido::CalcularPrecioCarrito(int canti)
//{
//	return embutido->getPrecioCosto() * canti;
//}

//