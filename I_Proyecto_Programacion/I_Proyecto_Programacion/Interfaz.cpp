#include "Interfaz.h"

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
	cout << "2)Eliminaci�n de producto " << endl;
	cout << "3)Actualizaci�n de producto" << endl;
	cout << "4)Retornar" << endl;
	cin >> opcion;
	return opcion;
}

void Interfaz::VentaGeneraFactura()
{
}



int Interfaz::MenuReportes()
{
	int opcion = 0;
	cout << "1)Reportar todos los productos" << endl;
	cout << "2)Reportar todos los productos de una categor�a" << endl;
	cout << "3)Debajo del l�mite de existencia" << endl;
	cout << "4)Facturas de un cliente" << endl;
	cout << "5)Mejores 5 clientes" << endl;
	cout << "6)Retornar" << endl;
	cin >> opcion;
	return opcion;
}
