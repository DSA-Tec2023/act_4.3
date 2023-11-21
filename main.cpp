#include <iostream>
#include "graph.hpp"

/*
Este código lee un archivo de texto donde se muestran las conexiones entre puertos
y las consultas necesarias, especificando el puerto inicial y el número máximo de puertos
que se pueden visitar desde ahí. Al crear el grafo, guardar sus relaciones y recorrerlo,
da como resultado el número de puertos que no se pueden visitar con las condiciones
especificadas.

Equipo:
Andrés Martínez, A00227463
Fernanda Granados, A01252895
Santiago Poblete, A01254609
Martín Tánori, A01252900

Fecha: 19 de noviembre de 2023
*/


int main() {

     Graph grafo(13);

/*
     std::cout << "Case 1: ";
     grafo.MNP(1); std::cout << std::endl;
     std::cout << "Case 2: ";
     grafo.MNP(2); std::cout << std::endl;
     std::cout << "Case 3: ";
     grafo.MNP(3); std::cout << std::endl;
     std::cout << "Case 4: ";
     grafo.MNP(4); std::cout << std::endl;

     */ 

     grafo.read_file("input.txt");
     return 0; 

}