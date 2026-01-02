#include "MonsterSyntax.h"
#include <cstdlib>
#include <string>

MonsterSyntax::MonsterSyntax(int characterLevel) : Monster(characterLevel)
{
    name = "문법오류";
}

void MonsterSyntax::hpDamaged(int damage)
    {
    hp -= damage;
        if (hp < 0)
            hp = 0;
    }

int MonsterSyntax::getHealthPoint()
{

    return hp;
}

int MonsterSyntax::getAttack()
{
    // TODO: 수정하세요
    return attackPower;
}

bool MonsterSyntax::isDead()
{
    
    return hp <= 0;
}

std::string MonsterSyntax::getName()
{
    
    return name;
}
