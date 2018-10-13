//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#ifndef ADTLIBRARY_LINKEDLIST_H
#define ADTLIBRARY_LINKEDLIST_H

#include "NodeLinkedList.h"
#include "NodeLinkedList.cpp"

template<typename T>
class LinkedList {

public:
    LinkedList();

    void add(T data);
    int getWeight(int index);
    void setWeight(int index, int weight);
    T get(int index);
    T operator[](int index);
    void remove(int index);
    NodeLinkedList<T>* getNode(int index);
    bool isDataIn(T data);
    void printList();

    NodeLinkedList<T> *getHead() const;

    int getSize() const;

private:
    NodeLinkedList<T>* head;
    int size;
};


#endif //ADTLIBRARY_LINKEDLIST_H
