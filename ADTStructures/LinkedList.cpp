//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#include <stdexcept>
#include <iostream>
#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
}

template<typename T>
T LinkedList<T>::get(int index) {
    return this->operator[](index);
}

template<typename T>
T LinkedList<T>::operator[](int index) {
    NodeLinkedList<T>* node = this->head;
    int internalIndex = 0;
    if (index >= size || index < 0){
        throw std::invalid_argument("Index out of Boundary");
    } else{
        while (node->getNext() != nullptr){
            if (internalIndex == index){
                break;
            }
            node = node->getNext();
            internalIndex++;

        }
    }
    T data = node->getData();
    //free(node);
    return data;
}

template<typename T>
void LinkedList<T>::add(T data) {
    if (this->head == nullptr){
        this->head = new NodeLinkedList<T>(data);
        size++;
    } else{
        NodeLinkedList<T>* node = this->head;
        size++;
        while (node != nullptr){
            if (node->getNext() == nullptr){
                node->setNext(new NodeLinkedList<T>(data));
                //free(node);
                break;
            }
            node = node->getNext();

        }
    }

}






template<typename T>
void LinkedList<T>::remove(int index) {

    if (index >= this->size || index < 0){
        throw std::invalid_argument("Index out of Boundary");
    } else{
        int internalIndex = 0;
        NodeLinkedList<T>* node = this->head;
        while (node != nullptr){
            if (index == 0){
                this->head = this->head->getNext();
                size--;
                //free(node);
                break;
            } else if (internalIndex + 1 == index){
                NodeLinkedList<T>* temp = node;
                if (node->getNext() == nullptr){
                    temp->setNext(nullptr);
                }else{
                    temp->setNext(node->getNext()->getNext());
                }

                size--;
                break;
            }

            node = node->getNext();
        }

    }

}

template<typename T>
void LinkedList<T>::printList() {
    NodeLinkedList<T> *node = this->head;
    while (node != nullptr){
        std::cout<< node->getData() << " ~> ";
        node = node->getNext();
    }

}

template<typename T>
NodeLinkedList<T> *LinkedList<T>::getHead() const {
    return head;
}

template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
int LinkedList<T>::getWeight(int index) {
    return getNode(index)->getWeight();

}

template<typename T>
void LinkedList<T>::setWeight(int index, int weight) {
    NodeLinkedList<T> *node = getNode(index);
    node->setWeight(weight);

}

template<typename T>
NodeLinkedList<T>* LinkedList<T>::getNode(int index) {
    NodeLinkedList<T>* node = this->head;
    int internalIndex = 0;
    if (index >= size || index < 0){
        throw std::invalid_argument("Index out of Boundary");
    } else{
        while (node->getNext() != nullptr){
            if (internalIndex == index){
                break;
            }
            node = node->getNext();
            internalIndex++;

        }
    }
    return node;
}

template<typename T>
bool LinkedList<T>::isDataIn(T data) {
    bool isIn = false;
    for (int i = 0; i < size ; i++) {
        if (get(i) == data){
            isIn = true;
            break;
        }

    }
    return isIn;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T> list) {
    for (int i = 0; i < list.getSize(); i++) {
        if(!isDataIn(list.get(i))){
            this->add(list.get(i));
        }

    }

}

template<typename T>
void LinkedList<T>::remove(T data) {
    for (int i = 0; i <size ; i++) {
        if (get(i) == data){
            remove(i);
            break;
        }
    }

}
