#pragma once

#include "Character.h"
#include "Item.h"

class HealthPotion : public Item
{
private:
    int healing;

public:
    HealthPotion(const std::string& itemName = "HP포션", int itemPrice = 10, int healing = 50);

    void use(Character& character) const override;
};
