//
// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_ASTARLEVEL_H
#define LOG_ASTARLEVEL_H


#include "Level.h"

class AstarLevel: public Level {
    std::list<Cell<int>*>* getPath(Graph* graph, int xTarget, int yTarget, int xPlayer, int yPlayer) override;
};


#endif //LOG_ASTARLEVEL_H
