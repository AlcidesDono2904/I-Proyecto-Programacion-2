#include "Empaque.h"

Empaque::Empaque(bool tripa)
{
    this->tripa = tripa;
}

Empaque::Empaque()
{
    tripa = false;
}

Empaque::~Empaque()
{
}

void Empaque::setTripa(bool tripa)
{
    this->tripa = tripa;
}

bool Empaque::getTripa()
{
    return tripa;
}


ostream& operator<<(ostream& salida, const Empaque& f)
{
    salida << "Tiene tripa: ";
    if (f.tripa)
        salida << "Si\n";
    else 
        salida << "No\n";
    return salida;
}
