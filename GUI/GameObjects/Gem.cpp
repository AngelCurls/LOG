//
// Created by jglez2330 on 12/11/18.
//

#include <allegro5/allegro_primitives.h>
#include "Gem.h"

void Gem::draw() {

    al_draw_filled_circle(this->i * 13 + 13 , this->j * 13,20,al_map_rgb(137,98,115));

}

int Gem::getI() const {
    return i;
}

int Gem::getJ() const {
    return j;
}
