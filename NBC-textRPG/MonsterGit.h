#pragma once

#include <string>

#include "Monster.h"

class MonsterGit : public Monster
{
public:
    MonsterGit(int characterLevel, const std::string& name = "Git");
};
