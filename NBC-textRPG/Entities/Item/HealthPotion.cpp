#include <algorithm>
#include <iostream>

#include "Character.h"
#include "HealthPotion.h"
#include "ItemTypes.h"

HealthPotion::HealthPotion(const std::string& name, int price, int healing) : Item(name, price), healing(healing)
{
}

ItemEffect HealthPotion::getEffect() const
{
    ItemEffect effect;
    effect.hp = healing;
    return effect;
}

void HealthPotion::use(Character& character) const
{
    std::string itemName = this->getName();
    int value = this->healing;
    character.setHp(std::max(1, std::min(character.getHp() + value, character.getMaxHp())));
    this->printEffect("HP", value);
}
