#ifndef LOG_KRUSKALLEVEL_H
#define LOG_KRUSKALLEVEL_H

#include "Level.h"

class KruskalLevel : public Level {
    std::list<Cell<int>*>* getPath(Graph* graph, int xPlayer, int yPlayer, int xTarget, int yTarget) override;
};


#endif //LOG_KRUSKALLEVEL_H
