#pragma once
#include <string>

class Item // 기본 클래스
{
private: // 멤버 변수
    std::string name;
    bool use;

public: // 멤버 함수
    Item(); // 생성자
    Item(const std::string& itemName, bool itemUse);
    ~Item(); // 소멸자


    std::string getItemName(); // getter 
    bool getUse();

    void setItemName(const std::string& itemName); // setter
    void setUse(bool itemUse);

};

};
