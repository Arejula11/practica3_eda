/* ----------------------------------------------------------------------------
 * File:   cola.hpp
 * Author: Pablo Angusto Delgado 842255 y Miguel Aréjula Aisa 850068
 * Date:   noviembre 2022
 * Coms:   Práctica 3 de EDA declaración del TAD genérico cola
 *
 * -----------------------------------------------------------------------------
 */

#ifndef COLA_HPP
#define COLA_HPP

using namespace std;
#include <iostream>

// PREDECLARACIÓN DEL TAD GENÉRICO cola

// Los valores del TAD representan una cola de elementos con comportamiento
// FIFO, el primero que entra es el primero que sale . En la cola se permiten
// repetidos. La colección cuenta con un iterador que permite recorrer toda la
// colección, yendo de la primero en entrar a la última.
template <typename Elemento> struct Cola;

// Definición de las operaciones:
//-------------------------------------------------

// Crea  una cola vacia con 0 elementos
//Parametros:
//    Entrada/salida: c de tipo cola
template <typename Elemento> void vacia(Cola<Elemento> &c);

// Devuelve la cola resultante de añadir un elemento e a c
// Parametros:
//    Entrada:  dato de tipo Elemento
//    Entrada/salida:  c de tipo Cola
template <typename Elemento>
void encolar(Cola<Elemento> &c, const Elemento &dato);

// Solo  y solo si la cola está vacia devuelve true, en caso contario devulve
// false 
// Parametros:
//    Entrada/salida: c de tipo Cola
template <typename Elemento> bool esVacia(const Cola<Elemento> &c);

// Si esVacia(c), devuelve la cola vacia. Si NOT esVacia(c), devuelve la cola
// resultante de eliminar el primer elemento encolado en c
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> void desencolar(Cola<Elemento> &c);

// Devuelve el primer elemento encolado de c solo y solo si NOT esVacia(c)
// Parametros:
//    Entrada:  dato de tipo elemento
//    Salida:   error de tipo booleano
//    Entrada/salida:  c de tipo Cola
template <typename Elemento>
void primero(const Cola<Elemento> &c, Elemento &dato, bool &error);

// Devuelve el número de elementos que tiene la cola c
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> int longitud(const Cola<Elemento> &c);

// Prepara el iterador para que el siguiente elemento a visitar sea el primero
// de la cola c, si es que existe
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> void iniciarIterador(Cola<Elemento> &c);

// Devuelve falso si ya se han visitado todos los elementos de c, en caso
// contrario devuelve verdad Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> bool haySiguiente(const Cola<Elemento> &c);

// Devuelve el siguiente elemento de c que fue encolado, si lo hay.
// Además Devuelve la cola resultante de avanzar el iterador en c al
// siguiente elemento que fue encolado y pendiente de visitar, si lo
// hay. 
// Parcial: la operación no está definida si no
// existeSiguiente(c).
// Parametros:
//    Entrada/salida:  c de tipo Cola,  dato de tipo elemento
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
  // La colección de elementos se trata de tipo de datos lineales, en los
  // cuales se guarda la posición del siguiente nodo. La colleción tambien 
  // guarda en un entero el número de elementos totales que hay en la cola
  // disminuyendo el coste en tiempo de la operación longitud(), a un coste 
  // constente O(n)

  // Se define el Nodo propio de la cola
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
//----------------------------------------------------------

// Crea  una cola vacia con 0 elementos, para 
// ello inicializa todas las variables de la cola
// Coste constante en tiempo O(1)
template <typename Elemento> void vacia(Cola<Elemento> &c) {
  c.elPrimero = nullptr;
  c.elUltimo = nullptr;
  c.numDatos = 0;
  c.iter = nullptr;
  
}
// La función devuelve el valor de la variable elPrimero, la cual
// representa el primer elemento añadido a la cola, y por tanto, 
// solo  y solo si la cola está vacia devuelve true, en caso contario 
// devulve false
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada/salida: c de tipo Cola
template <typename Elemento> bool esVacia(const Cola<Elemento> &c) {
  return c.elPrimero == nullptr;
}

// Devuelve la cola resultante de añadir un elemento e a c.
// La funcón mira si la cola está vacia, si lo está asigna a la 
// variable elPrimero y a elUltimo el elemento que se ha dado para encolar. 
// En caso contrario lo asigna únicamente a la varibale elUltimo
// El coste de la operación es constante O(1)
// Parametros:
//    Entrada:  dato de tipo Elemento
//    Entrada/salida:  c de tipo Cola
template <typename Elemento>
void encolar(Cola<Elemento> &c, const Elemento &dato) {
  if (esVacia(c)) {
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

// Si esVacia(c), devuelve la cola vacia. Si NOT esVacia(c), devuelve la cola
// resultante de eliminar el primer elemento encolado en c.
// En caso que la cola este vacia no se realiza nada, en caso que haya uno o más 
// elementos se distinguen dos casos, la cola tenga un único elemento o si tiene
// más de un elemento. En el primer caso se elimina el valor asociado a la variable
// elPrimero y a la variable elUltimo, en el segundo caso unicamente la que está asociado 
// a elPrimero. En ambos casos los punteros que quedan si apuntar a ningun dato se les asigna el valor nil
// El coste de la operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento>
void desencolar(
    Cola<Elemento> &c) { 
  if(!esVacia(c)){ // cola no vacia
      if(c.elPrimero->siguiente != nullptr){ // cola  no vacia && mas de un elemento
      typename Cola<Elemento>::Nodo *aux;
      aux = c.elPrimero;
      delete c.elPrimero;
      c.elPrimero = aux->siguiente;

    } else if (c.elPrimero->siguiente == nullptr){ //cola no vacia && un elemento en la cola
      c.elUltimo = nullptr;
      delete c.elPrimero;
      c.elPrimero = nullptr;
    }
    c.numDatos--;
  }
}

// Devuelve el primer elemento encolado de c solo y solo si NOT esVacia(c)
// En caso que la cola este vacia error = true. 
// Si la cola no está vacia error = true y dato = el valor del primer elemento encolado
// El coste de la operación es constante O(1)
// Parametros:
//    Entrada:  dato de tipo elemento
//    Salida:   error de tipo booleano
//    Entrada/salida:  c de tipo Cola
template <typename Elemento>
void primero(const Cola<Elemento> &c, Elemento &dato, bool &error) {
  if (esVacia(c)) {
    dato = c.elPrimero->valor;
    error = false;
  } else {
    error = true;
  }
}
// Devuelve el número de elementos que tiene la cola c
// Devuelve la variable numDatos que es aumentada cada vez que se encola un dato y se disminuye cuando se desencola
// El coste de la operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> int longitud(const Cola<Elemento> &c) {
  return c.numDatos;
}

// Prepara el iterador para que el siguiente elemento a visitar sea el primero
// de la cola c, si es que existe
// Se asigna la variable correspondiente al iterador al primer dato encolado
// El coste de la operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> void iniciarIterador(Cola<Elemento> &c) {
  c.iter = c.elPrimero;
}
// Devuelve falso si ya se han visitado todos los elementos de c, en caso
// contrario devuelve verdad 
// Devuelve falso en el caso que la variable correspondiente al iterador este 
// apuntando a nil. En caso contrario devuelve true.
// El coste de la operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> bool haySiguiente(const Cola<Elemento> &c) {
  return c.iter != nullptr;
}

// Devuelve el siguiente elemento de c que fue encolado, si lo hay.
// Además Devuelve la cola resultante de avanzar el iterador en c al
// siguiente elemento que fue encolado y pendiente de visitar, si lo
// hay. 
// Parcial: la operación no está definida si no existeSiguiente(c).
// Para devolver el siguiente dato encolado, se deuvlve el valor al
// que esta apuntando la variable correspondiente al iterador. Y para 
// avazar asigna a la variable del iterador la dirección de memoria en
// la que se encuentra el siguiente dato
// El coste de la operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola,  dato de tipo elemento
template <typename Elemento>
bool siguienteYavanza(Cola<Elemento> &c, Elemento &dato) {
  typename Cola<Elemento>::Nodo *aux;
  if (haySiguiente(c)) {
    dato = c.iter->valor;       // siguiente
    c.iter = c.iter->siguiente; // avanza
    return true;
  } else {
    return false;
  }
}

#endif