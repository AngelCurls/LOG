//
// Created by Joseph González Pastora on 10/22/18.
//

#include <ctime>
#include <cstdlib>
#include "DNA.h"

DNA::DNA() {
    srand(time(nullptr));
    this->ataque = rand() % this->ataqueMaximo + 1;
    this->defenza = rand() % this->defenzaMaxima + 1;
    this->vida = rand() % this->vidaMaxima + 1;
}

int DNA::fitness() {
    return (this->vida + this->defenza + this->ataque) * 100  / 65;
}

int DNA::getVida() const {
    return vida;
}

void DNA::setVida(int vida) {
    DNA::vida = vida % this->getVidaMaxima() + 1;
}

int DNA::getDefenza() const {
    return defenza;
}

void DNA::setDefenza(int defenza) {
    DNA::defenza = defenza % this->defenzaMaxima + 1;
}

int DNA::getAtaque() const {
    return ataque;
}

void DNA::setAtaque(int ataque) {
    DNA::ataque = ataque % this->getAtaqueMaximo() +1;
}

DNA::~DNA() {

}

int DNA::getVidaMaxima() const {
    return vidaMaxima;
}

int DNA::getDefenzaMaxima() const {
    return defenzaMaxima;
}

int DNA::getAtaqueMaximo() const {
    return ataqueMaximo;
}


