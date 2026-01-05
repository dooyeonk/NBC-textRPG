#pragma once
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <string>
#include <vector>

class ItemFactory
{
public:
    enum class ItemType
    {
        HEALTH_POTION,
        ATTACK_BOOST
    };

    static Item* createItem(ItemType type)
    {
        switch (type)
        {
        case ItemType::HEALTH_POTION:
            return new HealthPotion();
        case ItemType::ATTACK_BOOST:
            return new AttackBoost();
        default:
            return nullptr;
        }
    }

    // 무작위 아이템 생성 (전투 보상용)
    static Item* createRandomItem()
    {
        int draw = rand() % 2;
        return createItem(static_cast<ItemType>(draw));
    }
};
