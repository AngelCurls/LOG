//
// Created by Joseph Luis González Pastora on 8/10/18.
//

#ifndef ADTLIBRARY_NODEGRAPH_H
#define ADTLIBRARY_NODEGRAPH_H

template <typename T>
class NodeGraph {
public:
    NodeGraph(T Xpos,T Ypos, int objectID = 0);

    int getWeight() const;

    void setWeight(int weight);

    int getObjectID() const;

    void setObjectID(int ObjectID);

    T getXpos() const;

    void setXpos(T Xpos);

    T getYpos() const;

    void setYpos(T Ypos);

    int getHeuristic() const;

    void setHeuristic(int Heuristic);

private:
    T Xpos;
    T Ypos;
    int ObjectID;
    int weight;
    int Heuristic;


};


#endif //ADTLIBRARY_NODEGRAPH_H
