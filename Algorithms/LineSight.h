//
// Created by jglez2330 on 08/11/18.
//

#ifndef LOG_LINESIGHT_H
#define LOG_LINESIGHT_H


#include <list>
#include "../ADTStructures/Graph.h"

class LineSight {

public:
    static std::list<Cell<int>*>* findPath(Graph* graph, int iStart,int jStart, int iTarget, int jTarget);

private:
    static bool hasLineOfSight(Graph* graph, int iCurrent, int jCurrent, int iTarget, int jTarget);
};


#endif //LOG_LINESIGHT_H
