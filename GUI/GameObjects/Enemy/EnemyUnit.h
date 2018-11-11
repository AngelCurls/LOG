//
// Created by jglez2330 on 10/11/18.
//

#ifndef LOG_ENEMYUNIT_H
#define LOG_ENEMYUNIT_H


#include "DNA.h"

class EnemyUnit {
public:
    EnemyUnit();

    virtual ~EnemyUnit();

    DNA *getUnitDNA() const;

    void mutate(int mutationRate);

private:
    DNA* unitDNA = nullptr;


};


#endif //LOG_ENEMYUNIT_H
