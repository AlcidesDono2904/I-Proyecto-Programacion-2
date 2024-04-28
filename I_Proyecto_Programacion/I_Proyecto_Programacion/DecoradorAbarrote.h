#ifndef DECORADORABARROTE_H
#define DECORADORABARROTE_H

#include "DecoradorAbstracto.h"
#include "Abarrote.h"
class DecoradorAbarrote : public DecoradorAbstracto{
private:
	Abarrote* abarrote;
public:

	DecoradorAbarrote(ComponenteAbstracto* decorar, Abarrote* abarrote);
	std::string toString() override;
	virtual ~DecoradorAbarrote();
	virtual ComponenteAbstracto* getDecorado();
	virtual ComponenteAbstracto* clonar();
	virtual void guardarCarrito(ostream&);
	static ComponenteAbstracto* leerCarrito(istream&);
};

#endif