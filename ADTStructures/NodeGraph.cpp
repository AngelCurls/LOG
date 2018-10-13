//
// Created by Joseph Luis González Pastora on 8/10/18.
//

#include "NodeGraph.h"

template<typename T>
NodeGraph<T>::NodeGraph(T data):data(data){}

template<typename T>
T NodeGraph<T>::getData() const {
    return data;
}

template<typename T>
void NodeGraph<T>::setData(T data) {
    NodeGraph::data = data;
}

