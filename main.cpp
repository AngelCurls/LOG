#include "Algorithms/AStar.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    //Pruebas del grafo
    Graph<int>* graph = new Graph<int>();

    /*graph->addEdge(0,1,1);
    graph->addEdge(1,0,1);
    graph->addEdge(1,2,1);
    graph->addEdge(2,1,1);
    graph->addEdge(3,4,1);
    graph->addEdge(4,3,1);
    graph->addEdge(4,5,1);
    graph->addEdge(5,4,1);
    graph->addEdge(6,7,1);
    graph->addEdge(7,6,1);
    graph->addEdge(7,8,1);
    graph->addEdge(8,7,1);
    graph->addEdge(0,3,1);
    graph->addEdge(3,0,1);
    graph->addEdge(3,0,1);
    graph->addEdge(1,4,1);
    graph->addEdge(4,1,1);
    graph->addEdge(2,5,1);
    graph->addEdge(5,2,1);
    graph->addEdge(3,6,1);
    graph->addEdge(6,3,1);
    graph->addEdge(4,7,1);
    graph->addEdge(7,4,1);
    graph->addEdge(5,8,1);
    graph->addEdge(8,5,1);

    graph->printGraph();
    graph->getNode(0)->setObjectID(4);
    graph->getNode(8)->setObjectID(3);
    graph->getNode(1)->setObjectID(1);
    graph->getNode(4)->setObjectID(1);
    std::cout << std::endl;*/
    graph->gridGenerator(20,20);
    auto list = AStar::findPath(*graph,graph->getNode(0,0),graph->getNode(19,19));
    for (int i = 0; i <list->getSize() ; i++) {
        std::cout<< "(" << list->get(i)->getXpos() << "," << list->get(i)->getYpos() << ")" << " -> ";

    }
    return 0;
}
