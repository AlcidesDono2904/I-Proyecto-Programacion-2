#ifndef DECORADORABSTRACTO_H
#define DECORADORABSTRACTO_H
	
#include "ComponenteAbstracto.h"
#include <sstream>
class DecoradorAbstracto :public ComponenteAbstracto{
protected:
	ComponenteAbstracto* decorado;
public:
	virtual ~DecoradorAbstracto();
	virtual std::string toString() = 0;
	virtual ComponenteAbstracto* clonar() = 0;
	/*virtual double CalcularPrecioCarrito() = 0;*/
};

#endif 