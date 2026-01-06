#pragma once
#include "Entities/Item/Item.h"
#include <string>
#include <vector>
class Shop
{
private:
    std::vector<Item*> items;

public:
    Shop();
    ~Shop();

    void addItem(Item* item);

    void showItem();

    Item* buyItem(int itemIndex);

    Item* sellItem(int itemIndex);
};
