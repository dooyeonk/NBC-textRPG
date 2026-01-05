#pragma once

#include <string>

#include "Monster.h"

class MonsterBoss : public Monster
{
public:
    MonsterBoss(int characterLevel, const std::string& name);
    virtual ~MonsterBoss() = default;

    bool isBoss() const override;
};
