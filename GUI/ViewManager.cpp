#include "ViewManager.h"
#include "GameObjects/Population.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ViewManager::ViewManager() {
    al_init();
    al_install_mouse();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_acodec_addon();


    int fps = 60;

    this->timer = al_create_timer(1.0/fps);
    this->timerDraw = al_create_timer(1.0*2/fps);
    this->eventQueue = al_create_event_queue();


    al_register_event_source(this->eventQueue,al_get_mouse_event_source());
    al_register_event_source(this->eventQueue,al_get_keyboard_event_source());
    al_register_event_source(this->eventQueue,al_get_timer_event_source(this->timer));
    al_register_event_source(this->eventQueue,al_get_timer_event_source(this->timerDraw));



    showing = true;




}

void ViewManager::showDisplay() {

    al_set_new_window_title("Menu");
    this->menuDisplay = al_create_display(435,435);
    al_register_event_source(this->eventQueue,al_get_display_event_source(this->menuDisplay));


    image = al_load_bitmap("../GUI/LOG.png");

    al_reserve_samples(1);
    music = al_load_sample("../GUI/Ameno.wav");
    al_play_sample(music,1.0,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,0);



    al_start_timer(this->timer);
    al_start_timer(this->timerDraw);
    ALLEGRO_KEYBOARD_STATE keyMenu;
    ALLEGRO_EVENT event;

    while (showing) {

        al_wait_for_event(this->eventQueue, &event);

        al_draw_bitmap(image,0,0, NULL);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            showing = false;
            destroyWindow();
        } else if (event.type == ALLEGRO_EVENT_TIMER) {
            if (event.timer.source == this->timer) {
                al_get_keyboard_state(&keyMenu);
                if(al_key_down(&keyMenu,ALLEGRO_KEY_ENTER)) {

                   mainLoop();


                }
            }


        }


    }
   /* al_destroy_display(menuDisplay);
    al_destroy_timer(timer);
    al_destroy_sample_instance(songInstance);
    al_destroy_sample(music);
    al_destroy_event_queue(eventQueue);
    al_destroy_bitmap(image); */
}

void ViewManager::mainLoop() {
    al_destroy_display(this->menuDisplay);
    al_set_new_window_title("LOG");
    this->ptrDisplay = al_create_display(this->Height,this->Width);


    al_register_event_source(this->eventQueue,al_get_display_event_source(this->ptrDisplay));

    al_start_timer(this->timer);
    al_start_timer(this->timerDraw);

    ALLEGRO_FONT *font = al_load_font("arial.ttf",72,0 );

    Graph* graph = new Graph(50,50,3);
    graph->generateGrid();

    Population* playerPopulation = new Population();
    playerPopulation->setMap(graph);

    std::list<Cell<int>*>* path = nullptr;
    ALLEGRO_MOUSE_STATE mouseState;
    ALLEGRO_KEYBOARD_STATE keyState;
    int levelNumber = 0;
    int yGraph = 0;
    int xGraph = 0;

    Level* gameLevel = LevelBuilder::getLevel(1);
    ALLEGRO_EVENT event;
    while (showing){


        al_wait_for_event(this->eventQueue,&event);

        //std::cout << event.type;

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            showing = false;
            destroyWindow();
        } else if (event.type == ALLEGRO_EVENT_TIMER){
            if (event.timer.source == this->timer){
                //drawPlayer();
                al_get_mouse_state(&mouseState);
                al_get_keyboard_state(&keyState);

                if (mouseState.buttons & 1 || mouseState.buttons & 2){

                    if (mouseState.x >= 0 && mouseState.y >= 0) {
                        xGraph = mouseState.x / this->relationRatio;
                        yGraph = mouseState.y / this->relationRatio;
                    }
                    playerPopulation->setPath(gameLevel, xGraph, yGraph); // Le da un path a todos los jugadores según el lugar donde se dio click
                }
                if(al_key_down(&keyState,ALLEGRO_KEY_Q)) {
                    std::cout << "Q \n";
                    //metodo para ataque desbloqueado
                }else if (al_key_down(&keyState, ALLEGRO_KEY_W)) {
                    std::cout << "W \n";
                    //metodo para ataque desbloqueado
                }else if (al_key_down(&keyState, ALLEGRO_KEY_E)) {
                    std::cout << "E \n";
                    //metodo para ataque desbloqueado
                }else if (al_key_down(&keyState, ALLEGRO_KEY_A)) {
                    std::cout << "A \n";
                    //metodo para ataque desbloqueado
                }else if (al_key_down(&keyState, ALLEGRO_KEY_S)) {
                    std::cout << "S \n";
                    //metodo para ataque desbloqueado
                }


            } else if (event.timer.source == this->timerDraw){

                playerPopulation->updatePlayers(); // Hace que los jugadores se muevan según el path
                al_clear_to_color(al_map_rgb(255,255,255));
                drawMap(graph);
                playerPopulation->draw(); // Dibuja todos los jugadores
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

void ViewManager::drawMap(Graph *graph) {
    for (int i = 0; i < graph->getHeight() ; i++) {
        for (int j = 0; j < graph->getWidth() ; j++) {
            Cell<int>* cellCurrent = graph->getKeyTable()[i][j];
            ALLEGRO_COLOR obstacleColor = al_map_rgb(255, 255, 255);
            if (cellCurrent->getObjectID() == 1) {
                obstacleColor = al_map_rgb(0, 0, 0);
            }
            else if (cellCurrent->getObjectID() == 2) {
                obstacleColor = al_map_rgb(0, 255, 0);
            }
            else if (cellCurrent->getObjectID() == 3) {
                obstacleColor = al_map_rgb(255, 0, 0);
            }
            al_draw_filled_rectangle(cellCurrent->getXpos() * 10, cellCurrent->getYpos() * 10,
                                     cellCurrent->getXpos() * 10 + 10, cellCurrent->getYpos() * 10 + 10,
                                     obstacleColor);
        }

    }

}