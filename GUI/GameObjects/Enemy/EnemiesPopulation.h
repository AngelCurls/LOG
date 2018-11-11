//
// Created by Joseph González Pastora on 10/22/18.
//

#ifndef LOG_ENEMY_H
#define LOG_ENEMY_H


#include "EnemyUnit.h"
#include <vector>

class EnemiesPopulation {
private:

    EnemyUnit** population;
    int generation = 0;
    int enemyQuantity;
    int mutationRate = 1;

    std::vector<EnemyUnit*>* matingPool = nullptr;

public:
    EnemiesPopulation(int enemyQuantity);

    void getNextGeneration();

    EnemyUnit* crossover(EnemyUnit* parentA, EnemyUnit* parentB);


    EnemyUnit *selectFromMatingPool();

    EnemyUnit **getPopulation() const;

    int getGeneration() const;

    void generateMatingPool();
};


#endif //LOG_ENEMY_H