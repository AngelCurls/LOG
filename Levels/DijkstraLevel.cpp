//
// Created by jglez2330 on 08/11/18.
//

#include "DijkstraLevel.h"
#include "../Algorithms/Dijkstra.h"

std::list<Cell<int> *> *DijkstraLevel::getPath(Graph *graph, int xTarget, int yTarget, int xPlayer, int yPlayer) {
    return Dijkstra::findPath(graph, xTarget, yTarget, xPlayer, yPlayer);
}
