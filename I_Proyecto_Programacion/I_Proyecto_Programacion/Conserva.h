#pragma once
#include <sstream>
#include <iostream>
#include "Producto.h"

using namespace std;

class Conserva:public Producto
{
private:
	bool envasado;
public:
	Conserva();
	Conserva(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool envasado);
	virtual ~Conserva();
	void setEnvasado(bool envasado);
	bool getEnvasado();
	virtual string toString();
	virtual Producto* clonar();
	virtual void guardarProducto(ostream& archi);
	static Producto* leerProductoConserva(istream& archi);
};

