//
// Created by jglez2330 on 12/11/18.
//

#ifndef LOG_GEM_H
#define LOG_GEM_H


class Gem {
public:
    void draw();

    int getI() const;

    int getJ() const;

private:
    int i = 49;
    int j = 0;

};


#endif //LOG_GEM_H
