/*
*Primer proyecto programación II
* Alcides Jiménez Carrillo - 4-0267-0686
* Laura Flores Barrantes - 119050003
*/
#include "headers.h"


int main() {
	//Prueba
	Abarrote* ab = new Abarrote("code", "Abarrote", "Descripcion Abarrote", 40.5, "02", 4, 10, 0, 14.5, 10, 7, 2024, "empresa...");
	Embutido* em = new Embutido("code1", "Embutido", "Descripcion Embutido", 40.5, "03", 4, 10, 0, 14.5, 10, 7, 2024,
		"nombreEEmpresa", "pig", "mjm", "marca? la hora", 1);
	//(string codigo, string nombre, string descripcion, double precio, string categoria, int existencia, int limite, bool envasado);
	Conserva* co = new Conserva("code2", "Conserva", "Descripcion Conserva", 40.5, "01", 4, 10, 0);

	ComponenteAbstracto* carrito1 = new Carrito();
	ComponenteAbstracto* paraBorrar = carrito1;
	carrito1 = new DecoradorConserva(carrito1, co);
	carrito1 = new DecoradorEmbutido(carrito1, em);
	carrito1 = new DecoradorAbarrote(carrito1, ab);

	cout<<carrito1->toString()<<endl;
	delete ab, em, co, paraBorrar;
	return 0;
}