#pragma once
#include "Headers.h"
#include "Interfaz.h"

class Controladora {
	Minisuper* super;
public:
	Controladora();
	~Controladora();
	void control0();
	void controlMantenimiento();
	void controlReportes();
	void controlVentas();
};