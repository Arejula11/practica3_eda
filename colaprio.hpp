
#ifndef COLAPRIO_HPP
#define COLAPRIO_HPP


#include "cola.hpp"

// using namespace std;

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
        Cola<Elemento> prioritaria;
        Cola<Elemento> normal;

};

// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO cola

template <typename Elemento> void vacia(Colaprio<Elemento>& c){
    vacia(c.prioritaria);
    vacia(c.normal);
}
    
template <typename Elemento> void encolar(Colaprio<Elemento>& c, const Elemento& dato, const bool prio){
    if(prio){
        encolar(c.prioritaria, dato);
    }else{
        encolar(c.normal, dato);
    }
    
}
template <typename Elemento> void desencolar(Colaprio<Elemento>& c){ 
    if(esVacia(c.prioritaria)){
        desencolar(c.normal);
    }else{
        desencolar(c.prioritaria);
    }
        
    
}

template <typename Elemento> void primero(const Colaprio<Elemento>& c, Elemento& dato, bool& error){
    if(esVacia(c.prioritaria)){
        primero(c.normal,dato,error);
    }else{
        primero(c.prioritaria, dato, error);
    }
}
template <typename Elemento> bool esVacia(const Colaprio<Elemento>& c){
    return esVacia(c.prioritaria) && esVacia(c.normal);
}
template <typename Elemento> int longitud(const Colaprio<Elemento>& c){
    return longitud(c.prioritaria) + longitud(c.normal);
}

template <typename Elemento> int longClase(const Colaprio<Elemento>& c, const bool prio){
    if (prio){
        return longitud(c.prioritaria);
    }else{
        return longitud(c.normal);
    }
}
    




template <typename Elemento> void iniciarIterador(Colaprio<Elemento>& c){
    iniciarIterador(c.normal);
    iniciarIterador(c.prioritaria);
}
template <typename Elemento> bool haySiguiente(const Colaprio<Elemento>& c){
    return haySiguiente(c.prioritaria) || haySiguiente(c.normal);
}
template <typename Elemento> bool siguienteYavanza(Colaprio<Elemento>& c, Elemento& dato){
    if(haySiguiente(c)){
        if(esVacia(c.prioritaria)){
            return siguienteYavanza(c.normal,dato);
        }else{
            return siguienteYavanza(c.prioritaria, dato);
        }
    }else{
        return false;
    }
}



#endif