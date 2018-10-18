//
// Created by Joseph González Pastora on 10/14/18.
//

#include "AStar.h"

LinkedList<NodeGraph<int>*>* AStar::findPath(Graph<int> graph, NodeGraph<int> start, NodeGraph<int> target) {
    calHeuristic(graph,target);

    auto openlist = new LinkedList<NodeGraph<int>*>();
    openlist->operator+(*graph.getAdjacencyList(start));
    LinkedList<NodeGraph<int>*>* closedList = nullptr;

    while (openlist->getSize() != 0){

    }


}

void AStar::calHeuristic(Graph<int> graph, NodeGraph<int> target) {
    auto list = graph.getGraphRepresentationList();
    for (int i = 0; i <list->getSize() ; i++) {
        auto node = list->get(i)->get(0);
        node->setHeuristic(abs(node->getXpos() - target.getXpos()) + abs(node->getYpos() - target.getYpos()));
    }

}
