#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <string> 

#pragma once

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
};
