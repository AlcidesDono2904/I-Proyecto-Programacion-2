#include "Venta.h"

Venta::Venta():carrito(nullptr), cantidadProductos(0), importe(0), IVA(0), subtotal(0), cedulaCliente(""), numFact(0)
{
}

Venta::Venta(ComponenteAbstracto* carri, int cantProd, string cedulaCli)
:carrito(carri), cantidadProductos(cantProd), cedulaCliente(cedulaCli)
{
    numFact = 0;
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


int Venta::getNumFact()
{
    return numFact;
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


void Venta::setNumFact(int n)
{
    numFact = n;
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
        << "Numero de factura: " << numFact << endl
        << "IVA: " << IVA << endl
        << "Subtotal: " << subtotal << endl
        << "Total: " << importe << endl << endl;
    s << "-----CARRITO---- " << endl;
    if (carrito!=nullptr)
        s << carrito->toString()<<endl;
    return s.str();
}

void Venta::guardarVenta(ostream& archi)
{
    archi << cantidadProductos << '\t'
        << cedulaCliente << '\t'
        << numFact << '\t'
        << subtotal << '\t'
        << importe << endl;
    if (carrito != nullptr) {
        while (carrito->getDecorado() != dynamic_cast<Carrito*>(carrito->getDecorado())) {
            carrito->guardarCarrito(archi);
        }
    }
}

Venta* Venta::leerVenta(istream& archi)
{
    return nullptr;
}
