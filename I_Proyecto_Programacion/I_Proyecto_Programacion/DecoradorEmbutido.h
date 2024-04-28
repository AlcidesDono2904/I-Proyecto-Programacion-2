#ifndef DECORADOREMBUTIDO_H
#define DECORADOREMBUTIDO_H

#include "DecoradorAbstracto.h"
#include "Embutido.h"
class DecoradorEmbutido :public DecoradorAbstracto{
private:
	Embutido* embutido;
public:
	DecoradorEmbutido(ComponenteAbstracto* decorado, Embutido* embutido);
	virtual ~DecoradorEmbutido();
	std::string toString();
	virtual ComponenteAbstracto* getDecorado();
	virtual ComponenteAbstracto* clonar(); 
	virtual void guardarCarrito(ostream&);
	static ComponenteAbstracto* leerCarrito(istream&);
};

#endif 