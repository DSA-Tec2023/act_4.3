#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include "graph.hpp"
#include "destination.hpp"

template <typename T>
bool contains(
    const std::vector<T>& vecObj,
    const T& element)
{
    // Get the iterator of first occurrence
    // of given element in vector
    auto it = std::find(
                  vecObj.begin(),
                  vecObj.end(),
                  element) ;
    return it != vecObj.end();
}

Graph::Graph(int number_nodes) {
    number_nodes_ = number_nodes;
    //Create a list of size number_nodes
    adj_list_ = new std::list<int>[number_nodes];
    //Create a matrix of size number_nodes x number_nodes and fill it with zeros
    for(int i=0; i<number_nodes; ++i) {
        adj_matrix_.push_back(std::vector<int>(number_nodes,0));
    }
}

void Graph::insertAdjacency(int node, int adj_node) {
    adj_list_[node].push_back(adj_node);
    adj_list_[adj_node].push_back(node);

}

void Graph::updateAdjacencyMatrix(std::string node, std::string adj_node) {
    //Place a 1 at position [node][adj_node] to represent the adjacency between the nodes
    adj_matrix_[0][0] = 1; // ignoring this for development purposes
}

void Graph::showAdjList() {
    for(int i=0; i<number_nodes_; ++i) {
        std::cout << i << "->";
        //Iterator for nodes
        std::list<int>::iterator j;
        for (j=adj_list_[i].begin(); j!=adj_list_[i].end(); ++j)
            std::cout << *j << ",";
        std::cout << "\n";
    }
}

void Graph::showAdjMatrix() {
    for(int i=0; i<number_nodes_; ++i) {
        for(int j=0; j<number_nodes_; ++j)
            std::cout << adj_matrix_[i][j];
        std::cout << "\n";
    }
}

void Graph::loadGraph(int m, std::vector<std::vector<int> > adj) {
    for(int i=0; i<m; ++i) {
        insertAdjacency(adj[i][0],adj[i][1]);
    }
}

void Graph::BFS(int firstNode) {
    //Create a boolean list and mark all nodes as not visited
    bool *visited = new bool[number_nodes_];
    for(int i=0; i<number_nodes_; ++i)
        visited[i] = false;

    //Create a queue for the nodes that haven't been visited
    std::queue<int> q;

    //Mark starting node as visited and enqueue it
    visited[firstNode] = true;
    q.push(firstNode);

    //While the queue is not empty
    while(!q.empty()) {
        //Get first node and print it
        firstNode = q.front();
        std::cout << firstNode << " ";
        //Dequeue node
        q.pop();

        //Get all adjacent nodes of current node
        for(auto i=adj_list_[firstNode].begin(); i!=adj_list_[firstNode].end(); ++i) {
            //If the node hasn't been visited, enqueue it and mark as visited
            if(!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

void Graph::DFS(int firstNode) {
    //Create a boolean list and mark all nodes as not visited
    bool *visited = new bool[number_nodes_];
    for(int i=0; i<number_nodes_; ++i)
        visited[i] = false;

    //Call recursive helper function
    recursiveDFS(firstNode,visited);
}

void Graph::recursiveDFS(int currentNode, bool visited[]) {
    //Mark current node as visited and print
    visited[currentNode] = true;
    std::cout << currentNode << " ";

    //Recur for all adjacent nodes that have not been visited yet
    std::list<int>::iterator i;
    for(i=adj_list_[currentNode].begin(); i!=adj_list_[currentNode].end(); ++i) {
        if(!visited[*i])
            recursiveDFS(*i,visited);
    }
}

std::vector<std::vector<int> > Graph::read_and_parse_file(std::string fileName) {
    std::vector<std::vector<int> > adj; // vector of vectors
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> edge;
        std::stringstream ss(line);
        int i;
        while (ss >> i) {
            edge.push_back(i); // add to edge
            if (ss.peek() == ' ')
                ss.ignore();
        }
        adj.push_back(edge); // add the edge to the vector
    }

    std::cout << "\tFinished reading file" << std::endl;
    return adj;
}

void Graph::read_file(std::string file_name) {
    std::ifstream file;
    std::string line;
    file.open(file_name);
    std::vector<std::vector <int> > pairs;

    int contador = 0;
    std::vector<Destination> destinations;

    std::getline(file, line);
    for (int i = 0; i < std::stoi(line); i++) {
        std::vector<int> local_vector;
        std::string nodo1, nodo2;

        if (!file.is_open()) {
            std::cerr << "Error reading from the file" << std::endl;
            exit(1);
        }

        file >> nodo1 >> nodo2;

        Destination place = *new Destination(nodo1, contador);
        if (!contains(destinations, place)) {
            destinations.push_back(place);
            contador++;

        }
        Destination place_two = *new Destination(nodo2, contador);
        if (!contains(destinations, place_two)) {
            destinations.push_back(place_two);
            contador++;

        }

        for (int i = 0; i < destinations.size(); i++) {
            if (destinations[i].get_name() == nodo1) {
                local_vector.push_back(destinations[i].get_id());
            }
            if (destinations[i].get_name() == nodo2) {
                local_vector.push_back(destinations[i].get_id());
            }
        }
        pairs.push_back(local_vector);

    }
    reference_list = destinations;

    loadGraph(pairs.size(), pairs);
    
    int nq, mnp;
    std::string puerto_inicio;

    file >> nq;
    for (int i = 0; i < nq; i++){

        file >> puerto_inicio >> mnp;

        for(int j = 0; j < destinations.size(); j++){
            if(puerto_inicio == destinations[j].get_name()){
                MNP(destinations[j].get_id(),mnp);
            }
        }
    }

    file.close();
}

void Graph::show_reference_list() {
    std::cout << "REFERENCE TABLE" << std::endl;
    for (int i = 0; i < reference_list.size(); i++) {
        std::cout << reference_list[i].get_name() << " " << reference_list[i].get_id() << std::endl;
    }
}

void Graph::MNP(int id, int mnp){
    //std::cout << "Hola" << std::endl;
    std::vector<int> visitados;
    std::queue<std::pair<int, int>> fila;

    visitados.push_back(id);
    fila.push(std::make_pair(id, 0));

    while(!fila.empty()){
        int currentNode = fila.front().first;
        int currentDepth = fila.front().second;
        fila.pop();

        if(currentDepth < mnp){
            for(auto i=adj_list_[currentNode].begin(); i!=adj_list_[currentNode].end(); ++i) {
                if(std::find(visitados.begin(), visitados.end(), *i) == visitados.end()){
                    visitados.push_back(*i);
                    fila.push(std::make_pair(*i, currentDepth+1));
                }
            }
        }
    }

    /*for(int i=0; i< visitados.size(); i++){
        std::cout << visitados[i] << std::endl;
    }
    std::cout << std::endl;*/

    std::cout << reference_list.size() - visitados.size() << " ports not reachable." << std::endl;
}