#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
template<class T>
class ListaEnlazada {
private:
	Nodo<T>* primero;
public:
	ListaEnlazada();
	virtual ~ListaEnlazada();
	void agregarInicio(T* objeto);
	void agregarFinal(T* objeto);
	void removerInicio();
	void removerFinal();
	bool estaVacio();
	unsigned int cantidad();
	T* obtener(unsigned int posicion);
	T* sacarDato(unsigned int posicion=0);//Por defecto saca el primer dato
	T* inicio();
	T* final();
	Nodo<T>* getPrimero();
};

template<class T>
ListaEnlazada<T>::ListaEnlazada() { primero = nullptr; }

template<class T>
ListaEnlazada<T>::~ListaEnlazada() {
	while (primero != nullptr) {
		Nodo<T>* aux = primero;
		T* dato = aux->getDato();
		primero = primero->getSig();
		delete aux;
		delete dato;
	}
}

template<class T>
void ListaEnlazada<T>::agregarInicio(T* objeto) {
	Nodo<T>* nuevo = new Nodo<T>(objeto);
	nuevo->setSig(primero);
	primero = nuevo;
}

template<class T>
void ListaEnlazada<T>::agregarFinal(T* objeto) {
	Nodo<T>* nuevo = new Nodo<T>(objeto);
	if (primero == nullptr) primero = nuevo;
	else {
		Nodo<T>* aux = primero;
		while (aux->getSig() != nullptr) {
			aux = aux->getSig();
		}
		aux->setSig(nuevo);
	}
}

template<class T>
void ListaEnlazada<T>::removerInicio() {//elimina el DATO del primer nodo
	if (primero == nullptr) throw "Error: la lista esta vacia\n";
	Nodo<T>* aux = primero;
	primero = primero->getSig();
	delete aux;
}

template<class T>
void ListaEnlazada<T>::removerFinal() {//elimina el DATO del ultimo nodo
	if (primero == nullptr) throw "Error: la lista esta vacia\n";
	Nodo<T>* aux = primero;
	while (aux->getSig()->getSig() != nullptr) {
		aux = aux->getSig();
	}
	delete aux->getSig();
	aux->setSig(nullptr);
}

template<class T>
bool ListaEnlazada<T>::estaVacio() {
	return primero == nullptr;
}

template<class T>
unsigned int ListaEnlazada<T>::cantidad() {
	int i;
	Nodo<T>* aux = primero;
	for (i = 0; aux != nullptr; aux = aux->getSig(), i++);
	return i;
}

template<class T>
T* ListaEnlazada<T>::obtener(unsigned int n) {//devuelve un puntero al dato en la posicion n
	if (primero == nullptr) throw "Error: la lista esta vacia\n";
	if (n >= cantidad()) throw "Error: indice fuera de rango de la lista\n";
	Nodo<T>* aux = primero;
	while (n > 0) {
		aux = aux->getSig();
		n--;
	}
	return aux->getDato();
}

template<class T>
T* ListaEnlazada<T>::sacarDato(unsigned int n) {//saca el dato en la posicion n y devuelve un puntero a el sin borrarlo
	if (primero == nullptr) throw "Error: la lista esta vacia\n";
	if (n > cantidad()) throw "Error: indice fuera de rango de la lista\n";
	Nodo<T>* aux = primero;
	Nodo<T>* aux2 = aux;
	while (n > 0) {
		aux2 = aux;
		aux = aux->getSig();
		n--;
	}
	if (aux == primero) {
		primero = aux->getSig();
		aux->setSig(nullptr);
		T* dato = aux->getDato();
		delete aux;
		return dato;
	}
	else {
		T* dato = aux->getDato();
		aux2->setSig(aux->getSig());
		aux->setSig(nullptr);
		delete aux;
		return dato;
	}
}

template<class T>
T* ListaEnlazada<T>::inicio() {
	if (primero == nullptr) throw "Error: la lista esta vacia\n";
	return primero->getDato();
}

template<class T>
T* ListaEnlazada<T>::final() {
	if (primero == nullptr) throw "Error: la lista esta vacia\n";
	Nodo<T>* aux = primero;
	while (aux->getSig() != nullptr) {
		aux = aux->getSig();
	}
	return aux->getDato();
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::getPrimero()
{
	return primero;
}

#endif