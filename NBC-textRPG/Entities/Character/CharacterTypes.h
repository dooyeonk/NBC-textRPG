#pragma once

#include "Item.h"

struct InventoryItem
{
    Item* item;
    int quantity;

    InventoryItem(Item* item) : item(item), quantity(1)
    {
    }
};
