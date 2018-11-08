//
// Created by jglez2330 on 08/11/18.
//

#include "LineSight.h"

std::list<Cell<int> *> *LineSight::findPath(Graph *graph, int iStart, int jStart, int iTarget, int jTarget) {


    Cell<int>* start = graph->getKeyTable()[iStart][jStart];
    Cell<int>* target = graph->getKeyTable()[iTarget][jTarget];

    std::list<Cell<int>*>* path = new std::list<Cell<int>* >();

    int iCurrent = iStart;
    int jCurrent = jStart;

    path->push_front(start);

    while (iCurrent != iTarget && jCurrent != jTarget){

      if(iCurrent < iTarget ){
          iCurrent++;
      }
      if(iCurrent > iTarget ){
          iCurrent--;
      }
      if(jCurrent < jTarget ){
          jCurrent++;
      }
      if(jCurrent > jTarget ){
          jCurrent--;
      }
      path->push_front(graph->getKeyTable()[iCurrent][jCurrent]);

    }

    path->push_front(target);

    return path;
}
