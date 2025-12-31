#pragma once

#include <string>

struct ItemEffect
{
    int hp = 0;
    int attackPower = 0;
};

class Item
{
public:
    std::string getName()
    {
        return name;
    }

    ItemEffect getItemEffect()
    {
        ItemEffect effect;
        effect.hp = 50;
        return effect;
    }

private:
    std::string name;
};
