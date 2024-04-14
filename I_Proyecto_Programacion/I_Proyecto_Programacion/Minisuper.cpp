#include "Minisuper.h"

Minisuper::Minisuper()
{
    productos = new ListaEnlazada<Producto>();
    ventas = new ListaEnlazada<Venta>();
}

Minisuper::~Minisuper()
{
    if (productos != nullptr) delete productos;
    if (ventas!=nullptr) delete ventas;
}

ListaEnlazada<Producto>* Minisuper::getProductos()
{
    return productos;
}

ListaEnlazada<Venta>* Minisuper::getVentas()
{
    return ventas;
}

void Minisuper::ingresarProducto(Producto* producto){
	productos->agregarInicio(producto);
}

Producto* Minisuper::eliminarProducto(string codigo) {//Recibe codigo como codigo o nombre comercial
    if (productos->estaVacio()) throw "Error: no hay productos para eliminar\n";
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        if (productos->obtener(i)->getCodigo() == codigo or productos->obtener(i)->getNombreComercial() == codigo) {
            return productos->sacarDato(i);
        }
    }
    throw "Error: no se encontro el producto\n";
}