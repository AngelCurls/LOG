//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#include "Graph.h"

template<typename T>
Graph<T>::Graph() {
    this->GraphRepresentationList = new LinkedList<LinkedList<NodeGraph<T>*>*>();
}

template<typename T>
void Graph<T>::addEdge(T fromNode,T toNode, int weight) {
    if (isDataIn(fromNode)) {
        for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
            if (this->GraphRepresentationList->get(i)->get(0)->getData() == fromNode && !this->contains(this->GraphRepresentationList->get(i),toNode)) {
                this->GraphRepresentationList->get(i)->add(addNode(toNode));
            }

        }
    } else {
        addNode(fromNode);
        for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
            if (this->GraphRepresentationList->get(i)->get(0)->getData() == fromNode && !this->contains(this->GraphRepresentationList->get(i),toNode)) {
                this->GraphRepresentationList->get(i)->add(addNode(toNode));
            }

        }
    }
}



template<typename T>
NodeGraph<T>* Graph<T>::addNode(T node) {
    NodeGraph<T>* nodeGraph;
    if (isDataIn(node)) {
        for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
            if (this->GraphRepresentationList->get(i)->get(0)->getData() == node ){
                nodeGraph = this->GraphRepresentationList->get(i)->get(0);
                break;
            }

        }
    } else {
        nodeGraph = new NodeGraph<T>(node);
        LinkedList<NodeGraph<T>*>* list = new LinkedList<NodeGraph<T>*>();
        list->add(nodeGraph);
        this->GraphRepresentationList->add(list);
    }
    return nodeGraph;



}

template<typename T>
void Graph<T>::printGraph() {
    for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
        for (int j = 0; j <this->GraphRepresentationList->get(i)->getSize() ; j++) {
            std::cout << this->GraphRepresentationList->get(i)->get(j)->getData() << " ~> ";

        }
        std::cout << std::endl;
    }

}

template<typename T>
bool Graph<T>::isDataIn(T data) {
    bool dataIn = false;
    for (int i = 0; i <this->GraphRepresentationList->getSize() ; i++) {
        if (this->GraphRepresentationList->get(i)->get(0)->getData() == data){
            dataIn = true;
            break;
        }

    }
    return dataIn;
}

template<typename T>
bool Graph<T>::contains(LinkedList<NodeGraph<T> *> *list, T data) {
    bool isDataIn = false;
    for (int i = 0; i <list->getSize(); i++) {
        if (list->get(i)->getData() == data){
            isDataIn = true;
            break;
        }

    }
    return isDataIn;
}
