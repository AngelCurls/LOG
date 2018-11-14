//
// Created by jglez2330 on 14/11/18.
//

#include "AttackOne.h"

void AttackOne::draw(EnemiesPopulation* enemiesPopulation) {
    for (int k = 0; k < enemiesPopulation->getEnemyQuantity(); k++) {
        if(enemiesPopulation->getPopulation()[k]->getI() == this->i && enemiesPopulation->getPopulation()[k]->getJ() == this->j ){

            auto enemy = enemiesPopulation->getPopulation()[k];

            enemy->getUnitDNA()->setVida(enemy->getUnitDNA()->getVida() - 7);

            if(enemy->getUnitDNA()->getVida() < 0){
                enemiesPopulation->getPopulation()[k] = nullptr;

            }
        }

    }



}
