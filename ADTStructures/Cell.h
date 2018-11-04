//
// Created by Joseph Luis González Pastora on 8/10/18.
//

#ifndef ADTLIBRARY_NODEGRAPH_H
#define ADTLIBRARY_NODEGRAPH_H

template <typename T>
class Cell {
public:
    Cell(T Xpos,T Ypos, int objectID = 0);

    int getObjectID() const;

    void setObjectID(int ObjectID);

    T getXpos() const;

    void setXpos(T Xpos);

    T getYpos() const;

    void setYpos(T Ypos);

    int getHeuristic() const;

    void setHeuristic(int Heuristic);

    int getG() const;

    void setG(int g);

    Cell<T> *getPrevious() const;

    void setPrevious(Cell<T> *previous);

    int getF() const;

    void setF(int F);

    int getHashKey() const;

    void setHashKey(int hashKey);

    bool operator < (Cell<int>* cellToCompare);
private:
    T Xpos;
    T Ypos;
    int ObjectID = 10000;
    int g = 10000;
    int Heuristic = 0;
    int F = 10000;
    int hashKey;
    Cell<T>* previous;


};


#endif //ADTLIBRARY_NODEGRAPH_H
