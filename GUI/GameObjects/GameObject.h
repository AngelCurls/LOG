//
// Created by edmobe on 29/10/18.
//

#ifndef LOG_GAMEOBJECT_H
#define LOG_GAMEOBJECT_H

#include "iostream"
#include <allegro5/allegro.h>


class GameObject {
public:
   virtual void draw() = 0;
};


#endif //LOG_GAMEOBJECT_H
