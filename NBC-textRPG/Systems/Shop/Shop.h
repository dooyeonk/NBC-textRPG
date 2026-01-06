#pragma once

#include <memory>
#include <vector>

#include "Entities/Item/Item.h"

class Character;

class Shop
{
public:
    // 상점 메인 루프 (입장)
    void Enter(Character& character);

private:
    void displayBuyMenu(Character& character);
    void displaySellMenu(Character& character);

    // 판매 가격 상수 (60%)
    const float SELL_PRICE_RATIO = 0.6f;
};
