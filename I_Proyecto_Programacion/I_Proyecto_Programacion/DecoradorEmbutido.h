#ifndef DECORADOREMBUTIDO_H
#define DECORADOREMBUTIDO_H

#include "DecoradorAbstracto.h"
#include "Embutido.h"
class DecoradorEmbutido :public DecoradorAbstracto{
private:
	Embutido* embutido;
public:
	DecoradorEmbutido(DecoradorAbstracto* decorado, Embutido* embutido);
	virtual ~DecoradorEmbutido();
	std::string toString() override;

};

#endif 