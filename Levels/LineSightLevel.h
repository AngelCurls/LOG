//
// Created by stephanie on 13/11/18.
//

#ifndef LOG_LINESIGHTLEVEL_H
#define LOG_LINESIGHTLEVEL_H


#include "Level.h"

class LineSightLevel: public Level {
    std::list<Cell<int>*>* getPath(Graph* graph, int xTarget, int yTarget, int xPlayer, int yPlayer) override;
};


#endif //LOG_LINESIGHTLEVEL_H
