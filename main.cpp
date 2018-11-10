#include <thread>
#include <vector>
#include <iostream>
#include "ADTStructures/Graph.h"
#include "GUI/ViewManager.h"
#include "Algorithms/AStar.h"

int main() {

    ViewManager *viewManager = ViewManager::getInstance();
    viewManager->showDisplay();

    return 0;
}

