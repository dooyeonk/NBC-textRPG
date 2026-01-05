#pragma once

#include <cstdlib> // rand()
#include <string>

class Monster
{
protected:
    const std::string name;
    int hp;
    int attackPower;
    int maxHp; // 최대 체력 비율 계산용

public:
    Monster(int characterLevel, const std::string& name);
    virtual ~Monster() = default;

    std::string getName() const;
    int getHp() const;
    int getAttackPower() const;

    void hpDamaged(int damage);
    bool isDead() const;
    virtual bool isBoss() const;
};
