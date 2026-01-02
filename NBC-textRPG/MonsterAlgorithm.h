#pragma once
#include "Monster.h"
#include <cstdlib>


class MonsterAlgorithm : public Monster
{
public:
    MonsterAlgorithm(int characterLevel);

    void hpDamaged(int damage);
    int getHealthPoint();
    int getAttack();
    bool isDead();
    std::string getName();
};


