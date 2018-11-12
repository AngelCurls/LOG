//
// Created by edmobe on 29/10/18.
//

#include "Player.h"

Player::Player() {}
Player::Player(int x, int y) {
    i = x;
    j = y;
}

void Player::draw() {
    if (path != nullptr && path->size() > 0) {
        for (auto currentCell : *path) {
            float x = currentCell->getXpos() * this->drawRelationRatio;
            float y = currentCell->getYpos() * this->drawRelationRatio;
            //this->i = currentCell->getXpos();
            //this->j = currentCell->getYpos();
            al_draw_filled_rectangle(x, y, x + this->drawRelationRatio, y + this->drawRelationRatio,
                                     al_map_rgb(155, 155, 155)); // draws path

        }
    }
    float x = i * this->drawRelationRatio;
    float y = j * this->drawRelationRatio;
    al_draw_bitmap(playerImage, x-25, y-25,0);

    //Ecuacion de la recta para calcular el color rojo
    unsigned int redColorHealth = -17/2 * this->health + 255;

    //Ecuacion de la recta para calcular el color verde
    unsigned int greenColorHealth = 17/2 * this->health;

    //Ecuacion de la recta para calcular el largo de la barra
    float healthBarLength = 6/3 * this->health;

    al_draw_filled_rectangle(x - 25 , y - 30, x - 25 + healthBarLength, y - 28 , al_map_rgb(redColorHealth,greenColorHealth,0));
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

int Player::getDrawRelationRatio() const {
    return drawRelationRatio;
}

void Player::setDrawRelationRatio(int drawRelationRatio) {
    Player::drawRelationRatio = drawRelationRatio;
}
