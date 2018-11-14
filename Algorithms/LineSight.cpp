//
// Created by jglez2330 on 08/11/18.
//

#include "LineSight.h"

std::list<Cell<int> *> *LineSight::findPath(Graph *graph, int iStart, int jStart, int iTarget, int jTarget) {
    int iCurrent = iStart,
        jCurrent = jStart;

    Cell<int>* target = graph->getNode(iTarget, jTarget);

    bool isTargetObstacle = (target->getObjectID() > 0 && target->getObjectID() < 10);

    auto *path = new std::list<Cell<int>* >();
    path->push_back(graph->getNode(iStart, jStart));

    while (!(iCurrent == iTarget && jCurrent == jTarget))
    {
        if (isTargetObstacle && (abs(iCurrent - iTarget) <= 1 || abs(jCurrent - jTarget) <= 1))
            break;
        else if (hasLineOfSight(graph, iCurrent, jCurrent, iTarget, jTarget)) {
            if (iCurrent == iTarget) { //misma columna
                if (jCurrent > jTarget)
                    jCurrent--;
                else
                    jCurrent++;
            }
            else if (jCurrent == jTarget) { //misma fila
                if (iCurrent > iTarget)
                    iCurrent--;
                else
                    iCurrent++;
            }
        }
        else
            break;
        path->push_back(graph->getNode(iCurrent, jCurrent));
    }
    return path;
}

bool LineSight::hasLineOfSight(Graph *graph, int iCurrent, int jCurrent, int iTarget, int jTarget) {
    bool sighted = false;
    
    Cell<int> *currentCell = graph->getNode(iCurrent, jCurrent),
              *target = graph->getNode(iTarget, jTarget);
    while (!(currentCell->getObjectID() > 0 && currentCell->getObjectID() < 10)) {
        
        if (currentCell == target) { //si son la misma, sale
            sighted = true;
            break;
        }
        else if (iCurrent == iTarget) { //misma fila
            if (jCurrent > jTarget)
                jCurrent--;
            else
                jCurrent++;
        }
        else if (jCurrent == jTarget) { //misma columna
            if (iCurrent > iTarget)
                iCurrent--;
            else
                iCurrent++;
        }
        else //si ninguno coincide, sale
            break;         
        
        currentCell = graph->getNode(iCurrent, jCurrent);
    }
    return sighted;
}