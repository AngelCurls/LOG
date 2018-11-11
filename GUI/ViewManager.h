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
#include <allegro5/allegro_audio.h>
#include "../Levels/Level.h"
#include "LevelBuilder.h"
#include "../ADTStructures/LinkedList.cpp"
#include <allegro5/allegro_acodec.h>



class ViewManager {
public:
    int Height = 500;

    int Width = 500;

    float relationRatio = 10;

    void showDisplay();

    static ViewManager* getInstance();

    void destroyWindow();

    bool isShowing() const;

    int getHeight() const;

    int getWidth() const;

    ALLEGRO_DISPLAY *getPtrDisplay() const;

    virtual ~ViewManager();

    void drawMap(Graph *graph);

    void drawPlayer();

private:
    ViewManager* viewManagerInstance = nullptr;
    bool showing = false;
    ALLEGRO_DISPLAY* ptrDisplay = nullptr;
    ALLEGRO_DISPLAY* menuDisplay = nullptr;
    void mainLoop();
    ALLEGRO_TIMER* timer;
    ALLEGRO_TIMER* timerDraw;
    ALLEGRO_EVENT_QUEUE* eventQueue;
    ALLEGRO_SAMPLE * music;
    ALLEGRO_SAMPLE_INSTANCE *songInstance;
    ALLEGRO_BITMAP* image;


    ViewManager();


    void drawPath(std::list<Cell<int>*> *pList);


};


#endif //LOG_VIEWMANAGER_H