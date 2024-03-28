#ifndef FECHA_H
#define FECHA_H
#include <ctime>
#include <string>
class Fecha{
private:
	unsigned int dia;
	unsigned int mes;
	unsigned int anio;
public:
	Fecha();
	Fecha(unsigned int dia, unsigned int mes, unsigned int anio);
	unsigned int getDia()const;
	unsigned int getMes()const;
	unsigned int getAnio()const;
	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setAnio(unsigned int anio);
	
};

#endif