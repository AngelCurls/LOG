//
// Created by Joseph González Pastora on 10/22/18.
//

#ifndef LOG_ADN_H
#define LOG_ADN_H


class DNA {
public:
    DNA();

    virtual ~DNA();

    int getVida() const;

    void setVida(int vida);

    int getDefensa() const;

    void setDefensa(int defenza);

    int getAtaque() const;

    void setAtaque(int ataque);

    int fitness();

    int getVidaMaxima() const;

    int getDefensaMaxima() const;

    int getAtaqueMaximo() const;

    int getRedPhenotype() const;

    int getGreenPhenotype() const;

    int getBluePhenotype() const;
    int vidaOriginal;

private:
    int vida;
    int defensa;
    int ataque;



    int vidaMaxima = 120;
    int defensaMaxima = 120;
    int ataqueMaximo = 120;

    unsigned int redPhenotype;
    unsigned int greenPhenotype;
    unsigned int bluePhenotype;

};


#endif //LOG_ADN_H
