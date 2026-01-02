#pragma once
#include <iostream>
#include <string>

enum class LogLevel
{
    INFO,   // 일반 정보 (흰색)
    COMBAT, // 전투 정보 (노란색/밝은 녹색)
    Error   // 에러/경고 (빨간색)
};

class Logger
{
public:
    static void Log(const std::string& message, LogLevel level = LogLevel::INFO);
    static void Info(const std::string& message);
    static void Combat(const std::string& message);
    static void Error(const std::string& message);
};
