//
// Created by jglez2330 on 25/10/18.
//

#include "LevelBuilder.h"
#include "../Levels/AstarLevel.h"
#include "../Levels/PrimLevel.h"
#include "../Levels/KruskalLevel.h"
#include "../Levels/DijkstraLevel.h"


Level* LevelBuilder::getLevel(int levelNumber) {
    if (levelNumber == 0)
        return new AstarLevel();

    else if (levelNumber == 1)
        return new DijkstraLevel();

    else if (levelNumber == 2)
        return new PrimLevel();

    else if (levelNumber == 3)
        return new KruskalLevel();
}
