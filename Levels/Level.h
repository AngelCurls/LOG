//
// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H


#include "../ADTStructures/Graph.h"

class Level {
public:
    virtual LinkedList<NodeGraph<int> *> * getPath(Graph<int> *graph, int xPlayer, int yPlayer, int xTarget,
                                                   int yTarget);

};


#endif //LOG_LEVEL_H
