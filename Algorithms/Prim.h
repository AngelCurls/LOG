#ifndef LOG_PRIM_H
#define LOG_PRIM_H


#include "../ADTStructures/Graph.h"
#include <list>

class Prim {
public:
    static std::list<Cell<int>*>* findPath(Graph* graph, int iTarget, int jTarget, int iPlayer, int jPlayer);

private:
    static std::list<Cell<int> *>* path;
    static int xTarget;
    static int yTarget;

    //se crea un arbol de expansion minima para un solo nodo objetivo. Si este cambia, se recalculara

    static Graph* findMST(Graph* graph, int iStart, int jStart, int iTarget, int jTarget);
};


#endif //LOG_PRIM_H
