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
