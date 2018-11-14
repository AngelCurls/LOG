//
// Created by jglez2330 on 08/11/18.
//

#ifndef LOG_DIJKSTRALEVEL_H
#define LOG_DIJKSTRALEVEL_H


#include "Level.h"

class DijkstraLevel :public Level{
    std::list<Cell<int> *> *getPath(Graph *graph, int xTarget, int yTarget, int xPlayer, int yPlayer) override;


};


#endif //LOG_DIJKSTRALEVEL_H
