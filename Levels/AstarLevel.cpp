//
// Created by jglez2330 on 25/10/18.
//

#include "AstarLevel.h"
#include "../Algorithms/AStar.h"
#include "../ADTStructures/LinkedList.h"
#include "../Algorithms/Dijkstra.h"

std::list<Cell<int>*>* AstarLevel::getPath(Graph* graph, int xPlayer, int yPlayer, int xTarget,
                                                   int yTarget) {
    return AStar::findPath(graph,xPlayer,yPlayer,xTarget,yTarget);
}
