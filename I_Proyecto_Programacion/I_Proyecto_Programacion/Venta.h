#pragma once
#include "headers.h"

class Venta {
private:
	ListaEnlazada<ComponenteAbstracto>* carrito;
	int numeroFat;
	int cantidadProductos;
	string descripcion;
	double importe;
	double IVA;
	double subtotal;
	string cedulaCliente;
public:
	Venta();
	Venta(ListaEnlazada<ComponenteAbstracto>* carrito, int numFac, int cantProd, string descp, double imp, double iva, double subto, string cedulaCli);
	virtual ~Venta();
	ListaEnlazada<ComponenteAbstracto>* getCarrito();
	int getNumeroFact();
	string getDescripcion();
	string getCedulaCliente();
	double getImporte();
	double getIVA();
	double getSubtotal();
	void setCarrito(ListaEnlazada<ComponenteAbstracto>* carrito);
	void setNumFact(int numFac);
	void setCantidadProductos(int cantProd);
	void setDescripcion(string descp);
	void setCedulaCliente(string cedulaCli);
	void setImporte(double imp);
	void setIVA(double iva);
	void setSubtotal(double subto);
	string toString() const;

};