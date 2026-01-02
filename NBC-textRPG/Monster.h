#pragma once
#include <iostream>
#include <string>

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
    std::string getName();
    virtual ~Monster()
    {
    }
};
