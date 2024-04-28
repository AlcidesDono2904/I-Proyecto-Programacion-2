#pragma once
#ifndef MINISUPER_H
#define MINISUPER_H
#include "Producto.h"
#include "Venta.h"
#include "Lista.h"
#include "headers.h"
#include "Cliente.h"

class Minisuper {
private:
	ListaEnlazada<Producto>* productos;
	ListaEnlazada<Venta>* ventas;
	string nombre;
public:
	Minisuper(string nom);
	virtual ~Minisuper();
	ListaEnlazada<Producto>* getProductos();
	ListaEnlazada<Venta>* getVentas();
	//mantenimiento productos
	void ingresarProducto(Producto* producto);
	Producto* eliminarProducto(string codigo);
	
	//reporte productos
	std::string reportarProductos();
	std::string reportarCategoria(std::string categoria);
	std::string reportarDebajoExistencia(); 
	//mantenimiento ventas
	
	//reporte ventas
	std::string reportarVentas(std::string cedula);

	void insertarVentaOrdenada(ListaEnlazada<Venta>* ventasOrden, const Venta* venta);
	string mejoresCincoClientes();
	Producto* getProductoPorCodigo(string cod);
	void ingresarVenta(Venta* venta);

	bool verificarCodigoUnico(string cod);

	//archivos
	void guardarProductos();
	void leerProductos();
};
#endif