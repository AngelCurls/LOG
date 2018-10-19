//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#include "Graph.h"
// TODO:
template<typename T>
Graph<T>::Graph() {
    this->GraphRepresentationList = new LinkedList<LinkedList<NodeGraph<T>*>*>();
}

template<typename T>
void Graph<T>::addEdge(T fromNodeXpos,T fromNodeYpos, T toNodeXpos, T toNodeYpos, int weight) {
    if (this->GraphRepresentationList->getSize() != 0) {
        for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
            if (this->GraphRepresentationList->get(i)->get(0)->getXpos() == fromNodeXpos && this->GraphRepresentationList->get(i)->get(0)->getYpos() == fromNodeYpos ) {
                this->GraphRepresentationList->get(i)->add(addNode(toNodeXpos,toNodeYpos));
                break;
            }

        }
    } else {
        addNode(fromNodeXpos, fromNodeYpos);
        for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
            if (this->GraphRepresentationList->get(i)->get(0)->getXpos() == fromNodeXpos && this->GraphRepresentationList->get(i)->get(0)->getYpos() == fromNodeYpos ){// && !this->contains(this->GraphRepresentationList->get(i),toNode)) {
                this->GraphRepresentationList->get(i)->add(addNode(toNodeXpos,toNodeYpos));
                break;
            }

        }
    }
}



template<typename T>
NodeGraph<T>* Graph<T>::addNode(T XposNode, T YposNode) {
    NodeGraph<T>* nodeGraph;
    if (isDataIn(XposNode,YposNode)) {
        for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
            if (this->GraphRepresentationList->get(i)->get(0)->getXpos() == XposNode && this->GraphRepresentationList->get(i)->get(0)->getYpos() == YposNode){
                nodeGraph = this->GraphRepresentationList->get(i)->get(0);
                break;
            }

        }
    } else {
        nodeGraph = new NodeGraph<T>(XposNode,YposNode);
        //nodeGraph->setObjectID(rand() % 2);
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
            std::cout <<"(" << this->GraphRepresentationList->get(i)->get(j)->getXpos()<<","<<this->GraphRepresentationList->get(i)->get(j)->getYpos()<< ") "<<" ~> ";

        }
        std::cout << std::endl;
    }

}

template<typename T>
void Graph<T>::printGraphMap() {
    for (int i = 0; i < this->GraphRepresentationList->getSize(); i++) {
        for (int j = 0; j <this->GraphRepresentationList->get(i)->getSize() ; j++) {
            std::cout << this->GraphRepresentationList->get(i)->get(j)->getObjectID() << " ~> ";

        }
        std::cout << std::endl;
    }

}

template<typename T>
bool Graph<T>::isDataIn(T Xpos, T Ypos) {
    bool dataIn = false;
    for (int i = 0; i <this->GraphRepresentationList->getSize() ; i++) {
        if (this->GraphRepresentationList->get(i)->get(0)->getXpos() == Xpos &&this->GraphRepresentationList->get(i)->get(0)->getYpos() == Ypos ){
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

template<typename T>
NodeGraph<T> *Graph<T>::getNode(T data) {
    NodeGraph<T>* node;
    for (int i = 0; i <this->GraphRepresentationList->getSize(); i++) {
        for (int j = 0; j <this->GraphRepresentationList->get(i)->getSize() ; j++) {
            if (this->GraphRepresentationList->get(i)->get(j)->getData() == data){
                node = this->GraphRepresentationList->get(i)->get(j);
            }

        }
        
    }
    return node;
}

template<typename T>
void Graph<T>::gridGenerator(int height, int widht) {

    for (int i = 0; i < height ; i++) {
        for (int j = 0; j < widht; j++) {
            if(i + 1 < height) {
                addEdge(i, j, i + 1, j,1);
                addEdge(i + 1, j, i, j,1);

            }
            if (i - 1 > height) {
                addEdge(i, j, i - 1, j,1);
                addEdge(i - 1, j, i , j,1);
            }
            if (j + 1 < widht) {
                addEdge(i, j, i, j + 1,1);
                addEdge(i, j + 1, i, j,1);
            }
            if (j -1 > widht) {
                addEdge(i, j, i, j - 1,1);
                addEdge(i, j - 1, i, j,1);
            }
        }
    }
}

template<typename T>
NodeGraph<T> *Graph<T>::getNode(int i, int j) {
    NodeGraph<T> * node = nullptr;
    for (int k = 0; k < this->GraphRepresentationList->getSize(); k++) {
        for (int l = 0; l < this->GraphRepresentationList->get(k)->getSize() ; l++) {
            auto nodeTemp= this->GraphRepresentationList->get(k)->get(l);
            if (nodeTemp->getXpos() == i && nodeTemp->getYpos() == j ){
                node = nodeTemp;
                break;
            }

        }

    }
    return node;
}

template<typename T>
LinkedList<LinkedList<NodeGraph<T> *> *> *Graph<T>::getGraphRepresentationList() const {
    return GraphRepresentationList;
}

template<typename T>
LinkedList<NodeGraph<T>*>*  Graph<T>::getAdjacencyList(NodeGraph<T>* searchedNode) {
    LinkedList<NodeGraph<T>*>* list = nullptr;
    for (int i = 0; i < this->GraphRepresentationList->getSize() ; i++) {
        if (this->GraphRepresentationList->get(i)->get(0) == searchedNode){
            list = this->GraphRepresentationList->get(i);
            break;
        }

    }
    return list;


}
