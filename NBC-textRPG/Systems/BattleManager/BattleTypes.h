#pragma once

#include <string>

enum class BattleResult
{
    VICTORY,
    DEFEAT,
};

struct BattleReport
{
    BattleResult result;
    int experience;
    int gold;
    std::string monsterName;
    std::string droppedItem;
    bool isBoss;
};
