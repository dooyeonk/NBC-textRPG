#include "Entities/Character/Character.h"
#include "Entities/Item/ItemManager.h"
#include "Shop.h"
#include "Utils/Logger.h"
#include <iostream>

using namespace std;

void Shop::Enter(Character& character)
{
    while (true)
    {
        system("cls");
        Logger::log(LogType::INFO, "===== [ 상점 ] =====");
        Logger::log(LogType::INFO, "현재 소지 골드: {}G", character.getGold());
        cout << "\n1. 아이템 구매\n2. 아이템 판매\n0. 나가기\n선택: ";

        int choice;
        cin >> choice;

        if (choice == 1)
            displayBuyMenu(character);
        else if (choice == 2)
            displaySellMenu(character);
        else if (choice == 0)
            break;
    }
}

void Shop::displayBuyMenu(Character& character)
{
    system("cls");
    auto items = ItemManager::getInstance().getAllPrototypes();

    Logger::log(LogType::INFO, "===== [ 아이템 구매 ] =====");
    for (int i = 0; i < items.size(); ++i)
    {
        cout << i + 1 << ". " << items[i]->getName() << " | " << items[i]->getPrice() << "G" << endl;
    }
    cout << "0. 뒤로가기\n구매할 아이템 번호: ";

    int choice;
    cin >> choice;

    if (choice > 0 && choice <= items.size())
    {
        auto selected = items[choice - 1];
        if (character.getGold() >= selected->getPrice())
        {
            character.spendGold(selected->getPrice());
            character.addItem(selected);
            Logger::log(LogType::ITEM, "{}을(를) 구매했습니다!", selected->getName());
            system("pause");
        }
        else
        {
            Logger::log(LogType::SYSTEM, "골드가 부족합니다!");
            system("pause");
        }
    }
}

void Shop::displaySellMenu(Character& character)
{
    system("cls");
    auto& inventory = character.getInventory();
    auto slots = inventory.getSlots();

    Logger::log(LogType::INFO, "===== [ 아이템 판매 (원가의 60%) ] =====");
    if (slots.empty())
    {
        Logger::log(LogType::SYSTEM, "판매할 아이템이 없습니다.");
        system("pause");
        return;
    }

    for (int i = 0; i < slots.size(); ++i)
    {
        int sellPrice = static_cast<int>(slots[i].item->getPrice() * SELL_PRICE_RATIO);
        cout << i + 1 << ". " << slots[i].item->getName() << " x" << slots[i].quantity << " | 판매가: " << sellPrice
             << "G" << endl;
    }
    cout << "0. 뒤로가기\n판매할 아이템 번호: ";

    int choice;
    cin >> choice;

    if (choice > 0 && choice <= slots.size())
    {
        auto selectedSlot = slots[choice - 1];
        int sellPrice = static_cast<int>(selectedSlot.item->getPrice() * SELL_PRICE_RATIO);

        character.addGold(sellPrice);
        inventory.remove(selectedSlot.item);
        Logger::log(LogType::SYSTEM, "{}을(를) 판매하여 {}G를 얻었습니다.", selectedSlot.item->getName(), sellPrice);
        system("pause");
    }
}
