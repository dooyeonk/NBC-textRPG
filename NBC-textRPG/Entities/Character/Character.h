#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Item.h"

struct InventoryItem
{
    Item* item;
    int quantity;

    InventoryItem(Item* item) : item(item), quantity(1)
    {
    }
};

class Character
{
public:
    static Character* instance;

    static Character* getInstance(std::string name = "Student", int hp = 200, int attackPower = 30);
    static void destroy();

    bool isDead() const;

    void gainExperience(int amount);
    void levelUp();
    void addGold(int amount);
    void addItem(Item* newItem);
    void reduceItem(const std::string& itemName);

    void setHp(int hp);

    void displayStatus() const;

    std::string getName() const;

    int getHp() const;
    int getMaxHp() const;
    int getLevel() const;
    int getAttackPower() const;
    int getExperience() const;
    int getMaxExperience() const;

    const std::vector<InventoryItem>& getInventory() const;

private:
    Character(std::string name, int healthPoint, int attackPower);
    ~Character();

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;

    const std::string name;

    int hp;
    int maxHp;
    int attackPower;
    int level;
    int experience;
    int maxExperience;
    int gold;

    std::vector<InventoryItem> inventory;
};
