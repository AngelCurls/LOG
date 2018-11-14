#ifndef LOG_KRUSKALLEVEL_H
#define LOG_KRUSKALLEVEL_H

#include "Level.h"

class KruskalLevel : public Level {
    std::list<Cell<int>*>* getPath(Graph* graph, int xTarget, int yTarget, int xPlayer, int yPlayer) override;
};


#endif //LOG_KRUSKALLEVEL_H
