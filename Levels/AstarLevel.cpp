//
// Created by jglez2330 on 25/10/18.
//

#include "AstarLevel.h"
#include "../Algorithms/AStar.h"

std::list<Cell<int>*>* AstarLevel::getPath(Graph* graph, int xTarget, int yTarget, int xPlayer, int yPlayer) {
    return AStar::findPath(graph, xTarget, yTarget, xPlayer, yPlayer);
}
