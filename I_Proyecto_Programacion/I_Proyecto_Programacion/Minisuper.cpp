#include "Minisuper.h"

Minisuper::Minisuper(string nom)
{
    productos = new ListaEnlazada<Producto>();
    ventas = new ListaEnlazada<Venta>();
    nombre = nom;
    this->leerProductos();
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
    if (productos->estaVacio()) return nullptr;
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        if (productos->obtener(i)->getCodigo() == codigo or productos->obtener(i)->getNombreComercial() == codigo) {
            return productos->sacarDato(i);
        }
    }
    return nullptr;
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
        return "Error: categoria no valida\n";
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
    if(!noExiste) return "No hay ningun cliente con esa cedula";

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
    
   
    
    // string cedulaCliente = ventas->obtener(i)->getCedulaCliente();
    //for (unsigned int i = 0; i < ventas->cantidad(); ++i) {
    //    const Venta* venta = ventas->obtener(i);
    //    std::string cedulaCliente = venta->getCedulaCliente();

    //    // Buscar si la cédula de cliente ya está en el arreglo de mejores clientes
    //    for (int j = 0; j < MAX_CLIENTES; ++j) {
    //        if (mejoresClientes[j].first == cedulaCliente) {
    //            // Si la cédula de cliente ya está en el arreglo, incrementar su cantidad de ventas
    //            ++mejoresClientes[j].second;
    //            break;
    //        }
    //        else if (mejoresClientes[j].second == 0) {
    //            // Si encontramos una posición vacía en el arreglo, agregar una nueva entrada con una venta
    //            mejoresClientes[j].first = cedulaCliente;
    //            mejoresClientes[j].second = 1;
    //            break;
    //        }
    //    }
    //}
    ////ListaEnlazada<Venta>* ventasOrden = new ListaEnlazada<Venta>();
    //for (unsigned int i = 0; i < ventas->cantidad(); i++) {
    //    Venta* ptrA = ventas->obtener(i);
    //    insertarVentaOrdenada(ventasOrden, ptrA);
    //}
    //s << "Los mejores 5 clientes son: " << endl;
    //for (unsigned int i = 0; i < ventas->cantidad() || i< 5; i++) {
    //    s << ventasOrden->obtener(i)->getCedulaCliente() << "con un importe de " << ventasOrden->obtener(i)->getImporte() << endl;
    //    s << "------------------" << endl;
    //}
    ////sumar las ventas de cada cliente
    //delete ventasOrden;


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

bool Minisuper::verificarCodigoUnico(string cod)
{
    bool unico = true;
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        if (productos->obtener(i)->getCodigo() == cod)
            unico = false;
    }
    return unico;
}


void Minisuper::guardarProductos()
{
    ofstream archi;
    archi.open("./Productos.txt");
    for (unsigned int i = 0; i < productos->cantidad(); i++) {
        productos->obtener(i)->guardarProducto(archi);
    }
}

void Minisuper::leerProductos()
{
    ifstream archi;
    Producto* produ = nullptr;
    string categ;
    archi.open("./Productos.txt");
    if (archi.good()) {
        /*cout << "Archivo abierto" << endl;
        system("Pause");*/
        while (!archi.eof()) {
            getline(archi, categ,'\t');
            stringstream ct(categ);
            int cat;
            ct >> cat;
            /*cout << cat << endl;
            system("Pause");*/
            switch (cat)
            {
            case 01: {
                
                produ = Conserva::leerProductoConserva(archi);
                /*cout << "Conserva leida" << endl;
                system("Pause");*/
                break;
            }
            case 02: {
                produ = Abarrote::leerProductoAbarrote(archi);
                /*cout << "Abarrote leida" << endl;
                system("Pause");*/
                break;
            }
            case 03: {
                produ = Embutido::leerProductoEmbutido(archi);
               /* cout << "Embutido leida" << endl;
                system("Pause");*/
                break;
            }
            default:
            {
                produ = nullptr;
                break;
            }
            }
            if (produ != nullptr && produ->getCodigo() != "") {
                productos->agregarInicio(produ);
               /* cout << "producto agregado" << endl;
                system("Pause");*/
            }
        }
    }
    archi.close();
}

