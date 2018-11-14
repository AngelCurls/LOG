//
// Created by jglez2330 on 06/11/18.
//

#ifndef LOG_PLAYERPOPULATION_H
#define LOG_PLAYERPOPULATION_H


#define pop_num 10

#include "Player.h"
#include "Gem.h"
#include "../../Levels/Level.h"
#include <list>

class Population: Player {
public:
    Population();
    void setPath(Level *gameLevel, int xGraph, int yGraph);
    void draw();

    Graph *getMap() const;

    void setMap(Graph *map);

    void updatePlayers();

    void setPlayersSpeed(int speed);

    void setDrawPopulationRatio(int populationRatio);

    bool collideWithGem(Gem *pGem);

    Player *const *getPlayers() const;

    int playerSize = pop_num;

private:

    Graph* map;
    Player* players[pop_num];

};


#endif //LOG_PLAYERPOPULATION_H
