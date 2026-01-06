#pragma once

#include <string>

#include "Monster.h"

class MonsterSyntax : public Monster
{
public:
    MonsterSyntax(int characterLevel, const std::string& name = "문법");
};
