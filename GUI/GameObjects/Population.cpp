//
// Created by jglez2330 on 06/11/18.
//

#include "Population.h"
#include "../../Algorithms/AStar.h"

Population::Population() {
    for (int i = 0; i < 5; i++) {
        this->players[i] = new Player(49 - 3 * i);
    }

}

void Population::draw() {
    for (int i = 0; i < 5 ; i++) {
        players[i]->draw();
        //players[i]->setPath(nullptr);
    }

}

void Population::moveToPath(Level* gameLevel, int xGraph, int yGraph) {
    for (int i = 0; i < 5 ; i++) {
        players[i]->path = gameLevel->getPath(map, xGraph, yGraph, players[i]->getI(), players[i]->getJ());
        /*
        std::list<Cell<int> *> *path = AStar::findPath(this->map, players[k]->getI(), this->getJ(), i + k, j);
        players[k]->setPath(path);
         */
    }

}

void Population::updatePlayers() {
    for (int i = 0; i < 5; i++) {
        if(players[i]->path != nullptr) {
            players[i]->setI(players[i]->path->back()->getXpos());
            players[i]->setJ(players[i]->path->back()->getYpos());
            players[i]->path->pop_back();
        }
    }
}

Graph *Population::getMap() const {
    return map;
}

void Population::setMap(Graph *map) {
    Population::map = map;
}
