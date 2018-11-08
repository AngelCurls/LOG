#include <thread>
#include <vector>
#include <iostream>
#include <queue>
#include "ADTStructures/Graph.h"
#include "GUI/ViewManager.h"
#include "Algorithms/AStar.h"
#include "Algorithms/Dijkstra.h"
//#include "Algorithms/AStar.h"
//#include "ADT/GraphAM.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

   ViewManager *viewManager = ViewManager::getInstance();
   viewManager->showDisplay();




    return 0;
}

