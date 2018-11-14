//
// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H



#include "../ADTStructures/Graph.h"
#include <list>

class Level {
public:
    virtual std::list<Cell<int>*>* getPath(Graph* graph, int xTarget, int yTarget, int xPlayer, int yPlayer);

};


#endif //LOG_LEVEL_H
