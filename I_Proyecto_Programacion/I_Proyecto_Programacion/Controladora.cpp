#include "Controladora.h"

Controladora::Controladora()
{
}

Controladora::~Controladora()
{
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
		case 4: break;//archivos //salir

		default:Interfaz::msjError();
		}

	} while (opcion != 4);
}

void Controladora::controlMantenimiento()
{
}

void Controladora::controlReportes()
{

}

void Controladora::controlVentas()
{
}