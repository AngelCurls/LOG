//
// Created by jglez2330 on 07/11/18.
//

#include "Dijkstra.h"

int Dijkstra::INF = 1000000;

std::list<Cell<int> *>* Dijkstra::findPath(Graph *graph, int iStart, int jStart, int iTarget, int jTarget) {

    //Cola de prioridad que coloque el nodo con la menor distancia en eñ inicio de la cola
    std::priority_queue<Cell<int>*, std::vector<Cell<int>*>,CompareNode> Nodos;



    //lista con los nodos que hacen el camino
    std::list<Cell<int>*>* path = new std::list<Cell<int>*>();;

    //Se colocan todas las distancias en infinito, por que aun no se visitan
    setDistanceInfinite(graph);

    //Celda de inicio
    Cell<int>* start = graph->getKeyTable()[iStart][jStart];

    //Celda final
    Cell<int>* target = graph->getKeyTable()[iTarget][jTarget];

    //Se coloca la distancia del inicio en cero, por que el costo de moverme al inicio es cero ya que estoy ahi
    start->setDijkstraDistance(0);

    //Se coloca el inicio en la cola
    Nodos.push(start);
    while (!Nodos.empty()){
        Cell<int>* minCell = Nodos.top();
        Nodos.pop();

        if (minCell == target){
            Cell<int>* current = minCell;

            while (current != nullptr){
                if (current == start){
                    path->push_front(start);
                    break;
                }
                path->push_front(current);
                current = current->getPrevious();
            }

            break;
        }

        //Se adquiere una lista de los vecinos del nodo
        auto neightbors = graph->getNodeAdjacencyList(minCell->getXpos(),minCell->getYpos());

        for ( Cell<int>* neightbor : neightbors) {
            //Distancia tentativa del nodo
            int tempDistance = minCell->getDijkstraDistance() + 1;

            //Si el la distancia que posee el nodo es mayor a la tentativa se le asigna y se coloca el nodo en la cola
            if (neightbor->getDijkstraDistance() > tempDistance && (neightbor->getObjectID() == 0 || neightbor->getObjectID() == 10) ){

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
