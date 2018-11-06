//
// Created by jglez2330 on 25/10/18.
//

#include "Game.h"
#include "../ADTStructures/Graph.cpp"
#include <allegro5/allegro_primitives.h>



Game::Game() {
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

void Game::showDisplay() {
    //std::thread displayThread(&Game::mainLoop,this->viewManagerInstance);
    //displayThread.join();
    mainLoop();

}

void Game::mainLoop() {
    this->ptrDisplay = al_create_display(this->Height,this->Width);
    al_register_event_source(this->eventQueue,al_get_display_event_source(this->ptrDisplay));

    al_start_timer(this->timer);
    al_start_timer(this->timerDraw);


    Graph<int>* graph = new Graph<int>();
    graph->gridGenerator(20, 20);
    LinkedList<NodeGraph<int>*>* path = nullptr;
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
        } else if (event.type == ALLEGRO_EVENT_TIMER){
            if (event.timer.source == this->timer){
                al_get_mouse_state(&mouseState);

                if (mouseState.buttons & 1 || mouseState.buttons & 2){

                    //al_get_mouse_cursor_position(&xGraph,&yGraph);
                    xGraph = mouseState.x;
                    yGraph = mouseState.y;
                    //std::cout<< xGraph << ";" << yGraph << std::endl;
                    //al_get_mouse_state(&mouseState);
                    std::cout<< "funka";
                    path = gameLevel->getPath(graph, xGraph/10, yGraph/10, 0, 0);

                    std::cout<< "funka";

                    levelNumber++;



                }

            } else if ( event.timer.source == this->timerDraw){
                al_clear_to_color(al_map_rgb(255, 255, 255));
                drawPath(path);
                al_flip_display();
            }
        }

    }
    delete(path);
    delete(graph);

}

Game* Game::getInstance() {
    Game* ptrInstance = new Game();
    ptrInstance->viewManagerInstance = ptrInstance;
    return ptrInstance;
}

bool Game::isShowing() const {
    return showing;
}

void Game::destroyWindow() {
    showing = false;
    al_destroy_display(this->ptrDisplay);

}

int Game::getHeight() const {
    return Height;
}

int Game::getWidth() const {
    return Width;
}

ALLEGRO_DISPLAY *Game::getPtrDisplay() const {
    return ptrDisplay;
}

Game::~Game() {
    delete(viewManagerInstance);
    if (showing){
        this->destroyWindow();
    }
}

void Game::drawPath(LinkedList<NodeGraph<int> *> *pList) {
    if (pList != nullptr) {
        for (int i = 0; i < pList->getSize(); i++) {
            NodeGraph<int> *node = pList->get(i);
            //al_draw_rectangle((float)node->getXpos(),(float)node->getYpos(),node->getXpos() + this->getWidth()/19,node->getXpos() + this->getWidth()/19,al_map_rgb(0, 255, 0), 255);
            float x = (float) node->getXpos();
            float y = (float) node->getYpos();
            al_draw_filled_rectangle(x * this->getHeight() / 20, y * this->getWidth() / 20,
                                     x * this->getHeight() / 20 + this->getHeight() / 20,
                                     y * this->getWidth() / 20 + this->getWidth() / 20, al_map_rgb(0, 255, 255));
        }


    }
}