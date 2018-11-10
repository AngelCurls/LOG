//
// Created by edmobe on 29/10/18.
//

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Player.h"

Player::Player() {}
Player::Player(int y) {
    j = y;
}

void Player::draw() {
    ALLEGRO_BITMAP *player =  al_load_bitmap("../Images/sold1.png");

    if (path != nullptr && path->size() > 0) {
            for (auto currentCell : *path) {
                    float x = currentCell->getXpos() * 10;
                    float y = currentCell->getYpos() * 10;
                    this->i = currentCell->getXpos();
                    this->j = currentCell->getYpos();
                    al_draw_filled_rectangle(x, y, x + 10, y + 10, al_map_rgb(155, 155, 155)); // draws path

            }
            delete(path);
            path = nullptr;

        }
    float x = i * 10;
    float y = j * 10;

    al_draw_bitmap(player,x-25,y-25,0);
    //al_draw_filled_rectangle(x,y,x+10,y+10,al_map_rgb(255,98,115)); // draws player rectangle

    }

void Player::attack() {

    
}



std::list<Cell<int> *> *Player::getPath() const {
    return path;
}

void Player::setPath(std::list<Cell<int> *> *path) {
    Player::path = path;
}

int Player::getI() const {
    return i;
}

void Player::setI(int i) {
    Player::i = i;
}

int Player::getJ() const {
    return j;
}

void Player::setJ(int j) {
    Player::j = j;
}

void Player::setSpeed(int speed) {
    this->speed = speed;

}
