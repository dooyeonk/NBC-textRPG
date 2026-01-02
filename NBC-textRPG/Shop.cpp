#include "Shop.h"
#include "Item.h"
#include <string>
#include <vector>
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

void Shop::ShowItem()
{
    for (size_t i = 0; i < items.size(); i++)
    {
        std::cout << i << ". " << items[i]->getName() << items[i]->getPrice() << "골드" << std::endl;
    }
}

Item* Shop::buyItem(int buy)
{
    if (buy < 0 || items.size() < 0)
    {
        return;
    }

}

Item* Shop::sellItem(int sell)
{

}
