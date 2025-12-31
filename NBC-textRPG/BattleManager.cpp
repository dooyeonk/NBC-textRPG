#include "BattleManager.h"
// #include "MonsterFactory.h"
#include "Monster.h" // TODO: factory pattern
#include <iostream>
#include <cstdlib> // rand(), srand()를 위해 필요
#include <algorithm>

BattleReport BattleManager::battle(Character& character)
{
    // 팩토리 패턴을 사용하여 플레이어 레벨에 맞는 몬스터 생성
    // TODO: factory pattern
    // Monster* monster = MonsterFactory::createMonster(character.getLevel());
    Monster* monster = new Monster;

    BattleReport report;
    report.monsterName = monster->getName();
    report.result = BattleResult::DEFEAT; // 기본값은 패배로 설정
    report.experience = 0;
    report.gold = 0;
    report.droppedItem = "없음";

    // "해당 전투 동안 유지"되는 공격력 보너스 (아이템 사용 시 증가)
    int attackBonus = 0;

    std::cout << "\n======================================" << std::endl;
    std::cout << "   전투 시작: " << monster->getName() << "이(가) 나타났다!" << std::endl;
    std::cout << "======================================" << std::endl;

    // 전투 루프: 누군가 죽을 때까지 반복
    while (true)
    {
        // 1. 플레이어 턴 수행
        this->executePlayerTurn(character, *monster, attackBonus);

        // 몬스터 사망 확인
        if (monster->isDead())
        {
            this->processVictory(character, report);

            delete monster; // 동적 할당된 몬스터 메모리 해제
            return report;
        }

        // 2. 몬스터 턴 수행
        this->executeMonsterTurn(character, *monster);

        // 플레이어 사망 확인
        if (character.isDead())
        {
            std::cout << "\n" << character.getName() << "이(가) 쓰러졌습니다..." << std::endl;

            delete monster; // 메모리 해제
            return report;
        }
    }
}

void BattleManager::executePlayerTurn(Character& character, Monster& monster, int& attackBonus)
{
    std::cout << "\n[" << character.getName() << "의 차례]" << std::endl;

    if (itemUsed(character, attackBonus))
    {
        return;
    }

    int finalDamage = character.getAttackPower() + attackBonus;
    monster.setHp(monster.getHp() - finalDamage);

    std::cout << ">> " << character.getName() << "의 공격! " << monster.getName() << "에게 " << finalDamage
              << "의 피해를 주었습니다." << std::endl;
}

bool BattleManager::itemUsed(Character& character, int& attackBonus)
{
    const auto inventory = character.getInventory();
    if ((rand() % 100) < 10 && inventory.size() > 0)
    {
        // 인벤토리 인덱스 중 하나를 랜덤하게 선택
        int randomIndex = rand() % inventory.size();
        const auto item = inventory[randomIndex].item;
        ItemEffect effect = item->getItemEffect();

        std::cout << "[아이템(" << item->getName() << ") 사용]: ";

        if (effect.hp != 0)
        {
            character.setHp(std::max(1, std::min(character.getHp() + effect.hp, character.getMaxHp())));
            std::string effectString = effect.hp > 0 ? "증가" : "감소";
            std::cout << "HP " << effect.hp << " " << effectString << std::endl;
        }

        if (effect.attackPower != 0)
        {
            attackBonus += effect.attackPower;
            std::string effectString = effect.attackPower > 0 ? "증가" : "감소";
            std::cout << "전투시간 동안 공격력이 " << effect.attackPower << " " << effectString;
        }

        character.reduceItem(item->getName());
        return true;
    }
    return false;
}

void BattleManager::executeMonsterTurn(Character& character, Monster& monster)
{
    std::cout << "\n[" << monster.getName() << "의 차례]" << std::endl;
    character.setHp(character.getHp() - monster.getAttackPower());

    std::cout << ">> " << monster.getName() << "의 공격! " << character.getName() << "에게 " << monster.getAttackPower()
              << "의 피해를 주었습니다." << std::endl;
}

void BattleManager::processVictory(Character& character, BattleReport& report)
{
    report.result = BattleResult::VICTORY;
    report.experience = 50;

    report.gold = (rand() % 11) + 10; // 10 ~ 20 random;

    std::cout << "\n======================================" << std::endl;
    std::cout << "   전투 승리! 보상을 획득합니다." << std::endl;
    std::cout << "======================================" << std::endl;

    std::cout << "획득 경험치: " << report.experience << std::endl;
    std::cout << "획득 골드: " << report.gold << " G" << std::endl;

    character.gainExperience(report.experience);
    character.addGold(report.gold);
}
