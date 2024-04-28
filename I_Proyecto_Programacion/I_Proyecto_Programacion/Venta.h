#pragma once
#include "Lista.h"
#include "ComponenteAbstracto.h"
#include "Producto.h"
#include <string>
#include <sstream>
using namespace std;
class Venta {
private:
	ComponenteAbstracto* carrito;
	int cantidadProductos;
	double importe;
	double IVA;
	double subtotal;
	string cedulaCliente;
public:
	Venta();
	Venta(ComponenteAbstracto* carrito, int cantProd, string cedulaCli);
	Venta(const Venta&);
	virtual ~Venta();
	ComponenteAbstracto* getCarrito();
	
	string getCedulaCliente();
	double getImporte();
	double getIVA();
	double getSubtotal();
	void setCarrito(ComponenteAbstracto* carrito);
	
	void setCantidadProductos(int cantProd);
	void setCedulaCliente(string cedulaCli);
	void setImporte(double imp);
	void setIVA(double iva);
	void setSubtotal(double subto);
	string toString() const;
	void guardarVenta(ostream&);
};