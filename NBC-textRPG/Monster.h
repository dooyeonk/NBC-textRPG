#pragma once

#include <cstdlib> // rand()
#include <iostream>
#include <string>

class Monster
{
protected:
    std::string name;
    int hp;
    int attackPower;

public:
    Monster(int characterLevel)
    {
        // - 체력: (레벨 × 20) ~ (레벨 × 30)
        // - 공격력 : (레벨 × 5) ~(레벨 × 10)
        hp = characterLevel * ((rand() % 11) + 20);
        attackPower = characterLevel * ((rand() % 6) + 5);
    }
    virtual void hpDamaged(int damage) = 0;
    virtual int getHealthPoint() = 0;
    virtual int getAttack() = 0;
    virtual bool isDead() = 0;
    virtual std::string getName() = 0;
    virtual ~Monster() = default;
};
