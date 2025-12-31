#include "Item.h"
#include <string>
using namespace std;

Item::Item() : use(false)  // 아이템 클래스의 생성자. use의 bool을 false로
{
}

Item::Item(const string& itemName, bool itemUse) : name(itemName), use(itemUse)
{
}

Item::~Item()
{
}

string Item::getItemName() // 타입을 제일 앞으로
{
    return name;
}

bool Item::getUse()
{
    return use;
}

void Item::setItemName(const string& itemName)
{
    name = itemName;
}

void Item::setUse(bool itemUse)
{
    use = itemUse;
}
