#include <algorithm>

#include "Character.h"

Character* Character::instance = nullptr;

Character::Character(std::string name, int healthPoint, int attackPower)
    : name(name), hp(healthPoint), maxHp(healthPoint), attackPower(attackPower), level(1), experience(0),
      maxExperience(100), gold(0)
{
}

Character::~Character()
{
}

Character* Character::getInstance(std::string name, int healthPoint, int attackPower)
{
    if (instance == nullptr)
    {
        instance = new Character(name, healthPoint, attackPower);
    }
    return instance;
}

void Character::destroy()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

bool Character::isDead() const
{
    return hp <= 0;
}

void Character::gainExperience(int amount)
{
    experience += amount;
    if (experience >= maxExperience)
    {
        levelUp();
    }
}

void Character::levelUp()
{
    if (level >= 10)
    {
        std::cout << "이미 최대 레벨입니다." << std::endl;
        return;
    }
    experience = 0;
    level++;
    maxHp += 20;
    hp = maxHp; // 레벨업 시 체력 풀회복
    attackPower += 5;

    std::cout << "=== LEVEL UP! 현재 레벨: " << level << " ===" << std::endl;
}

void Character::addGold(int amount)
{
    gold += amount;
}

void Character::addItem(Item* newItem)
{
    if (!newItem)
    {
        return;
    }

    for (auto& slot : inventory)
    {
        if (slot.item->getName() == newItem->getName())
        {
            slot.quantity++;
            std::cout << newItem->getName() << "의 수량이 증가했습니다." << std::endl;
            return;
        }
    }

    inventory.push_back(InventoryItem(newItem));
}

void Character::setHp(int hp)
{
    // 0과 maxHp 사이로 값 제한
    hp = std::max(0, std::min(hp, maxHp));
}

void Character::displayStatus() const
{
    std::cout << "\n----------------------------" << std::endl;
    std::cout << "이름: " << name << " (Lv." << level << ")" << std::endl;
    std::cout << "HP: " << hp << " / " << maxHp << std::endl;
    std::cout << "공격력: " << attackPower << " | 골드: " << gold << std::endl;
    std::cout << "----------------------------\n" << std::endl;
}

void Character::reduceItem(const std::string& itemName)
{
    for (auto iterator = inventory.begin(); iterator != inventory.end(); ++iterator)
    {
        if (iterator->item->getName() == itemName)
        {

            iterator->quantity--;
            if (iterator->quantity <= 0)
            {
                delete iterator->item;
                inventory.erase(iterator);
            }
            return;
        }
    }
}

std::string Character::getName() const
{
    return name;
}

int Character::getHp() const
{
    return hp;
}

int Character::getMaxHp() const
{
    return maxHp;
}

int Character::getLevel() const
{
    return level;
}

int Character::getMaxExperience() const
{
    return maxExperience;
}

int Character::getAttackPower() const
{
    return attackPower;
}

int Character::getExperience() const
{
    return experience;
}

const std::vector<InventoryItem>& Character::getInventory() const
{
    return inventory;
}
