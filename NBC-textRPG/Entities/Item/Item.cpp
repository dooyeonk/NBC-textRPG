#include <string>

#include "Item.h"

Item::Item()
{
}

Item::Item(const std::string& itemName, int itemPrice) : name(itemName), price(itemPrice)
{
}

std::string Item::getName()
{
    return name;
}

int Item::getPrice()
{
    return price;
}

void Item::setName(const std::string& itemName)
{
    name = itemName;
}

void Item::setPrice(int itemPrice = 0)
{
    price = itemPrice;
}
HealthPotion::HealthPotion() : heal(50)
{
}

HealthPotion::HealthPotion(const std::string& itemName, int itemPrice, int healing)
    : Item(itemName, itemPrice), heal(healing)
{
}

HealthPotion::~HealthPotion()
{
}

ItemEffect HealthPotion::getEffect()
{
    ItemEffect effect;
    effect.hp = heal;
    return effect;
}

AttackBoost::AttackBoost() : attackUp(10)
{
}

AttackBoost::AttackBoost(const std::string& itemName, int itemPrice, int atkUp)
    : Item(itemName, itemPrice), attackUp(atkUp)
{
}

AttackBoost::~AttackBoost()
{
}

ItemEffect AttackBoost::getEffect()
{
    ItemEffect effect;
    effect.attackPower = attackUp;
    return effect;
}
