#pragma once
#include "ExcepcionTipo.h"

class ExcepcionTipoDouble : public ExcepcionTipo {
public:
	virtual const char* what() {
		return "Excepcion no es tipo Double";
	}
	virtual ~ExcepcionTipoDouble() {}
};