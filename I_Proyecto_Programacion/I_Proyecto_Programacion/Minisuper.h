#ifndef MINISUPER_H
#define MINISUPER_H
#include "Producto.h"
#include "Venta.h"
#include "Lista.h"

class Minisuper {
private:
	ListaEnlazada<Producto>* productos;
	ListaEnlazada<Venta>* ventas;
public:
	Minisuper();
	virtual ~Minisuper();
	ListaEnlazada<Producto>* getProductos();
	ListaEnlazada<Venta>* getVentas();
	//mantenimiento productos
	void ingresarProducto(Producto* producto);
	Producto* eliminarProducto(string codigo);
	//void modificarProducto(string codigo, Producto* producto);
	//reporte productos
	std::string reportarProductos();
	std::string reportarCategoria(std::string categoria);
	//std::string reportarDebajoExistencia(); ??
	//mantenimiento ventas
	//std::string generarVenta(Venta* venta,std::string cedula);
	//reporte ventas
	std::string reportarVentas(std::string cedula);
	//reportar 5 mejores cedulas
};
#endif