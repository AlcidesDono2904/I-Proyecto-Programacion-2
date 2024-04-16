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

//void modificar

std::string Minisuper::reportarProductos() {
    if (productos->estaVacio()) return "No hay productos\n";
	std::stringstream ss;
    ss<<"Productos:\n";
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        ss<<"=====Producto "<<i+1<<"=====\n";
        ss << productos->obtener(i)->toString() << '\n';
	}
	return ss.str();
}

std::string Minisuper::reportarCategoria(std::string categoria) {
	if (productos->estaVacio()) return "No hay productos\n";
    if (categoria != "01" and categoria != "02" and categoria != "03")
        throw "Error: categoria no valida\n";
	std::stringstream ss;
	ss << "Productos de la categoria " << categoria << ":\n";
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        if (productos->obtener(i)->getCategoria() == categoria) {
            ss << "====================\n";
			ss << productos->obtener(i)->toString() << '\n';
		}
	}
	return ss.str();
}

//reportarDebajoExistencia
/*
std::string Minisuper::generarVenta(Venta* venta, std::string cedula) {//lo hago otro dia
    return "";
}*/

std::string Minisuper::reportarVentas(std::string cedula) {
    if (ventas->estaVacio()) return "No hay ventas\n";

    bool noExiste = false;
    for (unsigned i = 0; i < ventas->cantidad() and !noExiste; i++)
        noExiste = (ventas->obtener(i)->getCedulaCliente() == cedula);
    if(!noExiste) throw "Error: no se encontro cliente con cedula " + cedula + '\n';

    std::stringstream ss;
	ss << "Ventas de " << cedula << ":\n";
    for (unsigned int i = 0; i < ventas->cantidad(); i++) {
        if (ventas->obtener(i)->getCedulaCliente() == cedula) {
			ss << "====================\n";
			ss << ventas->obtener(i)->toString() << '\n';
		}
	}
	return ss.str();
}

void Minisuper::insertarVentaOrdenada(ListaEnlazada<Venta>* ventasOrden, Venta* venta)
{
    if (ventasOrden->estaVacio() || ventasOrden->inicio()->getImporte() < venta->getImporte()) {
        ventasOrden->agregarInicio(venta);
    }
    else{ 
        Nodo<Venta>* ptr = ventasOrden->getPrimero();
        while (ptr->getSig() != nullptr && ptr->getSig()->getDato()->getImporte() > venta->getImporte()) {
            ptr = ptr->getSig();
        }
        Nodo<Venta>* nuevo = new Nodo<Venta>(venta);
        nuevo->setSig(ptr->getSig());
        ptr->setSig(nuevo);
    }
}

string Minisuper::mejoresCincoClientes()
{
    stringstream s;
   
    if(ventas->estaVacio()) return "No hay ventas\n";
    ListaEnlazada<Venta>* ventasOrden = new ListaEnlazada<Venta>();
    for (int i = 0; i < ventas->cantidad(); i++) {
        Venta* ptrA = ventas->obtener(i);
        insertarVentaOrdenada(ventasOrden, ptrA);
    }
    s << "Los mejores 5 clientes son: " << endl;
    for (int i = 0; i < ventas->cantidad() || i< 5; i++) {
        s << ventasOrden->obtener(i)->getCedulaCliente() << "con un importe de " << ventasOrden->obtener(i)->getImporte() << endl;
        s << "------------------" << endl;
    }

    delete ventasOrden;
    return s.str();
}
