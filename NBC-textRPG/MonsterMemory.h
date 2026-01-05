#pragma once

#include <string>

#include "Monster.h"

class MonsterMemory : public Monster
{
public:
    MonsterMemory(int characterLevel, const std::string& name = "MemoryLeak");
};
