#include "Tablet.h"
#include "DeviceException.h"
#include <iostream>

Tablet::Tablet(int id, const std::string& name, double screenSize, bool hasPen)
    : Device(id, name), screenSize(screenSize), hasPen(hasPen)
{
    if (screenSize <= 0) {
        throw DeviceException("Некорректный размер экрана: должен быть положительным");
    }
}

void Tablet::PrintInfo() const {
    std::cout << "Планшет ID: " << id << ", Название: " << name
              << ", Размер экрана: " << screenSize << "\", Стилус: "
              << (hasPen ? "Есть" : "Нет") << std::endl;
}