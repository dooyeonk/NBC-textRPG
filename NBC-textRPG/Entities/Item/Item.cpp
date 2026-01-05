#include <iostream>
#include <string>

#include "Item.h"

Item::Item(const std::string& name, int price) : name(name), price(price)
{
}

std::string Item::getName() const
{
    return name;
}

int Item::getPrice() const
{
    return price;
}

void Item::setName(const std::string& itemName)
{
    name = itemName;
}

void Item::setPrice(int itemPrice = 0)
{
    price = itemPrice;
}

void Item::printEffect(const std::string& statName, int value) const
{
    std::cout << "[아이템(" << this->getName() << ") 사용]: ";
    std::string effectString = value > 0 ? "증가" : "감소";
    std::cout << statName << " " << value << " " << effectString << std::endl;
}
