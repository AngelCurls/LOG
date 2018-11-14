#include "Kruskal.h"
#include <queue>
#include <stack>
#include <iostream>

std::list<Cell<int> *>* Kruskal::path = nullptr;
int Kruskal::xTarget = -1;
int Kruskal::yTarget = -1;



std::list<Cell<int> *> *Kruskal::findPath(Graph *graph, int iPlayer, int jPlayer, int iTarget, int jTarget) {
    //si el punto del click cambia, se recalcula el arbol
    //if (path == nullptr || (iTarget != xTarget || jTarget != yTarget)) {
        xTarget = iTarget;
        yTarget = jTarget;
        Graph *MST = findMST(graph, iTarget, jTarget, iPlayer, jPlayer);

        bool targetFound = false,
                progress;
        std::set<Cell<int> *> adjacencyList;
        auto *cellStack = new std::vector<Cell<int> *>(),
                *pathStack = new std::vector<Cell<int> *>();
        cellStack->push_back(MST->getNode(iPlayer, jPlayer));

        Cell<int> *currentCell = nullptr,
                *previousCell = nullptr,
                *target = graph->getNode(iTarget, jTarget);

        // usando dos pilas > cellStack = pila de celdas que se van analizando
        //                  > pathStack = pila de celdas que se han recorrido hasta el momento
        // se van agregando nodos para calcular el path
        // empezando desde el objetivo y utilizando los edges del MST
        while (!targetFound) {
            progress = false;
            currentCell = cellStack->back(), cellStack->pop_back();

            //Si la celda actual es el objetivo, se quedara en el mismo lugar
            if (*currentCell == *target)
                targetFound = progress = true;

            //Si la celda actual esta junto a la objetivo, pero el objetivo es un obstaculo, se quedara en el mismo lugar
            else if (target->getObjectID() > 0 &&
                     (abs(currentCell->getXpos() - iTarget) <= 1 || abs(currentCell->getYpos() - jTarget) <= 1))
                targetFound = progress = true;

                //Si ninguno se cumple, se analizaran las celdas cercanas unidas con los edges del MST
            else {
                adjacencyList = MST->getNodeAdjacencyList(currentCell->getXpos(), currentCell->getYpos());

                //para cada celda unida a la actual...
                for (Cell<int> *adjacentCell : adjacencyList) {

                    //Si la celda adyacente no es la anterior o no ha sido visitada ya, se agrega a la pila
                    if (!adjacentCell->isVisited() &&
                        (previousCell == nullptr || previousCell != adjacentCell)) {
                        cellStack->push_back(adjacentCell);
                        progress = true;
                    }
                    if (adjacentCell == target)
                        break;
                }
            }
            // si se ha avanzado de celda, se inserta la celda actual en pathStack para avanzar a las cercanas a ella
            if (progress) {
                pathStack->push_back(currentCell);
                previousCell = currentCell;
            }
                // si no, se retrocede una celda en el path actual
            else {
                currentCell->setVisited(true);
                previousCell = pathStack->back(), pathStack->pop_back();
            }
        }

        //se traduce la pila del path a una lista para retornarla
        path = new std::list<Cell<int> *>();

        for (unsigned long i = pathStack->size(); i > 0; i--) {
            path->push_back(pathStack->back()), pathStack->pop_back();
        }
    //}
    return path;
}

Graph* Kruskal::findMST(Graph* graph, int iStart, int jStart, int iPlayer, int jPlayer) {
    //se crea un nuevo grafo, que sera el arbol de expansion minima
    Graph* MST = new Graph(graph->getHeight(), graph->getWidth());

    Cell<int> *currentCell, *MSTCell,
              *player = graph->getNode(iPlayer, jPlayer);
    std::set<Cell<int> *> adjacencyList;
    std::queue<Cell<int> *> visited;
    visited.push(graph->getNode(iStart, jStart));
    MST->getNode(iStart, jStart)->setVisited(true);

    //utilizando una cola, se agregara el "camino optimo" a cualquier celda
    //hasta encontrar la celda clickeada.
    bool targetFound = false;
    while (!targetFound) {
        currentCell = visited.front(), visited.pop();

        if (currentCell == player)
            targetFound = true;
        else {
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
                    MST->addEdge(adjacentCell, currentCell);
                }

                //si la celda adyacente es el objetivo, se detiene el ciclo
                if (adjacentCell == player) {
                    targetFound = true;
                    break;
                }
            }
        }
    }
    //se reinicia el visitado de todas las celdas
    MST->restoreVisited();
    return MST;
}


