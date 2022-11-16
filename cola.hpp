

#ifndef COLA_HPP
#define COLA_HPP

using namespace std;
#include <iostream>

// PREDECLARACIÓN DEL TAD GENÉRICO cola

template <typename Elemento> struct Cola;

// Devuelve  una cola vacia, 0 elementos
template <typename Elemento> void vacia(Cola<Elemento> &c);

// Devuelve la cola resultante de añadir un elemento "e" a "c"
template <typename Elemento>
void encolar(Cola<Elemento> &c, const Elemento &dato);

// Si "c" no es vacía, devuelve la cola resultante de eliminar el primer
// elemento encolado a "c"
template <typename Elemento> void desencolar(Cola<Elemento> &c);

// Devuelve el primer elemento encolado de "c"
template <typename Elemento>
void primero(const Cola<Elemento> &c, Elemento &dato, bool &error);

// Si la cola está vacia devuelve true, en caso de que no esté vacia devulve
// false
template <typename Elemento> bool esVacia(const Cola<Elemento> &c);

// Devuelve el número de elementos que tiene la cola
template <typename Elemento> int longitud(const Cola<Elemento> &c);

//
template <typename Elemento> void iniciarIterador(Cola<Elemento> &c);

//
template <typename Elemento> bool haySiguiente(const Cola<Elemento> &c);

//
template <typename Elemento>
bool siguienteYavanza(Cola<Elemento> &c, Elemento &dato);

// DECLARACIÓN DEL TAD GENÉRICO cola

template <typename Elemento> struct Cola {
  friend void vacia<Elemento>(Cola<Elemento> &c);
  friend void encolar<Elemento>(Cola<Elemento> &c, const Elemento &dato);
  friend void desencolar<Elemento>(Cola<Elemento> &c);
  friend void primero<Elemento>(const Cola<Elemento> &c, Elemento &dato,
                                bool &error);
  friend bool esVacia<Elemento>(const Cola<Elemento> &c);
  friend int longitud<Elemento>(const Cola<Elemento> &c);
  friend void iniciarIterador<Elemento>(Cola<Elemento> &c);
  friend bool haySiguiente<Elemento>(const Cola<Elemento> &c);
  friend bool siguienteYavanza<Elemento>(Cola<Elemento> &c, Elemento &dato);

private:
  struct Nodo {
    Elemento valor;
    Nodo *siguiente;
  };
  Nodo *elPrimero;
  Nodo *elUltimo;
  int numDatos;
  Nodo *iter;
};

// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO cola

template <typename Elemento> void vacia(Cola<Elemento> &c) {
  c.elPrimero = nullptr;
  c.elUltimo = nullptr;
  c.numDatos = 0;
  c.iter = nullptr;
}
template <typename Elemento>
void encolar(Cola<Elemento> &c, const Elemento &dato) {
  if (c.elPrimero == nullptr) {
    c.elUltimo = new typename Cola<Elemento>::Nodo;
    c.elPrimero = c.elUltimo;
  } else {
    c.elUltimo->siguiente = new typename Cola<Elemento>::Nodo;
    c.elUltimo = c.elUltimo->siguiente;
  }
  c.elUltimo->valor = dato;
  c.elUltimo->siguiente = nullptr;
  c.numDatos++;
}
template <typename Elemento> void desencolar(Cola<Elemento> &c) {
  if (c.elPrimero != nullptr &&
      c.elPrimero->siguiente != nullptr) { // lista  no vacia && mas de un elemento
    typename Cola<Elemento>::Nodo *aux;
    aux = c.elPrimero;
    delete c.elPrimero; 
    c.elPrimero = aux->siguiente;
   
  } else if (c.elPrimero->siguiente == nullptr) { // un elemento en la cola
    c.elUltimo = nullptr;
    
    delete c.elPrimero;
    c.elPrimero = nullptr;
  }
   c.numDatos--;
}

template <typename Elemento>
void primero(const Cola<Elemento> &c, Elemento &dato, bool &error) {
  if (c.elPrimero != nullptr) {
    dato = c.elPrimero->valor;
    error = false;
  } else {
    error = true;
  }
}
template <typename Elemento> bool esVacia(const Cola<Elemento> &c) {
  return c.elPrimero == nullptr;
}
template <typename Elemento> int longitud(const Cola<Elemento> &c) {
  return c.numDatos;
}


template <typename Elemento> void iniciarIterador(Cola<Elemento> &c) {
  c.iter = c.elPrimero;
}
template <typename Elemento> bool haySiguiente(const Cola<Elemento> &c) {
  return c.iter != nullptr;
}
template <typename Elemento>
bool siguienteYavanza(Cola<Elemento> &c, Elemento &dato) {
  typename Cola<Elemento>::Nodo* aux;
  if (haySiguiente(c)) {
    // c.iter = c.iter->siguiente;
    // dato = c.iter->valor;    // siguiente
    // aux = c.iter->siguiente; // avanza
    // c.iter->siguiente = aux->siguiente;

    dato = c.iter->valor;    // siguiente
    c.iter = c.iter->siguiente; // avanza


    return true;
  } else {
    return false;
  }
}

#endif