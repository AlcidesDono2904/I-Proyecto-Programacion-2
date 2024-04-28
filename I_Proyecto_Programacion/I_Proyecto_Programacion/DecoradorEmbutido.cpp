#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(ComponenteAbstracto* dec, Embutido* emb) {
	decorado = dec;
	embutido = emb;
}

DecoradorEmbutido::~DecoradorEmbutido() {}

std::string DecoradorEmbutido::toString() {
	return "Embutido: " + embutido->toString() + "\n" + decorado->toString();
}

ComponenteAbstracto* DecoradorEmbutido::getDecorado()
{
	return decorado;
}

ComponenteAbstracto* DecoradorEmbutido::clonar()
{
	return new DecoradorEmbutido(decorado, embutido);
}

void DecoradorEmbutido::guardarCarrito(ostream& archi)
{
	this->embutido->guardarProducto(archi);
}

ComponenteAbstracto* DecoradorEmbutido::leerCarrito(istream&)
{
	return nullptr;
}
