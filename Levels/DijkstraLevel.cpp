//
// Created by jglez2330 on 08/11/18.
//

#include "DijkstraLevel.h"
#include "../Algorithms/Dijkstra.h"

std::list<Cell<int> *> *DijkstraLevel::getPath(Graph *graph, int xPlayer, int yPlayer, int xTarget, int yTarget) {
    return Dijkstra::findPath(graph, xPlayer, yPlayer, xTarget, yTarget);
}
