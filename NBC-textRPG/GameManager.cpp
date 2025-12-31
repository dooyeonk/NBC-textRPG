#include "GameManager.h"
#include "Character.h"
#include "BattleSystem.h"
#include "Monster.h"
#include <iostream>
#include <thread> // 딜레이 효과를 위해
#include <chrono> // 딜레이 효과를 위해

using namespace std;

GameManager::GameManager()
{
    BattleSys = new BattleSystem();
}

GameManager::~GameManager()
{
    if (BattleSys != nullptr)
    {
        delete BattleSys;
        BattleSys = nullptr;
    }
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

            ShowPostBattleMenu();
        }

        // 패배 시
        else
        {
            cout << "Game Over" << endl;
            bIsGameOver = true;
        }
    }
}

Monster* GameManager::GenerateMonster()
{
    return nullptr;
}

void GameManager::VisitShop(Character* player)
{
    /*
    * 상점 나갈 때 자동으로 소멸되도록 스택에 할당
    * 상점에 Player 넘겨 주고,
    * Enter 함수가 끝나면 다시 GameManager로 복귀
    */

    /*
    Shop shop;
    shop.Enter(Player);
    cout << "상점을 나옵니다." << endl;
    */

    
}

void GameManager::ShowPostBattleMenu()
{
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
        else
        {
            cout << "잘못된 입력입니다." << endl;
        }
    }
}

void GameManager::Ending()
{
    system("cls");

    // 보스 처치 후 정적...
    cout << "\n\n";
    cout << "보스 [Memory_Leak]가 비명을 지르며 소멸합니다..." << endl;
    this_thread::sleep_for(chrono::seconds(2)); // 2초 대기 (긴장감)

    // 텍스트 연출 (한 줄씩 천천히)
    string endingLines[] = {"...", "시스템의 모든 오류가 수정되었습니다.", "코드 컴파일 중...", "Linking...",
                            "Build Succeeded."};

    for (const string& line : endingLines)
    {
        cout << ">> " << line << endl;
        this_thread::sleep_for(chrono::milliseconds(800)); // 0.8초 딜레이
    }

    // ASCII 아트 암거나 
    cout << "\n\n";
    cout << "      ___________      " << endl;
    cout << "     '._==_==_=_.'     " << endl;
    cout << "     .-\\:      /-.    " << endl;
    cout << "    | (|:.     |) |    " << endl;
    cout << "     '-|:.     |-'     " << endl;
    cout << "       \\::.    /      " << endl;
    cout << "        '::. .'        " << endl;
    cout << "          ) (          " << endl;
    cout << "        _.' '._        " << endl;
    cout << "       `\"\"\"\"\"\"\"`       " << endl;

    cout << "\n=============================================" << endl;
    cout << "   축하합니다! 위대한 개발자로 거듭나셨습니다!" << endl;
    cout << "=============================================" << endl;

    // 4. 엔딩 크레딧
    cout << "\n[ Made by Team 6 ]" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << " - Main Director : [본인 이름]" << endl;
    cout << " - Battle System : [팀원 A]" << endl;
    cout << " - Character Dev : [팀원 B]" << endl;
    cout << " - Monster Design: [팀원 C]" << endl;
    cout << " - Item Logic    : [팀원 D]" << endl;
    cout << " - UI / Logger   : [팀원 E]" << endl;

    cout << "\n\nPress any key to exit...";
    int temp;
    cin >> temp; // 종료 대기

}
