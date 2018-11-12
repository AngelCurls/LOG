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

    int getI() const;

    void setI(int i);

    int getJ() const;

    void setJ(int j);

private:
    DNA* unitDNA = nullptr;
    int i;
    int j;


};


#endif //LOG_ENEMYUNIT_H
