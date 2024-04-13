#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo {
	T* dato;
	Nodo<T>* sig;
public:
	Nodo(T* dato);
	virtual ~Nodo();
	T* getDato();
	Nodo<T>* getSig();
	void setDato(T* dato);
	void setSig(Nodo<T>* siguienteNodo);
};

template<class T>
Nodo<T>::Nodo(T* t) : sig(nullptr) { dato = t; }

template<class T>
Nodo<T>::~Nodo() {}//Este destructor NO borra el dato, solo el nodo

template<class T>
T* Nodo<T>::getDato() { return dato; }

template<class T>
Nodo<T>* Nodo<T>::getSig() { return sig; }

template<class T>
void Nodo<T>::setDato(T* t) { dato = t; }

template<class T>
void Nodo<T>::setSig(Nodo<T>* sN) { sig = sN; }

#endif