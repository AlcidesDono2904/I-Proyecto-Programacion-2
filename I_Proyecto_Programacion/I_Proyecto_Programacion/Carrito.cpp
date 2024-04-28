#include "Carrito.h"

Carrito::Carrito() {
}

Carrito::~Carrito() {
}

ComponenteAbstracto* Carrito::getDecorado()
{
	return nullptr;
}

std::string Carrito::toString() {
	return "Fin del carrito\n";
}

ComponenteAbstracto* Carrito::clonar()
{
	return new Carrito();
}

void Carrito::guardarCarrito(ostream&)
{
}
