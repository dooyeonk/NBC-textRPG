#pragma once

#include <string>

#include "Monster.h"

class MonsterError : public Monster
{
public:
    MonsterError(int characterLevel, const std::string& name = "컴파일 에러");
};
