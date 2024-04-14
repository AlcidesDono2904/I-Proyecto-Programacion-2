#ifndef MINISUPER_H
#define MINISUPER_H
#include "Producto.h"
#include "Venta.h"
#include "Lista.h"

class Minisuper {
private:
	ListaEnlazada<Producto>* productos;
	ListaEnlazada<Venta>* ventas;
public:
	Minisuper();
	virtual ~Minisuper();
	ListaEnlazada<Producto>* getProductos();
	ListaEnlazada<Venta>* getVentas();
	void ingresarProducto(Producto* producto);
	Producto* eliminarProducto(string codigo);
	//void modificarProducto(string codigo, Producto* producto);
	
};
#endif