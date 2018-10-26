//
// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_ASTARLEVEL_H
#define LOG_ASTARLEVEL_H


#include "Level.h"

class AstarLevel: public Level {
    LinkedList<NodeGraph<int> *> * getPath(Graph<int> *graph, int xPlayer, int yPlayer, int xTarget, int yTarget) override;
};


#endif //LOG_ASTARLEVEL_H
