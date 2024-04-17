#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <sstream>
#include <iostream>
#include "Fecha.h"
class Producto{
	protected:
		std::string codigo;
		std::string nombreComercial;
		std::string descripcion;
		double precioCosto;
		std::string categoria;
		int existencia;
		int limite;
		Fecha* fechaIngreso;
	public:
		Producto();
		Producto(std::string codigo,std::string nombre,std::string descripcion,double precio,std::string categoria,int existencia,int limite);
		virtual ~Producto();
		std::string getCodigo();
		void setCodigo(std::string);
		std::string getNombreComercial();
		void setNombreComercial(std::string);
		std::string getDescripcion();
		void setDescripcion(std::string);
		double getPrecioCosto();
		void setPrecioCosto(double);
		std::string getCategoria();
		void setCategoria(std::string);
		int getExistencia();
		void setExistencia(int);
		int getLimite();
		void setLimite(int);
		Fecha* getFechaIngreso();
		void setFechaIngreso(Fecha*);
		virtual std::string toString();
		virtual Producto* clonar() = 0;
};
#endif