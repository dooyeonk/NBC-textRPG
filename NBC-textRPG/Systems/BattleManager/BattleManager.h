#pragma once

#include <string>

#include "BattleTypes.h"
#include "Character.h"
#include "Monster.h"

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
