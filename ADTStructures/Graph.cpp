#include "Graph.h"

Graph::Graph(int height,int width, int level) {

    int key = 0;
    Cell<int>* currentCell = nullptr;
    //srand(time(nullptr));
    auto map = this->loadMap(level);
    //Determina el tamaño del grafo
    this->height = height;
    this->width = width;
    //Determina el tamaño del array de las listas de adyacencia
    this->adjacencyList = new std::set<Cell<int>*>[this->height * this->width];

    this->keyTable = new Cell<int>** [this->height];
    for (int i = 0; i <this->height ; ++i) {

        this->keyTable[i] = new Cell<int>* [this->width];

        for (int j = 0; j < this->width ; j++) {

            currentCell = new Cell<int>(i,j);
            this->keyTable[i][j] = currentCell;
            currentCell->setHashKey(key);
            currentCell->setObjectID(map[key]);

            //Aumenta la llave del siguiente elemento
            key++;


        }

    }
    delete(map);

}

void Graph::generateGrid() {
    for (int i = 0; i <this->height ; ++i) {
        for (int j = 0; j < this->width; ++j) {

            if (i - 1 >= 0)             //upper edge
                addEdge(this->keyTable[i][j], this->keyTable[i - 1][j]);

            if (i + 1 < this->height)   //bottom edge
                addEdge(this->keyTable[i][j], this->keyTable[i + 1][j]);

            if (j - 1 >= 0)             //left edge
                addEdge(this->keyTable[i][j], this->keyTable[i][j - 1]);

            if (j + 1 < this->width)    //right edge
                addEdge(this->keyTable[i][j], this->keyTable[i][j + 1]);
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

void Graph::restoreVisited() {
    for (int i = 0; i < this->height ; i++)
        for (int j = 0; j < this->width; j++)
            this->keyTable[i][j]->setVisited(false);
}

void Graph::addEdge(Cell<int> *CellFrom, Cell<int> *CellTo) {
        int keyFrom = CellFrom->getHashKey();
        this->adjacencyList[keyFrom].insert(CellTo);
}

int* Graph::loadMap(int lvl) {
    FILE *myFile;
    if (lvl == 1) myFile = fopen("../Resources/level1.txt", "r");
    if (lvl == 2) myFile = fopen("../Resources/level2.txt", "r");
    if (lvl == 3) myFile = fopen("../Resources/level3.txt", "r");
    if (lvl == 4) myFile = fopen("../Resources/level4.txt", "r");
    if (lvl == 5) myFile = fopen("../Resources/level5.txt", "r");

    //read file into array
    int* numberArray;
    numberArray = new int[2500];
    int i;

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < 2500; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
    }

    fclose(myFile);

    return numberArray;
}

Graph::~Graph() {


    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->height; j++) {

            delete this->keyTable[i][j];

        }
        delete this->keyTable[i];
        
    }
    delete this->keyTable;

    for (int k = 0; k < this->width* this->height; k++) {
        this->adjacencyList[k].clear();

    }

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
