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
	virtual ComponenteAbstracto* getDecorado() = 0;
	virtual ComponenteAbstracto* clonar() = 0;
	virtual void guardarCarrito(ostream&) = 0;
};

#endif 