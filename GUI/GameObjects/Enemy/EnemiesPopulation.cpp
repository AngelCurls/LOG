//
// Created by Joseph González Pastora on 10/22/18.
//

#include <time.h>
#include <cstdlib>
#include <allegro5/allegro_primitives.h>
#include "EnemiesPopulation.h"
#include "../Population.h"
#include "../../../ADTStructures/Graph.h"
#include "../AttackOne.h"

EnemiesPopulation::EnemiesPopulation(int enemyQuantity, Graph *pGraph) {

    this->enemyQuantity = enemyQuantity;

    //Crea un Array del tamaño de la cantidad de enemigos
    this->population = new EnemyUnit*[enemyQuantity];

    //Crea y agrega enemigos al array
    for (int i = 0; i < enemyQuantity ; i++) {
        this->population[i] = new EnemyUnit();

        auto enemyActual = this->population[i];
        int k = enemyActual->getI();
        int j = enemyActual->getJ();

        if(pGraph->getKeyTable()[k][j]->getObjectID() != 0){

            while (pGraph->getKeyTable()[k][j]->getObjectID() != 0){
                k = rand() % 50;
                j = rand() % 50;
            }
            enemyActual->setI(k);
            enemyActual->setJ(j);
        }
        pGraph->getKeyTable()[k][j]->setObjectID(4);
        this->map = pGraph;



    }
}

EnemyUnit* EnemiesPopulation::crossover(EnemyUnit* parentA, EnemyUnit* parentB) {
    EnemyUnit* enemyChild = new EnemyUnit();

    int ataqueHijo = parentA->getUnitDNA()->getAtaque();
    int defenzaHijo = parentB->getUnitDNA()->getDefensa();
    int vidaHijo = (parentA->getUnitDNA()->getVida() + parentB->getUnitDNA()->getVida());

    enemyChild->getUnitDNA()->setVida(vidaHijo);
    enemyChild->getUnitDNA()->setDefensa(defenzaHijo);
    enemyChild->getUnitDNA()->setAtaque(ataqueHijo);

    enemyChild->mutate(this->mutationRate);


    return enemyChild;
}

void EnemiesPopulation::getNextGeneration() {
    srand(time(nullptr));


    EnemyUnit** newPopulation = new EnemyUnit*[this->enemyQuantity];
    generateMatingPool();

    for (int i = 0; i < this->enemyQuantity; i++) {

        EnemyUnit* parentA = selectFromMatingPool();
        EnemyUnit* parentB = selectFromMatingPool();

        newPopulation[i] = crossover(parentA,parentB);

    }

    for (int j = 0; j < this->enemyQuantity; j++) {

        newPopulation[j]->setI(this->population[j]->getI());
        newPopulation[j]->setJ(this->population[j]->getJ());

        int x = newPopulation[j]->getI();
        int y = newPopulation[j]->getJ();

        this->map->getKeyTable()[x][y]->setObjectID(4);
        delete population[j];

    }
    this->generation++;
    this->matingPool->clear();
    delete matingPool;

    delete population;

    this->population = newPopulation;

}

EnemyUnit* EnemiesPopulation::selectFromMatingPool() {

    int winnerIndex = rand() % matingPool->size();

    return *(matingPool->begin() + winnerIndex);

}

EnemyUnit **EnemiesPopulation::getPopulation() const {
    return population;
}

int EnemiesPopulation::getGeneration() const {

    return generation;
}

void EnemiesPopulation::generateMatingPool() {
    //Crea la piscina de genes
    this->matingPool = new std::vector<EnemyUnit*>();
    for (int i = 0; i < this->enemyQuantity; i++) {

        int frecuencia = population[i]->getUnitDNA()->fitness() % 100;

        for (int j = 0; j < frecuencia; j++) {
            this->matingPool->push_back(population[i]);

        }
    }


}

void EnemiesPopulation::draw() {
    for (int i = 0; i < this->enemyQuantity; i++) {
        if (this->population[i]->getUnitDNA()->getVida() > 0) {


            float x = this->population[i]->getI() * this->relationRatio;
            float y = this->population[i]->getJ() * this->relationRatio;

            EnemyUnit *enemy = this->population[i];
            al_draw_filled_rectangle(x, y, x + this->relationRatio, y + this->relationRatio,
                                     al_map_rgb((unsigned char) enemy->getUnitDNA()->getRedPhenotype(),
                                                (unsigned char) enemy->getUnitDNA()->getGreenPhenotype(),
                                                (unsigned char) enemy->getUnitDNA()->getBluePhenotype()));

            int length = 50/enemy->getUnitDNA()->vidaOriginal * this->population[i]->getUnitDNA()->getVida();

            al_draw_filled_rectangle(x - 10, y - 10, x - 10 + length, y - 5, al_map_rgb(100,100,100));
        }

    }
}

float EnemiesPopulation::getRelationRatio() const {
    return relationRatio;
}

void EnemiesPopulation::setRelationRatio(float relationRatio) {
    EnemiesPopulation::relationRatio = relationRatio;
}

void EnemiesPopulation::setMap(Graph *map) {
    EnemiesPopulation::map = map;
}

void EnemiesPopulation::collisionPlayerDraw(Population *pPopulation) {


    for (int j = 0; j < this->enemyQuantity; j++) {
        EnemyUnit *enemyUnit = this->population[j];
        for (int i = 0; i < pPopulation->playerSize; i++) {
            Player *player = pPopulation->getPlayers()[i];


            if (playerInSight(player, enemyUnit) && enemyUnit->getUnitDNA()->getVida() > 0) {

                if (enemyUnit->getI() == player->getI() && animationTimer % 20 == 0) {
                    //Dibuja una linea de ataque enemigo
                    al_draw_filled_rectangle(this->population[j]->getI() * this->relationRatio,
                                             this->population[j]->getJ() * this->relationRatio,
                                             pPopulation->getPlayers()[i]->getI() * this->relationRatio + 10,
                                             pPopulation->getPlayers()[i]->getJ() * this->relationRatio,
                                             al_map_rgb(55, 100, 150));

                    pPopulation->getPlayers()[i]->setHealth(pPopulation->getPlayers()[i]->getHealth() -
                                                            (this->population[j]->getUnitDNA()->getAtaque() * 100 /
                                                             this->population[j]->getUnitDNA()->getAtaqueMaximo()));

                    enemyUnit->getUnitDNA()->setVida(enemyUnit->getUnitDNA()->getVida() - player->attack() *10);
                    printf("Ataque No%i", player->attack());

                } else if (player->getJ() == enemyUnit->getJ() && animationTimer % 20 == 0) {
                    //Dibuja una linea de ataque enemigo
                    al_draw_filled_rectangle(this->population[j]->getI() * this->relationRatio,
                                             this->population[j]->getJ() * this->relationRatio,
                                             pPopulation->getPlayers()[i]->getI() * this->relationRatio,
                                             this->population[j]->getJ() * this->relationRatio + 10,
                                             al_map_rgb(55, 100, 150));
                    //Disminuye la vida del jugador
                    pPopulation->getPlayers()[i]->setHealth(pPopulation->getPlayers()[i]->getHealth() -
                                                            (this->population[j]->getUnitDNA()->getAtaque() * 100 /
                                                             this->population[j]->getUnitDNA()->getAtaqueMaximo()));

                    enemyUnit->getUnitDNA()->setVida(enemyUnit->getUnitDNA()->getVida() - player->attack() * 10);
                    printf("Ataque No%i", player->attack());

                }

                al_draw_bitmap(this->alertImage, 650/4,650/4,0);



            }


        }
    }
}


bool EnemiesPopulation::playerInSight(Player* player, EnemyUnit *enemyUnit) {
    if(player == nullptr || enemyUnit == nullptr) return false;


    bool inSight = false;
    if (enemyUnit->getJ() == player->getJ()) {


        if (enemyUnit->getI() < player->getI()) {
            for (int i = enemyUnit->getI() + 1; i < player->getI(); i++) {
                inSight = true;
                if (map->getKeyTable()[i][player->getJ()]->getObjectID() != 0) {
                    inSight = false;
                    break;
                }


            }
            return inSight;

        } else if (player->getI() < enemyUnit->getI()) {
            for (int i = player->getI()+1; i < enemyUnit->getI(); i++) {
                inSight = true;
                if (map->getKeyTable()[i][player->getJ()]->getObjectID() != 0) {
                    inSight = false;
                    break;
                }


            }

            return inSight;
        }

    } else if (enemyUnit->getI() == player->getI()) {


        if (enemyUnit->getJ() < player->getJ()) {
            for (int i = enemyUnit->getJ() + 1; i < player->getJ(); i++) {
                inSight = true;
                if (map->getKeyTable()[player->getI()][i]->getObjectID() != 0) {
                    inSight = false;
                    break;
                }


            }

            return inSight;
        } else if (player->getJ() < enemyUnit->getJ()) {
            for (int i = player->getJ() + 1; i < enemyUnit->getJ(); i++) {
                inSight = true;
                if (map->getKeyTable()[player->getI()][i]->getObjectID() != 0) {
                    inSight = false;
                    break;
                }


            }
            return inSight;

        }
    }
}

void EnemiesPopulation::collisionPlayer(Population *playerPopulation) {

    this->animationTimer++;
    collisionPlayerDraw(playerPopulation);



}

int EnemiesPopulation::getEnemyQuantity() const {
    return enemyQuantity;
}
