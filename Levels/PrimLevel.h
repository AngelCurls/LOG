#ifndef LOG_PRIMLEVEL_H
#define LOG_PRIMLEVEL_H

#include "Level.h"

class PrimLevel : public Level {
    std::list<Cell<int>*>* getPath(Graph* graph, int xPlayer, int yPlayer, int xTarget, int yTarget) override;
};


#endif //LOG_PRIMLEVEL_H
