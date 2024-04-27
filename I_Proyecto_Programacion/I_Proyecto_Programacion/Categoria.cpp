#include "Categoria.h"

Categoria::~Categoria() {
}

double Categoria::porceGanancia(std::string categ) {
	if (categ == "01") return 1.15;
	if (categ=="02") return 1.20;
	if (categ == "03") return 1.25;
	else 0.0;
}