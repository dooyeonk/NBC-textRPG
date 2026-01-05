#include <algorithm>
#include <cstdlib> // rand(), srand()를 위해 필요
#include <iostream>

#include "AttackBoost.h"
#include "BattleManager.h"
#include "HealthPotion.h"
#include "ItemFactory.h"
#include "Logger.h"
#include "MonsterFactory.h"

BattleReport BattleManager::battle(Character& character)
{
    // 팩토리 패턴을 사용하여 플레이어 레벨에 맞는 몬스터 생성
    Monster* monster = MonsterFactory::createMonster(character.getLevel());
    // 캐릭터 버프 공격력 초기화
    character.clearTempAttackPower();

    BattleReport report;
    report.monsterName = monster->getName();
    report.result = BattleResult::DEFEAT; // 기본값은 패배로 설정
    report.experience = 0;
    report.gold = 0;
    report.droppedItem = "없음";
    report.isBoss = monster->isBoss();

    if (isEasyMode)
    {
        // 쉬움 난이도에서는 배틀 시작에서 hp 회복하고 시작
        character.setHp(character.getMaxHp());
    }

    Logger::printLine();
    Logger::log(LogType::SYSTEM, "전투 시작: {}이(가) 나타났다!", monster->getName());
    Logger::printLine();

    // 전투 루프: 누군가 죽을 때까지 반복
    while (true)
    {
        // 1. 플레이어 턴 수행
        this->executePlayerTurn(character, *monster);

        // 몬스터 사망 확인
        if (monster->isDead())
        {
            Logger::log(LogType::BATTLE, "{}이(가) 쓰러졌다...", monster->getName());
            Logger::printLine();
            this->processVictory(character, report);

            delete monster; // 동적 할당된 몬스터 메모리 해제
            return report;
        }

        // 2. 몬스터 턴 수행
        this->executeMonsterTurn(character, *monster);

        // 플레이어 사망 확인
        if (character.isDead())
        {
            Logger::log(LogType::DANGER, "{}이(가) 쓰러졌다...", character.getName());

            delete monster; // 메모리 해제
            return report;
        }
    }
}

void BattleManager::executePlayerTurn(Character& character, Monster& monster)
{
    Logger::log(LogType::BATTLE, "[{}의 차례]", character.getName());

    if (itemUsed(character))
    {
        return;
    }

    int finalDamage = character.getTotalAttackPower();
    monster.hpDamaged(finalDamage);

    Logger::log(LogType::BATTLE, ">> {}의 공격! {}에게 {}의 피해를 입혔습니다.\n", character.getName(),
                monster.getName(), finalDamage);
}

bool BattleManager::itemUsed(Character& character)
{
    const auto& inventory = character.getInventory();
    if ((rand() % 100) < 20 && inventory.size() > 0)
    {
        character.useRandomItem();
        return true;
    }
    return false;
}

void BattleManager::executeMonsterTurn(Character& character, Monster& monster)
{
    Logger::log(LogType::BATTLE, "[{}의 차례]", monster.getName());
    character.setHp(character.getHp() - monster.getAttackPower());

    Logger::log(LogType::DANGER, ">> {}의 역습! {}에게 {}의 피해!\n", monster.getName(), character.getName(),
                monster.getAttackPower());
}

void BattleManager::processVictory(Character& character, BattleReport& report)
{
    report.result = BattleResult::VICTORY;
    report.experience = 50;

    report.gold = (rand() % 11) + 10; // 10 ~ 20 random;

    Logger::log(LogType::SYSTEM, "전투 승리! {} 오류를 해결했습니다.", report.monsterName);
    Logger::printLine();
    Logger::log(LogType::REWARD, "경험치: {} EXP / 골드: {}G 획득", report.experience, report.gold);

    if ((rand() % 100) < 30)
    {
        Item* item = ItemFactory::createRandomItem();
        if (item)
        {
            report.droppedItem = item->getName();
            Logger::log(LogType::ITEM, "드랍: [{}] 획득", report.droppedItem);
            character.addItem(item);
        }
    }

    character.gainExperience(report.experience);
    character.addGold(report.gold);

    Logger::printLine();
}

void BattleManager::changeMode()
{
    isEasyMode = !isEasyMode;
    std::string modeName = isEasyMode ? "쉬움" : "보통";
    Logger::printLine();
    Logger::log(LogType::SYSTEM, "난이도를 {}로 변경합니다.", modeName);
    Logger::printLine();
}
