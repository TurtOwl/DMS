#include "Phone.h"
#include "DeviceException.h"
#include <iostream>

int Phone::countCreated = 0;

Phone::Phone(int id, const std::string& name, const std::string& model,
             const std::string& serialNumber, const std::string& phoneType)
    : Device(id, name), model(model), serialNumber(serialNumber), phoneType(phoneType)
{
    if (model.empty()) {
        throw DeviceException("Некорректная модель: модель не может быть пустой");
    }
    if (serialNumber.empty()) {
        throw DeviceException("Некорректный серийный номер: не может быть пустым");
    }
    countCreated++;
}

void Phone::PrintInfo() const {
    std::cout << "Телефон  ID: " << id << ", Название: " << name
              << ", Модель: " << model << ", Серийный: " << serialNumber
              << ", Тип: " << phoneType << std::endl;
}

int Phone::GetCreatedCount() {
    return countCreated;
}

bool Phone::operator==(const Phone& other) const {
    return serialNumber == other.serialNumber;
}