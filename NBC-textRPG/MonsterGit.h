#pragma once
#include "Monster.h"

class MonsterGit : public Monster
{
public:
    MonsterGit(int characterLevel);
    void hpDamaged(int damage);
    int getHealthPoint();
    int getAttack();
    bool isDead();
    std::string getName();
};
