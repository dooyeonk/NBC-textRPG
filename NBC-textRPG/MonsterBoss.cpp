#include "MonsterBoss.h"
#include <cstdlib>
#include <string>

MonsterBoss::MonsterBoss(int characterLevel, const std::string& name) : Monster(characterLevel, name)
{
    // - 체력: (레벨 × 20) ~ (레벨 × 30) x 1.5
    maxHp = int(characterLevel * ((rand() % 11) + 20) * 1.5);
    // - 공격력 : (레벨 × 5) ~(레벨 × 10) x 1.5
    attackPower = int(characterLevel * ((rand() % 6) + 5) * 1.5);
    hp = maxHp;
}
