#include <algorithm>

#include "AttackBoost.h"
#include "Character.h"

AttackBoost::AttackBoost(const std::string& itemName, int itemPrice, int attackUp)
    : Item(itemName, itemPrice), attackUp(attackUp)
{
}

void AttackBoost::use(Character& character) const
{
    std::string itemName = this->getName();
    int value = this->attackUp;
    character.setHp(std::max(1, std::min(character.getHp() + value, character.getMaxHp())));
    this->printEffect("공격력", value);
}
