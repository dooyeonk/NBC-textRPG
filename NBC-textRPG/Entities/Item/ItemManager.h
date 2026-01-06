#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "AttackBoost.h"
#include "HealthPotion.h"
#include "Item.h"

class ItemManager
{
private:
    std::unordered_map<std::string, std::shared_ptr<Item>> registry;

    ItemManager()
    {
        // 게임 초기 아이템 등록
        registerItem(std::make_shared<HealthPotion>());
        registerItem(std::make_shared<AttackBoost>());
    }

    // 아이템 등록
    void registerItem(std::shared_ptr<Item> item)
    {
        if (item)
        {
            registry[item->getName()] = item;
        }
    }

public:
    ~ItemManager() = default;

    static ItemManager& getInstance()
    {
        static ItemManager instance;
        return instance;
    }

    // 이름으로 찾기
    std::shared_ptr<Item> getItem(const std::string& name)
    {
        if (registry.count(name))
        {
            return registry[name];
        }
        return nullptr;
    }

    // 랜덤 드랍 로직 (전투 보상)
    std::shared_ptr<Item> getRandomItem()
    {
        if (registry.empty())
        {
            return nullptr;
        }

        auto it = std::next(registry.begin(), rand() % registry.size());
        return it->second;
    }

    // 전체 목록 (상점용)
    std::vector<std::shared_ptr<Item>> getAllPrototypes()
    {
        std::vector<std::shared_ptr<Item>> list;
        for (auto& pair : registry)
        {
            list.push_back(pair.second);
        }
        return list;
    }
};
