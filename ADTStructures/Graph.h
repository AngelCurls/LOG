//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#ifndef ADTLIBRARY_GRAPH_H
#define ADTLIBRARY_GRAPH_H


#include "LinkedList.cpp"
#include "NodeGraph.cpp"
template<typename T>
class Graph {
public:
    Graph();
    void addEdge(T fromNodeXpos,T fromNodeYpos, T toNodeXpos, T toNodeYpos,int weight = 0);
    void printGraph();
    void printGraphMap();
    bool contains(LinkedList<NodeGraph<T>*>* list, T data);
    NodeGraph<T>* getNode(T data);
    NodeGraph<T>* getNode(int i, int j);
    void gridGenerator(int height, int width);
    void remove(T data);

    LinkedList<LinkedList<NodeGraph<T> *> *> *getGraphRepresentationList() const;

    LinkedList<NodeGraph<T>*>*  getAdjacencyList(NodeGraph<T>* node);

private:
    LinkedList<LinkedList<NodeGraph<T>*>*>* GraphRepresentationList;
    NodeGraph<T>* addNode(T XposNode,T YposNode);
    bool isDataIn(T Xpos, T Ypos);


};


#endif //ADTLIBRARY_GRAPH_H
