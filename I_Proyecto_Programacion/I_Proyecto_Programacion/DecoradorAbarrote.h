#ifndef DECORADORABARROTE_H
#define DECORADORABARROTE_H
#include "headers.h"
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
	Abarrote* getAbarrote();
	virtual ComponenteAbstracto* clonar();
	virtual void guardarCarrito(ostream&);
	virtual ComponenteAbstracto* leerCarrito(istream&);
};

#endif