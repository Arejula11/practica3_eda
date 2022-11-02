/* Nombre, apellidos y NIP del (de los) autor(es).
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
    
    // AQUÍ FALTA COMPLETAR CÓDIGO
    
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
			
            // AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "ENCOLADO PRIO " << elemento << endl;
        } else if (instruccion == "EN") {
            string elemento;
            getline(inf,elemento);
			
            // AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "ENCOLADO NO PRIO " << elemento << endl;
        } else if (instruccion == "P") {
            string elemento;
            bool error;
			
            // AQUÍ FALTA COMPLETAR CÓDIGO
			
            if (error) {
                outf << "NO HAY" << endl;
            } else {
                outf << "PRIMERO " << elemento << endl;
            }
        } else if (instruccion == "D") {
			
            // AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "DESENCOLADO" << endl;
        } else if (instruccion == "L") {
			int longi;
			
			// AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "LONGITUD " << longi << endl;
        } else if (instruccion == "LP") {
	    int longi;
			
	    // AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "LONGPRI " << longi << endl;
        } else if (instruccion == "LN") {
	    int longi;
			
	    // AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "LONGNOPRI " << longi << endl;
        } else if (instruccion == "M") {
			
            // AQUÍ FALTA COMPLETAR CÓDIGO
			
        }
    }
    
    outf.close();
    inf.close();
    
    return 0;
}