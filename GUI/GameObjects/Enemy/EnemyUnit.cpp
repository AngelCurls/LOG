//
// Created by jglez2330 on 10/11/18.
//

#include <time.h>
#include <cstdlib>
#include "EnemyUnit.h"

EnemyUnit::EnemyUnit() {
    this->unitDNA = new DNA();
}

EnemyUnit::~EnemyUnit() {

    delete this->unitDNA;

}

DNA *EnemyUnit::getUnitDNA() const {
    return unitDNA;
}

void EnemyUnit::mutate(int mutationRate) {

    srand(time(nullptr));
    //Numero para comparae que el porcentaje de mutacion se cumpla
    int randomMutation = rand() % 100;
    //tipo del dato que va a mutar
    int mutationType = rand() % 3;

    if(randomMutation < mutationRate){

        if(mutationType == 0){
            this->unitDNA->setAtaque(rand() % this->unitDNA->getAtaqueMaximo() + 1);

        }
        if(mutationType == 1){
            this->unitDNA->setDefenza(rand() % this->unitDNA->getDefenzaMaxima() + 1);

        }
        if(mutationType == 2){
            this->unitDNA->setVida(rand() % this->unitDNA->getVidaMaxima() + 1);

        }


    }


}
