//
// Created by edmobe on 29/10/18.
//

#ifndef LOG_PLAYER_H
#define LOG_PLAYER_H

#include "../../ADTStructures/Cell.h"
#include <list>

class Player {
public:
    Player();

    void draw();
    void draw(std::list<Cell<int>*>* path);

    std::list<Cell<int>*>* path = nullptr;

    bool isMoving();

    void setMoving(bool moving);

    bool getSpeed();

    void setSpeed(int speed);

    int getI() const;

    void setI(int i);

    int getJ() const;

    void setJ(int j);

    std::list<Cell<int> *> *getPath() const;

    void setPath(std::list<Cell<int> *> *path);

private:
    int i = 0;
    int j = 49;
    int moving = false;
    int speed = 100;
};



#endif //LOG_PLAYER_H
