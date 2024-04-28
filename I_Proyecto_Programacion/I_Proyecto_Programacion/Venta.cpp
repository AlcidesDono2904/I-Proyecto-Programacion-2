#include "Venta.h"

Venta::Venta():carrito(nullptr), cantidadProductos(0), importe(0), IVA(0), subtotal(0), cedulaCliente("")
{
}

Venta::Venta(ComponenteAbstracto* carri, int cantProd, string cedulaCli)
:carrito(carri), cantidadProductos(cantProd), cedulaCliente(cedulaCli)
{
    
    
    IVA = 0.13;
}

Venta::Venta(const Venta& otra)
{
   
    this->cantidadProductos = otra.cantidadProductos;
    this->importe = otra.importe;
    this->IVA = otra.IVA;
    this->subtotal = otra.subtotal;
    this->cedulaCliente = otra.cedulaCliente;
    if (this->carrito != nullptr)
        this->carrito = otra.carrito->clonar();
    else
        this->carrito = nullptr;
}

Venta::~Venta()
{
    if (carrito != nullptr) delete carrito; 
}

ComponenteAbstracto* Venta::getCarrito()
{
    return carrito;
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
    s << "----FACTURA----" << endl
        << "Cantidad de productos: " << cantidadProductos << endl
        << "IVA: " << IVA << endl
        << "Subtotal: " << subtotal << endl
        << "Total: " << importe << endl << endl;
    s << "-----CARRITO---- " << endl;
    if (carrito!=nullptr)
        s << carrito->toString()<<endl;
    return s.str();
}

void Venta::guardarVenta(ofstream& archi)
{
    stringstream s;

    s<<cantidadProductos<<endl;
    s<<importe<<endl;
    s<<IVA<<endl;
    s<<subtotal<<endl;
    s<<cedulaCliente<<endl;
    s<<carrito->guardarCarrito()<<endl;
}