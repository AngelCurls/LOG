#include "KruskalLevel.h"
#include "../Algorithms/Kruskal.h"

std::list<Cell<int>*>* KruskalLevel::getPath(Graph* graph, int xTarget, int yTarget, int xPlayer,int yPlayer) {
    return Kruskal::findPath(graph, xPlayer, yPlayer, xTarget, yTarget);
}