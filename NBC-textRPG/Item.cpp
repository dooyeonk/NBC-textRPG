#include "Item.h"
#include <string>

Item::Item() : price(0)
{
}

Item::Item(const std::string& itemName, int itemPrice) : name(itemName), price(itemPrice)
{
}


std::string Item::getItemName()
{
    return name;
}

int Item::getItemPrice()
{
    return price;
}

void Item::setItemName(const std::string& itemName)
{
    name = itemName;
}

void Item::setItemPrice(int itemPrice)
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

