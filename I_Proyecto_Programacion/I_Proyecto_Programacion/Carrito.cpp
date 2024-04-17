#include "Carrito.h"

Carrito::Carrito() {
}

Carrito::~Carrito() {
}

std::string Carrito::toString() {
	return "Fin del carrito";
}

ComponenteAbstracto* Carrito::clonar()
{
	return new Carrito();
}
