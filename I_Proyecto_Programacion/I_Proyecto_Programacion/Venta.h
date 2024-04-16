#pragma once
#include "Lista.h"
#include "ComponenteAbstracto.h"
#include "headers.h"
#include <string>
#include <sstream>
using namespace std;
class Venta {
private:
	ComponenteAbstracto* carrito;
	int numeroFat;
	int cantidadProductos;
	double importe;
	double IVA;
	double subtotal;
	double total;
	string cedulaCliente;
public:
	Venta();
	Venta(ComponenteAbstracto* carrito, int numFac, int cantProd, string cedulaCli);
	virtual ~Venta();
	ComponenteAbstracto* getCarrito();
	int getNumeroFact();
	string getCedulaCliente();
	double getImporte();
	double getIVA();
	double getSubtotal();
	void setCarrito(ComponenteAbstracto* carrito);
	void setNumFact(int numFac);
	void setCantidadProductos(int cantProd);
	void setCedulaCliente(string cedulaCli);
	void setImporte(double imp);
	void setIVA(double iva);
	void setSubtotal(double subto);
	string toString() const;
	
};