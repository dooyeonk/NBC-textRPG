#include "Character.h"
#include <algorithm>

Character* Character::instance = nullptr;

Character::Character(std::string name, int healthPoint, int attackPower)
    : name(name), healthPoint(healthPoint), maxHealthPoint(healthPoint), attackPower(attackPower), level(1),
      experience(0), maxExperience(100), gold(0)
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
    return healthPoint <= 0;
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
    maxHealthPoint += 20;
    healthPoint = maxHealthPoint; // 레벨업 시 체력 풀회복
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
        return;

    for (auto& slot : inventory)
    {
        // TODO: 아이템 method 없어서 일단 주석처리
        /*if (slot.item->getName() == newItem->getName())
        {
            slot.quantity++;
            std::cout << newItem->getName() << "의 수량이 증가했습니다." << std::endl;
            return;
        }*/
    }

    inventory.push_back(InventoryItem(newItem));
}

void Character::setHealthPoint(int amount)
{
    // 0과 maxHealthPoint 사이로 값 제한
    healthPoint = std::max(0, std::min(amount, maxHealthPoint));
}

void Character::displayStatus() const
{
    std::cout << "\n----------------------------" << std::endl;
    std::cout << "이름: " << name << " (Lv." << level << ")" << std::endl;
    std::cout << "HP: " << healthPoint << " / " << maxHealthPoint << std::endl;
    std::cout << "공격력: " << attackPower << " | 골드: " << gold << std::endl;
    std::cout << "----------------------------\n" << std::endl;
}

void Character::useItem(const std::string& itemName)
{
    for (auto iterator = this->inventory.begin(); iterator != this->inventory.end(); ++iterator)
    {
        // TODO: 아이템 클래스 구현되면 수정
        // if (iterator->item->getName() == itemName)
        {
            // TODO: 아이템 클래스 구현되면 수정
            // iterator->item->use(this);

            iterator->quantity--;
            if (iterator->quantity <= 0)
            {
                delete iterator->item;
                this->inventory.erase(iterator);
            }
            return;
        }
    }
}

std::string Character::getName() const
{
    return this->name;
}

int Character::getHealthPoint() const
{
    return this->healthPoint;
}

int Character::getAttackPower() const
{
    return this->attackPower;
}

int Character::getExperience() const
{
    return this->experience;
}

const std::vector<InventoryItem>& Character::getInventory() const
{
    return this->inventory;
}
