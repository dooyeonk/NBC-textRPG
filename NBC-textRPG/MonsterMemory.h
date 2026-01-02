#pragma once
#include "Monster.h"
#include <cstdlib>
#include <string>


class MonsterMemory : public Monster
{
public:
    MonsterMemory(int characterLevel);

    void hpDamaged(int damage);
    int getHealthPoint();
    int getAttack();
    bool isDead();
    std::string getName();






};
