#pragma once
#include <string>

struct ItemEffect
{
    int hp = 0;
    int attackPower = 0;
};

class Item
{
private:
    std::string name;
    int price;

public:
    Item();
    Item(const std::string& itemName, int itemPrice);
    virtual ~Item() = default;

    virtual ItemEffect getEffect() = 0;


    std::string getItemName();
    int getItemPrice();

    void setItemName(const std::string& itemName);
    void setItemPrice(int itmePrice);

};

class HealthPotion : public Item
{
private:
    int heal;

public:
    HealthPotion();
    HealthPotion(const std::string& itemName, int itemPrice, int healing);
    ~HealthPotion();

    ItemEffect getEffect();
};

class AttackBoost : public Item
{
private:
    int attackUp;

public:
    AttackBoost();
    AttackBoost(const std::string& itemName, int itemPrice, int atkUp);
    ~AttackBoost();

    ItemEffect getEffect();

};
