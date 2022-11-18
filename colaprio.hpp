
#ifndef COLAPRIO_HPP
#define COLAPRIO_HPP

#include "cola.hpp"

// using namespace std;

// PREDECLARACIÓN DEL TAD GENÉRICO cola

template <typename Elemento> struct Colaprio;

// Crea  una cola vacia, 0 elementos
template <typename Elemento> void vacia(Colaprio<Elemento> &c);


// Devuelve la cola resultante de añadir un elemento "e" a "c" como elemento 
// prioritario si prio es verdad o como no prioritario en caso contrario
template <typename Elemento>
void encolar(Colaprio<Elemento> &c, const Elemento &dato, const bool prio);


// Si esVacia(c), devuelve la cola vacía. Si "c" no es vacía, devuelve la cola resultante
// de eliminar el primer elemento encolado a "c" como prioritario, en el caso de que no haya 
// prioritarios devuelve el primero no prioritario encolado
template <typename Elemento> void desencolar(Colaprio<Elemento> &c);


// Devuelve el primer elemento encolado de "c" como prioritario de los que 
// hay en c. Si no hay ningún elemento prioritario, devuelve el primer elemento
// encolado como no prioritario.
template <typename Elemento>
void primero(const Colaprio<Elemento> &c, Elemento &dato, bool &error);

// Si la cola está vacia devuelve true, en caso de que no esté vacia devulve
// false
template <typename Elemento> bool esVacia(const Colaprio<Elemento> &c);

// Devuelve el número de elementos que tiene la cola
template <typename Elemento> int longitud(const Colaprio<Elemento> &c);

// Si prio es verdad, devuelve el número de elementos prioritarios de c;
// en caso contrario, devuelve el número de elementos no prioritarios de "c"
template <typename Elemento>
int longClase(const Colaprio<Elemento> &c, const bool prio);

// Prepara el iterador para que el sigugiente elemento a visitar sea el primero 
// de la cola "c" (entendido según la operación primero(c) previamente especificada),
// si es que existe
template <typename Elemento> void iniciarIterador(Colaprio<Elemento> &c);

// Devuelve falso si ya se han visitado todos los elementos de "c", devuelve verdad 
//en caso contrario
template <typename Elemento> bool haySiguiente(const Colaprio<Elemento> &c);

// Devuelve el siguiente elemento prioritario de c que fue encolado, si lo hay; si por el
// contrario ya no hay más elementos prioritarios en c pendientes de visitar, devuelve el
// siguiente elemento no prioritario de c que fue encolado, si lo hay. Además Devuelve la 
// cola resultante de avanzar el iterador en c al siguiente elemento prioritario que fue 
// encolado y pendiente de visitar, si lo hay; si por el contrario ya no hay más elementos 
// prioritarios en c pendientes de visitar, avanza al siguiente elemento no prioritario de
// c pendiente de visitar, si lo hay.
// Parcial: la operación no está definida si no existeSiguiente(c).
template <typename Elemento>
bool siguienteYavanza(Colaprio<Elemento> &c, Elemento &dato);

// DECLARACIÓN DEL TAD GENÉRICO cola

template <typename Elemento> struct Colaprio {
  friend void vacia<Elemento>(Colaprio<Elemento> &c);
  friend void encolar<Elemento>(Colaprio<Elemento> &c, const Elemento &dato,
                                const bool prio);
  friend void desencolar<Elemento>(Colaprio<Elemento> &c);
  friend void primero<Elemento>(const Colaprio<Elemento> &c, Elemento &dato,
                                bool &error);
  friend bool esVacia<Elemento>(const Colaprio<Elemento> &c);
  friend int longitud<Elemento>(const Colaprio<Elemento> &c);
  friend int longClase<Elemento>(const Colaprio<Elemento> &c, const bool prio);
  friend void iniciarIterador<Elemento>(Colaprio<Elemento> &c);
  friend bool haySiguiente<Elemento>(const Colaprio<Elemento> &c);
  friend bool siguienteYavanza<Elemento>(Colaprio<Elemento> &c, Elemento &dato);

private:
  Cola<Elemento> prioritaria;
  Cola<Elemento> normal;
};

// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO cola

// Crea  una cola vacia, 0 elementos
template <typename Elemento> void vacia(Colaprio<Elemento> &c) {
  vacia(c.prioritaria);
  vacia(c.normal);
}

// Devuelve la cola resultante de añadir un elemento "e" a "c" como elemento 
// prioritario si prio es verdad o como no prioritario en caso contrario
template <typename Elemento>
void encolar(Colaprio<Elemento> &c, const Elemento &dato, const bool prio) {
  if (prio) {
    encolar(c.prioritaria, dato);
  } else {
    encolar(c.normal, dato);
  }
}

// Si esVacia(c), devuelve la cola vacía. Si "c" no es vacía, devuelve la cola resultante
// de eliminar el primer elemento encolado a "c" como prioritario, en el caso de que no haya 
// prioritarios devuelve el primero no prioritario encolado
template <typename Elemento> void desencolar(Colaprio<Elemento> &c) {
  if (esVacia(c.prioritaria)) {
    desencolar(c.normal);
  } else {
    desencolar(c.prioritaria);    
  }
}

// Devuelve el primer elemento encolado de "c" como prioritario de los que 
// hay en c. Si no hay ningún elemento prioritario, devuelve el primer elemento
// encolado como no prioritario.
template <typename Elemento>
void primero(const Colaprio<Elemento> &c, Elemento &dato, bool &error) {
  if (esVacia(c.prioritaria)) {
    primero(c.normal, dato, error);
  } else {
    primero(c.prioritaria, dato, error);
  }
}

// Si la cola está vacia devuelve true, en caso de que no esté vacia devulve
// false
template <typename Elemento> bool esVacia(const Colaprio<Elemento> &c) {
  return esVacia(c.prioritaria) && esVacia(c.normal);
}

// Devuelve el número de elementos que tiene la cola
template <typename Elemento> int longitud(const Colaprio<Elemento> &c) {
  return longitud(c.prioritaria) + longitud(c.normal);
}

// Si prio es verdad, devuelve el número de elementos prioritarios de c;
// en caso contrario, devuelve el número de elementos no prioritarios de "c"
template <typename Elemento>
int longClase(const Colaprio<Elemento> &c, const bool prio) {
  if (prio) {
    return longitud(c.prioritaria);
  } else {
    return longitud(c.normal);
  }
}

// Prepara el iterador para que el sigugiente elemento a visitar sea el primero 
// de la cola "c" (entendido según la operación primero(c) previamente especificada),
// si es que existe
template <typename Elemento> void iniciarIterador(Colaprio<Elemento> &c) {
  iniciarIterador(c.normal);
  iniciarIterador(c.prioritaria);
}

// Devuelve falso si ya se han visitado todos los elementos de "c", devuelve verdad 
//en caso contrario
template <typename Elemento> bool haySiguiente(const Colaprio<Elemento> &c) {
  return haySiguiente(c.prioritaria) || haySiguiente(c.normal);
}

// Devuelve el siguiente elemento prioritario de c que fue encolado, si lo hay; si por el
// contrario ya no hay más elementos prioritarios en c pendientes de visitar, devuelve el
// siguiente elemento no prioritario de c que fue encolado, si lo hay. Además Devuelve la 
// cola resultante de avanzar el iterador en c al siguiente elemento prioritario que fue 
// encolado y pendiente de visitar, si lo hay; si por el contrario ya no hay más elementos 
// prioritarios en c pendientes de visitar, avanza al siguiente elemento no prioritario de
// c pendiente de visitar, si lo hay.
// Parcial: la operación no está definida si no existeSiguiente(c).
template <typename Elemento>
bool siguienteYavanza(Colaprio<Elemento> &c, Elemento &dato) {
  if (!haySiguiente(c.prioritaria)) {
      return siguienteYavanza(c.normal, dato);
  }else{
      return siguienteYavanza(c.prioritaria, dato);
  
    
  }
  return false;
}

#endif