//
// Created by Joseph González Pastora on 10/22/18.
//

#include <ctime>
#include <cstdlib>
#include "DNA.h"

DNA::DNA() {
    srand(time(nullptr));
    this->ataque = rand() % this->ataqueMaximo + 1;
    this->defensa = rand() % this->defensaMaxima + 1;
    this->vida = rand() % this->vidaMaxima + 1;

    this->redPhenotype = 255 - 255/this->ataqueMaximo * this->ataque;
    this->greenPhenotype = 255 - 255/this->vidaMaxima * this->vida;
    this->bluePhenotype = 255 - 255/this->defensaMaxima * this->defensa;


}

int DNA::fitness() {
    return (this->vida + this->defensa + this->ataque) * 100  / (this->defensaMaxima + this->vidaMaxima + this->ataqueMaximo);
}

int DNA::getVida() const {
    return vida;
}

void DNA::setVida(int vida) {
    DNA::vida = vida % this->getVidaMaxima() + 1;
}

int DNA::getDefensa() const {
    return defensa;
}

void DNA::setDefensa(int defenza) {
    DNA::defensa = defenza % this->defensaMaxima + 1;
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

int DNA::getDefensaMaxima() const {
    return defensaMaxima;
}

int DNA::getAtaqueMaximo() const {
    return ataqueMaximo;
}

int DNA::getRedPhenotype() const {
    return redPhenotype;
}

int DNA::getGreenPhenotype() const {
    return greenPhenotype;
}

int DNA::getBluePhenotype() const {
    return bluePhenotype;
}
