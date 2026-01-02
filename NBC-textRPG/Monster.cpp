#include "Monster.h"
void Monster::hpDamaged(int damage)
{
    if (damage > healthPoint)
    {
        healthPoint = 0;
        return;
    }
    healthPoint -= damage;
}
int Monster::getHealthPoint()
{
    return healthPoint;
}
int Monster::getAttack()
{
    return attack;
}
bool Monster::isDead()
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
