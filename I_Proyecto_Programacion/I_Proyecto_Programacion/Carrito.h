#ifndef CARRITO_H
#define CARRITO_H
#include "ComponenteAbstracto.h"
class Carrito:public ComponenteAbstracto{
public:
	std::string toString()override;
};

#endif