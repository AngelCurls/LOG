//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#ifndef ADTLIBRARY_GRAPH_H
#define ADTLIBRARY_GRAPH_H


#include "LinkedList.h"
#include "LinkedList.cpp"
#include "NodeGraph.h"
#include "NodeGraph.cpp"
template<typename T>
class Graph {
public:
    Graph();
    void addEdge(T fromNode,T toNode,int weight = 0);
    void printGraph();
    bool contains(LinkedList<NodeGraph<T>*>* list, T data);

private:
    LinkedList<LinkedList<NodeGraph<T>*>*>* GraphRepresentationList;
    NodeGraph<T>* addNode(T node);
    bool isDataIn(T data);


};


#endif //ADTLIBRARY_GRAPH_H
