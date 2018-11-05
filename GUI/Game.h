//
// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_VIEWMANAGER_H
#define LOG_VIEWMANAGER_H

#include "allegro5/allegro.h"
#include <thread>
#include <iostream>
#include <list>
#include <allegro5/allegro_image.h>
#include "../Levels/Level.h"
#include "LevelBuilder.h"
#include "../ADTStructures/LinkedList.cpp"



class Game {
public:
    int Height = 500;

    int Width = 500;

    void showDisplay();

    static Game* getInstance();

    void destroyWindow();

    bool isShowing() const;

    int getHeight() const;

    int getWidth() const;

    ALLEGRO_DISPLAY *getPtrDisplay() const;

    virtual ~Game();

private:
    Game* viewManagerInstance = nullptr;
    bool showing = false;
    ALLEGRO_DISPLAY* ptrDisplay = nullptr;
    void mainLoop();
    ALLEGRO_TIMER* timer;
    ALLEGRO_TIMER* timerDraw;
    ALLEGRO_EVENT_QUEUE* eventQueue;

    Game();


    void drawPath(std::list<Cell<int>*> *pList);
};


#endif //LOG_VIEWMANAGER_H
