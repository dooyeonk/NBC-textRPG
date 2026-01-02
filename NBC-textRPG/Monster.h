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
    void hpDamaged(int damage)
    {
        if (damage > healthPoint)
        {
            healthPoint = 0;
            return;
        }
        healthPoint -= damage;
    }
    int getHealthPoint()
    {
        return healthPoint;
    }
    int getAttack()
    {
        return attack;
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

    virtual ~Monster()
    {
    }
};
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
    void hpDamaged(int damage)
    {
        if (damage > healthPoint)
        {
            healthPoint = 0;
            return;
        }
        healthPoint -= damage;
    }
    int getHealthPoint()
    {
        return healthPoint;
    }
    int getAttack()
    {
        return attack;
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

    virtual ~Monster()
    {
    }
};
