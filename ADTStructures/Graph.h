//
// Created by jglez2330 on 28/10/18.
//

#ifndef LOG_GRAPH_H
#define LOG_GRAPH_H


#include "Cell.cpp"
#include <vector>
#include <set>

/***
 *
 */
class Graph {
public:
    Graph(int height = 100, int width = 100);

private:
    int height;
    int width;
    int CantObstaculos = 2;
    Cell<int>*** keyTable;
    std::set<Cell<int>*>*adjacencyList;
public:

    /**
     * Genera en un patron de malla en el grafo conectando de la siguiente manera
     *
     *
     *          N
     *          |
     *    O --  C -- E
     *          |
     *          S
     * Donde el centro (C) esta conectado con el nodo de arriba(N), el de abajo(S), el de la derecha(E), el de la izquierda(O)
     *
     */
    void generateGrid();
    /**
     * Funcion que restaura el valor de los puntos G y la heuristica de cada Nodo
     */
    void restoreGraph();

    /**
     * Agrega en la lista de CellFrom, el nodo CellTo
     * @param CellFrom Nodo en que se va a agregar el nodo CellTo
     * @param CellTo Nodo que se quiere agregar en CellFrom
     */
    void addEdge(Cell<int>* CellFrom,Cell<int>* CellTo);

    /**
     * Obtiene la lista de adyacencia del nodo en la posicion I,J
     * @param i Posicion en x en el que se encuentra el nodo
     * @param j Posicon en y en el que se encuentr el nodo
     * @return Lista de adyacencia del Nodo en (i,j)
     */
    std::set<Cell<int> *> getNodeAdjacencyList(int i, int j);
    /**
     * Metodo que obtiene el nodo en la posicion (i,j)
     * @param i posicion x en la que se encuentra el nodo
     * @param j Posicion y en la que se encuentra el nodo
     * @return El nodo en la posicion (i,j)
     */
    Cell<int>* getNode(int i , int j);

    int* loadMap(int lvl);

    /**
     * Destructor de la clase
     */
    virtual ~Graph();


};


#endif //LOG_GRAPH_H
