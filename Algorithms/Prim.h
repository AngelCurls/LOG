//
// Created by jglez2330 on 28/10/18.
//

#ifndef LOG_PRIM_H
#define LOG_PRIM_H


#include "../ADT/GraphAM.h"

class Prim {
public:
    static void findPath(GraphAM* graphAM, int iStart, int jStart, int iTarget, int jTarget);
private:
    static GraphAM* findMST(GraphAM* graphAM, int iStart, int jStart, int iTarget, int jTarget);


};


#endif //LOG_PRIM_H
