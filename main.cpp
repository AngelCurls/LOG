#include "Algorithms/AStar.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    //Pruebas del grafo
    Graph<int>* graph = new Graph<int>();

    /*graph->gridGenerator(30,30);
    auto list = AStar::findPath(*graph,graph->getNode(0,19),graph->getNode(19,19));
    for (int i = 0; i <list->getSize() ; i++) {
        std::cout<< "(" << list->get(i)->getXpos() << "," << list->get(i)->getYpos() << ")" << " -> ";

    }*/

    return 0;
}
