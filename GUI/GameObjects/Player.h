//
// Created by edmobe on 29/10/18.
//

#ifndef LOG_PLAYER_H
#define LOG_PLAYER_H

#include "../../ADTStructures/Cell.h"
#include <list>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_image.h>

class Player {
public:
    Player();
    Player(int x, int y);

    void draw();
    void attack();

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

    int getDrawRelationRatio() const;

    void setDrawRelationRatio(int drawRelationRatio);

private:
    int drawRelationRatio = 15;
    int i = 0;
    int j = 49;
    int moving = false;
    ALLEGRO_BITMAP *playerImage =  al_load_bitmap("../Images/sold1.png");
//<<<<<<< Updated upstream
    int speed = 100;
//=======
    int speedClock = speed;
//>>>>>>> Stashed changes
    //ALLEGRO_BITMAP  *p1;
};



#endif //LOG_PLAYER_H
