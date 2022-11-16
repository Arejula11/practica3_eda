
#ifndef COLAPRIO_HPP
#define COLAPRIO_HPP


#include "cola.hpp"

using namespace std;

// PREDECLARACIÓN DEL TAD GENÉRICO cola


template <typename Elemento> struct Colaprio;

// Devuelve  una cola vacia, 0 elementos
template <typename Elemento> void vacia(Colaprio<Elemento>& c);

// Devuelve la cola resultante de añadir un elemento "e" a "c"
template <typename Elemento> void encolar(Colaprio<Elemento>& c, const Elemento& dato, const bool prio);

//Si "c" no es vacía, devuelve la cola resultante de eliminar el primer elemento encolado a "c"
template <typename Elemento> void desencolar(Colaprio<Elemento>& c);

//Devuelve el primer elemento encolado de "c"
template <typename Elemento> void primero(const Colaprio<Elemento>& c, Elemento& dato, bool& error);

//Si la cola está vacia devuelve true, en caso de que no esté vacia devulve false
template <typename Elemento> bool esVacia(const Colaprio<Elemento>& c);

//Devuelve el número de elementos que tiene la cola
template <typename Elemento> int longitud(const Colaprio<Elemento>& c);
//
template <typename Elemento> int longClase(const Colaprio<Elemento>& c, const bool prio);

//
template <typename Elemento> void iniciarIterador(Colaprio<Elemento>& c);

//
 template <typename Elemento> bool haySiguiente(const Colaprio<Elemento>& c);

//
 template <typename Elemento> bool siguienteYavanza(Colaprio<Elemento>& c, Elemento& dato);



// DECLARACIÓN DEL TAD GENÉRICO cola

template <typename Elemento> struct Colaprio{
    friend void vacia<Elemento>(Colaprio<Elemento>& c);
    friend void encolar<Elemento>(Colaprio<Elemento>& c, const Elemento& dato, const bool prio);
    friend void desencolar<Elemento>(Colaprio<Elemento>& c);
    friend void primero<Elemento>(const Colaprio<Elemento>& c, Elemento& dato, bool& error);
    friend bool esVacia<Elemento>(const Colaprio<Elemento>& c);
    friend int longitud<Elemento>(const Colaprio<Elemento>& c);
    friend int longClase<Elemento>(const Colaprio<Elemento>& c, const bool prio);
    friend void iniciarIterador<Elemento>(Colaprio<Elemento>& c);
    friend bool haySiguiente<Elemento>(const Colaprio<Elemento>& c);
    friend bool siguienteYavanza<Elemento>(Colaprio<Elemento>& c, Elemento& dato);
    private:
    struct Nodo {
        Elemento valor;
        Nodo* siguiente;
        bool prioridad;
    };
    Nodo* elPrimero ;
    // Nodo* elPrimerioprio;
    Nodo* elUltimo;
    Nodo* elUltimoprio;
    int numDatos;
    int numDatosprio;
    Nodo* iter;
    Nodo* aux;
};

// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO cola

template <typename Elemento> void vacia(Colaprio<Elemento>& c){
    c.elPrimero = nullptr;
    c.elUltimo = nullptr;
    c.elUltimoprio = nullptr;
    c.numDatos = 0;
}
template <typename Elemento> void encolar(Colaprio<Elemento>& c, const Elemento& dato, const bool prio){
    if(prio){
        if(c.numDatos + c.numDatosprio == 0){ // lista vacia 
            c.elUltimoprio = new typename Colaprio<Elemento>::Nodo;
            c.elPrimero = c.elUltimoprio;
            c.elUltimo = c.elUltimoprio;
            // c.elUltimo->siguiente = nullptr;
            // c.elUltimoprio->siguiente = nullptr; // preguntar si al crear el nodo se pone el siguiente a nullptr
        }else{ // lista no vacia 
            c.aux = c.elUltimoprio;
            c.elUltimoprio = new typename Colaprio<Elemento>::Nodo;
            c.elUltimoprio->siguiente= c.aux->siguiente;
        }
        c.elUltimoprio->valor = dato;
        c.numDatosprio++;
        c.elUltimo->prioridad = prio;
    }else{ // preguntar como usar encolar de cola.hpp
        if(c.numDatos + c.numDatosprio == 0){
            c.elUltimo = new typename Colaprio<Elemento>::Nodo;
            c.elPrimero = c.elUltimo;
        }else{
            c.elUltimo->siguiente = new typename Colaprio<Elemento>::Nodo;
            c.elUltimo = c.elUltimo->siguiente;
        }
        c.elUltimo->valor = dato;
        c.elUltimo->siguiente= nullptr;
        c.numDatos++;
        c.elUltimo->prioridad = prio;
    }
    
}
template <typename Elemento> void desencolar(Colaprio<Elemento>& c){ // preguntar como usar desencolar de cola.hpp
    // if(c.elPrimero->prioridad){
    //     if (c.elPrimero != nullptr && c.elPrimero->siguiente != nullptr){ // lista  no vacia && mas de un elemento
    //     c.aux = c.elPrimero;
    //     delete typename Cola<Elemento>::Nodo(c.elPrimero);  //preguntar cual elimina
    //     c.elPrimero  = c.aux;
    //     c.numDatosprio--;
    //     }
    //     else if (c.elPrimero->siguiente == nullptr){ // un elemento en la cola
    //         c.elUltimo = nullptr;
    //         c.numDatosprio--;
    //         delete typename Cola<Elemento>::Nodo(c.elPrimero); 
    //         c.elPrimero = nullptr;
    //     }
    // }else{
    //     if (c.elPrimero != nullptr && c.elPrimero->siguiente != nullptr){ // lista  no vacia && mas de un elemento
    //     c.aux = c.elPrimero;
    //     delete typename Cola<Elemento>::Nodo(c.elPrimero);  //preguntar cual elimina
    //     c.elPrimero  = c.aux;
    //     c.numDatos--;
    //     }
    //     else if (c.elPrimero->siguiente == nullptr){ // un elemento en la cola
    //         c.elUltimo = nullptr;
    //         c.numDatos--;
    //         delete typename Cola<Elemento>::Nodo(c.elPrimero); 
    //         c.elPrimero = nullptr;
    //     }
    // }

    if(c.elPrimero->siguiente == nullptr){//caso solo un elemento
            c.elUltimo = nullptr;
            delete typename Cola<Elemento>::Nodo(c.elPrimero); 
            c.elPrimero = nullptr;
            if (c.elPrimero->prioridad){ //si c.elUltimoprio== nullptr sabemos q es no prio
                c.numDatosprio--;
            }else{
                c.numDatos--;
            }
    }
    if(c.elPrimero != nullptr && c.elPrimero->siguiente != nullptr && c.elPrimero=c.elUltimoprio ){ // caso un prio y mas de un no prio
        c.elUltimoprio = nullptr;

    }
    // caso de mas de un prio
    //caso de no haya prio y mas de un no prio ( desencolar cola.hpp)
    
    
        
    
}

template <typename Elemento> void primero(const Colaprio<Elemento>& c, Elemento& dato, bool& error){
    if(c.elPrimero!=nullptr){
        dato=c.elPrimero->valor;
        error=false;

    }else{
        error=true;
    }
}
template <typename Elemento> bool esVacia(const Colaprio<Elemento>& c){
    return c.elPrimero == nullptr && c.elPrimerioprio == nullptr;
}
template <typename Elemento> int longitud(const Colaprio<Elemento>& c){
    return c.numDatos+c.numDatosprio;
}

template <typename Elemento> int longClase(const Colaprio<Elemento>& c, const bool prio){
    if (prio){
        return c.numDatosprio;
    }else{
        return c.numDatos;
    }
}
    




template <typename Elemento> void iniciarIterador(Colaprio<Elemento>& c){
    Elemento dato;
    bool error;
    primero(c,dato, error);
    if(!error){
        c.iter->siguiente=c.elPrimero;
    }
}
template <typename Elemento> bool haySiguiente(const Colaprio<Elemento>& c){
    return c.iter->siguiente == nullptr;
}
template <typename Elemento> bool siguienteYavanza(Colaprio<Elemento>& c, Elemento& dato){
    if(haySiguiente(c)){
        dato = (c.iter->siguiente)->valor;
        c.iter=c.iter->siguiente;
        return true;
    }else{
        return false;
    }
}



#endif