#include "Minisuper.h"

Minisuper::Minisuper()
{
    productos = new ListaEnlazada<Producto>();
    ventas = new ListaEnlazada<Venta>();
}

Minisuper::~Minisuper()
{
    if (!productos->estaVacio())
        delete productos;
    if (!ventas->estaVacio())
        delete ventas;
}

ListaEnlazada<Producto>* Minisuper::getProductos()
{
    return productos;
}

ListaEnlazada<Venta>* Minisuper::getVentas()
{
    return ventas;
}
