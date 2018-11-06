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

int* Graph::loadMap(int lvl) {
    FILE *myFile;
    if (lvl == 1) myFile = fopen("../Resources/2500array1.txt", "r");
    if (lvl == 2) myFile = fopen("../Resources/2500array2.txt", "r");
    if (lvl == 3) myFile = fopen("../Resources/2500array3.txt", "r");
    if (lvl == 4) myFile = fopen("../Resources/2500array4.txt", "r");
    if (lvl == 5) myFile = fopen("../Resources/2500array5.txt", "r");

    //read file into array
    int numberArray[2500];
    int i;

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < 2500; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
    }

    for (i = 0; i < 2500; i++){
        printf("Number is: %d\n\n", numberArray[i]);
    }

    fclose(myFile);

    return numberArray;
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
