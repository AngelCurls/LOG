//
// Created by jglez2330 on 25/10/18.
//

#include "LevelBuilder.h"
#include "../Levels/LineSightLevel.h"
#include "../Levels/AstarLevel.h"
#include "../Levels/PrimLevel.h"
#include "../Levels/KruskalLevel.h"
#include "../Levels/DijkstraLevel.h"


Level* LevelBuilder::getLevel(int levelNumber) {
    Level* lvl = nullptr;
    switch(levelNumber)
    {
        case 0:
            lvl = new LineSightLevel();
            break;

        case 1:
            lvl = new PrimLevel();
            break;

        case 2:
            lvl = new KruskalLevel();
            break;

        case 3:
            lvl = new DijkstraLevel();
            break;

        default:
            lvl = new AstarLevel();
            break;
    }
    return lvl;
}
