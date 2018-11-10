#include "PrimLevel.h"
#include "../Algorithms/Prim.h"

std::list<Cell<int>*>* PrimLevel::getPath(Graph* graph, int xTarget, int yTarget, int xPlayer,int yPlayer) {
    return Prim::findPath(graph, xTarget, yTarget, xPlayer, yPlayer);
}