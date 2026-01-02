#include "Shop.h"
#include "Item.h"
#include "Character.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

Shop::Shop()
{
}
Shop::~Shop()
{
}

void Shop::addItem(Item* item)
{
    items.push_back(item);
}

void Shop::showItem()
{
    for (size_t i = 0; i < items.size(); i++)
    {
        std::cout << i << ". " << items[i]->getName() << items[i]->getPrice() << "Gold" << std::endl;
    }
}

Item* Shop::buyItem(int itemIndex)
{
    if (itemIndex < 0 || items.size() < itemIndex)
    {
        return nullptr;
    }
    Item* boughtItem = items[itemIndex];
    items.erase(items.begin() + itemIndex);

    return boughtItem;
}


Item* Shop::sellItem(int itemIndex)
{
    return 0;//추가 필요
}
