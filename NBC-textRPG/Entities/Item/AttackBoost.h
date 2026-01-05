#pragma once

#include "Item.h"

class AttackBoost : public Item
{
private:
    int attackUp;

public:
    AttackBoost(const std::string& itemName = "공격력 증가 스크롤", int price = 15, int attackUp = 10);

    void use(Character& character) const override;
};
