//
// Created by jglez2330 on 25/10/18.
//

#include "LevelBuilder.h"
#include "../Levels/AstarLevel.h"


Level* LevelBuilder::getLevel(int levelNumber) {
    if (levelNumber == 0){
        return new AstarLevel();
    }
}
