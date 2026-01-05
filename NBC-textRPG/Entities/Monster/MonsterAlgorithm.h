#pragma once

#include <string>

#include "Monster.h"

class MonsterAlgorithm : public Monster
{
public:
    MonsterAlgorithm(int characterLevel, const std::string& name = "알고리즘");
};
