/*
*Primer proyecto programación II
* Alcides Jiménez Carrillo - 4-0267-0686
* Laura Flores Barrantes - 119050003
*/
#include "Headers.h"


int main() {
	//Prueba
	Abarrote* ab = new Abarrote("01", "Abarrote", "Descripcion Abarrote", 40.5, "02", 4, 10, 0, 14.5, 10, 7, 2024, "empresa...");

	Embutido* em = new Embutido("02", "Embutido", "Descripcion Embutido", 40.5, "03", 4, 10, 0, 14.5, 10, 7, 2024,
		"nombreEEmpresa", "pig", "mjm", "marca? la hora", 1);
	
	Conserva* co = new Conserva("03", "Conserva", "Descripcion Conserva", 40.5, "01", 4, 10, 0);
	/*
	ComponenteAbstracto* carrito1 = new Carrito();
	ComponenteAbstracto* paraBorrar = carrito1;
	carrito1 = new DecoradorConserva(carrito1, co);
	carrito1 = new DecoradorEmbutido(carrito1, em);
	carrito1 = new DecoradorAbarrote(carrito1, ab);
	
	cout<<carrito1->toString()<<endl;*/

	ListaEnlazada<Producto>* lista = new ListaEnlazada<Producto>();
	lista->agregarInicio(ab);
	lista->agregarInicio(em);
	lista->agregarInicio(co);

	cout << "Borrando un dato de la lista..\n";
	delete lista->sacarDato();
	cout << "Borando toda la lista";
	delete lista;
	return 0;
}