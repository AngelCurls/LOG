//
// Created by Joseph Luis González Pastora on 8/10/18.
//

#ifndef ADTLIBRARY_NODEGRAPH_H
#define ADTLIBRARY_NODEGRAPH_H

template <typename T>
class Cell {
public:
    Cell(T Xpos,T Ypos);

    int getObjectID() const;

    void setObjectID(int ObjectID);

    T getXpos() const;


    T getYpos() const;


    int getHeuristic() const;

    void setHeuristic(int Heuristic);

    int getG() const;

    void setG(int g);

    Cell<T> *getPrevious() const;

    void setPrevious(Cell<T> *previous);


    int getHashKey() const;

    void setHashKey(int hashKey);

    bool operator < (Cell<T>* cellToCompare);

    int getDijkstraDistance() const;

    void setDijkstraDistance(int DijkstraDistance);

    bool isVisited() const;

    void setVisited(bool pVisit);

    bool operator == (const Cell<T> &cellToCompare) const;

private:
    T Xpos;
    T Ypos;
    int ObjectID = 0;
    int g = 10000;
    int Heuristic = 0;
    int DijkstraDistance = 0;
    bool visited = false;

    int hashKey;
    Cell<T>* previous;


};


#endif //ADTLIBRARY_NODEGRAPH_H
