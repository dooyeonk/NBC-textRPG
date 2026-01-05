#include <algorithm>
#include <iostream>

#include "Character.h"
#include "HealthPotion.h"

HealthPotion::HealthPotion(const std::string& name, int price, int healing) : Item(name, price), healing(healing)
{
}

void HealthPotion::use(Character& character) const
{
    int value = this->healing;
    character.setHp(std::max(1, std::min(character.getHp() + value, character.getMaxHp())));
    this->printEffect("HP", value);
}
