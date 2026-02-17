#include "Device.h"
#include "Phone.h"
#include "Tablet.h"
#include "DeviceException.h"
#include "TemplateStack.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <locale>
#include <windows.h>


template <typename T>
void PrintContainer(const T& container)
{

    if constexpr (std::is_same_v<typename T::value_type, Device*>)
    {
        std::cout << "Список устройств (vector):\n";
        for (const auto* dev : container)
        {
            if (dev)
            {
                dev->PrintInfo();
            }
            else
            {
                std::cout << "  [null]\n";
            }
        }
    }

    else if constexpr (std::is_same_v<typename T::value_type, std::pair<const int, Device*>>)
    {
        std::cout << "Устройства по ID (map):\n";
        for (const auto& [id, dev] : container)
        {
            std::cout << "  ID " << id << " → ";
            if (dev)
            {
                dev->PrintInfo();
            }
            else
            {
                std::cout << "[null]\n";
            }
        }
    }
    else
    {
        std::cout << "[неподдерживаемый тип контейнера]\n";
    }
    std::cout << "\n";
}


Device* FindById(const std::map<int, Device*>& deviceMap, int id)
{
    auto it = deviceMap.find(id);
    return (it != deviceMap.end()) ? it->second : nullptr;
}

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    std::vector<Device*> devices;
    std::map<int, Device*> deviceMap;
    TemplateStack<Device*> historyStack;

    try
    {

        Phone* phone1 = new Phone(1, "iPhone 14", "iPhone 14 Pro", "SN-A14P-001", "Флагман");
        devices.push_back(phone1);
        deviceMap[phone1->getId()] = phone1;
        historyStack.push(phone1);

        Phone* phone2 = new Phone(2, "Galaxy S23", "Samsung Galaxy S23 Ultra", "SN-S23U-777", "Флагман");
        devices.push_back(phone2);
        deviceMap[phone2->getId()] = phone2;
        historyStack.push(phone2);

        Tablet* tablet1 = new Tablet(3, "iPad Pro 2024", 12.9, true);
        devices.push_back(tablet1);
        deviceMap[tablet1->getId()] = tablet1;
        historyStack.push(tablet1);

        std::cout << "=== Все устройства (прямой цикл по vector) ===\n";
        for (const auto* dev : devices)
        {
            if (dev) dev->PrintInfo();
        }
        std::cout << "\n";

        std::cout << "=== Вывод vector через PrintContainer ===\n";
        PrintContainer(devices);

        std::cout << "=== Вывод map через PrintContainer ===\n";
        PrintContainer(deviceMap);

        std::cout << "Создано телефонов всего: " << Phone::GetCreatedCount() << "\n\n";


        Phone tempPhone(999, "Test Duplicate", "Samsung Galaxy S23 Ultra", "SN-S23U-777", "Тест");
        std::cout << "Сравнение phone2 и tempPhone по серийному номеру: "
                  << ((*phone2 == tempPhone) ? "ОДИНАКОВЫЕ" : "РАЗНЫЕ") << "\n\n";


        std::cout << "=== Поиск по ID ===\n";
        for (int id : {1, 2, 3, 5})
        {
            Device* found = FindById(deviceMap, id);
            std::cout << "ID " << id << ": ";
            if (found)
            {
                found->PrintInfo();
            }
            else
            {
                std::cout << "не найдено\n";
            }
        }
        std::cout << "\n";


        std::cout << "=== Демонстрация стека (history) ===\n";
        std::cout << "Верхний элемент: ";
        if (!historyStack.empty())
        {
            historyStack.top()->PrintInfo();
        }
        else
        {
            std::cout << "[пуст]\n";
        }

        std::cout << "Выполняем pop()...\n";
        if (!historyStack.empty()) historyStack.pop();

        std::cout << "Новый верхний элемент: ";
        if (!historyStack.empty())
        {
            historyStack.top()->PrintInfo();
        }
        else
        {
            std::cout << "[пуст]\n";
        }
        std::cout << "\n";
        
    }
    catch (const DeviceException& e)
    {
        std::cerr << "Ошибка устройства: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Стандартная ошибка: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка\n";
    }

    std::cout << "Освобождаем память...\n";
    for (auto* dev : devices)
    {
        delete dev;
    }
    devices.clear();
    deviceMap.clear();

    std::cout << "Программа завершена.\n";
    return 0;
}