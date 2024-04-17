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
	ComponenteAbstracto* productoC;
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
			cout << "Su carrito va así: " << endl << carrito->toString()
				<< "Si desea seguir añadiendo productos digite 1, si desea terminar su compra y recibir su factura digite 0" << endl;
			cin >> seguir;
		} while (seguir != 0);
		if (sePudo) {
			// Hacer venta y mostrar factura
			Venta* ventaC = new Venta(carrito, 0, cantProdu, ced);
			mini->ingresarVenta(ventaC);
			cout << "Aqui esta su factura: " << endl
				<< ventaC->toString() << endl;
		}
		else throw "No se pudo hacer la venta";

	}
	else throw "No hay productos en el minisuper";
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
