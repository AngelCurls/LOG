//
// Created by jglez2330 on 25/10/18.
//

#ifndef LOG_VIEWMANAGER_H
#define LOG_VIEWMANAGER_H

#include "allegro5/allegro.h"
#include <thread>
#include <iostream>
#include <allegro5/allegro_image.h>
#include "../Levels/Level.h"
#include "LevelBuilder.h"



class ViewManager {
public:
    int Height = 200;

    int Width = 200;

    void showDisplay();

    static ViewManager* getInstance();

    void destroyWindow();

    bool isShowing() const;

    int getHeight() const;

    int getWidth() const;

    ALLEGRO_DISPLAY *getPtrDisplay() const;

    virtual ~ViewManager();

private:
    ViewManager* viewManagerInstance = nullptr;
    bool showing = false;
    ALLEGRO_DISPLAY* ptrDisplay = nullptr;
    void mainLoop();
    ALLEGRO_TIMER* timer;
    ALLEGRO_TIMER* timerDraw;
    ALLEGRO_EVENT_QUEUE* eventQueue;

    ViewManager();


    void drawPath(LinkedList<NodeGraph<int> *> *pList);
};


#endif //LOG_VIEWMANAGER_H
