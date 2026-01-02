#pragma once
#include "Monster.h"
#include <cstdlib>
#include <string>




class MonsterBoss : public Monster
{
private:
    int specialHp;

public:
    
    MonsterBoss(int characterLevel);

    void hpDamaged(int damage);
    int getHealthPonint();
    int getAttack();
    bool isDead();
    std::string getName();
};
