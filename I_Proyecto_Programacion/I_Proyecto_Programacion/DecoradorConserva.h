#ifndef DECORADORCONSERVA_H
#define DECORADORCONSERVA_H
#include "DecoradorAbstracto.h"
#include "Conserva.h"
class DecoradorConserva : public DecoradorAbstracto{
private:
	Conserva* conserva;
public:
	DecoradorConserva(ComponenteAbstracto* decorado, Conserva* conserva);
	virtual ~DecoradorConserva();
	std::string toString()override;

	virtual ComponenteAbstracto* clonar();
	
};

#endif