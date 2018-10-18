//
// Created by Joseph González Pastora on 10/14/18.
//

#ifndef LOG_ASTAR_H
#define LOG_ASTAR_H


#include "../ADTStructures/Graph.h"
class AStar{
private:

public:
    LinkedList<NodeGraph<int>*>* findPath(Graph<int> graph,NodeGraph<int> start, NodeGraph<int> target);

    void calHeuristic(Graph<int> graph, NodeGraph<int> nodeGraph);
};


#endif //LOG_ASTAR_H
