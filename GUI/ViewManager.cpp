//
// Created by jglez2330 on 25/10/18.
//

#include "ViewManager.h"
#include "../ADTStructures/Graph.cpp"
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

    al_start_timer(this->timer);
    al_start_timer(this->timerDraw);

    showing = true;

    //showDisplay();
    //std::cout << "Hola ";


}

void ViewManager::showDisplay() {
    std::thread displayThread(&ViewManager::mainLoop,this->viewManagerInstance);
    displayThread.join();


}

void ViewManager::mainLoop() {
    this->ptrDisplay = al_create_display(this->Height,this->Width);
    al_register_event_source(this->eventQueue,al_get_display_event_source(this->ptrDisplay));


    Graph<int>* graph = new Graph<int>();
    graph->gridGenerator(20,20);
    LinkedList<NodeGraph<int>*>* path = nullptr;
    int levelNumber = 0;
    Level* gameLevel = LevelBuilder::getLevel(levelNumber);
    while (showing){
        ALLEGRO_EVENT event;

        al_wait_for_event(this->eventQueue,&event);
        //std::cout << event.type;

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            showing = false;
            destroyWindow();
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            ALLEGRO_MOUSE_STATE mouseState;
            al_get_mouse_state(&mouseState);
            int xGraph = 19 * mouseState.x/this->getWidth();
            int yGraph = 19 * mouseState.y/this->getHeight();
            path = gameLevel->getPath(graph,xGraph,yGraph, 19,19);

        }
        drawPath(path);
        al_flip_display();

    }

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

ALLEGRO_DISPLAY *ViewManager::getPtrDisplay() const {
    return ptrDisplay;
}

ViewManager::~ViewManager() {
    delete(viewManagerInstance);
    if (showing){
        this->destroyWindow();
    }
}

void ViewManager::drawPath(LinkedList<NodeGraph<int> *> *pList) {
    if (pList != nullptr) {
        for (int i = 0; i < pList->getSize(); i++) {
            NodeGraph<int> *node = pList->get(i);
            //al_draw_rectangle((float)node->getXpos(),(float)node->getYpos(),node->getXpos() + this->getWidth()/19,node->getXpos() + this->getWidth()/19,al_map_rgb(0, 255, 0), 255);
            float x = (float) node->getXpos();
            float y = (float) node->getYpos();
            al_draw_filled_rectangle(x * this->getHeight() / 20, y * this->getWidth() / 20,
                                     x * this->getHeight() / 20 + this->getHeight() / 20,
                                     y * this->getWidth() / 20 + this->getWidth() / 20, al_map_rgb(0, 100, 100));
        }


    }
}