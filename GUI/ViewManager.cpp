//
// Created by jglez2330 on 25/10/18.
//

#include "ViewManager.h"
#include <allegro5/allegro_primitives.h>



ViewManager::ViewManager() {
    al_init();
    al_install_mouse();
    al_init_image_addon();
    bool t = al_init_primitives_addon();

    int fps = 60;

    this->timer = al_create_timer(1.0/fps);
    this->timerDraw = al_create_timer(1.0*2/fps);
    this->eventQueue = al_create_event_queue();


    al_register_event_source(this->eventQueue,al_get_mouse_event_source());
    al_register_event_source(this->eventQueue,al_get_timer_event_source(this->timer));
    al_register_event_source(this->eventQueue,al_get_timer_event_source(this->timerDraw));



    showing = true;

    //showDisplay();
    //std::cout << "Hola ";


}

void ViewManager::showDisplay() {
    //std::thread displayThread(&ViewManager::mainLoop,this->viewManagerInstance);
    //displayThread.join();
mainLoop();

}

void ViewManager::mainLoop() {
    this->ptrDisplay = al_create_display(this->Height,this->Width);
    al_register_event_source(this->eventQueue,al_get_display_event_source(this->ptrDisplay));

    al_start_timer(this->timer);
    al_start_timer(this->timerDraw);


    Graph* graph = new Graph();
    graph->generateGrid();
    std::list<Cell<int>*>* path = nullptr;
    ALLEGRO_MOUSE_STATE mouseState;
    int levelNumber = 0;
    int yGraph;
    int xGraph;
    Level* gameLevel = LevelBuilder::getLevel(levelNumber);
    ALLEGRO_EVENT event;

    while (showing){

        al_wait_for_event(this->eventQueue,&event);
        //std::cout << event.type;

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            showing = false;
            destroyWindow();
        }else if (event.type == ALLEGRO_EVENT_TIMER){
            if (event.timer.source == this->timer){
                al_get_mouse_state(&mouseState);

                if (mouseState.buttons & 1 || mouseState.buttons & 2){

                    xGraph = mouseState.x;
                    yGraph = mouseState.y;

                    path = gameLevel->getPath(graph,xGraph/10,yGraph/10, 49,49);






                }

            } else if ( event.timer.source == this->timerDraw){
                al_clear_to_color(al_map_rgb(255,255,255));
                drawPath(path);
                drawObstacles(graph);
                al_flip_display();

            }
        }

    }
    delete(path);
    delete(graph);

}

ViewManager* ViewManager::getInstance() {
    ViewManager* ptrInstance = new ViewManager();
    ptrInstance->viewManagerInstance = ptrInstance;
    return ptrInstance;
}

bool ViewManager::isShowing() const {
    return showing;
}

void ViewManager::destroyWindow() {
    showing = false;
    al_destroy_display(this->ptrDisplay);

}

int ViewManager::getHeight() const {
    return Height;
}

int ViewManager::getWidth() const {
    return Width;
}

ALLEGRO_DISPLAY* ViewManager::getPtrDisplay() const {
    return ptrDisplay;
}

ViewManager::~ViewManager() {
    delete(viewManagerInstance);
    if (showing){
        this->destroyWindow();
    }
}


void ViewManager::drawPath(std::list<Cell<int>*>* pList) {
    if (pList != nullptr) {
        for (auto currentCell : *pList) {
            //al_draw_rectangle((float)node->getXpos(),(float)node->getYpos(),node->getXpos() + this->getWidth()/19,node->getXpos() + this->getWidth()/19,al_map_rgb(0, 255, 0), 255);
            float x = (float) currentCell->getXpos();
            float y = (float) currentCell->getYpos();
            al_draw_filled_rectangle(x*10, y*10 ,x*10+10,y*10+10, al_map_rgb(0, 255, 255));
        }
    }
}

void ViewManager::drawObstacles(Graph *graph) {
    for (int i = 0; i < graph->getHeight() ; i++) {
        for (int j = 0; j < graph->getWidth() ; j++) {
            Cell<int>* cellCurrent = graph->getKeyTable()[i][j];
            if (cellCurrent->getObjectID() == 10000) {
                al_draw_filled_rectangle(cellCurrent->getXpos() * 10, cellCurrent->getYpos() * 10,
                                         cellCurrent->getXpos() * 10 + 10, cellCurrent->getYpos() * 10 + 10,
                                         al_map_rgb(0, 0, 0));
            }
        }

    }

}
