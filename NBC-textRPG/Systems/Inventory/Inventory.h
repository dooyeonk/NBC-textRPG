#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "Entities/Item/Item.h"

struct InventorySlot
{
    std::shared_ptr<Item> item;
    int quantity;
};

class Inventory
{
private:
    std::vector<InventorySlot> slots;

    // 실제 삭제 처리를 담당하는 내부 함수
    void executeRemove(std::vector<InventorySlot>::iterator it);

public:
    Inventory() = default;
    ~Inventory();

    void add(std::shared_ptr<Item> newItem);

    void remove(std::shared_ptr<Item> targetItem);
    void remove(const std::string& itemName);

    void useRandom(class Character& owner);

    bool empty() const
    {
        return slots.empty();
    }

    size_t size() const
    {
        return slots.size();
    }

    void display() const;
};
