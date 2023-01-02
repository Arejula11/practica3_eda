/* ----------------------------------------------------------------------------
 * File:   colaprio.hpp
 * Author: Pablo Angusto Delgado 842255 y Miguel Aréjula Aisa 850068
 * Date:   noviembre 2022
 * Coms:   Práctica 3 de EDA declaración del TAD genérico colaprio
 *         
 * -----------------------------------------------------------------------------
 */

#ifndef COLAPRIO_HPP
#define COLAPRIO_HPP

#include "cola.hpp"

// using namespace std;

// PREDECLARACIÓN DEL TAD GENÉRICO colaprio

// Los valores del TAD representan una cola con prioridad de elementos con comportamiento
// similar al FIFO. Al tener los elementos prioridad no siempre el primero en entrar es 
// el primero en salir. Los elementos con priridad saldrán antes que los elementos sin prioridad.
// En la cola se permiten repetidos. La colección cuenta con un iterador que permite recorrer toda la
// colección, yendo de la primero en entrar a la última.
template <typename Elemento> struct Colaprio;

// Definición de las operaciones:
//-------------------------------------------------

// Crea  una cola vacia con 0 elementos
// Parametros:
//    Entrada/salida: c de tipo Cola
template <typename Elemento> void vacia(Colaprio<Elemento> &c);


// Devuelve la cola resultante de añadir un elemento "e" a "c" como elemento 
// prioritario si prio es verdad o como no prioritario en caso contrario
// Parametros:
//    Entrada:  dato de tipo Elemento, prio de tipo booleano
//    Entrada/salida:  c de tipo Cola
template <typename Elemento>
void encolar(Colaprio<Elemento> &c, const Elemento &dato, const bool prio);

// Si la cola está vacia devuelve true, en caso de que no esté vacia devulve
// false
// Parametros:
//    Entrada/salida: c de tipo Cola
//    Salida: booleano
template <typename Elemento> bool esVacia(const Colaprio<Elemento> &c);

// Si esVacia(c), devuelve la cola vacía. Si "c" no es vacía, devuelve la cola resultante
// de eliminar el primer elemento encolado a "c" como prioritario, en el caso de que no haya 
// prioritarios devuelve el primero no prioritario encolado
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> void desencolar(Colaprio<Elemento> &c);


// Devuelve el primer elemento encolado de "c" como prioritario de los que 
// hay en c. Si no hay ningún elemento prioritario, devuelve el primer elemento
// encolado como no prioritario.
// Parametros:
//    Entrada:  dato de tipo elemento
//    Entrada/salida:  c de tipo Cola,  error de tipo booleano
template <typename Elemento>
void primero(const Colaprio<Elemento> &c, Elemento &dato, bool &error);


// Devuelve el número de elementos que tiene la cola
// Parametros:
//    Entrada/salida:  c de tipo Cola
//    Salida: entero
template <typename Elemento> int longitud(const Colaprio<Elemento> &c);

// Si prio es verdad, devuelve el número de elementos prioritarios de c;
// en caso contrario, devuelve el número de elementos no prioritarios de "c"
// Parametros:
//    Entrada: prio de tipo booleano
//    Entrada/salida:  c de tipo Cola
//    Salida: entero
template <typename Elemento>
int longClase(const Colaprio<Elemento> &c, const bool prio);

// Prepara el iterador para que el sigugiente elemento a visitar sea el primero 
// de la cola "c" (entendido según la operación primero(c) previamente especificada),
// si es que existe
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> void iniciarIterador(Colaprio<Elemento> &c);

// Devuelve falso si ya se han visitado todos los elementos de "c", devuelve verdad 
// en caso contrario
//    Entrada/salida:  c de tipo Cola
//    Salida: booleano
template <typename Elemento> bool haySiguiente(const Colaprio<Elemento> &c);

// Devuelve el siguiente elemento de c prioritario que fue encolado, si lo hay. Si no quedan mas 
// devuelve el priemer elemento no prioritario encolado, si lo hay.
// Además Devuelve la cola resultante de avanzar el iterador en c al
// siguiente elemento que fue encolado y pendiente de visitar, si lo
// hay. 
// Parcial: la operación no está definida si no
// existeSiguiente(c).
// Parametros:
//    Entrada/salida:  c de tipo Cola,  dato de tipo elemento
//    Salida: booleano
template <typename Elemento>
bool siguienteYavanza(Colaprio<Elemento> &c, Elemento &dato);

// DECLARACIÓN DEL TAD GENÉRICO colaprio

template <typename Elemento> struct Colaprio {
  friend void vacia<Elemento>(Colaprio<Elemento> &c);
  friend void encolar<Elemento>(Colaprio<Elemento> &c, const Elemento &dato,
                                const bool prio);
  friend bool esVacia<Elemento>(const Colaprio<Elemento> &c);
  friend void desencolar<Elemento>(Colaprio<Elemento> &c);
  friend void primero<Elemento>(const Colaprio<Elemento> &c, Elemento &dato,
                                bool &error);
  friend int longitud<Elemento>(const Colaprio<Elemento> &c);
  friend int longClase<Elemento>(const Colaprio<Elemento> &c, const bool prio);
  friend void iniciarIterador<Elemento>(Colaprio<Elemento> &c);
  friend bool haySiguiente<Elemento>(const Colaprio<Elemento> &c);
  friend bool siguienteYavanza<Elemento>(Colaprio<Elemento> &c, Elemento &dato);

private:
  // La colección de elementos se trata de dos colas. Una cola pertenece a los
  // elementos con prioridad y la otra a los elementos sin
  Cola<Elemento> prioritaria;
  Cola<Elemento> normal;
};

// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO colaprio

// Crea  una cola vacia con 0 elementos
// Llama a la funcion que crea las colas vacias del TAD cola
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada/salida: c de tipo Cola
template <typename Elemento> void vacia(Colaprio<Elemento> &c) {
  vacia(c.prioritaria);
  vacia(c.normal);
}

// Devuelve la cola resultante de añadir un elemento "e" a "c" como elemento 
// prioritario si prio es verdad o como no prioritario en caso contrario
// Si prio es true encola el elemento en la cola prioritaria, en caso contrario 
// encola en la no prioritaria
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada:  dato de tipo Elemento, prio de tipo booleano
//    Entrada/salida:  c de tipo Cola
template <typename Elemento>
void encolar(Colaprio<Elemento> &c, const Elemento &dato, const bool prio) {
  if (prio) {
    encolar(c.prioritaria, dato);
  } else {
    encolar(c.normal, dato);
  }
}

// Si las colas están vacia devuelve true, en caso de que no estén vacias devulve
// false
// Comprueba si ambas colas son vacias devuelve true, en caso de que una de las dos 
// tenga algun elemento devuelve falso
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada/salida: c de tipo Cola
//    Salida: booleano
template <typename Elemento> bool esVacia(const Colaprio<Elemento> &c) {
  return esVacia(c.prioritaria) && esVacia(c.normal);

// Si esVacia(c), devuelve la cola vacía. Si "c" no es vacía, devuelve la cola resultante
// de eliminar el primer elemento encolado con a "c" como prioritario, en el caso de que no haya 
// prioritarios devuelve el primero no prioritario encolado
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola
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
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada:  dato de tipo elemento
//    Entrada/salida:  c de tipo Cola,  error de tipo booleano
template <typename Elemento>
void primero(const Colaprio<Elemento> &c, Elemento &dato, bool &error) {
  if (esVacia(c.prioritaria)) {
    primero(c.normal, dato, error);
  } else {
    primero(c.prioritaria, dato, error);
  }
}
}
// Devuelve el número de elementos que tiene la cola
// Devuelve el longitud de ambas colas
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola
//    Salida: entero
template <typename Elemento> int longitud(const Colaprio<Elemento> &c) {
  return longitud(c.prioritaria) + longitud(c.normal);
}

// Si prio es verdad, devuelve el número de elementos prioritarios de c;
// en caso contrario, devuelve el número de elementos no prioritarios de "c"
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada: prio de tipo booleano
//    Entrada/salida:  c de tipo Cola
//    Salida: entero
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
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola
template <typename Elemento> void iniciarIterador(Colaprio<Elemento> &c) {
  iniciarIterador(c.normal);
  iniciarIterador(c.prioritaria);
}

// Devuelve falso si ya se han visitado todos los elementos de "c", devuelve verdad 
// en caso contrario
// El coste de esta operación es constante O(1)
//    Entrada/salida:  c de tipo Cola
//    Salida: booleano
template <typename Elemento> bool haySiguiente(const Colaprio<Elemento> &c) {
  return haySiguiente(c.prioritaria) || haySiguiente(c.normal);
}

// Devuelve el siguiente elemento de c prioritario que fue encolado, si lo hay. Si no quedan mas 
// devuelve el priemer elemento no prioritario encolado, si lo hay.
// Además Devuelve la cola resultante de avanzar el iterador en c al
// siguiente elemento que fue encolado y pendiente de visitar, si lo
// hay. 
// Parcial: la operación no está definida si no
// existeSiguiente(c).
// El coste de esta operación es constante O(1)
// Parametros:
//    Entrada/salida:  c de tipo Cola,  dato de tipo elemento
//    Salida: booleano
template <typename Elemento>
bool siguienteYavanza(Colaprio<Elemento> &c, Elemento &dato) {
  if (!haySiguiente(c.prioritaria)) {
      return siguienteYavanza(c.normal, dato);
  }else if(haySiguiente(c.normal)){
      return siguienteYavanza(c.prioritaria, dato);
  
    
  }else{
      return false;
    
  }
}

#endif