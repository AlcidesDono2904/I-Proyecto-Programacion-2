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
	do {
		system("CLS");
		opcion = Interfaz::MenuPrincipal();
		switch (opcion)
		{

		case 1: this->controlMantenimiento(); break;
		case 2: this->controlVentas(); break;
		case 3: this->controlReportes(); break;
		case 4: super->guardarProductos();
			break;//archivos //salir

		default:Interfaz::msjError();
		}

	} while (opcion != 4);
}

void Controladora::controlMantenimiento()
{
	int opcion; 
	do {
		system("CLS");
		opcion = Interfaz::MenuMantenimiento();
		switch (opcion)
		{
		case 1: {
			//Interfaz crea producto y lo ingresa a la lista
			Interfaz::ingresarProducto(super);
			break;
		}
		case 2: {
			//Interfaz muestra lista de productos y elimina segun el código
			Interfaz::eliminarProducto(super);
			break;
		}
		case 3: {
			//Interfaz muestre la lista de productos y modifica cantidad y otros atributos y lo haga según el código
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
			switch (opcion)
			{
			case 1: {
				//Mostrar todos los productos
				Interfaz::mostrarProductos(super);
				system("pause");
				break;
			}
			case 2: {
				//Mostrar todos los productos de una categoría en especifíco
				Interfaz::mostrarPorCategoria(super);
				system("pause");
				break;
			}
			case 3: {
				//Mostrar productos debajo del limite de existencia
				Interfaz::reportarDebajoExistencia(super);
				system("pause");
				break;
			}
			case 4: {
				// Pedir cedula para mostrar las ventas de esa persona
				Interfaz::mostrarVentasPorCedula(super);
				system("pause");
				break;
			}
			case 5: {
				//Mejores 5 clientes, sumar las ventas de cada cédula en especifico y compararlo
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
	Interfaz::VentaGeneraFactura(super);
}