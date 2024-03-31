#pragma once
#include "ProduPerecedero.h"
class Carne :
    public ProduPerecedero
{
protected:
    string nombreAnimal;
    string parteDelAnimal;
public:
    Carne();
    Carne(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool nacional, double peso, 
        int dia, int mes, int anio, string nombreEmpresa, string nombreDelAnimal, string parteDelAnimal);
    virtual ~Carne();
    void setNombreAnimala(string nombreDelAnimal);
    void setParteDelAnimal(string parteDelAnimal);
    string getNombreDelAnimal();
    string getParteDelAnimal();
    virtual string toString() = 0;
};

