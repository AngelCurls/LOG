#include "ViewManager.h"
#include "GameObjects/PlayerPopulation.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

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

    ALLEGRO_FONT *font = al_load_font("arial.ttf",72,0 );

    Graph* graph = new Graph(100,100,4);
    graph->generateGrid();
    PlayerPopulation* playerPopulation = new PlayerPopulation();
    playerPopulation->setMap(graph);
    std::list<Cell<int>*>* path = nullptr;
    ALLEGRO_MOUSE_STATE mouseState;
    int levelNumber = 0;
    int yGraph = 0;
    int xGraph = 0;

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

                    if (mouseState.x >= 0 && mouseState.y >= 0) {
                        xGraph = mouseState.x / this->relationRatio;
                        yGraph = mouseState.y / this->relationRatio;
                    }
                    //playerPopulation->moveToPath(xGraph/10,yGraph/10);
                    path = gameLevel->getPath(graph,xGraph,yGraph,10, 39);


                }

            } else if (event.timer.source == this->timerDraw){
                al_clear_to_color(al_map_rgb(255,255,255));
                //playerPopulation->draw();
                drawObstacles(graph);
                drawPath(path);

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
            float x = currentCell->getXpos() * this->relationRatio;
            float y = currentCell->getYpos() * this->relationRatio;
            al_draw_filled_rectangle(x, y ,x+this->relationRatio,y + this->relationRatio, al_map_rgb(0, 255, 255));
        }
    }
}

void ViewManager::drawObstacles(Graph *graph) {
    for (int i = 0; i < graph->getHeight() ; i++) {
        for (int j = 0; j < graph->getWidth() ; j++) {
            Cell<int>* cellCurrent = graph->getKeyTable()[i][j];
            if (cellCurrent->getObjectID() == 1) {
                al_draw_filled_rectangle(cellCurrent->getXpos() * 10, cellCurrent->getYpos() * 10,
                                         cellCurrent->getXpos() * 10 + 10, cellCurrent->getYpos() * 10 + 10,
                                         al_map_rgb(0, 0, 0));
            }
            /*if (cellCurrent->getObjectID() == 2) {
                al_draw_filled_rectangle(cellCurrent->getXpos() * 10, cellCurrent->getYpos() * 10,
                                         cellCurrent->getXpos() * 10 + 10, cellCurrent->getYpos() * 10 + 10,
                                         al_map_rgb(0, 255, 0));
            }if (cellCurrent->getObjectID() == 3) {
                al_draw_filled_rectangle(cellCurrent->getXpos() * 10, cellCurrent->getYpos() * 10,
                                         cellCurrent->getXpos() * 10 + 10, cellCurrent->getYpos() * 10 + 10,
                                         al_map_rgb(255, 0, 0));
            }
*/
        }

    }

}