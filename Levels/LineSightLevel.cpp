//
// Created by stephanie on 13/11/18.
//

#include "LineSightLevel.h"
#include "../Algorithms/LineSight.h"

std::list<Cell<int>*>* LineSightLevel::getPath(Graph* graph, int xPlayer, int yPlayer, int xTarget, int yTarget) {
    return LineSight::findPath(graph,xPlayer,yPlayer,xTarget,yTarget);
}