#ifndef COMPONENTEABSTRACTO_H
#define COMPONENTEABSTRACTO_H
#include <string>
class ComponenteAbstracto{
public:
	virtual ~ComponenteAbstracto();
	virtual std::string toString() = 0;
};
#endif