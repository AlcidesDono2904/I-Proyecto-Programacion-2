#pragma once
#include "Perecedero.h"
#include "Producto.h"

class ProduPerecedero: public Producto
{
protected:
	bool nacional;
	double peso;
	Perecedero* ptrPere;
public:
	ProduPerecedero();
	ProduPerecedero(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, int dia, int mes, int anio);
	virtual ~ProduPerecedero();
	void setNacional(bool nacional); 
	void setPeso(double peso);
	bool getNacional();
	double getPeso();
	virtual string toString() = 0;
};

