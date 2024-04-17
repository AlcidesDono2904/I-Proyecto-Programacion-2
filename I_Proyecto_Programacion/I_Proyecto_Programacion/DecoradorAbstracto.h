#ifndef DECORADORABSTRACTO_H
#define DECORADORABSTRACTO_H
	
#include "ComponenteAbstracto.h"
#include <sstream>
class DecoradorAbstracto :public ComponenteAbstracto{
protected:
	ComponenteAbstracto* decorado;
public:
	virtual ~DecoradorAbstracto();
	virtual ComponenteAbstracto* clonar() = 0;
};

#endif 