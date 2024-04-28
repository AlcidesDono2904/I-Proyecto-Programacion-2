#ifndef COMPONENTEABSTRACTO_H
#define COMPONENTEABSTRACTO_H
#include <string>
#include<iostream>
#include <sstream>
#include <fstream>

using namespace std;

class ComponenteAbstracto {
public:
	virtual ~ComponenteAbstracto();
	virtual std::string toString() = 0;
	virtual ComponenteAbstracto* getDecorado() = 0;
	virtual ComponenteAbstracto* clonar() = 0;
	virtual void guardarCarrito(ostream&)=0;
	
};
#endif