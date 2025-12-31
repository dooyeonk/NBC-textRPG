#pragma once

#include <string>

class Monster
{
public:
    bool isDead()
    {
        return hp <= 0;
    }

    std::string getName()
    {
        return name;
    }

    int getAttackPower()
    {
        return attackPower;
    }
    void setHp(int amount)
    {
        hp = amount;
    }
    int getHp()
    {
        return hp;
    }

private:
    std::string name;
    int hp;
    int attackPower;
};
