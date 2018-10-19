//
// Created by Joseph Luis González Pastora on 8/10/18.
//

#include "NodeGraph.h"

template<typename T>
NodeGraph<T>::NodeGraph(T Xpos, T Ypos, int objectID):Xpos(Xpos), Ypos(Ypos), ObjectID(objectID){
    this->previous = nullptr;
}


template<typename T>
int NodeGraph<T>::getObjectID() const {
    return ObjectID;
}

template<typename T>
void NodeGraph<T>::setObjectID(int ObjectID) {
    NodeGraph::ObjectID = ObjectID;
}

template<typename T>
T NodeGraph<T>::getXpos() const {
    return Xpos;
}

template<typename T>
void NodeGraph<T>::setXpos(T Xpos) {
    NodeGraph::Xpos = Xpos;
}

template<typename T>
T NodeGraph<T>::getYpos() const {
    return Ypos;
}

template<typename T>
void NodeGraph<T>::setYpos(T Ypos) {
    NodeGraph::Ypos = Ypos;
}

template<typename T>
int NodeGraph<T>::getHeuristic() const {
    return Heuristic;
}

template<typename T>
void NodeGraph<T>::setHeuristic(int Heuristic) {
    NodeGraph::Heuristic = Heuristic;
}

template<typename T>
int NodeGraph<T>::getG() const {
    return g;
}

template<typename T>
void NodeGraph<T>::setG(int g) {
    NodeGraph::g = g;
}

template<typename T>
NodeGraph<T> *NodeGraph<T>::getPrevious() const {
    return previous;
}

template<typename T>
void NodeGraph<T>::setPrevious(NodeGraph<T> *previous) {
    NodeGraph::previous = previous;
}

template<typename T>
int NodeGraph<T>::getF() const {
    return F;
}

template<typename T>
void NodeGraph<T>::setF(int F) {
    NodeGraph::F = F;
}
