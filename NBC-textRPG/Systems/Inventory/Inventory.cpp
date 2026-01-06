#include <iostream>
#include <memory>

#include "Entities/Character/Character.h"
#include "Inventory.h"
#include "Utils/Logger.h"

Inventory::~Inventory()
{
    slots.clear();
}

void Inventory::add(std::shared_ptr<Item> item)
{
    if (!item)
        return;

    // 이름으로 중복 체크
    for (auto& slot : slots)
    {
        if (slot.item->getName() == item->getName())
        {
            slot.quantity++;
            return;
        }
    }
    slots.push_back({item, 1});
}

void Inventory::executeRemove(std::vector<InventorySlot>::iterator it)
{
    it->quantity--;
    if (it->quantity <= 0)
    {
        slots.erase(it);
    }
}

void Inventory::remove(std::shared_ptr<Item> target)
{
    if (!target)
        return;

    auto it =
        std::find_if(slots.begin(), slots.end(), [target](const InventorySlot& slot) { return slot.item == target; });

    if (it != slots.end())
    {
        executeRemove(it);
    }
}

void Inventory::remove(const std::string& name)
{
    auto it = std::find_if(slots.begin(), slots.end(),
                           [&name](const InventorySlot& slot) { return slot.item->getName() == name; });

    if (it != slots.end())
    {
        executeRemove(it);
    }
}

void Inventory::useRandom(Character& owner)
{
    if (slots.empty())
    {
        return;
    }

    int randomIndex = rand() % slots.size();
    auto selectedItem = slots[randomIndex].item;

    // 아이템 효과 적용
    selectedItem->use(owner);
    auto it = slots.begin() + randomIndex;
    executeRemove(it);
}

void Inventory::display() const
{
    Logger::log(LogType::INFO, "\n========== [ 인벤토리 목록 ] ==========\n");
    if (slots.empty())
    {
        Logger::log(LogType::INFO, "(비어있음)");
    }
    else
    {
        for (const auto& slot : slots)
        {

            Logger::log(LogType::INFO, " - {} (개수:  {}개)", slot.item->getName(), slot.quantity);
        }
    }

    Logger::log(LogType::INFO, "\n========================================\n");
}
