#pragma once

#include <string>

#include "MonsterBoss.h"

class MonsterUnreal : public MonsterBoss
{
public:
    MonsterUnreal(int characterLevel, std::string name = "언리얼 C++");
};
