#pragma once
#include <string>
#include <iostream>

class Monster
{
private:
    std::string monName;
    int healthPoint;
    int attack;
    
public:
    Monster()
    {

        std::cout << monName << "가 나타났다!" << std::endl;
    }
    void hpDamaged(int damage)
    {
        if (damage > healthPoint)
        {
            healthPoint = 0;
        }
        else
        {
            healthPoint -= damage;
        }
    }
    int getMonHealthPoint()
    {
        return healthPoint;
    }
    bool isDead()
    {
        if (healthPoint == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ~Monster()
    {
        std::cout << monName << "가 쓰러졌다." << std::endl;
    }
};
