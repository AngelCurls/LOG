//
// Created by Joseph González Pastora on 10/22/18.
//

#include <time.h>
#include <cstdlib>
#include "EnemiesPopulation.h"

EnemiesPopulation::EnemiesPopulation(int enemyQuantity) {

    this->enemyQuantity = enemyQuantity;

    //Crea un Array del tamaño de la cantidad de enemigos
    this->population = new EnemyUnit*[enemyQuantity];

    //Crea y agrega enemigos al array
    for (int i = 0; i < enemyQuantity ; i++) {
        this->population[i] = new EnemyUnit();

    }
}

EnemyUnit* EnemiesPopulation::crossover(EnemyUnit* parentA, EnemyUnit* parentB) {
    EnemyUnit* enemyChild = new EnemyUnit();

    int ataqueHijo = parentA->getUnitDNA()->getAtaque();
    int defenzaHijo = parentB->getUnitDNA()->getDefenza();
    int vidaHijo = (parentA->getUnitDNA()->getVida() + parentB->getUnitDNA()->getVida());

    enemyChild->getUnitDNA()->setVida(vidaHijo);
    enemyChild->getUnitDNA()->setDefenza(defenzaHijo);
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
