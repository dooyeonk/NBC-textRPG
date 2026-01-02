#include "MonsterError.h"
#include <string>

MonsterError::MonsterError(int characterLevel) : Monster(characterLevel)
{
    hp = characterLevel * ((rand() % 11) + 20);
    attackPower = characterLevel * ((rand() % 6) + 5);
}

void MonsterError::hpDamaged(int damage)
{
    if (damage > hp)
    {
        hp = 0;
        return;
    }
    hp -= damage;
}

int MonsterError::getHealthPoint()
{
    return hp;
}

int MonsterError::getAttack()
{
    return attackPower;
}

bool MonsterError::isDead()
{
    if (hp == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string MonsterError::getName()
{
    return "Error";
}
