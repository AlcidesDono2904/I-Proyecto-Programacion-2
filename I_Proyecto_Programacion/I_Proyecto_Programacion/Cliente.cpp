#include "Cliente.h"

Cliente::Cliente() {
	cedula = "";
	totalVentas = 0;
}

Cliente::Cliente(std::string cedula, double totalVentas) {
	this->cedula = cedula;
	this->totalVentas = totalVentas;
}

std::string Cliente::getCedula() {
	return cedula;
}

double Cliente::getTotalVentas() {
	return totalVentas;
}

void Cliente::setCedula(std::string cedula) {
	this->cedula = cedula;
}

void Cliente::setTotalVentas(double totalVentas) {
	this->totalVentas = totalVentas;
}

void Cliente::incrementarTotalVentas(double monto) {
	totalVentas += monto;
}

bool Cliente::operator==(const Cliente& c) {
	return cedula == c.cedula;
}