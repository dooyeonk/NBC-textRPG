#include "MonsterMemory.h"
#include <string>
#include <cstdlib>

MonsterMemory::MonsterMemory(int characterLevel) : Monster(characterLevel)
{
    name = "메모리누수";
}

void MonsterMemory::hpDamaged(int damage)
{
    hp -= damage;
    if (hp < 0)
        hp = 0;
}

int MonsterMemory::getHealthPoint()
{
    return hp;
}

int MonsterMemory::getAttack()
{
    return attackPower;
}

bool MonsterMemory::isDead()
{
    return hp <= 0;
}

std::string MonsterMemory::getName()
{
    return name;
}
