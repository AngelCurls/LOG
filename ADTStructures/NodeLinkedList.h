//
// Created by Joseph Luis González Pastora on 7/10/18.
//

#ifndef ADTLIBRARY_NODELINKEDLIST_H
#define ADTLIBRARY_NODELINKEDLIST_H

template<typename T>
class NodeLinkedList {
public:
    NodeLinkedList(T data);

    T getData() const;

    void setData(T data);

    NodeLinkedList<T> *getNext() const;

    void setNext(NodeLinkedList<T> *next);

    int getWeight() const;

    void setWeight(int weight);


private:
    T data;
    int weight;
    NodeLinkedList<T>* next;

};


#endif //ADTLIBRARY_NODELINKEDLIST_H
