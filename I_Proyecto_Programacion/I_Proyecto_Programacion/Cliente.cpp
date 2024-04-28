#include "Cliente.h"

Cliente::Cliente(std::string c, double v) : cedula(c), tVentas(v) {}

Cliente::~Cliente() {}

std::string Cliente::getCedula() { return cedula; }

double Cliente::getTVentas() { return tVentas; }

void Cliente::setCedula(std::string c) { cedula = c; }

void Cliente::setTVentas(double v) { tVentas = v; }

bool Cliente::operator==(const Cliente& c) { return cedula == c.cedula; }

bool Cliente::operator<(const Cliente& c) { return tVentas < c.tVentas; }

Cliente& Cliente::operator=(const Cliente& c) {
	if (this != &c) {
		cedula = c.cedula;
		tVentas = c.tVentas;
	}
	return *this;
}
