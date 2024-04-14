#include "Venta.h"

Venta::Venta():carrito(nullptr), numeroFat(0), cantidadProductos(0), importe(0), IVA(0), subtotal(0), cedulaCliente("")
{
}

Venta::Venta(ListaEnlazada<ComponenteAbstracto>* carri, int numFac, int cantProd, double imp, double iva, double subto, string cedulaCli)
:carrito(carri), numeroFat(numFac), cantidadProductos(cantProd), importe(imp), IVA(iva), subtotal(subto), cedulaCliente(cedulaCli)
{
}

Venta::~Venta()
{
    if (carrito == nullptr) delete carrito; 
}

ListaEnlazada<ComponenteAbstracto>* Venta::getCarrito()
{
    return carrito;
}

int Venta::getNumeroFact()
{
    return numeroFat;
}

string Venta::getCedulaCliente()
{
    return cedulaCliente;
}

double Venta::getImporte()
{
    return importe;
}

double Venta::getIVA()
{
    return IVA;
}

double Venta::getSubtotal()
{
    return subtotal;
}

void Venta::setCarrito(ListaEnlazada<ComponenteAbstracto>* carri)
{
    carrito = carri;
}

void Venta::setNumFact(int numFac)
{
    numeroFat = numFac;
}

void Venta::setCantidadProductos(int cantProd)
{
    cantidadProductos = cantProd;
}

void Venta::setCedulaCliente(string cedulaCli)
{
    cedulaCliente = cedulaCli;
}

void Venta::setImporte(double imp)
{
    importe = imp;
}

void Venta::setIVA(double iva)
{
    IVA = iva;
}

void Venta::setSubtotal(double subto)
{
    subtotal = subto;
}

string Venta::toString() const
{
    stringstream s;
    s << "Numero de factura: " << numeroFat << endl
        << "Cantidad de productos: " << cantidadProductos << endl
        << "Importe: " << importe << endl
        << "IVA: " << IVA << endl
        << "Subtotal: " << subtotal << endl;
    s << "Carrito: " << endl;
    if (!carrito->estaVacio())
        s << carrito->sacarDato(1)->toString();
    return s.str();
}
