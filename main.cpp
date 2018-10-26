#include <thread>
#include "GUI/ViewManager.h"
#include "Algorithms/AStar.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    //Pruebas del grafo
    Graph<int>* graph = new Graph<int>();
    ViewManager* viewManager = ViewManager::getInstance();
    viewManager->showDisplay();



    std::cout << "HOla";

    graph->gridGenerator(20,20);
    auto list = AStar::findPath(*graph,graph->getNode(17,6),graph->getNode(19,19));
    for (int i = 0; i <list->getSize() ; i++) {
        std::cout<< "(" << list->get(i)->getXpos() << "," << list->get(i)->getYpos() << ")" << " -> ";

    }
    std::cout<<std::endl;
    auto lista2 = AStar::findPath(*graph,graph->getNode(19,10),graph->getNode(19,19));
    for (int j = 0; j < lista2->getSize(); j++) {
        std::cout<< "(" << list->get(j)->getXpos() << "," << list->get(j)->getYpos() << ")" << " -> ";
    }

    //while (viewManager->isShowing()){}

    
    return 0;
}
