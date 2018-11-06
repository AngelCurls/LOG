//
// Created by jglez2330 on 06/11/18.
//

#include "PlayerPopulation.h"
#include "../../Algorithms/AStar.h"

PlayerPopulation::PlayerPopulation() {
    for (int i = 0; i < 5; i++) {
        this->players[i] = new Player();
        if (i != 0){
            players[i]->setI(players[i-1]->getI() + 1);
            players[i]->setJ(players[0]->getJ());
        }
    }

}

void PlayerPopulation::draw() {
    for (int i = 0; i <5 ; i++) {
        players[i]->draw();
        players[i]->setPath(nullptr);
    }

}



void PlayerPopulation::moveToPath(int i, int j) {

    for (int k = 0; k < 5 ; k++) {


        std::list<Cell<int> *> *path = AStar::findPath(this->map, players[k]->getI(), this->getJ(), i + k, j);
        players[k]->setPath(path);

    }

}

Graph *PlayerPopulation::getMap() const {
    return map;
}

void PlayerPopulation::setMap(Graph *map) {
    PlayerPopulation::map = map;
}
