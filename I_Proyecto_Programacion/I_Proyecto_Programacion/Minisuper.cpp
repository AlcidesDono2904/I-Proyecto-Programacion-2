#include "Minisuper.h"

Minisuper::Minisuper(string nom)
{
    productos = new ListaEnlazada<Producto>();
    ventas = new ListaEnlazada<Venta>();
    nombre = nom;
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

std::string Minisuper::reportarDebajoExistencia() {
    if(ventas->estaVacio()) return "No hay productos\n";
    std::stringstream ss;
    ss << "";
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
		if (productos->obtener(i)->getExistencia() < productos->obtener(i)->getLimite()) {
			ss << "====================\n";
			ss << productos->obtener(i)->toString() << '\n';
		}
	}
    if (ss.str()=="") return "No hay productos por debajo de su existencia\n";
    return ss.str();
}

std::string Minisuper::reportarVentas(std::string cedula) {//El metodo fue hecho antes de crear el de buscar...
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

void Minisuper::insertarVentaOrdenada(ListaEnlazada<Venta>* ventasOrden, const Venta* venta)
{
    Venta* ventaCopia = new Venta(*venta);
    if (ventasOrden->estaVacio() || ventasOrden->inicio()->getImporte() < ventaCopia->getImporte()) {
        ventasOrden->agregarInicio(ventaCopia);
    }
    else{ 
        Nodo<Venta>* ptr = ventasOrden->getPrimero();
        while (ptr->getSig() != nullptr && ptr->getSig()->getDato()->getImporte() > ventaCopia->getImporte()) {
            ptr = ptr->getSig();
        }
        Nodo<Venta>* nuevo = new Nodo<Venta>(ventaCopia);
        nuevo->setSig(ptr->getSig());
        ptr->setSig(nuevo);
    }
}

string Minisuper::mejoresCincoClientes()
{
    stringstream s;
   
    if(ventas->estaVacio()) return "No hay ventas\n";
    ListaEnlazada<Venta>* ventasOrden = new ListaEnlazada<Venta>();
    for (unsigned int i = 0; i < ventas->cantidad(); i++) {
        Venta* ptrA = ventas->obtener(i);
        insertarVentaOrdenada(ventasOrden, ptrA);
    }
    s << "Los mejores 5 clientes son: " << endl;
    for (unsigned int i = 0; i < ventas->cantidad() || i< 5; i++) {
        s << ventasOrden->obtener(i)->getCedulaCliente() << "con un importe de " << ventasOrden->obtener(i)->getImporte() << endl;
        s << "------------------" << endl;
    }
    //sumar las ventas de cada cliente
    delete ventasOrden;
    return s.str();
}

Producto* Minisuper::getProductoPorCodigo(string cod)
{
    if (productos->estaVacio()) return nullptr;

    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        if (productos->obtener(i)->getCodigo() == cod )
            return productos->obtener(i);
    }
    return nullptr;
}

void Minisuper::ingresarVenta(Venta* venta)
{
    ventas->agregarInicio(venta);
}

Producto* Minisuper::buscarProducto(string codigo) {
    if (productos->estaVacio()) throw "Error: la lista esta vacia";
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        if (productos->obtener(i)->getCodigo() == codigo or productos->obtener(i)->getNombreComercial() == codigo) {
            return productos->obtener(i);
        }
    }
    throw "Error: codigo/nombre incorrecto o el producto no existe";
}