//
// Created by edmobe on 29/10/18.
//

#ifndef LOG_PLAYER_H
#define LOG_PLAYER_H

#include "AliveObject.h"
#include "../../ADTStructures/Cell.h"
#include <list>

class Player : AliveObject {
public:
    Player();
    void draw() override;
    void draw(std::list<Cell<int>*>* path);

    std::list<Cell<int>*>* path = nullptr;

    int getI() const;

    void setI(int i);

    int getJ() const;

    void setJ(int j);

    std::list<Cell<int> *> *getPath() const;

    void setPath(std::list<Cell<int> *> *path);

private:
    int i = 0;
    int j = 0;

};



#endif //LOG_PLAYER_H
