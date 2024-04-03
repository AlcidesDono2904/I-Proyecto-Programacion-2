#ifndef CARRITO_H
#define CARRITO_H
#include "ComponenteAbstracto.h"
class Carrito:public ComponenteAbstracto{
public:
	Carrito();
	virtual ~Carrito();
	std::string toString()override;
};

#endif