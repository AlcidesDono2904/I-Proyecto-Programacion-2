#ifndef CARRITO_H
#define CARRITO_H
#include "ComponenteAbstracto.h"
#include <fstream>
#include <sstream>
using namespace std;
class Carrito:public ComponenteAbstracto{
public:
	Carrito();
	virtual ~Carrito();
	virtual ComponenteAbstracto* getDecorado();
	std::string toString()override;
	virtual ComponenteAbstracto* clonar();
	virtual void guardarCarrito(ostream&);
};

#endif