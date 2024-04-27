#pragma once
#include "ExcepcionTipo.h"

class ExcepcionTipoBool : public ExcepcionTipo {
	public:
	virtual const char* what() {
		return "Excepcion no es tipo Bool";
	}
	virtual ~ExcepcionTipoBool(){}
};