#pragma once
#include "ExcepcionTipo.h"

class ExcepcionTipoInt : public ExcepcionTipo {
public:
	virtual const char* what() {
		return "Excepcion no es tipo int";
	}
	virtual ~ExcepcionTipoInt(){}
};