#include "Device.h"
#include "DeviceException.h"
#include <iostream>

Device::Device(int id, const std::string& name) {
    if (id < 0) {
        throw DeviceException("Invalid ID: ID must be non-negative.");
    }
    if (name.empty()) {
        throw DeviceException("Invalid Name: Name cannot be empty.");
    }
    this->id = id;
    this->name = name;
}

int Device::getId() const {
    return id;
}

std::string Device::getName() const {
    return name;
}
