//
// Created by jglez2330 on 07/11/18.
//

#include "Dijkstra.h"

int Dijkstra::INF = 1000000;

std::list<Cell<int> *>* Dijkstra::findPath(Graph *graph, int iStart, int jStart, int iTarget, int jTarget) {

    std::priority_queue<Cell<int>*, std::vector<Cell<int>*>,CompareNode> Nodos;
    std::set<Cell<int>*> nodosVisitados;
    std::list<Cell<int>*>* path = new std::list<Cell<int>*>();;

    //Se colocan todas las distancias en infinito, por que aun no se visitan
    setDistanceInfinite(graph);
    //Se coloca la distancia del inicio en cero, por que ya estoy en ella
    Cell<int>* start = graph->getKeyTable()[iStart][jStart];

    Cell<int>* target = graph->getKeyTable()[iTarget][jTarget];
    start->setDijkstraDistance(0);

    Nodos.push(start);
    while (!Nodos.empty()){
        Cell<int>* minCell = Nodos.top();
        Nodos.pop();
        nodosVisitados.insert(minCell);

        if (minCell == target){
            Cell<int>* current = minCell;

            while (current->getPrevious() != nullptr){
                if (current == start){
                    path->push_front(start);
                    break;
                }
                path->push_front(current);
                current = current->getPrevious();
            }

            break;
        }
        auto neightbors = graph->getNodeAdjacencyList(minCell->getXpos(),minCell->getYpos());

        for ( Cell<int>* neightbor : neightbors) {
            int tempDistance = minCell->getDijkstraDistance() + 1;

            if (neightbor->getDijkstraDistance() > tempDistance && neightbor->getObjectID() == 0){
                neightbor->setDijkstraDistance(tempDistance);
                neightbor->setPrevious(minCell);
                Nodos.push(neightbor);


            }




        }

    }


    return path;



}

void Dijkstra::setDistanceInfinite(Graph *graph) {
    for (int i = 0; i <graph->getHeight(); i++) {
        for (int j = 0; j <graph->getWidth() ; j++) {
            graph->getKeyTable()[i][j]->setDijkstraDistance(INF);
            graph->getKeyTable()[i][j]->setPrevious(nullptr);


        }

    }

}
