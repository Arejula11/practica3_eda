# Coms:   Makefile para la practica 3 de EDA
#------------------------------------------------------------------------------

#---------------------------------------------------------
# Definición de macros
CC = g++
CPPFLAGS = -g -std=c++11      #opciones de compilación
LDFLAGS =                      #opciones de linkado
RM = rm -f                     #comando para borrar ficheros

all:  cola.hpp.gch colaprio.hpp.gch main
#-----------------------------------------------------------
# Compilacion
#g++ -std=c++11 cola.hpp colaprio.hpp main.cpp -o main
main.o: main.cpp
	${CC} -c main.cpp  ${CPPFLAGS}

cola.hpp.gch: cola.hpp.gch 
	${CC} -c cola.hpp   ${CPPFLAGS}

colaprio.hpp.gch: colaprio.hpp.gch 
	${CC} -c colaprio.hpp  cola.hpp ${CPPFLAGS}
# Linkado
main: main.o  cola.hpp.gch colaprio.hpp.gch
	${CC} main.o cola.hpp.gch colaprio.hpp.gch -o main ${LDFLAGS}
	${RM} main.o 
	${RM} colaprio.hpp.gch
	${RM} cola.hpp.gch



#-----------------------------------------------------------	
clean:
	${RM} main.o main
	${RM} colaprio.hpp.gch
	${RM} cola.hpp.gch
