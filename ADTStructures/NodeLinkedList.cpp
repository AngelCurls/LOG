//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#include "NodeLinkedList.h"

template<typename T>
T NodeLinkedList<T>::getData() const {
    return data;
}

template<typename T>
void NodeLinkedList<T>::setData(T data) {
    this->data = data;
}

template<typename T>
NodeLinkedList<T> *NodeLinkedList<T>::getNext() const {
    return next;
}

template<typename T>
void NodeLinkedList<T>::setNext(NodeLinkedList<T> *next) {
    this->next = next;
}

template<typename T>
NodeLinkedList<T>::NodeLinkedList(T data):data(data) {
    this->next = nullptr;
}

template<typename T>
int NodeLinkedList<T>::getWeight() const {
    return weight;
}

template<typename T>
void NodeLinkedList<T>::setWeight(int weight) {
    NodeLinkedList::weight = weight;
}

