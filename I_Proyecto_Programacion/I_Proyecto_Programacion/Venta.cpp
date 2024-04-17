#include "Venta.h"

Venta::Venta():carrito(nullptr), numeroFat(0), cantidadProductos(0), importe(0), IVA(0), subtotal(0), cedulaCliente("")
{
}

Venta::Venta(ComponenteAbstracto* carri, int numFac, int cantProd, string cedulaCli)
:carrito(carri), numeroFat(numFac), cantidadProductos(cantProd), cedulaCliente(cedulaCli)
{
    subtotal = dynamic_cast<Producto*>(carrito)->getPrecioCosto();
    importe = subtotal * 0.13 + subtotal;
}

Venta::Venta(const Venta& otra)
{
    this->numeroFat = otra.numeroFat;
    this->cantidadProductos = otra.cantidadProductos;
    this->importe = otra.importe;
    this->IVA = otra.IVA;
    this->subtotal = otra.subtotal;
    this->total = otra.total;
    this->cedulaCliente = otra.cedulaCliente;
    if (this->carrito != nullptr)
        this->carrito = otra.carrito->clonar();
    else
        this->carrito = nullptr;
}

Venta::~Venta()
{
    if (carrito == nullptr) delete carrito; 
}

ComponenteAbstracto* Venta::getCarrito()
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


void Venta::setCarrito(ComponenteAbstracto* carri)
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
        << "Subtotal: " << subtotal << endl
        << "Total: " << total << endl;
    s << "Carrito: " << endl;
    if (carrito!=nullptr)
        s << carrito->toString();
    return s.str();
}
