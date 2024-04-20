#pragma once
#include "Headers.h"
#include "Carrito.h"
#include <iostream>
#include <sstream>

class Interfaz {
public:
	static void msjError();
	static int MenuPrincipal();
	static int MenuMantenimiento();
	static void VentaGeneraFactura(Minisuper* mini);
	static int MenuReportes();
	static void mostrarPorCategoria(Minisuper* mini);
	static void mostrarVentasPorCedula(Minisuper* mini);
	static void ingresarProducto(Minisuper* mini);
	static void eliminarProducto(Minisuper* mini);
	static void modificarProducto(Minisuper* mini);

};