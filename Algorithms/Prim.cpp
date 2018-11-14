#include "Prim.h"
#include <queue>
#include <iostream>

std::list<Cell<int> *>* Prim::path = nullptr;
int Prim::xTarget = -1;
int Prim::yTarget = -1;



std::list<Cell<int> *> *Prim::findPath(Graph *graph, int iTarget, int jTarget, int iPlayer, int jPlayer) {
    //si el punto del click cambia, se recalcula el arbol
    if (path == nullptr || (iTarget != xTarget || jTarget != yTarget))
    {
        xTarget = iTarget;
        yTarget = jTarget;
        Graph *MST = findMST(graph, iPlayer, jPlayer, iTarget, jTarget);

        bool targetFound = false,
             progress;
        std::set<Cell<int> *> adjacencyList;
        auto *pathStack = new std::vector<Cell<int> *>();
        pathStack->push_back(MST->getNode(iPlayer, jPlayer));

        Cell<int> *currentCell = nullptr,
                  *target = graph->getNode(iTarget, jTarget);

        // usando pathStack = pila de celdas que se han recorrido hasta el momento
        // se van agregando nodos para calcular el path
        // empezando desde la posicion del jugador y utilizando los edges del MST
        while (!targetFound) {
            currentCell = pathStack->back();
            currentCell->setVisited(true);

            //Si la celda actual es el objetivo, se quedara en el mismo lugar
            if (currentCell == target)
                targetFound = true;

            //Si la celda actual esta junto al objetivo, pero el objetivo es un obstaculo, se quedara en el mismo lugar
            else if (target->getObjectID() > 0 && target->getObjectID() < 10 &&
                     (abs(currentCell->getXpos() - iTarget) <= 1 && abs(currentCell->getYpos() - jTarget) <= 1))
                targetFound = true;

                //Si ninguno se cumple, se analizaran las celdas cercanas unidas con los edges del MST
            else {
                progress = false;
                adjacencyList = MST->getNodeAdjacencyList(currentCell->getXpos(), currentCell->getYpos());

                //para cada celda unida a la actual...
                for (Cell<int> *adjacentCell : adjacencyList) {
                    //Si la celda adyacente no es la anterior o no ha sido visitada ya, se agrega a la pila
                    if (!adjacentCell->isVisited()) {
                        pathStack->push_back(adjacentCell);
                        progress = true;
                        break;
                    }
                }
                if (!progress)
                    pathStack->pop_back();
            }
        }

        //se traduce la pila del path a una lista para retornarla
        path = new std::list<Cell<int> *>();

        for (unsigned long i = pathStack->size(); i > 0; i--) {
            path->push_back(pathStack->back()), pathStack->pop_back();
        }
    }
    return path;
}

Graph* Prim::findMST(Graph* graph, int iStart, int jStart, int iTarget, int jTarget) {
    //se crea un nuevo grafo, que sera el arbol de expansion minima
    auto MST = new Graph(graph->getHeight(), graph->getWidth());

    Cell<int> *currentCell, *MSTCell, *target = graph->getNode(iTarget, jTarget);
    std::set<Cell<int> *> adjacencyList;
    std::queue<Cell<int> *> visited;
    visited.push(graph->getNode(iStart, jStart));
    MST->getNode(iStart, jStart)->setVisited(true);

    //utilizando una cola, se agregara el "camino optimo" a cualquier celda
    //hasta encontrar la celda clickeada.
    bool targetFound = false;
    while (!targetFound) {
        currentCell = visited.front(), visited.pop();
        adjacencyList = graph->getNodeAdjacencyList(currentCell->getXpos(), currentCell->getYpos());

        //para toda celda adyacente...
        for (Cell<int> *adjacentCell : adjacencyList) {
            MSTCell = MST->getNode(adjacentCell->getXpos(), adjacentCell->getYpos());

            //si la celda adyacente no esta visitada ya y no es un obstaculo
            //se creara un Edge hacia el
            if (!MSTCell->isVisited() && (adjacentCell->getObjectID() == 0 ||
                                          adjacentCell->getObjectID() == 10))
            {
                visited.push(adjacentCell);
                MSTCell->setVisited(true);
                MST->addEdge(currentCell, adjacentCell);
            }

            //si la celda adyacente es el objetivo, se detiene el ciclo
            if (adjacentCell == target) {
                targetFound = true;
                break;
            }
        }
    }
    //se reinicia el visitado de todas las celdas
    MST->restoreVisited();
    graph->restoreVisited();
    return MST;
}


