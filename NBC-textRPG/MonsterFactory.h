#pragma once
#include "Monster.h"
#include <memory>

class MonsterFactory
{
public:
    // 플레이어 레벨에 따라 적절한 몬스터를 동적으로 생성하여 반환
    static Monster* createMonster(int playerLevel)
    {
        if (playerLevel < 3)
        {
            // 저레벨: 슬라임이나 고블린
            return new Monster("슬라임", 30, 5, 20, 10);
        }
        else if (playerLevel < 7)
        {
            // 중레벨: 오크
            return new Monster("오크", 80, 15, 50, 40);
        }
        else
        {
            // 고레벨: 드래곤
            return new Monster("드래곤", 300, 50, 200, 500);
        }
    }
};
