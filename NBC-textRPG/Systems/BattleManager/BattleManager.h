#pragma once

#include <string>

#include "BattleTypes.h"
#include "Character.h"
#include "Monster.h"

class BattleManager
{
public:
    BattleReport battle(Character& character);
    void changeMode();

private:
    void executePlayerTurn(Character& character, Monster& monster);
    void executeMonsterTurn(Character& character, Monster& monster);
    void processVictory(Character& character, BattleReport& report);
    bool itemUsed(Character& character);

    bool isEasyMode = false;
};
