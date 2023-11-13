#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <fstream> 
#include <string>
#include <sstream>
#include "graph.hpp"


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
    //Update adjacency matrix
    updateAdjacencyMatrix(node,adj_node);
}

void Graph::updateAdjacencyMatrix(int node, int adj_node) {
    //Place a 1 at position [node][adj_node] to represent the adjacency between the nodes
    adj_matrix_[node][adj_node] = 1;
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

std::vector<std::vector<std::string> > Graph::read_and_parse_file_string(std::string fileName) {
    std::vector<std::vector<std::string> > adj; // vector of vectors
    std::ifstream file(fileName);
    std::string line;

    int lines_to_read;
    std::getline(file, line);
    std::stringstream ss(line);
    ss >> lines_to_read;

    // Read the second line of the file as a vector of integers
    std::vector<std::string> int_vector;
    std::getline(file, line);
    std::stringstream ss2(line);
    std::string i;
    while (ss2 >> i) {
        int_vector.push_back(i);
        if (ss2.peek() == ' ')
            ss2.ignore();
    }

    // Read the remaining lines of the file as a vector of vectors of strings
    for (int i = 0; i < lines_to_read; i++) {
        std::vector<std::string> edge;
        std::getline(file, line);
        std::stringstream ss(line);
        std::string str;
        while (ss >> str) {
            edge.push_back(str);
            if (ss.peek() == ' ')
                ss.ignore();
        }
        adj.push_back(edge);
    }

    std::cout << "\tFinished reading file" << std::endl;
    return std::vector<std::vector<std::string> >(); // return an empty vector of vectors of strings
}