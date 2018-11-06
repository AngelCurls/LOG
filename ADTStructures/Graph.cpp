#include "Graph.h"

Graph::Graph(int height,int width) {

    int key = 0;
    Cell<int>* currentCell = nullptr;
    srand(time(nullptr));
    //Determina el tamaño del grafo
    this->height = height;
    this->width = width;
    //Determina el tamaño del array de las listas de adyacencia
    this->adjacencyList = new std::set<Cell<int>*>[this->height * this->width];

    this->keyTable = new Cell<int>** [this->height];
    for (int i = 0; i <this->height ; ++i) {

        this->keyTable[i] = new Cell<int>* [this->width];

        for (int j = 0; j < this->width ; j++) {

            currentCell = new Cell<int>(i,j, rand() % this->CantTypeObstaculos);
            this->keyTable[i][j] = currentCell;
            currentCell->setHashKey(key);

            //Aumenta la llave del siguiente elemento
            key++;


        }

    }

}

void Graph::generateGrid() {
    for (int i = 0; i <this->height ; ++i) {
        for (int j = 0; j < this->width; ++j) {

            if (i - 1 > 0){

                addEdge(this->keyTable[i][j], this->keyTable[i - 1][j]);
                addEdge(this->keyTable[i - 1][j], this->keyTable[i][j]);

            }
            if (i + 1 < this->height){

                addEdge(this->keyTable[i][j], this->keyTable[i + 1][j]);
                addEdge(this->keyTable[i + 1][j], this->keyTable[i][j]);

            }
            if (j - 1 > 0){

                addEdge(this->keyTable[i][j], this->keyTable[i][j - 1]);
                addEdge(this->keyTable[i][j - 1], this->keyTable[i][j]);

            }
            if (j + 1 < this->width){

                addEdge(this->keyTable[i][j], this->keyTable[i][j + 1]);
                addEdge(this->keyTable[i][j + 1], this->keyTable[i][j]);

            }

        }
    }
}

void Graph::restoreGraph() {
    Cell<int>* currentCell;

    for (int i = 0; i < this->height ; i++) {
        for (int j = 0; j < this->width; j++) {
            currentCell = this->keyTable[i][j];

            currentCell->setG(10000);
            currentCell->setHeuristic(0);

        }
    }

}

void Graph::addEdge(Cell<int> *CellFrom, Cell<int> *CellTo) {
        int keyFrom = CellFrom->getHashKey();
        this->adjacencyList[keyFrom].insert(CellTo);



}

Graph::~Graph() {

    //TODO: Desarrollar el destructor

}

std::set<Cell<int> *> Graph::getNodeAdjacencyList(int i, int j) {
    int key = this->keyTable[i][j]->getHashKey();
    return this->adjacencyList[key];
}

Cell<int> *Graph::getNode(int i, int j) {
    return this->keyTable[i][j];
}

int Graph::getHeight() const {
    return height;
}

int Graph::getWidth() const {
    return width;
}

Cell<int> ***Graph::getKeyTable() const {
    return keyTable;
}
