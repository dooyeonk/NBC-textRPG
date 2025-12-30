#pragma once

class Character;
class Monster;
class BattleSystem;

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void Run();

private:

    // 몬스터 생성 (레벨에 따라 일반/보스 결정)
    Monster* GenerateMonster();

    // 상점 ㄱㄱ
    void VisitShop(Character* player);

    // 엔딩 처리 (보스 클리어 시)
    void Ending();

    // 전투 승리 후 보여줄 선택지
    void ShowPostBattleMenu();

private:
    Character* Player;       
    BattleSystem* BattleSys; 
    bool bIsGameOver;       
};