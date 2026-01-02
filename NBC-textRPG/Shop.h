#pragma once
#include "item.h"
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

    void ShowItem();

    Item* buyItem(int buy);

    Item* sellItem(int sell);
};
