#include <thread>
#include <vector>
#include <iostream>
#include "ADTStructures/Graph.h"
#include "GUI/ViewManager.h"
#include "Algorithms/AStar.h"
//#include "Algorithms/AStar.h"
//#include "ADT/GraphAM.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

   ViewManager *viewManager = ViewManager::getInstance();
   viewManager->showDisplay();

  auto graph = new Graph();

  graph->generateGrid();

  int * array = graph->loadMap(1);

  auto list = AStar::findPath(graph,0,0,499,499);

    for (auto element : *list) {

      std::cout << "("<<element->getXpos()<<","<<element->getYpos()<<")" <<"~>";

    }



    return 0;
}

