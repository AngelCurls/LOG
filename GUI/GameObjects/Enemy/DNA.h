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

    int getDefenza() const;

    void setDefenza(int defenza);

    int getAtaque() const;

    void setAtaque(int ataque);

    int fitness();

    int getVidaMaxima() const;

    int getDefenzaMaxima() const;

    int getAtaqueMaximo() const;

private:
    int vida;
    int defenza;
    int ataque;

    int vidaMaxima = 30;
    int defenzaMaxima = 25;
    int ataqueMaximo = 10;

};


#endif //LOG_ADN_H
