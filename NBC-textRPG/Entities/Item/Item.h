#pragma once

#include <string>

class Character;

class Item
{
protected:
    std::string name;
    int price;

    void printEffect(const std::string& statName, int value) const;

public:
    Item(const std::string& name, int price);
    virtual ~Item() = default;

    virtual void use(Character& character) const = 0;

    std::string getName() const;
    int getPrice() const;

    void setName(const std::string& name);
    void setPrice(int price);
};
