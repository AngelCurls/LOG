//
// Created by Joseph González Pastora on 10/14/18.
//

#ifndef LOG_ASTAR_H
#define LOG_ASTAR_H


#include "../ADTStructures/Graph.cpp"
class AStar{
private:

public:
    static LinkedList<NodeGraph<int>*>* findPath(Graph<int> graph,NodeGraph<int>* start, NodeGraph<int>* target);

    static void calHeuristic(NodeGraph<int> current, NodeGraph<int> target);

    static NodeGraph<int>* minF(LinkedList<NodeGraph<int> *> *pList,NodeGraph<int>* target);
};


#endif //LOG_ASTAR_H
