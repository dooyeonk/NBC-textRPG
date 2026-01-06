#pragma once

#include <string>

class Character;
class BattleManager;

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void run();

private:
    void visitShop(Character* player);        // 상점 ㄱㄱ
    void ending(const std::string& bossName); // 엔딩 처리 (보스 클리어 시)
    void showPostBattleMenu();                // 전투 승리 후 보여줄 선택지
    void displayInventory();
    void showDefeatSans();

private:
    Character* player;
    BattleManager* battleMg;
    bool bIsGameOver;
};
