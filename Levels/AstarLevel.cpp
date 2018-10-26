//
// Created by jglez2330 on 25/10/18.
//

#include "AstarLevel.h"
#include "../Algorithms/AStar.h"

LinkedList<NodeGraph<int> *> * AstarLevel::getPath(Graph<int> *graph, int xPlayer, int yPlayer, int xTarget,
                                                   int yTarget) {
    return AStar::findPath(*graph,graph->getNode(xPlayer,yPlayer),graph->getNode(xTarget,yTarget));

}
