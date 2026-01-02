#pragma once

class Character;
class Monster;
class BattleManager;

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void run();

private:

    // 상점 ㄱㄱ
    void visitShop(Character* player);

    // 엔딩 처리 (보스 클리어 시)
    void ending();

    // 전투 승리 후 보여줄 선택지
    void showPostBattleMenu();

private:
    Character* player;
    BattleManager* battleMg;
    bool bIsGameOver;
};
