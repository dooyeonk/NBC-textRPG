#include "MonsterGit.h"
#include <string>

MonsterGit::MonsterGit(int characterLevel) : Monster(characterLevel)
{
    hp = characterLevel * ((rand() % 11) + 20);
    attackPower = characterLevel * ((rand() % 6) + 5);
}

void MonsterGit::hpDamaged(int damage)
{
    if (damage > hp)
    {
        hp = 0;
        return;
    }
    hp -= damage;
}

int MonsterGit::getHealthPoint()
{
    return hp;
}

int MonsterGit::getAttack()
{
    return attackPower;
}

bool MonsterGit::isDead()
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

std::string MonsterGit::getName()
{
    return "Git";
}
