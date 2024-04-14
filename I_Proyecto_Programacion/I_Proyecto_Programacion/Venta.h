#pragma once
#include "Lista.h"
#include "ComponenteAbstracto.h"
#include <string>
#include <sstream>
using namespace std;
class Venta {
private:
	ListaEnlazada<ComponenteAbstracto>* carrito;
	int numeroFat;
	int cantidadProductos;
	double importe;
	double IVA;
	double subtotal;
	string cedulaCliente;
public:
	Venta();
	Venta(ListaEnlazada<ComponenteAbstracto>* carrito, int numFac, int cantProd, double imp, double iva, double subto, string cedulaCli);
	virtual ~Venta();
	ListaEnlazada<ComponenteAbstracto>* getCarrito();
	int getNumeroFact();
	string getCedulaCliente();
	double getImporte();
	double getIVA();
	double getSubtotal();
	void setCarrito(ListaEnlazada<ComponenteAbstracto>* carrito);
	void setNumFact(int numFac);
	void setCantidadProductos(int cantProd);
	void setCedulaCliente(string cedulaCli);
	void setImporte(double imp);
	void setIVA(double iva);
	void setSubtotal(double subto);
	string toString() const;
};