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
    void moveToPath(Level* gameLevel, int xGraph, int yGraph);
    void draw();

    Player* getPlayers();

    Graph *getMap() const;

    void setMap(Graph *map);

    void updatePlayers();

private:

    Graph* map;
    Player* players[5];

};


#endif //LOG_PLAYERPOPULATION_H
