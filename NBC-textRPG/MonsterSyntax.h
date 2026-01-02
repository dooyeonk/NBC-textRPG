#include "Monster.h"

class MonsterSyntax : public Monster
{
public:
    MonsterSyntax(int characterLevel);

    void hpDamaged(int damage);
    int getHealthPoint();
    int getAttack();
    bool isDead();
    std::string getName();
};
