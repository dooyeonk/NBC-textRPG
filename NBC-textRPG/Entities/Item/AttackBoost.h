#pragma once

#include "Item.h"
#include "ItemTypes.h"

class AttackBoost : public Item
{
private:
    int attackUp;

public:
    AttackBoost(const std::string& itemName = "공격력 증가 스크롤", int price = 15, int attackUp = 10);

    ItemEffect getEffect() const override;
    void use(Character& character) const override;
};
