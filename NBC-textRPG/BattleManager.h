#pragma once

#include <string>

#include "Character.h"
#include "Monster.h"

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
};

class BattleManager
{
public:
    BattleReport battle(Character& character);

private:
    void executePlayerTurn(Character& character, Monster& monster, int& attackBonus);
    void executeMonsterTurn(Character& character, Monster& monster);
    void processVictory(Character& character, BattleReport& report);
    bool itemUsed(Character& character, int& attackBonus);
};
