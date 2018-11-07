//
// Created by jglez2330 on 06/11/18.
//

#include "Population.h"
#include "../../Algorithms/AStar.h"

Population::Population() {
    for (int i = 0; i < 5; i++) {
        this->players[i] = new Player();
        if (i != 0){
            players[i]->setI(players[i-1]->getI() + 1);
            players[i]->setJ(players[0]->getJ());
        }
    }

}

void Population::draw() {
    for (int i = 0; i <5 ; i++) {
        players[i]->draw();
        players[i]->setPath(nullptr);
    }

}



void Population::moveToPath(int i, int j) {

    for (int k = 0; k < 5 ; k++) {
        std::list<Cell<int> *> *path = AStar::findPath(this->map, players[k]->getI(), this->getJ(), i + k, j);
        players[k]->setPath(path);
    }

}

Graph *Population::getMap() const {
    return map;
}

void Population::setMap(Graph *map) {
    Population::map = map;
}
