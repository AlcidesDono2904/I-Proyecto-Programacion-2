#ifndef DECORADORCONSERVA_H
#define DECORADORCONSERVA_H
#include "DecoradorAbstracto.h"
#include "headers.h"
#include "Conserva.h"
class DecoradorConserva : public DecoradorAbstracto{
private:
	Conserva* conserva;
public:
	DecoradorConserva(ComponenteAbstracto* decorado, Conserva* conserva);
	virtual ~DecoradorConserva();
	std::string toString()override;
	virtual ComponenteAbstracto* getDecorado();
	Conserva* getConserva();
	virtual ComponenteAbstracto* clonar();
	virtual void guardarCarrito(ostream&);
	virtual ComponenteAbstracto* leerCarrito(istream&);

};

#endif