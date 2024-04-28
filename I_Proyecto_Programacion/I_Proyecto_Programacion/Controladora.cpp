#include "Controladora.h"

Controladora::Controladora()
{
	super = new Minisuper("Mini");
	
}

Controladora::~Controladora()
{
	delete super;
}


void Controladora::control0()
{
	int opcion;
	setlocale(LC_ALL, "spanish");
		do {
			try {
				system("CLS");
				opcion = Interfaz::MenuPrincipal();
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw* new ExcepcionTipoInt();
				}
				switch (opcion)
				{

				case 1: this->controlMantenimiento(); break;
				case 2: this->controlVentas(); break;
				case 3: this->controlReportes(); break;
				case 4: super->guardarProductos();
					super->guardarVentas();
					break;//archivos //salir

				default:Interfaz::msjError();
				}
			}
				catch (ExcepcionTipo& e) {
					cerr << "Excepcion capturada" <<endl << e.what();
					system("pause");

				}
			
		} while (opcion != 4);
	}
	

void Controladora::controlMantenimiento()
{
	int opcion; 
	do {
		system("CLS");
		opcion = Interfaz::MenuMantenimiento();
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw* new ExcepcionTipoInt();
		}
		switch (opcion)
		{
		case 1: {
			//Interfaz crea producto y lo ingresa a la lista
			system("CLS");
			Interfaz::ingresarProducto(super);
			break;
		}
		case 2: {
			//Interfaz muestra lista de productos y elimina segun el c�digo
			system("CLS");
			Interfaz::eliminarProducto(super);
			break;
		}
		case 3: {
			//Interfaz muestre la lista de productos y modifica cantidad y otros atributos y lo haga seg�n el c�digo
			system("CLS");
			Interfaz::modificarProducto(super);
			break;
		}
		default:
			break;
		}

	} while (opcion != 4);
}

void Controladora::controlReportes()
{
	int opcion;
	if (super->getProductos()->estaVacio()) {
		Interfaz::msjError();
		system("pause");
	}
	else
	{
		do {
			system("CLS");

			opcion = Interfaz::MenuReportes();
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw* new ExcepcionTipoInt();
			}
			switch (opcion)
			{
			case 1: {
				//Mostrar todos los productos
				system("CLS");
				Interfaz::mostrarProductos(super);
				system("pause");
				break;
			}
			case 2: {
				//Mostrar todos los productos de una categor�a en especif�co
				system("CLS");
				Interfaz::mostrarPorCategoria(super);
				system("pause");
				break;
			}
			case 3: {
				//Mostrar productos debajo del limite de existencia
				system("CLS");
				Interfaz::reportarDebajoExistencia(super);
				system("pause");
				break;
			}
			case 4: {
				// Pedir cedula para mostrar las ventas de esa persona
				system("CLS");
				Interfaz::mostrarVentasPorCedula(super);
				system("pause");
				break;
			}
			case 5: {
				//Mejores 5 clientes, sumar las ventas de cada c�dula en especifico y compararlo
				system("CLS");
				Interfaz::cincoMejoresClientes(super);
				system("pause");
				break;
			}
			default:
				break;
			}

		} while (opcion != 6);
	}
}




void Controladora::controlVentas()
{
	//Crear venta
	system("CLS");
	Interfaz::VentaGeneraFactura(super);
}