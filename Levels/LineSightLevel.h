//
// Created by stephanie on 13/11/18.
//

#ifndef LOG_LINESIGHTLEVEL_H
#define LOG_LINESIGHTLEVEL_H


#include "Level.h"

class LineSightLevel: public Level {
    std::list<Cell<int>*>* getPath(Graph* graph, int xPlayer, int yPlayer, int xTarget, int yTarget) override;
};


#endif //LOG_LINESIGHTLEVEL_H
