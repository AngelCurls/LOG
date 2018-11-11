#include <thread>
#include <vector>
#include <iostream>
#include <queue>
#include "ADTStructures/Graph.h"
#include "GUI/ViewManager.h"
#include "Algorithms/AStar.h"
#include "Algorithms/Dijkstra.h"
#include "GUI/GameObjects/Enemy/EnemiesPopulation.h"
//#include "Algorithms/AStar.h"
//#include "ADT/GraphAM.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

   ViewManager *viewManager = ViewManager::getInstance();
   viewManager->showDisplay();

   EnemiesPopulation* enemiesPopulation = new EnemiesPopulation(15);


   while (enemiesPopulation->getPopulation()[0]->getUnitDNA()->getDefenza() != enemiesPopulation->getPopulation()[0]->getUnitDNA()->getDefenzaMaxima()){

       std::cout << enemiesPopulation->getGeneration()<<", defenza " << enemiesPopulation->getPopulation()[0]->getUnitDNA()->getDefenza() << std::endl;
       enemiesPopulation->getNextGeneration();
   }

    return 0;
}

