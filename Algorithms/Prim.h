//
// Created by jglez2330 on 28/10/18.
//

#ifndef LOG_PRIM_H
#define LOG_PRIM_H


#include "../ADTStructures/Graph.h"

class Prim {
public:
    static void findPath(Graph* graph, int iStart, int jStart, int iTarget, int jTarget);
private:
    static Graph* findMST(Graph* graphAM, int iStart, int jStart, int iTarget, int jTarget);


};


#endif //LOG_PRIM_H
