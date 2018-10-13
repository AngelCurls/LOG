#include <iostream>
#include "ADTStructures/Graph.cpp"
#include "ADTStructures/Graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    //Pruebas del grafo
    Graph<int>* graph = new Graph<int>();
    graph->addEdge(1,2,2);
    graph->addEdge(1,3,2);
    graph->addEdge(6,12,2);
    graph->addEdge(6,12,2);
    graph->addEdge(3,6,2);
    graph->addEdge(10,6,2);
    graph->addEdge(3,22,2);
    graph->printGraph();

    Graph<char>* graph1 = new Graph<char>();
    graph1->addEdge('a','b');
    graph1->addEdge('c','d');
    graph1->addEdge('e','f');
    graph1->printGraph();
    return 0;
}