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
	double sub = 0;
	string ced = "", cod = "", categ = "";
	bool sePudo = false;
	Producto* produ = nullptr;
	ComponenteAbstracto* carrito = new Carrito();
	ComponenteAbstracto* productoC = nullptr;
	Venta* ventaC = nullptr;

	if (!mini->getProductos()->estaVacio()) {
		cout << "----Ingrese su cedula para emitir la factura----" << endl;
		cin >> ced;
		do {
			cout << "----Productos disponibles---- " << endl;
			cout << mini->reportarProductos() << endl;
			cout << "Digite el codigo del producto que desea comprar: " << endl;
			cin >> cod;
			produ = mini->getProductoPorCodigo(cod);
			if (produ == nullptr) {
				cout << "No hay producto con ese codigo";
				sePudo = false;

			}
			else {
				
					cout << "Digite la cantidad de este producto que desea comprar: " << endl;
					cin >> cant;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw* new ExcepcionTipoInt();
					}
					if (produ->getExistencia() < cant)
						cout << "No hay existe tanta cantidad de productos" << endl;
					
					else {
						categ = produ->getCategoria();
						stringstream ct(categ);
						int cat;
						ct >> cat;
						switch (cat)
						{
						case 01: {
							if (productoC == nullptr)
								productoC = new DecoradorConserva(carrito, dynamic_cast<Conserva*>(produ));
							else
								productoC = new DecoradorConserva(productoC, dynamic_cast<Conserva*>(produ));
							break;
						}
						case 02: {
							if (productoC == nullptr)
								productoC = new DecoradorAbarrote(carrito, dynamic_cast<Abarrote*>(produ));
							else
								productoC = new DecoradorAbarrote(productoC, dynamic_cast<Abarrote*>(produ));
							break;
						}
						case 03: {
							if (productoC == nullptr)
								productoC = new DecoradorEmbutido(carrito, dynamic_cast<Embutido*>(produ));
							else
								productoC = new DecoradorEmbutido(productoC, dynamic_cast<Embutido*>(produ));
							break;
						}
						default:
						{
							break;
						}
						}

						//Modificar lista productos
						mini->getProductoPorCodigo(cod)->setExistencia(produ->getExistencia() - cant);
						//Dar una advertencia de que algún producto este debajo del limite
						cantProdu += cant;
						ventaC = new Venta(productoC, cantProdu, ced);
						ventaC->setSubtotal(produ->getPrecioCosto() * cant * Categoria::porceGanancia(categ));
						sub = ventaC->getSubtotal();

						ventaC->setImporte(sub * 0.13 + sub);
						
						system("CLS");
						cout << "Su carrito va asi: " << endl << productoC->toString() << endl;
						if (ventaC != nullptr)
							sePudo = true;
						cout << "Si desea seguir añadiendo productos digite 1, si desea terminar su compra y recibir su factura digite 0" << endl;
						cin >> seguir;
					}
				
			}


			
		} while (seguir != 0);
		if (sePudo) {
			//Hacer una venta arriba e ir agregandole los productos en el switch o arriba
			// Hacer venta y mostrar factura
			 //multiplicar el precio por la cantidad de productos

			mini->ingresarVenta(ventaC);
			cout << "Aqui esta su factura: " << endl
				<< ventaC->toString() << endl;
			system("pause");
		}
		else cout << "No se pudo hacer la venta";

	}

	else cout << "No hay productos en el minisuper";
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
	cout << "Digite la cedula de asociada a las facturas que desea ver" << endl;
	cin >> ced;
	cout << mini->reportarVentas(ced);
	
}

void Interfaz::ingresarProducto(Minisuper* mini)
{
	int op;
	Producto* produ = nullptr;
	string codigo = "", nombre, descripcion, parteDelAnimal, marca, nombreDelAnimal, nombreEmpresa;
	double precio, peso;
	int existencia, limite, dia, mes, anio;
	bool nacional, tripa, envasado;
	cout << "El producto que desea ingresar es tipo:" << endl
		<< "1)Conserva" << endl
		<< "2)Abarrote" << endl
		<< "3)Embutido" << endl
		<< "4)Desea retornar" << endl;
	cin >> op;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw* new ExcepcionTipoInt();
	}
	while (op < 4 && op>0) {
		system("cls");
		while(!mini->verificarCodigoUnico(codigo) || codigo == "")
		{
			cout << "Codigo: " << endl;
			cin >> codigo; // verificar que no se repita
		}
		
		cout << "Nombre del producto: " << endl;
		cin >> nombre;
		cout << "Descripcion del producto: " << endl;
		cin.ignore();
		getline(cin, descripcion);

		cout << "Precio: " << endl;
		cin >> precio;
		cout << "Cuantos productos va a ingresar: " << endl;
		cin >> existencia;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw* new ExcepcionTipoInt();
		}
		cout << "Cual es el limite de productos: " << endl;
		cin >> limite;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw* new ExcepcionTipoInt();
		}


		switch (op)
		{
		case 1: {
			cout << "Es envasado: si(1), no(0)" << endl;
			cin >> envasado;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoBool();
			}
			produ = new Conserva(codigo, nombre, descripcion, precio, "01", existencia, limite, envasado);
			mini->ingresarProducto(produ);
			cout << "Producto ingresado!" << endl;
			system("pause");
			break;
		}
		case 2: {
			cout << "Es nacional, si(1), no(0) " << endl;
			cin >> nacional;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			cout << "Cuanto pesa: " << endl;
			cin >> peso;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoDouble();
			}
			cout << "Fecha de vencimiento: " << endl << "Dia: " << endl;
			cin >> dia;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			cout << "Mes: " << endl;
			cin >> mes;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			cout << "Anio: " << endl;
			cin >> anio;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
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
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			cout << "Cuanto pesa: " << endl;
			cin >> peso;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoDouble();
			}
			cout << "Fecha de vencimiento: " << endl << "Dia: " << endl;
			cin >> dia;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			cout << "Mes: " << endl;
			cin >> mes;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			cout << "Anio: " << endl;
			cin >> anio;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			cout << "Nombre del Animal: " << endl;
			cin >> nombreDelAnimal;
			cout << "Parte del Animal: " << endl;
			cin >> parteDelAnimal;
			cout << "Marca: " << endl;
			cin >> marca;
			cout << "Es tripa, si(1), no(0): " << endl;
			cin >> tripa;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoBool();
			}
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
		cout << "No existe producto con ese codigo" << endl;
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
		cout<< "No existe producto con ese codigo"<<endl;
	else {
		cout << "Que desea modificar del producto: " << endl
			<< "1)Existencia" << endl
			<< "2)Descripcion" << endl
			<< "3)Precio" << endl;
		cin >> op;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw* new ExcepcionTipoInt();
		}
		switch (op)
		{
		case 1: {
			cout << "Ingrese la nueva existencia: " << endl;
			cin >> cant;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
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
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoDouble();
			}
			produ->setPrecioCosto(precio);
			cout << "Producto modificado!" << endl;
			system("pause");
			break;
		}
		default:
			Interfaz::msjError();
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
