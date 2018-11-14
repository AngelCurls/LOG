//
// Created by stephanie on 13/11/18.
//

#include "LineSightLevel.h"
#include "../Algorithms/LineSight.h"

std::list<Cell<int>*>* LineSightLevel::getPath(Graph* graph, int xTarget, int yTarget, int xPlayer, int yPlayer) {
    return LineSight::findPath(graph, xPlayer, yPlayer, xTarget, yTarget);
}