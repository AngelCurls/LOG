//
// Created by jglez2330 on 25/10/18.
//

#include "LevelBuilder.h"
#include "../Levels/AstarLevel.h"
#include "../Levels/DijkstraLevel.h"


Level* LevelBuilder::getLevel(int levelNumber) {
    if (levelNumber == 0){
        return new AstarLevel();
    }
    if (levelNumber == 1){
        return new DijkstraLevel();
    }
}
