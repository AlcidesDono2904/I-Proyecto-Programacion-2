#include "Fecha.h"

Fecha::Fecha() {//constructor por defecto
    std::time_t tActual = std::time(nullptr);// Obtiene el tiempo actual

    std::tm tLocal;// Estructura de tiempo local

    //Con esto se saca la fecha local
    localtime_s(&tLocal, &tActual);

    dia = tLocal.tm_mday;
    mes = tLocal.tm_mon + 1;
    anio = tLocal.tm_year + 1900;
    //se necesita hacer un pequenio calculo para sacar la fecha correcta.
}

Fecha::Fecha(unsigned int d, unsigned int m, unsigned int a){//constructor por parametros
    if (d == 0 or d > 31)
        throw  "Error: dia incorrecto";
    if (m==0 or m>12)
        throw "Error: mes incorrecto";
    dia=d;
    mes = m;
    anio = a;
}

unsigned int Fecha::getDia()const{
	return dia;
}

unsigned int Fecha::getMes()const{
	return mes;
}

unsigned int Fecha::getAnio()const{
	return anio;
}

void Fecha::setDia(unsigned int d){
	if (d == 0 or d > 31)
		throw  "Error: dia incorrecto";
	dia = d;
}

void Fecha::setMes(unsigned int m){
	if (m == 0 or m > 12)
		throw "Error: mes incorrecto";
	mes = m;
}

void Fecha::setAnio(unsigned int a){
	anio = a;
}

std::ostream& operator<<(std::ostream& salida, const Fecha& f){
	salida << f.dia << "/" << f.mes << "/" << f.anio;
	return salida;
}