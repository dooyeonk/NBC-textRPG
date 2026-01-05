#include <string>

#include "Monster.h"

Monster::Monster(int characterLevel, const std::string& name) : name(name), hp(0), attackPower(0), maxHp(0)
{
    // - 체력: (레벨 × 20) ~ (레벨 × 30)
    maxHp = characterLevel * ((rand() % 11) + 20);
    // - 공격력 : (레벨 × 5) ~(레벨 × 10)
    attackPower = characterLevel * ((rand() % 6) + 5);
    hp = maxHp;
}

std::string Monster::getName() const
{
    return name;
}

int Monster::getHp() const
{
    return hp;
}

int Monster::getAttackPower() const
{
    return attackPower;
}

void Monster::hpDamaged(int damage)
{
    if (damage > hp)
    {
        hp = 0;
        return;
    }
    hp -= damage;
}

bool Monster::isDead() const
{
    return hp <= 0;
}

bool Monster::isBoss() const
{
    return false;
}
