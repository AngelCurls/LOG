//
// Created by Joseph González Pastora on 10/14/18.
//

#include "AStar.h"

std::list<Cell<int> *> *AStar::findPath(Graph *graph, int iStart, int jStart, int iTarget, int jTarget) {


    std::set<Cell<int>*> closedList = std::set<Cell<int>*>();
    std::set<Cell<int>*> openList = std::set<Cell<int>*>();
    auto path = new std::list<Cell<int>*>();

    Cell<int>* start = graph->getNode(iStart,jStart);
    Cell<int>* target = graph->getNode(iTarget,jTarget);

    start->setG(0);
    calHeuristic(start,iTarget,jTarget);
    openList.insert(start);

    Cell<int>* current;
    int tempScoreG;
    while (!openList.empty()){
        current = minF(openList,target);

        if (current == target ){
            if (target->getObjectID() == 1){
                current = current->getPrevious();
            }
            while (current != nullptr){

                if (current == start){
                    path->push_front(current);
                    break;
                }

                path->push_front(current);
                current = current->getPrevious();
            }
            if (start->getObjectID() == 1){
                path->remove(start);
            }
            return path;
        }

        openList.erase(current);
        closedList.insert(current);

        auto neighbors = graph->getNodeAdjacencyList(current->getXpos(), current->getYpos());

        for (auto neighborCurrentCell : neighbors) {
            if (closedList.count(neighborCurrentCell)){
                continue;
            }
            tempScoreG = current->getG() + 1;

            if (!openList.count(neighborCurrentCell)){

                openList.insert(neighborCurrentCell);
            } else if (tempScoreG >= neighborCurrentCell->getG()){
                continue;
            }
            if (neighborCurrentCell->getObjectID() == 1){
                openList.erase(neighborCurrentCell);
                closedList.insert(neighborCurrentCell);
                continue;
            }

            neighborCurrentCell->setPrevious(current);
            neighborCurrentCell->setG(tempScoreG);

        }

    }
    while (current != nullptr){
        if (current == start){
            path->push_front(current);
            break;
        }

        path->push_front(current);
        current = current->getPrevious();
    }
    return path;
}

Cell<int> *AStar::minF(std::set<Cell<int> *> openList, Cell<int> *Target) {
    Cell<int>* min = *openList.begin();
    int minF = min->getG() + min->getObjectID() + min->getHeuristic();

    int currentMin;
    for (auto currentCell : openList) {
        calHeuristic(currentCell,Target->getXpos(),Target->getYpos());
        currentMin = currentCell->getHeuristic() + currentCell->getObjectID() + currentCell->getG();
        if (currentMin < minF){
            min = currentCell;
            minF = currentMin;
        }


    }
    return min;
}

void AStar::calHeuristic(Cell<int> *current, int iTarget, int jTarget) {
    int iCurrent = current->getXpos();
    int jCurrent = current->getYpos();

    current->setHeuristic(abs(iCurrent-iTarget) + abs(jCurrent - jTarget));

}
