#pragma once

#include <string>

#include "Monster.h"

class MonsterCompile : public Monster
{
public:
    MonsterCompile(int characterLevel, const std::string& name = "컴파일 에러");
};
