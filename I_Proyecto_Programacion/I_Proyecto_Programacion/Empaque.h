#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Empaque
{
private:
	bool tripa;
public:
	Empaque(bool tripa);
	Empaque();
	virtual ~Empaque();
	void setTripa(bool tripa);
	bool getTripa();


	friend ostream& operator<<(ostream& salida, const Empaque& f);
};

