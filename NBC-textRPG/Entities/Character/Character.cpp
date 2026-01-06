#include <algorithm>
#include <memory>

#include "Character.h"
#include "Entities/Item/Item.h"
#include "Systems/Inventory/Inventory.h"
#include "Utils/Logger.h"

Character* Character::instance = nullptr;

Character::Character(std::string name, int healthPoint, int attackPower)
    : name(name), hp(healthPoint), maxHp(healthPoint), attackPower(attackPower), level(1), experience(0),
      maxExperience(100), gold(0), tempAttackPower(0)
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
        return;
    }
    experience = 0;
    level++;
    maxHp += level * 20;
    hp = maxHp; // 레벨업 시 체력 풀회복
    attackPower += level * 5;

    Logger::log(LogType::SYSTEM, "레벨업! 현재 레벨: {}", level);
}

void Character::addGold(int amount)
{
    gold += amount;
}

void Character::addItem(std::shared_ptr<Item> item)
{
    inventory.add(item);
}

void Character::addTempAttackPower(int amount)
{
    tempAttackPower += amount;
}

void Character::clearTempAttackPower()
{
    tempAttackPower = 0;
}

void Character::setHp(int hp)
{
    // 0과 maxHp 사이로 값 제한
    this->hp = std::max(0, std::min(hp, maxHp));
}

void Character::displayStatus() const
{
    Logger::log(LogType::INFO, "\n========== [ 캐릭터 스탯 ] ==========\n");
    Logger::log(LogType::INFO, "이름: {}", name);
    Logger::log(LogType::INFO, "레벨: {}", level);
    Logger::log(LogType::INFO, "HP: {} / {}", hp, maxHp);
    Logger::log(LogType::INFO, "공격력: {}", attackPower);
    Logger::log(LogType::INFO, "골드: {}G", gold);
    Logger::log(LogType::INFO, "경험치: {} / {}", experience, maxExperience);
    Logger::log(LogType::INFO, "\n=====================================\n");
}

void Character::useRandomItem()
{
    inventory.useRandom(*this);
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

Inventory& Character::getInventory()
{
    return inventory;
}

int Character::getTotalAttackPower() const
{
    return attackPower + tempAttackPower;
}

int Character::getGold() const
{
    return gold;
}

void Character::spendGold(int amount)
{
    if (amount > gold)
    {
        Logger::log(LogType::SYSTEM, "골드가 부족합니다.");
        return;
    }
    gold -= amount;
}
