#pragma once
#include "Carne.h"
#include "Empaque.h"
class Embutido :
    public Carne
{
private:
    string marca;
    Empaque* ptrEmpaque;
public:
    Embutido();
    Embutido(string codigo, string nombre, string descripcion, double precio,string categoria,
        int existencia, int limite, bool nacional, double peso,
        int dia, int mes, int anio,
        string nombreEmpresa, string nombreDelAnimal,
        string parteDelAnimal, string marca, bool tripa);
    virtual ~Embutido();
    void setMarca(string marca);
    string getMarca();
    string toString();

};

