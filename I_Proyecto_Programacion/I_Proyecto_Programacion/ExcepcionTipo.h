#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class ExcepcionTipo {
public:
	virtual const char* what() = 0;
	virtual ~ExcepcionTipo(){}
};