#include <chrono> // 딜레이 효과를 위해
#include <iostream>
#include <thread> // 딜레이 효과를 위해

#include "Core/GameManager/GameManager.h"
#include "Entities/Character/Character.h"
#include "Systems/BattleManager/BattleManager.h"
#include "Systems/BattleManager/BattleTypes.h"
#include "Systems/Shop/Shop.h"
#include "Utils/Logger.h"

using namespace std;

GameManager::GameManager() : player(nullptr), bIsGameOver(false)
{
    battleMg = new BattleManager();
}

GameManager::~GameManager()
{
    if (battleMg != nullptr)
    {
        delete battleMg;
        battleMg = nullptr;
    }

    // 캐릭터 메모리 해제
    Character::destroy();
    player = nullptr;
}

void GameManager::run()
{
    // 캐릭터 생성
    string name;
    while (true)
    {
        cout << "수강생의 이름을 입력하세요: ";
        getline(cin, name);

        // 앞뒤 공백 제거
        name.erase(0, name.find_first_not_of(" ")); // 앞 공백 제거
        name.erase(name.find_last_not_of(" ") + 1); // 뒤 공백 제거

        // 유효성 검사
        if (name.empty())
        {
            Logger::log(LogType::SYSTEM, "이름은 한 글자 이상 입력해야 합니다.");
            continue;
        }

        if (name.length() > 30)
        {
            Logger::log(LogType::SYSTEM, "이름이 너무 깁니다.");
            continue;
        }

        break;
    }
    player = Character::getInstance(name); // 싱글톤

    // 루프 시작
    while (!bIsGameOver)
    {
        system("cls");

        int currentLevel = player->getLevel();

        BattleReport report = battleMg->battle(*player);
        bool bVictory = (report.result == BattleResult::VICTORY);

        if (bVictory)
        {
            // 보스 잡으면 엔딩
            if (report.isBoss)
            {
                ending(report.monsterName);
                break;
            }

            showPostBattleMenu();
        }

        // 패배 시
        else
        {
            showDefeatSans();
            bIsGameOver = true;
        }
    }
}

void GameManager::visitShop(Character* player)
{
    /*
     * 상점 나갈 때 자동으로 소멸되도록 스택에 할당
     * 상점에 Player 넘겨 주고,
     * Enter 함수가 끝나면 다시 GameManager로 복귀
     */

    Shop shop;
    shop.Enter(*player);
    cout << "상점을 나옵니다." << endl;
}

void GameManager::showPostBattleMenu()
{
    // 전투 승리 후 정비 시간
    bool bReadyForNextBattle = false;

    while (!bReadyForNextBattle)
    {
        cout << "\n[정비 메뉴] 1.상점 방문  2.인벤토리 확인  3.스탯 확인  4.다음 전투 시작\n8. 킬로그 확인  9. 난이도 "
                "변경  0. 게임 "
                "종료: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            visitShop(player); // 상점 다녀오면 다시 이 메뉴로 돌아옴
        }
        else if (choice == 2)
        {
            displayInventory();
        }
        else if (choice == 3)
        {
            player->displayStatus();
        }
        else if (choice == 4)
        {
            cout << "전투 지역으로 이동합니다..." << endl;
            bReadyForNextBattle = true; // 메인 루프로!
        }
        else if (choice == 8)
        {
            Logger::showKillLogs();
        }
        else if (choice == 9)
        {
            battleMg->changeMode();
        }
        else if (choice == 0)
        {
            bIsGameOver = true;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
        }
    }
}

void GameManager::displayInventory()
{
    player->getInventory().display();
}

void GameManager::showDefeatSans()
{
    cout << "\n" << endl;
    cout << "░░░░░░░▄▄▄▀▀▀▀▀▀▀▀▀▀▀▀▄▄▄░░░░░░░" << endl;
    cout << "░░░░▄▀▀░░░░░░░░░░░░░░░░░░▀▀▄░░░░" << endl;
    cout << "░░▄▀░░░░░░░░░░░░░░░░░░░░░░░░▀▄░░" << endl;
    cout << "░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░" << endl;
    cout << "█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█" << endl;
    cout << "█░░░▄▄██████▄░░░░░░▄██████▄▄░░░█" << endl;
    cout << "█░░███▀▀█████░░░░░░██▀▀██████░░█" << endl;
    cout << "▀▄░███▄▄█████░░▄▄░░██▄▄██████░▄▀" << endl;
    cout << "░▀▄░░░░░░░▄▀░░▄██▄░░▀▄░░░░░░░▄▀░" << endl;
    cout << "░▄▀░░░▄░▀▀░░░░████░░░░▀▀░▄░░░▀▄░" << endl;
    cout << "░█░░▄▄█▀▄▄░░░░░░░░░░░░░▄▄██▄░░█░" << endl;
    cout << "░▀▄░░░▀▄█░▀▀█▀▀█▀▀▀█▀▀█░█▀░░░▄▀░" << endl;
    cout << "░░▀▄░░░░▀▀▄▄█░░█░░░█░▄█▀░░░░▄▀░░" << endl;
    cout << "░░░░▀▄▄░░░░░▀▀▀▀▀▀▀▀▀░░░░▄▄▀░░░░" << endl;
    cout << "░░░░░░░▀▀▀▄▄▄▄▄▄▄▄▄▄▄▄▀▀▀░░░░░░░" << endl;

    cout << "\n=============================================" << endl;
    cout << "         (당신은 의지를 잃었다...)" << endl;
    cout << "=============================================" << endl;
    cout << "                 GAME OVER                   " << endl;

    Logger::showKillLogs();

    cout << "\n계속하려면 아무 키나 누르세요...";
    string temp;
    cin >> temp;
}

void GameManager::ending(const string& bossName)
{
    // 보스 처치 후 정적
    cout << "\n\n";
    cout << "보스 [" << bossName << "]가 비명을 지르며 소멸합니다... " << endl;
    this_thread::sleep_for(chrono::seconds(2)); // 2초 대기

    // 텍스트 연출 (한 줄씩 천천히)
    string endingLines[] = {"...", "시스템의 모든 오류가 수정되었습니다.", "코드 컴파일 중...", "Linking...",
                            "Build Succeeded."};

    for (const string& line : endingLines)
    {
        cout << ">> " << line << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
    }

    Logger::showKillLogs();

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

    // 엔딩 크레딧
    cout << "\n[ Made by Team 3 ]" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << " - GameManager   : [김상민]" << endl;
    cout << " - Logger        : [김상민 & 강두연]" << endl;
    cout << " - Battle System : [강두연]" << endl;
    cout << " - Character     : [성헌호 & 강두연]" << endl;
    cout << " - Monster       : [유주연 & 성헌호]" << endl;
    cout << " - BossMonster   : [유주연 & 성헌호]" << endl;
    cout << " - Item          : [송승환]" << endl;
    cout << " - Shop          : [송승환]" << endl;

    cout << "\n\nPress any key to exit...";
    int temp;
    cin >> temp; // 종료 대기
}
