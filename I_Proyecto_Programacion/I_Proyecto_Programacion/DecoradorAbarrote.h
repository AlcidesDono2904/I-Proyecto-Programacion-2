#ifndef DECORADORABARROTE_H
#define DECORADORABARROTE_H

#include "DecoradorAbstracto.h"
#include "Abarrote.h"
class DecoradorAbarrote : public DecoradorAbstracto{
private:
	Abarrote* abarrote;
public:
	DecoradorAbarrote(DecoradorAbstracto* decorar, Abarrote* abarrote);
	std::string toString() override;
	virtual ~DecoradorAbarrote();
};

#endif