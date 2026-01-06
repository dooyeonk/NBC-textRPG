#pragma once

// general monster
#include "MonsterAlgorithm.h"
#include "MonsterCompile.h"
#include "MonsterGit.h"
#include "MonsterMemory.h"
#include "MonsterSyntax.h"

// boss monster
#include "Boss/MonsterRuntime.h"

class MonsterFactory
{
public:
    // 플레이어 레벨에 따라 적절한 몬스터를 동적으로 생성하여 반환
    static Monster* createMonster(int characterLevel)
    {
        if (characterLevel < 3)
        {
            // level 1 ~ 2
            return new MonsterSyntax(characterLevel);
        }
        else if (characterLevel < 5)
        {
            // level 3 ~ 4
            return new MonsterCompile(characterLevel);
        }
        else if (characterLevel < 7)
        {
            // level 5 ~ 6
            return new MonsterMemory(characterLevel);
        }
        else if (characterLevel < 9)
        {
            // level 7 ~ 8
            return new MonsterGit(characterLevel);
        }
        else if (characterLevel < 10)
        {
            // level 9
            return new MonsterAlgorithm(characterLevel);
        }
        else
        {
            // level 10 (boss)
            return new MonsterRuntime(characterLevel);
        }
    }
};
