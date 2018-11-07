// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_VIEWMANAGER_H
#define LOG_VIEWMANAGER_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <thread>
#include <iostream>
#include <list>
#include <allegro5/allegro_image.h>
#include "../Levels/Level.h"
#include "LevelBuilder.h"
#include "../ADTStructures/LinkedList.cpp"



class ViewManager {
public:
    int Height = 1000;

    int Width = 1000;

    void showDisplay();

    static ViewManager* getInstance();

    void destroyWindow();

    bool isShowing() const;

    int getHeight() const;

    int getWidth() const;

    ALLEGRO_DISPLAY *getPtrDisplay() const;

    virtual ~ViewManager();

    void drawObstacles(Graph* graph);

private:
    ViewManager* viewManagerInstance = nullptr;
    bool showing = false;
    ALLEGRO_DISPLAY* ptrDisplay = nullptr;
    void mainLoop();
    ALLEGRO_TIMER* timer;
    ALLEGRO_TIMER* timerDraw;
    ALLEGRO_EVENT_QUEUE* eventQueue;
    ALLEGRO_BITMAP* image;

    ViewManager();


    void drawPath(std::list<Cell<int>*> *pList);

};


#endif //LOG_VIEWMANAGER_H