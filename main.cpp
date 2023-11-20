#include <iostream>
#include "graph.hpp"

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
     grafo.showAdjList();

     grafo.show_reference_list(); 
     return 0; 

}