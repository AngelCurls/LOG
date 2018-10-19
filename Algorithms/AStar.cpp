//
// Created by Joseph González Pastora on 10/14/18.
//

#include "AStar.h"

LinkedList<NodeGraph<int>*>* AStar::findPath(Graph<int> graph, NodeGraph<int>* start, NodeGraph<int>* target) {

    auto openlist = new LinkedList<NodeGraph<int>*>();
    LinkedList<NodeGraph<int>*>* path = new LinkedList<NodeGraph<int>*>();
    openlist->add(start);
    start->setG(0);
    //openlist->operator+(*graph.getAdjacencyList(*start));
    LinkedList<NodeGraph<int>*>* closedList = new LinkedList<NodeGraph<int>*>();

    while (openlist->getSize() != 0){
        NodeGraph<int>* current = minF(openlist, target);
        if (current == target){
            while (current != nullptr){
                path->add(current);
                current = current->getPrevious();
            }
            break;
        }
        openlist->remove(current);
        closedList->add(current);

        LinkedList<NodeGraph<int>*>* neighbors = graph.getAdjacencyList(current);
        for (int i = 0; i <neighbors->getSize() ; i++) {
            NodeGraph<int>* neighbor = neighbors->get(i);
            if (closedList->isDataIn(neighbor)){
                continue;
            }
            int tempG_score = current->getG() + 1;

            if (!openlist->isDataIn(neighbor)){
                openlist->add(neighbor);
            } else if (tempG_score >= neighbor->getG()){
                continue;
            }
            neighbor->setPrevious(current);
            neighbor->setG(tempG_score);


        }

    }
    free(openlist);
    free(closedList);
    return path;


}

void AStar::calHeuristic(NodeGraph<int> current, NodeGraph<int> target) {
        current.setHeuristic(abs(current.getXpos() - target.getXpos()) + abs(current.getYpos() - target.getYpos()));

}

NodeGraph<int>* AStar::minF(LinkedList<NodeGraph<int> *> *openList, NodeGraph<int>* target) {
    NodeGraph<int>* min = openList->get(0);
    for (int i = 0; i < openList->getSize() ; i++) {
        NodeGraph<int>* current = openList->get(i);
        calHeuristic(*current,*target);
        if (current->getHeuristic() + current->getG() < min->getG() + min->getHeuristic()){
            min = current;
        }

    }
    return min;
}
