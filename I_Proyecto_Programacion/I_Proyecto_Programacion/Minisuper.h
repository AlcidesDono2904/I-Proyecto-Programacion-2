#pragma once
#include "headers.h"

class Minisuper {
private:
	ListaEnlazada<Producto>* productos;
	ListaEnlazada<Venta>* ventas;
public:
	Minisuper();
	virtual ~Minisuper();
	ListaEnlazada<Producto>* getProductos();
	ListaEnlazada<Venta>* getVentas();

};