#include <iostream>

#include "Entities/Character/Character.h"
#include "Inventory.h"
#include "Utils/Logger.h"

Inventory::~Inventory()
{
    for (auto& slot : slots)
    {
        delete slot.item;
    }
    slots.clear();
}

void Inventory::add(Item* item)
{
    if (!item)
        return;

    // 이름으로 중복 체크
    for (auto& slot : slots)
    {
        if (slot.item->getName() == item->getName())
        {
            slot.quantity++;
            delete item; // 이미 있는 아이템이므로 메모리 해제
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
        delete it->item;
        slots.erase(it);
    }
}

void Inventory::remove(Item* target)
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
        return;

    int randomIndex = rand() % slots.size();
    Item* selectedItem = slots[randomIndex].item;

    // 아이템 효과 적용
    selectedItem->use(owner);
    // quantity 차감 혹은 삭제
    this->remove(selectedItem);
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
