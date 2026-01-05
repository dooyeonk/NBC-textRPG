#pragma once

#include <iostream>
#include <string>

#include "Inventory.h"

class Item;

class Character
{
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

    Inventory inventory;

public:
    static Character* instance;

    static Character* getInstance(std::string name = "Student", int hp = 200, int attackPower = 30);
    static void destroy();

    bool isDead() const;

    void gainExperience(int amount);
    void levelUp();
    void addGold(int amount);
    void addItem(Item* item);
    void useRandomItem();

    void setHp(int hp);

    void displayStatus() const;

    std::string getName() const;

    int getHp() const;
    int getMaxHp() const;
    int getLevel() const;
    int getAttackPower() const;
    int getExperience() const;
    int getMaxExperience() const;

    const Inventory& getInventory() const;
};
