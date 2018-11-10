//
// Created by jglez2330 on 06/11/18.
//

#define num_players 1

#include "Population.h"
#include "../../Algorithms/AStar.h"

Population::Population() {
    for (int i = 0; i < num_players; i++) {
        this->players[i] = new Player(49 - 3 * i); // Crea 5 jugadores y uno va encima del otro
    }

}

void Population::draw() {
    for (int i = 0; i < num_players ; i++) {
        players[i]->draw(); // Dibuja todos los jugadores
        //players[i]->setPath(nullptr);
    }

}

void Population::setPath(Level *gameLevel, int xGraph, int yGraph) {
    for (int i = 0; i < num_players ; i++) {
        players[i]->path = gameLevel->getPath(map, xGraph, yGraph, players[i]->getI(), players[i]->getJ()); // Encuentra un path para un mapa específico para cada uno de los jugadores
        /*
        std::list<Cell<int> *> *path = AStar::findPath(this->map, players[k]->getI(), this->getJ(), i + k, j);
        players[k]->setPath(path);
         */
    }

}

void Population::updatePlayers() {
    for (int i = 0; i < num_players; i++) {
        if(players[i]->path != nullptr && players[i]->path->size() > 0) {
            players[i]->setI(players[i]->path->back()->getXpos()); // La nueva posición en X es la coordenada en X de la próxima casilla a la que se debe dirigir
            players[i]->setJ(players[i]->path->back()->getYpos());// La nueva posición en Y es la coordenada en Y de la próxima casilla a la que se debe dirigir
            players[i]->path->pop_back(); // Se elimina el grid por el que el jugador acaba de pasar
        }
    }
}

Graph *Population::getMap() const {
    return map;
}

void Population::setMap(Graph *map) {
    Population::map = map;
}

void Population::setPlayersSpeed(int speed) {
    for (int k = 0; k < sizeof(players)/sizeof(*players); k++) {

        this->players[k]->setSpeed(speed);
    }

}
