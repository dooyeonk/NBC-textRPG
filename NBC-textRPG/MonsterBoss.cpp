#include "MonsterBoss.h"
#include <cstdlib>
#include <string>

void MonsterBoss::hpDamaged(int damage)
{
    hp -= damage;
    if (hp < 0)
        hp = 0;
}

int MonsterBoss::getHealthPoint()
{

    if (hp > maxTotalHp * 0.1)
    {
        std::cout << name << "체력 : ???" << std::endl;
    }
    else
    {
        std::cout << name << "체력 : " << hp << std::endl;
    }
    return hp;
}




int MonsterBoss::getAttack()
{
    return attackPower;
}


bool MonsterBoss::isDead()
{
    return hp <= 0;
}


std::string MonsterBoss::getName()
{
    return name;
}
