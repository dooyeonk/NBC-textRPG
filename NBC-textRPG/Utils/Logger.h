#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <string>

enum class LogType
{
    INFO,
    BATTLE,
    ITEM,
    REWARD,
    DANGER,
    SYSTEM
};

class Logger
{
private:
    static std::map<std::string, int> monsterKillCounts;
    static void applyColor(LogType type);

    static void formatPlaceholders(std::string& f)
    {
    }

    // 개별 값을 문자열로 변환하여 {}를 치환하는 도우미 함수
    template <typename T> static void formatPlaceholders(std::string& f, T value)
    {
        size_t pos = f.find("{}");
        if (pos != std::string::npos)
        {
            std::ostringstream oss;
            oss << value;
            f.replace(pos, 2, oss.str());
        }
    }

    // 여러 개의 인자를 처리하기 위한 재귀적 전개
    template <typename T, typename... Args> static void formatPlaceholders(std::string& f, T value, Args... args)
    {
        formatPlaceholders(f, value);
        formatPlaceholders(f, args...);
    }

public:
    // 핵심 함수: {}를 찾아 순서대로 값을 채워줌
    template <typename... Args> static void log(LogType type, std::string format, Args... args)
    {
        applyColor(type);
        (formatPlaceholders(format, args...));
        std::cout << format << "\033[0m" << std::endl;
    }

    static void recordKill(const std::string& monsterName)
    {
        monsterKillCounts[monsterName]++;
    }

    // 지금까지 잡은 목록 요약 출력
    static void showKillLogs()
    {
        printLine();
        log(LogType::SYSTEM, "===== 개발 기록 (Monster Kill Log) =====");
        if (monsterKillCounts.empty())
        {
            log(LogType::INFO, "아직 해결한 오류(몬스터)가 없습니다.");
        }
        else
        {
            for (auto const& pair : monsterKillCounts)
            {
                log(LogType::INFO, "{} : {}마리 해결", pair.first, pair.second);
            }
        }
        printLine();
    }

    static void printLine();
    static void clear();
};
