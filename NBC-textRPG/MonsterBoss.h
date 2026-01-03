#pragma once
#include "Monster.h"
#include <cstdlib>
#include <string>




class MonsterBoss : public Monster
{
private:
    int maxTotalHp;// 최대체력에서 10%계산용

public:
    
    MonsterBoss(int characterLevel) : Monster(characterLevel)
    {
        name = "언리얼 C++";

        maxHp = static_cast<int>(maxHp * 1.5);
        hp = maxHp;//부모 클래스에서 만든 체력에 1.5배(보스 전용체력)

        attackPower = static_cast<int>(attackPower * 1.5); // 1.5배 공격력

        maxTotalHp = maxHp;
    }

    void hpDamaged(int damage);
    int getHealthPoint();
    int getAttack();
    bool isDead();
    std::string getName();
};
