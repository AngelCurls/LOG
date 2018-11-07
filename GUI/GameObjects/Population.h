//
// Created by jglez2330 on 06/11/18.
//

#ifndef LOG_PLAYERPOPULATION_H
#define LOG_PLAYERPOPULATION_H


#include "Player.h"
#include "../ViewManager.h"
#include <list>

class Population: Player {
public:
    Population();
    void moveToPath(int i, int j);
    void draw();

    Graph *getMap() const;

    void setMap(Graph *map);

private:

    Graph* map;
    Player* players[5];

};


#endif //LOG_PLAYERPOPULATION_H
