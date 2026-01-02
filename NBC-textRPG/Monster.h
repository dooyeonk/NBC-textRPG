#pragma once
#include <string>
#include <iostream>

class Monster
{
private:
    std::string name;
    int healthPoint;
    int attack;

public:
    Monster()
    {
    }
    void hpDamaged(int damage);
    int getHealthPoint();
    int getAttack();
    bool isDead();
    virtual ~Monster()
    {
    }
};
