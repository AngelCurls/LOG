//
// Created by Joseph Luis González Pastora on 8/10/18.
//

#ifndef ADTLIBRARY_NODEGRAPH_H
#define ADTLIBRARY_NODEGRAPH_H

template <typename T>
class NodeGraph {
public:
    NodeGraph(T data);

    T getData() const;

    void setData(T data);

    int getWeight() const;

    void setWeight(int weight);

private:
    T data;
    int weight;

};


#endif //ADTLIBRARY_NODEGRAPH_H
