#pragma once
#include "headers.h"
#include <iostream>
#include <sstream>

class Interfaz {
public:
	static void msjError();
	static int MenuPrincipal();
	static int MenuMantenimiento();
	static void VentaGeneraFactura(Minisuper* mini);
	static int MenuReportes();

};