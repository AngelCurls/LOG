//
// Created by Joseph González Pastora on 10/22/18.
//

#ifndef LOG_ENEMY_H
#define LOG_ENEMY_H


#include "EnemyUnit.h"
#include "../../../ADTStructures/Graph.h"
#include "../Population.h"
#include <vector>

class EnemiesPopulation {
private:

    Graph* map = nullptr;
    EnemyUnit** population;
    int generation = 0;
    int enemyQuantity;
    int mutationRate = 1;

    int animationTimer = 0;
    float relationRatio;

    std::vector<EnemyUnit*>* matingPool = nullptr;

    ALLEGRO_BITMAP *alertImage =  al_load_bitmap("../Images/alert.png");

public:
    EnemiesPopulation(int enemyQuantity, Graph *pGraph);

    void getNextGeneration();

    EnemyUnit* crossover(EnemyUnit* parentA, EnemyUnit* parentB);


    EnemyUnit *selectFromMatingPool();

    EnemyUnit **getPopulation() const;

    int getGeneration() const;

    void generateMatingPool();

    void draw();

    float getRelationRatio() const;

    void setRelationRatio(float relationRatio);

    void setMap(Graph *map);

    void collisionPlayerDraw(Population *pPopulation);

    void collisionPlayer(Population* playerPopulation);

    bool playerInSight(Player* player, EnemyUnit *enemyUnit);

    int getEnemyQuantity() const;
};


#endif //LOG_ENEMY_H
