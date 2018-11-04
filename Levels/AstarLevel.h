//
// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_ASTARLEVEL_H
#define LOG_ASTARLEVEL_H


#include "Level.h"
#include "../ADTStructures/Graph.h"
#include <list>

class AstarLevel: public Level {
    std::list<Cell<int>*>* getPath(Graph* graph, int xPlayer, int yPlayer, int xTarget, int yTarget) override;
};


#endif //LOG_ASTARLEVEL_H
