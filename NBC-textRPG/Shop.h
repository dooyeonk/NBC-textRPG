#pragma once
#include "Item.h"
#include <vector>
#include <string>
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
