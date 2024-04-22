#include "Interfaz.h"

void Interfaz::msjError() {
	cout<<"Error..."<<endl;
}

int Interfaz::MenuPrincipal()
{
	int opcion = 0;
	cout << "1) Mantenimiento " << endl;
	cout << "2) Ventas " << endl;
	cout << "3) Reportes " << endl;
	cout << "4) Salir " << endl;
	cin >> opcion;
	return opcion;
}

int Interfaz::MenuMantenimiento()
{
	int opcion = 0;
	cout << "1)Ingreso producto" << endl;
	cout << "2)Eliminación de producto " << endl;
	cout << "3)Actualización de producto" << endl;
	cout << "4)Retornar" << endl;
	cin >> opcion;
	return opcion;
}

void Interfaz::VentaGeneraFactura(Minisuper* mini)
{

	int seguir = 0, cant = 0, cantProdu = 0;
	string ced = "", cod = "", categ= "";
	bool sePudo = true;
	Producto* produ = nullptr;
	ComponenteAbstracto* carrito = new Carrito();
	ComponenteAbstracto* productoC = nullptr;
	try {
		if (!mini->getProductos()->estaVacio()) {
			cout << "----Ingrese su cedula para emitir la factura----" << endl;
			cin >> ced;
			do {
				try {
					cout << "----Productos disponibles---- " << endl;
					cout << mini->reportarProductos() << endl;
					cout << "Digite el codigo del producto que desea comprar: " << endl;
					cin >> cod;
					produ = mini->getProductoPorCodigo(cod);
					if (produ == nullptr)
						throw "No hay producto con ese codigo";
					else {
						cout << "Digite la cantidad de este producto que desea comprar: " << endl;
						cin >> cant;
						if (produ->getExistencia() < cant)
							throw "No hay existe tanta cantidad de productos";
						else {
							categ = produ->getCategoria();
							stringstream ct(categ);
							int cat;
							ct >> cat;
							switch (cat)
							{
							case 01: {
								productoC = new DecoradorConserva(carrito, dynamic_cast<Conserva*>(produ));
								break;
							}
							case 02: {
								productoC = new DecoradorAbarrote(carrito, dynamic_cast<Abarrote*>(produ));
								break;
							}
							case 03: {
								productoC = new DecoradorEmbutido(carrito, dynamic_cast<Embutido*>(produ));
								break;
							}
							default:
							{
								break;
							}
							}

							//Modificar lista productos
							mini->getProductoPorCodigo(cod)->setExistencia(produ->getExistencia() - cant);
							//if (mini->getProductoPorCodigo(cod)->getExistencia() == 0) {
							//	//metodo eliminar producto de la lista
							//}

						}
					}
				}
				catch (...) {
					sePudo = false;
					seguir = 0;
				}
				cantProdu += cant;
				cout << "Su carrito va así: " << endl << productoC->toString()
					<< "Si desea seguir añadiendo productos digite 1, si desea terminar su compra y recibir su factura digite 0" << endl;
				cin >> seguir;
			} while (seguir != 0);
			if (sePudo) {
				// Hacer venta y mostrar factura
				Venta* ventaC = new Venta(productoC, 0, cantProdu, ced); //multiplicar el precio por la cantidad de productos
				ventaC->setSubtotal(produ->getPrecioCosto());
				mini->ingresarVenta(ventaC);
				cout << "Aqui esta su factura: " << endl
					<< ventaC->toString() << endl;
				system("pause");
			}
			else throw "No se pudo hacer la venta";

		}

		else throw "No hay productos en el minisuper";
	}
	catch (...) {

	}
	
}

int Interfaz::MenuReportes()
{
	int opcion = 0;
	cout << "1)Reportar todos los productos" << endl;
	cout << "2)Reportar todos los productos de una categoría" << endl;
	cout << "3)Debajo del límite de existencia" << endl;
	cout << "4)Facturas de un cliente" << endl;
	cout << "5)Mejores 5 clientes" << endl;
	cout << "6)Retornar" << endl;
	cin >> opcion;
	return opcion;
}

void Interfaz::mostrarPorCategoria(Minisuper* mini)
{
	string categ = "";
	cout << "Cual categoría desea ver: 01(Conserva), 02(Abarrote), 03(Embutido)" << endl;
	cin >> categ;
	cout << mini->reportarCategoria(categ);
}

void Interfaz::mostrarVentasPorCedula(Minisuper* mini)
{
	string ced = "";
	cin >> ced;
	cout << mini->reportarVentas(ced);
	
}

void Interfaz::ingresarProducto(Minisuper* mini)
{
	int op;
	Producto* produ = nullptr;
	string codigo, nombre, descripcion, parteDelAnimal, marca, nombreDelAnimal, nombreEmpresa;
	double precio, peso;
	int existencia, limite, dia, mes, anio;
	bool nacional, tripa, envasado;
	cout << "El producto que desea ingresar es tipo:" << endl
		<< "1)Conserva" << endl
		<< "2)Abarrote" << endl
		<< "3)Embutido" << endl
		<< "4)Desea retornar" << endl;
	cin >> op;
	while (op < 4) {
		system("cls");

		cout << "Codigo: " << endl;
		cin >> codigo;
		cout << "Nombre del producto: " << endl;
		cin >> nombre;
		cout << "Descripcion del producto: " << endl;
		getline(cin, descripcion);
		cout << "Precio: " << endl;
		cin >> precio;
		cout << "Cuantos productos va a ingresar: " << endl;
		cin >> existencia;
		cout << "Cual es el limite de productos: " << endl;
		cin >> limite;


		switch (op)
		{
		case 1: {
			cout << "Es envasado: si(1), no(0)" << endl;
			cin >> envasado;
			produ = new Conserva(codigo, nombre, descripcion, precio, "01", existencia, limite, envasado);
			mini->ingresarProducto(produ);
			cout << "Producto ingresado!" << endl;
			system("pause");
			break;
		}
		case 2: {
			cout << "Es nacional, si(1), no(0) " << endl;
			cin >> nacional;
			cout << "Cuanto pesa: " << endl;
			cin >> peso;
			cout << "Fecha de vencimiento: " << endl << "Dia: " << endl;
			cin >> dia;
			cout << "Mes: " << endl;
			cin >> mes;
			cout << "Anio: " << endl;
			cin >> anio;
			cout << "Nombre de la empresa: " << endl;
			cin >> nombreEmpresa;

			produ = new Abarrote(codigo, nombre, descripcion, precio, "02", existencia, limite, nacional, peso, dia, mes, anio, nombreEmpresa);
			mini->ingresarProducto(produ);
			cout << "Producto ingresado!" << endl;
			system("pause");
			break;
		}
		case 3: {
			cout << "Es nacional, si(1), no(0) " << endl;
			cin >> nacional;
			cout << "Cuanto pesa: " << endl;
			cin >> peso;
			cout << "Fecha de vencimiento: " << endl << "Dia: " << endl;
			cin >> dia;
			cout << "Mes: " << endl;
			cin >> mes;
			cout << "Anio: " << endl;
			cin >> anio;
			cout << "Nombre del Animal: " << endl;
			cin >> nombreDelAnimal;
			cout << "Marca: " << endl;
			cin >> marca;
			cout << "Es tripa, si(1), no(0): " << endl;
			cin >> tripa;
			produ = new Embutido(codigo, nombre, descripcion, precio, "03", existencia, limite, nacional, peso, dia, mes, anio, nombreDelAnimal, parteDelAnimal, marca, tripa);
			mini->ingresarProducto(produ);
			cout << "Producto ingresado!" << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
		op = 4;
	}
}

void Interfaz::eliminarProducto(Minisuper* mini)
{
	string codigo;
	cout << mini->reportarProductos() << endl;
	cout << "Ingrese el codigo del producto que desea eliminar: " << endl;
	cin >> codigo;

	if (mini->getProductoPorCodigo(codigo) == nullptr)
		throw "No existe producto con ese codigo";
	else {
		mini->eliminarProducto(codigo);
		cout << "Producto eliminado!" << endl;
		system("pause");
	}
}

void Interfaz::modificarProducto(Minisuper* mini)
{
	string codigo, descrp;
	int op, cant;
	double precio;
	
	cout << mini->reportarProductos() << endl;
	cout << "Ingrese el codigo del producto que desea modificar: " << endl;
	cin >> codigo;

	Producto* produ = mini->getProductoPorCodigo(codigo);

	if (produ == nullptr)
		throw "No existe producto con ese codigo";
	else {
		cout << "Que desea modificar del producto: " << endl
			<< "1)Existencia" << endl
			<< "2)Descripcion" << endl
			<< "3)Precio" << endl;
		cin >> op;
		switch (op)
		{
		case 1: {
			cout << "Ingrese la nueva existencia: " << endl;
			cin >> cant;
			produ->setExistencia(cant);
			cout << "Producto modificado!" << endl;
			system("pause");
			break;
		}
		case 2: {
			cout << "Ingrese la nueva descripcion: " << endl;
			getline(cin, descrp);
			produ->setDescripcion(descrp);
			cout << "Producto modificado!" << endl;
			system("pause");
			break;
		}
		case 3: {
			cout << "Ingrese el nuevo precio: " << endl;
			cin >> precio;
			produ->setPrecioCosto(precio);
			cout << "Producto modificado!" << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
	}
}

void Interfaz::mostrarProductos(Minisuper* mini)
{
	cout << mini->reportarProductos();
}

void Interfaz::reportarDebajoExistencia(Minisuper* mini)
{
	cout << mini->reportarDebajoExistencia();
}

void Interfaz::cincoMejoresClientes(Minisuper* mini)
{
	cout << mini->mejoresCincoClientes();
}
