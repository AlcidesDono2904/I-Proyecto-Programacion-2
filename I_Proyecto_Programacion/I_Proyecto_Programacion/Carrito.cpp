#include "Carrito.h"

Carrito::Carrito() {
}

Carrito::~Carrito() {
}

std::string Carrito::toString() {
	return "Fin del carrito\n";
}

ComponenteAbstracto* Carrito::clonar()
{
	return new Carrito();
}

//double Carrito::CalcularPrecioCarrito()
//{
//	return 0.0;
//}
