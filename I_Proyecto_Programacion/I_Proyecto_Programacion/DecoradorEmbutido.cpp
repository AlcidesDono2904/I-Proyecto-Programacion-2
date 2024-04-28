#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(ComponenteAbstracto* dec, Embutido* emb) {
	decorado = dec;
	embutido = emb;
}

DecoradorEmbutido::~DecoradorEmbutido() {}

std::string DecoradorEmbutido::toString() {
	return "Embutido: " + embutido->toString() + "\n" + decorado->toString();
}

Embutido* DecoradorEmbutido::getEmbutido()
{
	return embutido;
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
	this->decorado->guardarCarrito(archi);
}

ComponenteAbstracto* DecoradorEmbutido::leerCarrito(istream& archi)
{
	Embutido* embu = nullptr;
	ComponenteAbstracto* deco = nullptr;
	embu->leerProductoEmbutido(archi);
	deco->leerCarrito(archi);
	return new DecoradorEmbutido(deco, embu);
}
