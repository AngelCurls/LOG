//
// Created by Joseph González Pastora on 10/14/18.
//

#ifndef LOG_ASTAR_H
#define LOG_ASTAR_H


#include "../ADTStructures/Graph.h"
#include <list>
#include <algorithm>

class AStar{
private:

public:
    static std::list<Cell<int>* >* findPath(Graph* graph,int iStart, int jStart, int iTarget, int jTarget);

    static void calHeuristic(Cell<int>* current,int iTarget, int jTarget);

    static Cell<int>* minF(std::set<Cell<int>*> openList, Cell<int>* Target);
};


#endif //LOG_ASTAR_H
