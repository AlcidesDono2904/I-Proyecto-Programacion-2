/*
*Primer proyecto programación II
* Alcides Jiménez Carrillo - 4-0267-0686
* Laura Flores Barrantes - 119050003
*/
#include "Headers.h"


int main() {
	//Prueba
	Abarrote* ab = new Abarrote("code1", "Abarrote", "Descripcion Abarrote", 40.5, "02", 4, 10, 0, 14.5, 10, 7, 2024, "empresa...");

	Embutido* em = new Embutido("code2", "Embutido", "Descripcion Embutido", 40.5, "03", 4, 10, 0, 14.5, 10, 7, 2024,
		 "pig", "mjm", "marca? la hora", 1);
	
	Conserva* co = new Conserva("code3", "Conserva", "Descripcion Conserva", 40.5, "01", 4, 10, 0);

	/*  Embutido(string codigo, string nombre, string descripcion, double precio,string categoria,
        int existencia, int limite, bool nacional, double peso,
        int dia, int mes, int anio, string nombreDelAnimal,
        string parteDelAnimal, string marca, bool tripa);*/
	/*
	ComponenteAbstracto* carrito1 = new Carrito();
	ComponenteAbstracto* paraBorrar = carrito1;
	carrito1 = new DecoradorConserva(carrito1, co);
	carrito1 = new DecoradorEmbutido(carrito1, em);
	carrito1 = new DecoradorAbarrote(carrito1, ab);
	
	cout<<carrito1->toString()<<endl;*/
	Minisuper* minisuper = new Minisuper();
	cout<<"Ingresando producto..."<<endl;
	minisuper->ingresarProducto(ab);
	minisuper->ingresarProducto(em);
	Producto* aux = minisuper->eliminarProducto("code1");
	std::cout << "Este es el producto a eliminar: \n" <<  aux->toString() << endl;
	delete aux;
	delete minisuper;
	return 0;
}