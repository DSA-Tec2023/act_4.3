#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <string> 
#include "destination.hpp"

#pragma once

/*
Declaración de la clase Grafo y sus funciones.

Equipo:
Andrés Martínez, A00227463
Fernanda Granados, A01252895
Santiago Poblete, A01254609
Martín Tánori, A01252900

Fecha: 19 de noviembre de 2023
*/

class Graph {
private:
    //Number of nodes in the graph
    int number_nodes_;
    //Adjacency list
    std::list<int> *adj_list_;
    //Adjacency matrix
    std::vector<std::vector<int> > adj_matrix_;

    //Recursive function to visit all adjacent nodes of current node, and
    //their respective adjacent nodes
    void recursiveDFS(int currentNode, bool visited[]);
    std::vector<Destination> reference_list;

public:
    //Constructor
    Graph(int number_nodes);

    //Insert adjacency in adjacency list
    void insertAdjacency(int node, int adj_node);

    //Update matrix which represents adjacencies
    void updateAdjacencyMatrix(std::string node, std::string adj_node);

    //Traverse list and print
    void showAdjList();

    //Traverse matrix and print
    void showAdjMatrix();

    //n = number of nodes
    //m = number of arcs
    //adj = adjacencies to be loaded onto graph
    void loadGraph(int m, std::vector<std::vector<int> > adj);

    //Breadth First Search (Traversal)
    void BFS(int firstNode);

    //Depth First Search (Traversal) 
    void DFS(int firstNode);

    std::vector<std::vector<int> > read_and_parse_file(std::string fileName);
    void read_file(std::string file_name); 

    void show_reference_list(); 

    void MNP(int id, int mnp);
};
