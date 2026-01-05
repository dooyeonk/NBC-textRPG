#include "Logger.h"
#include <windows.h>

void Logger::Log(const std::string& message, LogLevel level)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 색상 설정
    switch (level)
    {
    case LogLevel::INFO:
        SetConsoleTextAttribute(hConsole, 7); // 기본 흰색
        std::cout << "[INFO] ";
        break;
    case LogLevel::COMBAT:
        SetConsoleTextAttribute(hConsole, 14); // 노란색 (전투 강조)
        std::cout << "[BATTLE] ";
        break;
    case LogLevel::Error:
        SetConsoleTextAttribute(hConsole, 12); // 빨간색 (에러)
        std::cout << "[ERROR] ";
        break;
    }

    // 메시지 출력
    std::cout << message << std::endl;

    // 색상 복구 (흰색)
    SetConsoleTextAttribute(hConsole, 7);
}

void Logger::Info(const std::string& message)
{
}

void Logger::Combat(const std::string& message)
{
}

void Logger::Error(const std::string& message)
{
}
