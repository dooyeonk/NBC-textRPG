#include <algorithm>

#include "AttackBoost.h"
#include "Entities/Character/Character.h"

AttackBoost::AttackBoost(const std::string& itemName, int itemPrice, int attackUp)
    : Item(itemName, itemPrice), attackUp(attackUp)
{
}

void AttackBoost::use(Character& character) const
{
    int value = this->attackUp;
    character.addTempAttackPower(value);
    this->printEffect("공격력", value);
}
