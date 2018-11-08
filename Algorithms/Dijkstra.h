//
// Created by jglez2330 on 07/11/18.
//

#ifndef LOG_DIJKSTRA_H
#define LOG_DIJKSTRA_H

#include <functional>
#include <queue>
#include <list>
#include "../ADTStructures/Cell.h"
#include "../ADTStructures/Graph.h"

struct CompareNode : public std::binary_function<Cell<int>*, Cell<int>*, bool>{
    bool operator() (Cell<int>* ComparativeCell,Cell<int>* cellToCompare) const {
        return ComparativeCell->operator<(cellToCompare);
    }
};

class Dijkstra {

public:

    static std::list<Cell<int>*>* findPath(Graph* graph, int iStart, int jStart, int iTarget, int jTarget);


private:
    static int INF;


    static void setDistanceInfinite(Graph *graph);


};



#endif //LOG_DIJKSTRA_H
