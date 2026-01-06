#include "Logger.h"

std::map<std::string, int> Logger::monsterKillCounts;

// 1. 타입에 따른 색상 및 말머리 적용
void Logger::applyColor(LogType type)
{
    switch (type)
    {
    case LogType::BATTLE:
        std::cout << "\033[33m[전투] "; // Yellow
        break;
    case LogType::ITEM:
        std::cout << "\033[36m[아이템] "; // Cyan
        break;
    case LogType::REWARD:
        std::cout << "\033[32m[보상] "; // Green
        break;
    case LogType::DANGER:
        std::cout << "\033[31m[피해] "; // Red
        break;
    case LogType::SYSTEM:
        std::cout << "\033[35m[시스템] "; // Magenta
        break;
    case LogType::INFO:
    default:
        std::cout << "\033[0m"; // Reset (White)
        break;
    }
}

// 2. 구분선 출력
void Logger::printLine()
{
    std::cout << "\033[0m========================================================" << std::endl;
}

// 3. 화면 정리
void Logger::clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
