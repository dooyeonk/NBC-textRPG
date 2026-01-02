#include "MonsterAlgorithm.h"
#include <cstdlib>
#include <string>

MonsterAlgorithm::MonsterAlgorithm(int characterLevel) : Monster(characterLevel)
{
    name = "알고리즘";
}

void MonsterAlgorithm::hpDamaged(int damage)
{
    hp -= damage;
    if (hp < 0)
        hp = 0;
}


int MonsterAlgorithm::getHealthPoint()
{
    return hp;
}


int MonsterAlgorithm::getAttack()
{
    return attackPower;
}

bool MonsterAlgorithm::isDead()
{
    return hp <= 0;
}

std::string MonsterAlgorithm::getName()
{
    return name;
}
