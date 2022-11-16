/* Pablo Ernesto Angusto Delgado 842255 y  Miguel Aréjula Aisa 850068
*/

#include <iostream>
#include <fstream>
#include "colaprio.hpp"

using namespace std;

/* Programa de prueba del módulo colaprio.hpp que crea una cola vacía de strings y luego lee un fichero "entrada.txt" 
 * con operaciones a realizar con esa cola con la siguiente sintaxis y escribe en un fichero "salida.txt" lo indicado 
 * en cada opción:
 * EP -> encola el string incluido en la siguiente línea como prioritario y escribe en una nueva línea en salida "ENCOLADO PRIO string"
 * EN -> encola el string incluido en la siguiente línea como no prioritario y escribe en una nueva línea en salida "ENCOLADO NO PRIO string"
 * P  -> escribe en una nueva línea en salida "PRIMERO " seguido del string primero de la cola, si existe; si no, escribe en una nueva línea en salida "NO HAY"
 * D  -> desencola y escribe en una nueva línea en salida "DESENCOLADO"
 * L  -> escribe en una nueva línea en salida la longitud (L) con formato "LONGITUD L"
 * LP -> escribe en una nueva línea en salida la longitud de los prioritarios (L) con formato "LONGPRI L"
 * LN -> escribe en una nueva línea en salida la longitud de los no prioritarios (L) con formato "LONGNOPRI L"
 * M  -> escribe en salida el listado de todos los strings de la cola (un string por línea), antecedido el listado por una línea con "--- LISTADO ---"
 *       y seguido por otra línea con "---". 
 * */
int main() {
    
    Colaprio<string> c;
    vacia(c);
    ifstream inf;
    inf.open("entrada.txt");
    ofstream outf;
    outf.open("salida.txt");
    
    string instruccion;
    string salto;
    string separador = "---";
    
    while (inf >> instruccion) {
            

        getline(inf, salto);
        
        if (instruccion == "EP") {
            string elemento;
            getline(inf,elemento);
			
            encolar(c,elemento,true);
			
            outf << "ENCOLADO PRIO " << elemento << endl;
        } else if (instruccion == "EN") {
            string elemento;
            getline(inf,elemento);
			
            encolar(c,elemento,false);

            outf << "ENCOLADO NO PRIO " << elemento << endl;
        } else if (instruccion == "P") {
            string elemento;
            bool error;
			
            primero(c,elemento,error);
			
            if (error) {
                outf << "NO HAY" << endl;
            } else {
                outf << "PRIMERO " << elemento << endl;
            }
        } else if (instruccion == "D") {

            
			desencolar(c);

            outf << "DESENCOLADO" << endl;
        } else if (instruccion == "L") {
			int longi;
			
            
			longitud(c);
			
            outf << "LONGITUD " << longi << endl;
        } else if (instruccion == "LP") {
	    int longi;
			
	    longClase(c,true);
			
            outf << "LONGPRI " << longi << endl;
        } else if (instruccion == "LN") {
	    int longi;
			
	    
	    longClase(c,true);
			
            outf << "LONGNOPRI " << longi << endl;
        } else if (instruccion == "M") {
			string dato;
            iniciarIterador(c);
			while (haySiguiente(c)){
               if(siguienteYavanza(c,dato)){
               outf<<dato<<endl;
               }
            }
            
        }
    }
    
    outf.close();
    inf.close();
    
    return 0;
}