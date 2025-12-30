#include "GameManager.h"
#include "Character.h"
#include "BattleSystem.h"
#include "Monster.h"
#include <iostream>

using namespace std;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::Run()
{
    // 캐릭터 생성
    string Name;
    cout << "용사의 이름을 입력하세요: ";
    cin >> Name;
    Player = Character::GetInstance(Name); // 싱글톤

    // 루프 시작
    while (!bIsGameOver)
    {
        // 레벨 10 달성 체크 (보스전 트리거)
        Monster* Enemy = nullptr;
        if (Player->GetLevel() >= 10)
        {
            cout << "\n=============================================" << endl;
            cout << "이제 일반 몬스터는 상대도 안 된다!" << endl;
            cout << "===============================================" << endl;
            Enemy = new BossMonster(Player->GetLevel());
        }
        else
        {
            Enemy = GenerateMonster(Player->GetLevel());
        }

        // 전투 시작 (랜덤 아이템 사용 등은 BattleSystem 내부에서 처리하는게 좋을 듯)
        cout << "\n전투 개시! 상대: " << Enemy->GetName() << endl;
        bool bVictory = BattleSys->StartBattle(Player, Enemy);

        delete Enemy;

        if (bVictory)
        {
            // 보스 잡으면 엔딩
            if (Player->GetLevel() >= 10)
            {
                Ending(); 
                break;         
            }

            // 전투 승리 후 정비 시간
            bool bReadyForNextBattle = false;
            while (!bReadyForNextBattle)
            {
                cout << "\n[정비 메뉴] 1.상점 방문  2.인벤토리 확인  3.다음 전투(나가기): ";
                int choice;
                cin >> choice;

                if (choice == 1)
                {
                    VisitShop(Player); // 상점 다녀오면 다시 이 메뉴로 돌아옴
                }
                else if (choice == 2)
                {
                    Player->DisplayInventory();
                }
                else if (choice == 3)
                {
                    cout << "전투 지역으로 이동합니다..." << endl;
                    bReadyForNextBattle = true; // 메인 루프로!
                }
            }
        }

        // 패배 시
        else
        {
            cout << "Game Over" << endl;
            bIsGameOver = true;
        }
    }
}
