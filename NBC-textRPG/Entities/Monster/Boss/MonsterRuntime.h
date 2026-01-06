#pragma once

#include <string>

#include "MonsterBoss.h"

class MonsterRuntime : public MonsterBoss
{
public:
    MonsterRuntime(int characterLevel, std::string name = "런타임 에러");
};
