#pragma once
#include "Monster.h"

class MonsterError : public Monster
{
public:
    MonsterError(int characterLevel);
    void hpDamaged(int damage);
    int getHealthPoint();
    int getAttack();
    bool isDead();
    std::string getName();
};
